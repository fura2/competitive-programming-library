// Euler's totient function
// O(sqrt(a))

long long phi(long long a){
	long long res=a;
	for(long long p=2;p*p<=a;p++) if(a%p==0) {
		res=res/p*(p-1);
		do{ a/=p; }while(a%p==0);
	}
	if(a>1) res=res/a*(a-1);
	return res;
}

// phi(1), ..., phi(n) のテーブルを作成する
// O(n loglog n)
vector<int> phi;
void build_phi(int n){
	phi.resize(n+1);
	iota(phi.begin(),phi.end(),0);
	for(int i=2;i<=n;i++) if(phi[i]==i) {
		for(int j=i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);
	}
}
