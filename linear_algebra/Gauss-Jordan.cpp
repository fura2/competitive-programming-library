vector<double> Gauss_Jordan(const matrix<double>& A,const vector<double>& b){
	const double EPS=1e-8;

	assert(A.h()==A.w() && A.w()==b.size());

	int n=A.h();
	matrix<double> B(n,n+1);
	rep(i,n){
		rep(j,n) B[i][j]=A[i][j];
		B[i][n]=b[i];
	}

	rep(i,n){
		int pivot=i;
		for(int j=i;j<n;j++) if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;
		rep(j,n+1) swap(B[i][j],B[pivot][j]);
		assert(abs(B[i][i])>EPS);
		for(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
		rep(j,n) if(i!=j) for(int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];
	}

	vector<double> x(n);
	rep(i,n) x[i]=B[i][n];
	return x;
}
