#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../library/template.hpp"
#include "../../library/graph/tree_diameter.hpp"

int main(){
	int n; scanf("%d",&n);
	weighted_graph<lint> T(n);
	rep(i,n-1){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c);
		add_undirected_edge(T,u,v,c);
	}

	auto [d,p]=tree_diameter(T);
	printf("%lld %ld\n",d,p.size());
	rep(i,p.size()) printf("%d%c",p[i],i+1<p.size()?' ':'\n');

	return 0;
}
