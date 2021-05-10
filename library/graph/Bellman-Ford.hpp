#pragma once
#include "../template.hpp"
#include "wgraph.hpp"

template<class T>
vector<T> Bellman_Ford(const weighted_graph<T>& G,int s){
	const T INF=numeric_limits<T>::max();
	const T NINF=numeric_limits<T>::min();

	int n=G.size();
	vector<T> d(n,INF);
	d[s]=0;
	rep(_,n){
		bool upd=false;
		rep(u,n) if(d[u]<INF) for(const auto& e:G[u]) {
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, upd=true;
		}
		if(!upd) return d;
	}

	queue<int> Q;
	rep(u,n) if(d[u]<INF) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>NINF && (d[u]==NINF || d[v]>d[u]+e.wt)) d[v]=NINF, Q.emplace(v);
		}
	}
	return d;
}
