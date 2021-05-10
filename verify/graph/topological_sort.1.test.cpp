#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include "../../library/template.hpp"
#include "../../library/graph/topological_sort.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_directed_edge(G,u,v);
	}

	for(int u:topological_sort(G)) printf("%d\n",u);

	return 0;
}
