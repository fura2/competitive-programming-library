#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../library/template.hpp"
#include "../../library/tree/lca.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);
	graph T(n);
	for(int v=1;v<n;v++){
		int u; scanf("%d",&u);
		add_undirected_edge(T,u,v);
	}

	lowest_common_ancestor LCA(T,0);

	rep(_,q){
		int u,v; scanf("%d%d",&u,&v);
		printf("%d\n",LCA.lca(u,v));
	}

	return 0;
}
