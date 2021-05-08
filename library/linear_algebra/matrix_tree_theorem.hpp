template<class T>
mint number_of_spanning_trees(matrix<T> A){
	assert(A.h()==A.w());
	int n=A.h();

	matrix<mint> Lap(n-1);
	rep(u,n-1) rep(v,n-1) {
		Lap[u][v]=-A[u][v];
		if(u==v){
			rep(w,n) Lap[u][u]+=A[u][w];
		}
	}
	return det(Lap);
}
