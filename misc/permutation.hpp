class permutation{
	vector<int> f;
public:
	permutation(){}
	permutation(int n){
		f.resize(n);
		iota(f.begin(),f.end(),0);
	}
	permutation(const vector<int>& p):f(p){}

	permutation operator*(const permutation& p)const{
		int n=f.size();
		permutation res(n);
		rep(i,n) res.f[i]=f[p[i]];
		return res;
	}
	int operator[](int i)const{ return f[i]; }

	int size()const{ return f.size(); }

	void swap(int i,int j){ std::swap(f[i],f[j]); }

	friend permutation inverse(const permutation& p){
		int n=p.f.size();
		permutation res(n);
		rep(i,n) res.f[p.f[i]]=i;
		return res;
	}
};

permutation pow(permutation p,long long k){
	permutation res(p.size());
	for(;k>0;k>>=1,p=p*p) if(k&1) res=res*p;
	return res;
}

long long inversion_number(const permutation& p){
	int n=p.size();
	long long res=0;
	Fenwick_tree<int> F(n);
	rep(i,n){ res+=F.sum(p[i]+1,n); F.add(p[i],1); }
	return res;
}
