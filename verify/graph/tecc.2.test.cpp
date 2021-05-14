#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../library/template.hpp"
#include "../../library/graph/tecc.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G,u,v);
	}

	auto B=two_edge_connected_components(G).bridges();
	sort(B.begin(),B.end());

	for(auto [u,v]:B) printf("%d %d\n",u,v);

	return 0;
}
