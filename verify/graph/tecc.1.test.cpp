#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../library/template.hpp"
#include "../../library/graph/tecc.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G,u,v);
	}

	two_edge_connected_components TECC(G);

	int k=TECC.bridge_block_forest().size();
	printf("%d\n",k);
	rep(i,k){
		const auto& C=TECC.component(i);
		printf("%lu ",C.size());
		rep(j,C.size()) printf("%d%c",C[j],j+1<C.size()?' ':'\n');
	}

	return 0;
}
