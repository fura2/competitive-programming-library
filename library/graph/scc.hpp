#pragma once
#include "../template.hpp"
#include "graph.hpp"
#include "wgraph.hpp"

template<class T>
class strongly_connected_components{ strongly_connected_components(const T&)=delete; };

template<>
class strongly_connected_components<graph>{
	vector<int> id;
	vector<vector<int>> Comp;
	graph D;

public:
	strongly_connected_components(const graph& G={}){ build(G); }

	void build(const graph& G){
		int n=G.size();
		graph G_rev(n);
		rep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);

		int k;
		vector<int> top(n);

		auto dfs1=[&](auto&& dfs1,int u)->void{
			id[u]=0;
			for(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);
			top[k++]=u;
		};
		auto dfs2=[&](auto&& dfs2,int u)->void{
			id[u]=k;
			for(int v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);
		};

		k=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs1(dfs1,u);

		reverse(top.begin(),top.end());

		k=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(dfs2,u), k++;

		Comp.resize(k);
		D.resize(k);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);
		}
	}

	int operator[](int u)const{ return id[u]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const graph& DAG()const{ return D; }
};

template<class W>
class strongly_connected_components<weighted_graph<W>>{
	vector<int> id;
	vector<vector<int>> Comp;
	weighted_graph<W> D;

public:
	strongly_connected_components(const weighted_graph<W>& G={}){ build(G); }

	void build(const weighted_graph<W>& G){
		int n=G.size();
		weighted_graph<W> G_rev(n);
		rep(u,n) for(const auto& [v,wt]:G[u]) add_directed_edge(G_rev,v,u,wt);

		int k;
		vector<int> top(n);

		auto dfs1=[&](auto&& dfs1,int u)->void{
			id[u]=0;
			for(const auto& [v,wt]:G[u]) if(id[v]==-1) dfs1(dfs1,v);
			top[k++]=u;
		};
		auto dfs2=[&](auto&& dfs2,int u)->void{
			id[u]=k;
			for(const auto& [v,wt]:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);
		};

		k=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs1(dfs1,u);

		reverse(top.begin(),top.end());

		k=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(dfs2,u), k++;

		Comp.resize(k);
		D.resize(k);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(const auto& [v,wt]:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v],wt);
		}
	}

	int operator[](int u)const{ return id[u]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const weighted_graph<W>& DAG()const{ return D; }
};
