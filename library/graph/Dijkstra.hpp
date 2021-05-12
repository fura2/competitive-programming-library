#pragma once
#include "../template.hpp"
#include "wgraph.hpp"

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();

	int n=G.size();
	vector<T> d(n,INF); d[s]=T{};
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	Q.emplace(T{},s);
	while(!Q.empty()){
		T d0;
		int u; tie(d0,u)=Q.top();
		Q.pop();
		if(d0>d[u]) continue;
		for(const auto& [v,wt]:G[u]){
			if(d[v]>d[u]+wt){
				d[v]=d[u]+wt;
				Q.emplace(d[v],v);
			}
		}
	}
	return d;
}
