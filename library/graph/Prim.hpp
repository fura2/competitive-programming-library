#pragma once
#include "../template.hpp"
#include "wgraph.hpp"

template<class T>
pair<T,weighted_graph<T>> Prim(const weighted_graph<T>& G){
	constexpr T INF=numeric_limits<T>::max();

	int n=G.size();
	T total{};
	weighted_graph<T> MSF(n);
	vector<bool> vis(n);
	vector<T> d(n,INF);
	vector<int> pre(n,-1);

	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	rep(s,n) if(!vis[s]) {
		d[s]=T{};
		Q.emplace(T{},s);
		while(!Q.empty()){
			T d0;
			int u; tie(d0,u)=Q.top();
			Q.pop();
			if(vis[u]) continue;
			vis[u]=true;

			if(pre[u]!=-1){
				total+=d[u];
				add_undirected_edge(MSF,u,pre[u],d[u]);
			}

			for(const auto& [v,wt]:G[u]){
				if(!vis[v] && d[v]>wt){
					d[v]=wt;
					pre[v]=u;
					Q.emplace(d[v],v);
				}
			}
		}
	}
	return {total,MSF};
}
