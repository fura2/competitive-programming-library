/*
	辺に重みがついた有向グラフ G のハミルトン路 (の重み) を求める
	求めるハミルトン路の始点と終点は任意

	T は重みの型
	G は隣接行列 A で与えられ, 辺がない部分には T の最大値が入っていることを仮定する
	G がハミルトン路をもたないときは T の最大値が返る
*/

template<class T>
T Hamiltonian_path(const vector<vector<T>>& A){
	constexpr T INF=numeric_limits<T>::max();
	int n=A.size();
	vector dp(1<<n,vector(n,INF));
	rep(u,n) dp[1<<u][u]=0;
	rep(S,1<<n) rep(u,n) if(S>>u&1 && dp[S][u]<INF) {
		rep(v,n) if(~S>>v&1 && A[u][v]<INF) {
			dp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+A[u][v]);
		}
	}

	T res=INF;
	rep(u,n) res=min(res,dp[(1<<n)-1][u]);
	return res;
}
