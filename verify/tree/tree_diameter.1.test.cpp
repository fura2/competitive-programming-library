#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../library/template.hpp"
#include "../../library/tree/tree_diameter.hpp"

int main(){
	int n; scanf("%d",&n);
	weighted_graph<int> T(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_undirected_edge(T,u,v,c);
	}

	printf("%d\n",tree_diameter(T).first);

	return 0;
}
