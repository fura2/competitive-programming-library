#pragma once
#include "../template.hpp"
#include "graph.hpp"

class two_edge_connected_components{
	vector<int> id;
	vector<vector<int>> Comp;
	vector<pair<int,int>> B;
	graph BBF;

public:
	two_edge_connected_components(const graph& G={}){ build(G); }

	void build(const graph& G){
		int n=G.size(),idx;
		vector<int> ord(n,-1),low(n,-1);

		auto dfs1=[&](auto&& dfs1,int u,int p)->void{
			ord[u]=low[u]=idx++;
			bool f=true;
			for(int v:G[u]){
				if(v==p && f){ f=false; continue; }
				if(ord[v]==-1){
					dfs1(dfs1,v,u);
					low[u]=min(low[u],low[v]);
				}
				else{
					low[u]=min(low[u],ord[v]);
				}
			}
		};

		auto dfs2=[&](auto&& dfs2,int u,int p)->void{
			if(p==-1 || ord[p]<low[u]){
				id[u]=idx++;
				if(p!=-1) B.emplace_back(minmax(p,u));
			}
			else{
				id[u]=id[p];
			}
			for(int v:G[u]) if(id[v]==-1) dfs2(dfs2,v,u);
		};

		idx=0;
		rep(u,n) if(ord[u]==-1) dfs1(dfs1,u,-1);

		idx=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs2(dfs2,u,-1);

		Comp.resize(idx);
		BBF.resize(idx);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) BBF[id[u]].emplace_back(id[v]);
		}
	}

	int operator[](int i)const{ return id[i]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const vector<pair<int,int>>& bridges()const{ return B; }
	const graph& bridge_block_forest()const{ return BBF; }
};
