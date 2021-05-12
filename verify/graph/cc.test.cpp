#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D"

#include "../../library/template.hpp"
#include "../../library/graph/cc.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G,u,v);
	}

	auto CC=connected_components(G);
	vector<int> id(n);
	rep(i,CC.size()) for(int u:CC[i]) id[u]=i;

	int q; scanf("%d",&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v);
		puts(id[u]==id[v]?"yes":"no");
	}

	return 0;
}
