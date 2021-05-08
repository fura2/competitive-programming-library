#pragma once
#include "../template.hpp"
#include "wgraph.hpp"

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	Q.emplace(0,s);
int cnt=0;
	while(!Q.empty()){
cnt++;
		T d0;
		int u; tie(d0,u)=Q.top();
		Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(d[v],v);
			}
		}
	}
printf("n = %d, s = %d: cnt = %d\n",n,s,cnt);
	return d;
}
