#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../library/template.hpp"
#include "../../library/graph/Prim.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_undirected_edge(G,u,v,c);
	}

	printf("%d\n",Prim(G).first);

	return 0;
}
