/*
	単一始点最短路
	負の重みがあってもよい
	T = int, lint を想定している (double だと不等号に EPS を考慮しないとまずいかも)

	s から到達できない頂点の距離は INF となる (ある負閉路から到達可能であっても)
	G が負閉路をもつ場合に, s からいくらでも小さいコストで到達できる頂点の距離は NINF となる (-INF ではないので注意)
*/

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
