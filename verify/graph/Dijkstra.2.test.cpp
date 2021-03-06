#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4

#include "../../library/template.hpp"
#include "../../library/graph/Dijkstra.hpp"

// T が double 型のケース
// ライブラリの要件を満たしていないが実用上問題なく動く

int main(){
	int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t); s--; t--;
	vector<double> x(n),y(n);
	rep(i,n) scanf("%lf%lf",&x[i],&y[i]);

	weighted_graph<double> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v,hypot(x[u]-x[v],y[u]-y[v]));
	}

	printf("%.9f\n",Dijkstra(G,s)[t]);

	return 0;
}
