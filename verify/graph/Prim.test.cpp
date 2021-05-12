#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A"

#include "../../library/template.hpp"
#include "../../library/graph/Prim.hpp"

int main(){
	int n; scanf("%d",&n);
	weighted_graph<int> G(n);
	rep(u,n) rep(v,n) {
		int c; scanf("%d",&c);
		if(u<v && c!=-1) add_undirected_edge(G,u,v,c);
	}

	printf("%d\n",Prim(G).first);

	return 0;
}
