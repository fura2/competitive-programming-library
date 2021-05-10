#pragma once
#include "../template.hpp"
#include "graph.hpp"
#include "wgraph.hpp"

pair<int,vector<int>> tree_diameter(const graph& T){
	int n=T.size();
	vector<int> pre(n,-1);

	auto dfs=[&](auto&& dfs,int u,int p)->pair<int,int>{
		int g=u,d_max=0;
		for(int v:T[u]) if(v!=p) {
			auto [d,w]=dfs(dfs,v,u);
			if(d+1>d_max){
				d_max=d+1;
				g=w;
			}
			pre[v]=u;
		}
		return {d_max,g};
	};
	int u0=dfs(dfs,0,-1).second;
	auto [diam,u1]=dfs(dfs,u0,-1);

	vector<int> P={u1};
	for(int u=u1;u!=u0;u=pre[u]){
		P.emplace_back(pre[u]);
	}
	reverse(P.begin(),P.end());

	return {diam,P};
}

template<class W>
pair<W,vector<int>> tree_diameter(const weighted_graph<W>& T){
	int n=T.size();
	vector<int> pre(n,-1);

	auto dfs=[&](auto&& dfs,int u,int p)->pair<W,int>{
		int g=u;
		W d_max=0;
		for(auto e:T[u]) if(e.to!=p) {
			auto [d,v]=dfs(dfs,e.to,u);
			if(d+e.wt>d_max){
				d_max=d+e.wt;
				g=v;
			}
			pre[e.to]=u;
		}
		return {d_max,g};
	};
	int u0=dfs(dfs,0,-1).second;
	auto [diam,u1]=dfs(dfs,u0,-1);

	vector<int> P={u1};
	for(int u=u1;u!=u0;u=pre[u]){
		P.emplace_back(pre[u]);
	}
	reverse(P.begin(),P.end());

	return {diam,P};
}
