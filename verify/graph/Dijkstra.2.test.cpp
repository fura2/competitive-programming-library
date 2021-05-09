/*
#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4

#include "../../library/template.hpp"
#include "../../library/graph/Dijkstra.hpp"

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
*/

// copy of http://kmyk.github.io/competitive-programming-library/graph/dijkstra.yukicoder-1065.test.cpp for debugging

#line 1 "graph/dijkstra.yukicoder-1065.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4
#include <bits/stdc++.h>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "graph/dijkstra.hpp"

/**
 * @brief Dijkstra ($O((E + V) \log V)$)
 */
template <class T = int64_t>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int, T> > > const & g, int root) {
    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());
    std::priority_queue<std::pair<T, int> > que;
    dist[root] = 0;
    que.emplace(- dist[root], root);
    while (not que.empty()) {
        T dist_x; int x; std::tie(dist_x, x) = que.top(); que.pop();
        if (dist[x] < - dist_x) continue;
        for (auto it : g[x]) {
            int y; T cost; std::tie(y, cost) = it;
            if (- dist_x + cost < dist[y]) {
                dist[y] = - dist_x + cost;
                que.emplace(dist_x - cost, y);
            }
        }
    }
    return dist;
}
#line 6 "graph/dijkstra.yukicoder-1065.test.cpp"
using namespace std;


int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    int start, goal; scanf("%d%d", &start, &goal);
    -- start;
    -- goal;
    vector<long long> x(n), y(n);
    REP (i, n) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    vector<vector<pair<int, double> > > g(n);
    REP (i, m) {
        int p, q; cin >> p >> q;
        -- p;
        -- q;
        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2));
        g[p].emplace_back(q, cost);
        g[q].emplace_back(p, cost);
    }

    // solve
    auto dist = dijkstra(g, start);

    // output
    printf("%.12lf\n", dist[goal]);
    return 0;
}
