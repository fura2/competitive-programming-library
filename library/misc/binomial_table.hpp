
vector<vector<long long>> binomial_table(int n){
	vector C(n+1,vector(n+1,0LL));
	rep(i,n+1){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	return C;
}
