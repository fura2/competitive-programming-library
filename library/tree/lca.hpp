#pragma once
#include "../template.hpp"
#include "../graph/graph.hpp"
#include "../graph/wgraph.hpp"

template<class T>
class lowest_common_ancestor{ lowest_common_ancestor(const T&,int)=delete; };

template<>
class lowest_common_ancestor<graph>{
	vector<int> dep;
	vector<vector<int>> par;

public:
	lowest_common_ancestor(){}
	lowest_common_ancestor(const graph& T,int root){ build(T,root); }

	void build(const graph& T,int root){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		auto dfs=[&](auto&& dfs,int u,int p)->void{
			for(int v:T[u]) if(v!=p) {
				dep[v]=dep[u]+1;
				par[0][v]=u;
				dfs(dfs,v,u);
			}
		};

		dfs(dfs,root,-1);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	int distance(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};

template<class W>
class lowest_common_ancestor<weighted_graph<W>>{
	vector<int> dep;
	vector<vector<int>> par;
	vector<vector<W>> dist;

public:
	lowest_common_ancestor(){}
	lowest_common_ancestor(const weighted_graph<W>& T,int root){ build(T,root); }

	void build(const weighted_graph<W>& T,int root){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));
		dist.assign(h,vector<W>(n));

		auto dfs=[&](auto&& dfs,int u,int p)->void{
			for(const auto& [v,wt]:T[u]) if(v!=p) {
				dep[v]=dep[u]+1;
				par[0][v]=u;
				dist[0][v]=wt;
				dfs(dfs,v,u);
			}
		};

		dfs(dfs,root,-1);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) {
			par[i+1][u]=par[i][par[i][u]];
			dist[i+1][u]=dist[i][u]+dist[i][par[i][u]];
		}
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	W distance(int u,int v)const{
		int h=par.size();
		W res=0;
		int w=lca(u,v);
		rep(i,h){
			if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];
			if((dep[v]-dep[w])>>i&1) res+=dist[i][v], v=par[i][v];
		}
		return res;
	}
};
