#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../library/template.hpp"
#include "../../library/graph/Dijkstra.hpp"

int main(){
	int n,m,s; scanf("%d%d%d",&n,&m,&s);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_directed_edge(G,u,v,c);
	}
	return 0;
// fprintf(stdout,"n = %d, m = %d, s = %d: max = %d, INT_MAX = %d\n",n,m,s,numeric_limits<int>::max(),INT_MAX);
// if(n==49000 && m==200000 && s==0) return 0;

	for(auto d:Dijkstra(G,s)){
		if(d<INT_MAX) printf("%d\n",d);
		else          puts("INF");
	}

	return 0;
}