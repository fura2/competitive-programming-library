#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0275"

#include "../../library/template.hpp"
#include "../../library/graph/Dijkstra.hpp"
#include "../../library/graph/offline_reachability.hpp"

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}
	int a,b,q; scanf("%d%d%d",&a,&b,&q); a--; b--;

	auto da=Dijkstra(G,a);
	auto db=Dijkstra(G,b);

	graph D(n);
	rep(u,n) for(auto [v,wt]:G[u]) {
		if(da[u]+wt==da[v]){
			add_directed_edge(D,u,v);
		}
	}

	vector<pair<int,int>> Q(q);
	rep(i,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		Q[i]={u,v};
	}

	auto res=offline_reachability(D,Q);
	rep(i,q){
		int u,v; tie(u,v)=Q[i];
		puts(da[v]+db[v]==da[b]&&res[i]?"Yes":"No");
	}

	return 0;
}
