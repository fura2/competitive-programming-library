#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../library/template.hpp"
#include "../../library/tree/lca.hpp"

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(u,n){
		int k; scanf("%d",&k);
		rep(i,k){
			int v; scanf("%d",&v);
			add_undirected_edge(T,u,v);
		}
	}

	lowest_common_ancestor LCA(T,0);

	int q; scanf("%d",&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v);
		printf("%d\n",LCA.lca(u,v));
	}

	return 0;
}
