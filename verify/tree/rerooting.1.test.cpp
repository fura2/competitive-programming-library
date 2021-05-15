#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../library/template.hpp"
#include "../../library/tree/rerooting.hpp"
#include "../../library/monoid/max_monoid.hpp"

struct top2_monoid{
	int a,b;
	top2_monoid(int a=0,int b=0):a(a),b(b){}
	top2_monoid operator*(const top2_monoid& x)const{
		return {max(a,x.a),min(a,x.a)};
	}
};

int main(){
	int n; scanf("%d",&n);
	weighted_graph<int> T(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_undirected_edge(T,u,v,c);
	}

	using monoid=top2_monoid;
	auto f=[](monoid m,int wt,int v)->monoid{
		return {m.a+wt,m.b+wt};
	};
	auto g=[](monoid m,int u)->monoid{
		return m;
	};

	int ans=0;
	for(auto m:rerooting<monoid>(T,f,g)){
		ans=max(ans,m.a+m.b);
	}
	printf("%d\n",ans);

	return 0;
}
