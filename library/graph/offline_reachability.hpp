#pragma once
#include "../template.hpp"
#include "graph.hpp"
#include "scc.hpp"

vector<bool> offline_reachability(const graph& G,vector<pair<int,int>> Q){
	strongly_connected_components SCC(G);
	for(auto& [u,v]:Q){
		u=SCC[u];
		v=SCC[v];
	}

	vector<bool> res(Q.size());
	vector<int> C;
	rep(i,Q.size()){
		int u,v; tie(u,v)=Q[i];
		if(u==v) res[i]=true;
		else     C.emplace_back(i);
	}

	const auto& D=SCC.DAG();
	int n=D.size();
	for(int l=0;l<C.size();l+=64){
		int r=min(l+64,int(C.size()));
		vector<int64_t> dp(n);
		for(int i=l;i<r;i++){
			dp[Q[C[i]].first]|=int64_t(1)<<(i-l);
		}
		rep(u,n) for(int v:D[u]) dp[v]|=dp[u];
		for(int i=l;i<r;i++){
			res[C[i]]=dp[Q[C[i]].second]>>(i-l)&1;
		}
	}

	return res;
}
