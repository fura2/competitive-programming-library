#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../library/template.hpp"
#include "../../library/graph/scc.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_directed_edge(G,u,v);
	}

	strongly_connected_components SCC(G);

	int k=SCC.DAG().size();
	printf("%d\n",k);
	rep(i,k){
		auto res=SCC.component(i);
		printf("%ld ",res.size());
		rep(i,res.size()) printf("%d%c",res[i],i+1<res.size()?' ':'\n');
	}

	return 0;
}
