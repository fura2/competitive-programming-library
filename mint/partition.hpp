/*
	分割数 P(n, k)
		n 個の区別できないボールを k 個のグループに分ける方法の数
		あるいは, n を k 個の非負整数の和で書く方法の数 (和の順序は区別しない)
*/

mint partition(int n,int k){
	vector dp(n+1,vector(k+1,mint(0)));
	rep(j,k+1) dp[0][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++) dp[i][j]=dp[i][j-1]+(j<=i?dp[i-j][j]:0);
	}
	return dp[n][k];
}

vector<vector<mint>> Part;
void build_partition(int n,int k){
	Part.assign(n+1,vector(k+1,mint(0)));
	rep(j,k+1) Part[0][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++) Part[i][j]=Part[i][j-1]+(j<=i?Part[i-j][j]:0);
	}
}
