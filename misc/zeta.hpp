/*
	下位集合に対する高速ゼータ変換
		M : 可換モノイド
		f : 2^{0, 1, ..., N-1} -> M
		に対して
		g(S) = Σ_{T ⊂ S} f(T)
		で定義される g : 2^{0, 1, ..., N-1} -> M を求める
*/

template<class M>
vector<M> zeta_subset(vector<M> f){
	int n=log2(f.size());
	rep(i,n) rep(S,1<<n) if(~S>>i&1) f[S|1<<i]=f[S|1<<i]*f[S];
	return f;
}
