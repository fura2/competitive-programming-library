#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include "../../library/template.hpp"
#include "../../library/graph/distance.hpp"

int main(){
	int n; scanf("%d",&n);
	graph G(n);
	rep(i,n){
		int u,k; scanf("%d%d",&u,&k); u--;
		G[u].resize(k);
		rep(j,k){
			int v; scanf("%d",&v); v--;
			add_directed_edge(G,u,v);
		}
	}

	auto d=distance(G,0);
	rep(u,n) printf("%d %d\n",u+1,d[u]<INT_MAX?d[u]:-1);

	return 0;
}
