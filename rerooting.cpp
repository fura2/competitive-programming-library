/*
	全方位木 DP
		T = (V, E) : 木
		(M, *) : モノイド
		f : M × V → M
		g : M × V → M

		根を任意に固定して T を根つき木とみなし, dp : V → M を
			dp[u] = g(f(dp[v_1], v_1) * f(dp[v_2], v_2) * ... * f(dp[v_k], v_k), u)
		と定める. ここで, 頂点 u の子を v_1, ..., v_k とする.
		f, g の第 2 引数は使わないことも多い (頂点に重みがついているときなどに有効).

		各頂点 u に対して, u を根としたときの dp[u] の値を求める.
		計算量は O(|V|) となる.

		使うときは次のように書く (必要に応じて [] は [&] に書き換える).

		auto f=[](monoid m,int u)->monoid{
			return ***;
		};
		auto g=[](monoid m,int u)->monoid{
			return ***;
		};
		auto res=rerooting<monoid>(T,f,g);

		参考 : https://null-mn.hatenablog.com/entry/2020/04/14/124151
*/

template<class M,class F,class G>
vector<M> rerooting(const graph& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(int v:T[u]) if(v!=p) {
			dfs1(dfs1,v,u);
			dp1[u]=dp1[u]*f(dp1[v],v);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			int v=T[u][i];
			lcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			int v=T[u][i];
			if(v!=p){
				dfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));
			}
		}
	};

	dfs1(dfs1,0,-1);
	dfs2(dfs2,0,-1,M());

	return dp2;
}

/*
	全方位木 DP
		T = (V, E) : 辺に重みがついた木
		W : 辺の重みの型
			実装上, T の辺は 2 本の有向辺で表される
			このとき, これら 2 本の有向辺の重みは異なっていてもよい
		(M, *) : モノイド
		f : M × E → M
		g : M × V → M

		根を任意に固定して T を根つき木とみなし, dp : V → M を
			dp[u] = g(f(dp[v_1], e_1) * f(dp[v_2], e_2) * ... * f(dp[v_k], e_k), u)
		と定める. ここで, 頂点 u の子を v_1, ..., v_k と, u から v_i への有向辺を e_i とおく.
		g の第 2 引数は使わないことも多い (頂点に重みがついているときなどに有効).

		各頂点 u に対して, u を根としたときの dp[u] の値を求める.
		計算量は O(|V|) となる.

		使うときは次のように書く (必要に応じて [] は [&] に書き換える).

		auto f=[](monoid m,edge<int> e)->monoid{
			return ***;
		};
		auto g=[](monoid m,int u)->monoid{
			return ***;
		};
		auto res=rerooting<monoid>(T,f,g);
*/

template<class M,class W,class F,class G>
vector<M> rerooting(const weighted_graph<W>& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(const auto& e:T[u]) if(e.to!=p) {
			dfs1(dfs1,e.to,u);
			dp1[u]=dp1[u]*f(dp1[e.to],e);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			const auto& e=T[u][i];
			lcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			const auto& e=T[u][i];
			if(e.to!=p){
				dfs2(dfs2,e.to,u,g(lcum[i]*rcum[i+1],u));
			}
		}
	};

	dfs1(dfs1,0,-1);
	dfs2(dfs2,0,-1,M());

	return dp2;
}
