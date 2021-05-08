#pragma once
#include "../template.hpp"

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}
