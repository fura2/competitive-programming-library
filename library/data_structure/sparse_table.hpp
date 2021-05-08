#pragma once
#include "../template.hpp"

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table()=default;
	sparse_table(const vector<T>& a){ build(a); }
	void build(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T fold(int l,int r)const{
		int i=h[r-l];
		return min(st[i][l],st[i][r-(1<<i)]);
	}
};
