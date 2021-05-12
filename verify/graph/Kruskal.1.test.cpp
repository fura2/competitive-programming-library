#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../library/template.hpp"
#include "../../library/graph/Kruskal.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<tuple<int,int,int>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		E[i]=tie(u,v,c);
	}

	printf("%d\n",Kruskal(n,E));

	return 0;
}
