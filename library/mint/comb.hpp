mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

mint factorial(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

mint factorial_inverse(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		memo[n]=inverse(factorial(n));
		for(int i=n;i>k;i--) memo[i-1]=memo[i]*i;
	}
	return memo[n];
}

mint choose(int n,int k,int type=0){
	if(k==0) return 1;
	if(n< k) return 0;
	if(type==0){
		return factorial(n)*factorial_inverse(k)*factorial_inverse(n-k);
	}
	else{
		if(k>n-k) k=n-k;
		mint res=factorial_inverse(k);
		rep(i,k) res*=n-i;
		return res;
	}
}

mint multichoose(int n,int k,int type=0){
	return choose(n+k-1,k,type);
}
