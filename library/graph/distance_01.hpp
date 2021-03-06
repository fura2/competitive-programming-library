#pragma once
#include "../template.hpp"
#include "wgraph.hpp"

vector<int> distance_01(const weighted_graph<int>& G,int s){
	constexpr int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	deque<int> Q; Q.emplace_back(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop_front();
		for(const auto& [v,wt]:G[u]){
			if(d[v]>d[u]+wt){
				d[v]=d[u]+wt;
				if(wt==0) Q.emplace_front(v);
				else      Q.emplace_back(v);
			}
		}
	}
	return d;
}
