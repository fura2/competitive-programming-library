#pragma once
#include "../template.hpp"

template<class T>
class Cartesian_tree{
	vector<T> a;
	int rt;
	vector<int> p,l,r;
public:
	Cartesian_tree(const vector<T>& a={}){ build(a); }

	void build(const vector<T>& a){
		this->a=a;
		int n=a.size();
		rt=0;
		p.assign(n,-1);
		l.assign(n,-1);
		r.assign(n,-1);

		for(int u=1;u<n;u++){
			int v=u-1;
			bool top=false;
			while(a[v]>a[u]){
				if(p[v]==-1){
					top=true;
					break;
				}
				v=p[v];
			}
			if(top){
				p[v]=u;
				l[u]=v;
				rt=u;
			}
			else{
				p[u]=v;
				if(r[v]!=-1) p[r[v]]=u;
				l[u]=r[v];
				r[v]=u;
			}
		}
	}
	const T& operator[](int u)const{ return a[u]; }
	int root()const{ return rt; }
	int parent(int u)const{ return p[u]; }
	int left(int u)const{ return l[u]; }
	int right(int u)const{ return r[u]; }
};
