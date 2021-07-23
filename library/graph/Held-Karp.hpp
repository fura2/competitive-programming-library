#pragma once
#include "../template.hpp"

/*
	辺に重みがついた有向グラフ G のハミルトン路 (の重み) を求める
	求めるハミルトン路の始点と終点は任意

	T は重みの型
	G は隣接行列 A で与えられ, 辺がない部分には T の最大値が入っていることを仮定する
	G がハミルトン路をもたないときは T の最大値が返る
*/

template<class T>
T Held_Karp(const vector<vector<T>>& d){
	constexpr T INF=numeric_limits<T>::max();
	int n=d.size();
	vector dp(1<<n,vector(n,INF));
	dp[1<<0][0]=T();
	rep(S,1<<n) rep(u,n) if(S>>u&1 && dp[S][u]<INF) {
		rep(v,n) if(~S>>v&1 && d[u][v]<INF) {
			dp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+d[u][v]);
		}
	}

	T res=INF;
	rep(u,n) if(dp[(1<<n)-1][u]<INF && d[u][0]<INF) {
		res=min(res,dp[(1<<n)-1][u]+d[u][0]);
	}
	return res;
}
