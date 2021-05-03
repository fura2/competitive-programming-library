mint det(matrix<mint> A){
	assert(A.h()==A.w());
	int n=A.h();

	int sgn=1;
	rep(i,n){
		int piv;
		for(piv=i;piv<n;piv++) if(A[piv][i].to_int()!=0) break;
		if(piv==n) return 0;
		if(piv!=i){
			rep(j,n) swap(A[i][j],A[piv][j]);
			sgn*=-1;
		}
		for(int k=i+1;k<n;k++) if(A[k][i].to_int()!=0) {
			mint c=A[k][i]/A[i][i];
			for(int j=i;j<n;j++) A[k][j]-=c*A[i][j];
		}
	}

	mint res=sgn;
	rep(i,n) res*=A[i][i];
	return res;
}
