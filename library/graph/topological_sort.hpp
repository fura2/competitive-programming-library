#pragma once
#include "../template.hpp"
#include "graph.hpp"
#include "wgraph.hpp"

vector<int> topological_sort(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

template<class T>
vector<int> topological_sort(const weighted_graph<T>& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(const auto& e:D[u]) deg[e.to]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(const auto& e:D[u]) if(--deg[e.to]==0) Q.emplace(e.to);
	}
	return res;
}
