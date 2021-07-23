#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include "../../library/template.hpp"
#include "../../library/graph/Held-Karp.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector d(n,vector(n,INT_MAX));
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		d[u][v]=c;
	}

	int ans=Held_Karp(d);
	printf("%d\n",ans<INT_MAX?ans:-1);

	return 0;
}
