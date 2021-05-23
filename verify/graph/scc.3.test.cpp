#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../library/template.hpp"
#include "../../library/graph/scc.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_directed_edge(G,u,v,1);
	}

	strongly_connected_components SCC(G);

	int q; scanf("%d",&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v);
		puts(SCC[u]==SCC[v]?"1":"0");
	}

	return 0;
}
