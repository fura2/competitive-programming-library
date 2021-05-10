#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../../library/template.hpp"
#include "../../library/graph/Bellman-Ford.hpp"

int main(){
	int n,m,s; scanf("%d%d%d",&n,&m,&s);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_directed_edge(G,u,v,c);
	}

	auto d=Bellman_Ford(G,s);
	if(count(d.begin(),d.end(),INT_MIN)>0){
		puts("NEGATIVE CYCLE");
	}
	else{
		rep(u,n){
			if(d[u]<INT_MAX) printf("%d\n",d[u]);
			else             puts("INF");
		}
	}

	return 0;
}
