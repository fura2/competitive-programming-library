#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include "../../library/template.hpp"
#include "../../library/tree/rerooting.hpp"
#include "../../library/monoid/max_monoid.hpp"

int main(){
	int n; scanf("%d",&n);
	weighted_graph<int> T(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_undirected_edge(T,u,v,c);
	}

	using monoid=max_monoid<int>;
	auto f=[](monoid m,edge<int> e)->monoid{
		return m.get()+e.wt;
	};
	auto g=[](monoid m,int u)->monoid{
		return m*0;
	};
	for(auto m:rerooting<monoid>(T,f,g)){
		printf("%d\n",m.get());
	}

	return 0;
}
