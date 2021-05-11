#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../library/template.hpp"
#include "../../library/graph/is_DAG.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_directed_edge(G,u,v);
	}

	puts(is_DAG(G)?"0":"1");

	return 0;
}
