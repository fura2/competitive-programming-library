#pragma once
#include "../template.hpp"
#include "wgraph.hpp"
#include "../data_structure/union-find.hpp"

template<class T>
T Kruskal(int n,vector<tuple<int,int,T>> E){
	sort(E.begin(),E.end(),[](const auto& e,const auto& f){
		return get<2>(e)<get<2>(f);
	});

	T total{};
	union_find U(n);
	for(const auto& [u,v,wt]:E){
		if(!U.is_same(u,v)){
			U.unite(u,v);
			total+=wt;
		}
	}
	return total;
}

template<class T>
pair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G){
	int n=G.size();
	vector<tuple<int,int,T>> E;
	rep(u,n) for(const auto& [v,wt]:G[u]) {
		if(u<v) E.emplace_back(u,v,wt);
	}

	sort(E.begin(),E.end(),[](const auto& e,const auto& f){
		return get<2>(e)<get<2>(f);
	});

	T total{};
	weighted_graph<T> MSF(n);
	union_find U(n);
	for(const auto& [u,v,wt]:E){
		if(!U.is_same(u,v)){
			U.unite(u,v);
			total+=wt;
			add_undirected_edge(MSF,u,v,wt);
		}
	}
	return {total,MSF};
}
