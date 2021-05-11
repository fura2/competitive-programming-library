#pragma once
#include "../template.hpp"

template<class B>
class sparse_table{
	vector<vector<B>> st;
	vector<int> h;
public:
	sparse_table()=default;
	template<class T>
	sparse_table(const vector<T>& a){ build(a); }

	template<class T>
	void build(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0].resize(n);
		rep(i,n) st[0][i]=a[i];
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=st[i-1][j]*st[i-1][j+(1<<(i-1))];
		}
	}

	B product(int l,int r)const{
		int i=h[r-l];
		return st[i][l]*st[i][r-(1<<i)];
	}
};
