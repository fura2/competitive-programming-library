---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/Dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':x:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1065
    document_title: Dijkstra ($O((E + V) \log V)$)
    links:
    - http://kmyk.github.io/competitive-programming-library/graph/dijkstra.yukicoder-1065.test.cpp
    - https://yukicoder.me/problems/no/1065
  bundledCode: "#line 1 \"verify/graph/Dijkstra.2.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\
    \n#define ERROR 1e-4\n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n\
    #include <cctype>\n#include <chrono>\n#include <climits>\n#include <cmath>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include\
    \ <algorithm>\n#include <deque>\n#include <functional>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    \nusing namespace std;\nusing lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\
    \n\ntemplate<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n#line 4 \"library/graph/Dijkstra.hpp\"\n\ntemplate<class\
    \ T>\nvector<T> Dijkstra(const weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \tint n=G.size();\n\tvector<T> d(n,INF); d[s]=0;\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(0,s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& e:G[u]){\n\t\t\t\
    int v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\t\t\t\tQ.emplace(d[v],v);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n#line 6 \"verify/graph/Dijkstra.2.test.cpp\"\
    \n\nint main(){\n\tint n,m,s,t; scanf(\"%d%d%d%d\",&n,&m,&s,&t); s--; t--;\n\t\
    vector<double> x(n),y(n);\n\trep(i,n) scanf(\"%lf%lf\",&x[i],&y[i]);\n\n\tweighted_graph<double>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v); u--; v--;\n\t\tadd_undirected_edge(G,u,v,hypot(x[u]-x[v],y[u]-y[v]));\n\
    \t}\n\n\t// printf(\"%.9f\\n\",Dijkstra(G,s)[t]);\n\n\treturn 0;\n}\n\n\n// copy\
    \ of http://kmyk.github.io/competitive-programming-library/graph/dijkstra.yukicoder-1065.test.cpp\
    \ for debugging\n\n// #line 1 \"graph/dijkstra.yukicoder-1065.test.cpp\"\n// #define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1065\"\n// #define ERROR 1e-4\n//\
    \ #include <bits/stdc++.h>\n// #line 2 \"utils/macros.hpp\"\n// #define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n// #define REP3(i, m, n) for (int\
    \ i = (m); (i) < (int)(n); ++ (i))\n// #define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n// #define REP3R(i, m, n) for (int i = (int)(n) - 1;\
    \ (i) >= (int)(m); -- (i))\n// #define ALL(x) std::begin(x), std::end(x)\n// #line\
    \ 7 \"graph/dijkstra.hpp\"\n\n// /**\n//  * @brief Dijkstra ($O((E + V) \\log\
    \ V)$)\n//  */\n// template <class T = int64_t>\n// std::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T> > > const & g, int root) {\n//     std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    //     std::priority_queue<std::pair<T, int> > que;\n//     dist[root] = 0;\n\
    //     que.emplace(- dist[root], root);\n//     while (not que.empty()) {\n//\
    \         T dist_x; int x; std::tie(dist_x, x) = que.top(); que.pop();\n//   \
    \      if (dist[x] < - dist_x) continue;\n//         for (auto it : g[x]) {\n\
    //             int y; T cost; std::tie(y, cost) = it;\n//             if (- dist_x\
    \ + cost < dist[y]) {\n//                 dist[y] = - dist_x + cost;\n//     \
    \            que.emplace(dist_x - cost, y);\n//             }\n//         }\n\
    //     }\n//     return dist;\n// }\n// #line 6 \"graph/dijkstra.yukicoder-1065.test.cpp\"\
    \n// using namespace std;\n\n\n// int main() {\n//     // input\n//     int n,\
    \ m; scanf(\"%d%d\", &n, &m);\n//     int start, goal; scanf(\"%d%d\", &start,\
    \ &goal);\n//     -- start;\n//     -- goal;\n//     vector<long long> x(n), y(n);\n\
    //     REP (i, n) {\n//         scanf(\"%lld%lld\", &x[i], &y[i]);\n//     }\n\
    //     vector<vector<pair<int, double> > > g(n);\n//     REP (i, m) {\n//    \
    \     int p, q; cin >> p >> q;\n//         -- p;\n//         -- q;\n//       \
    \  double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2));\n//        \
    \ g[p].emplace_back(q, cost);\n//         g[q].emplace_back(p, cost);\n//    \
    \ }\n\n//     // solve\n//     auto dist = dijkstra(g, start);\n\n//     // output\n\
    //     printf(\"%.12lf\\n\", dist[goal]);\n//     return 0;\n// }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\n#define ERROR\
    \ 1e-4\n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Dijkstra.hpp\"\
    \n\nint main(){\n\tint n,m,s,t; scanf(\"%d%d%d%d\",&n,&m,&s,&t); s--; t--;\n\t\
    vector<double> x(n),y(n);\n\trep(i,n) scanf(\"%lf%lf\",&x[i],&y[i]);\n\n\tweighted_graph<double>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v); u--; v--;\n\t\tadd_undirected_edge(G,u,v,hypot(x[u]-x[v],y[u]-y[v]));\n\
    \t}\n\n\t// printf(\"%.9f\\n\",Dijkstra(G,s)[t]);\n\n\treturn 0;\n}\n\n\n// copy\
    \ of http://kmyk.github.io/competitive-programming-library/graph/dijkstra.yukicoder-1065.test.cpp\
    \ for debugging\n\n// #line 1 \"graph/dijkstra.yukicoder-1065.test.cpp\"\n// #define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1065\"\n// #define ERROR 1e-4\n//\
    \ #include <bits/stdc++.h>\n// #line 2 \"utils/macros.hpp\"\n// #define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n// #define REP3(i, m, n) for (int\
    \ i = (m); (i) < (int)(n); ++ (i))\n// #define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n// #define REP3R(i, m, n) for (int i = (int)(n) - 1;\
    \ (i) >= (int)(m); -- (i))\n// #define ALL(x) std::begin(x), std::end(x)\n// #line\
    \ 7 \"graph/dijkstra.hpp\"\n\n// /**\n//  * @brief Dijkstra ($O((E + V) \\log\
    \ V)$)\n//  */\n// template <class T = int64_t>\n// std::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T> > > const & g, int root) {\n//     std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    //     std::priority_queue<std::pair<T, int> > que;\n//     dist[root] = 0;\n\
    //     que.emplace(- dist[root], root);\n//     while (not que.empty()) {\n//\
    \         T dist_x; int x; std::tie(dist_x, x) = que.top(); que.pop();\n//   \
    \      if (dist[x] < - dist_x) continue;\n//         for (auto it : g[x]) {\n\
    //             int y; T cost; std::tie(y, cost) = it;\n//             if (- dist_x\
    \ + cost < dist[y]) {\n//                 dist[y] = - dist_x + cost;\n//     \
    \            que.emplace(dist_x - cost, y);\n//             }\n//         }\n\
    //     }\n//     return dist;\n// }\n// #line 6 \"graph/dijkstra.yukicoder-1065.test.cpp\"\
    \n// using namespace std;\n\n\n// int main() {\n//     // input\n//     int n,\
    \ m; scanf(\"%d%d\", &n, &m);\n//     int start, goal; scanf(\"%d%d\", &start,\
    \ &goal);\n//     -- start;\n//     -- goal;\n//     vector<long long> x(n), y(n);\n\
    //     REP (i, n) {\n//         scanf(\"%lld%lld\", &x[i], &y[i]);\n//     }\n\
    //     vector<vector<pair<int, double> > > g(n);\n//     REP (i, m) {\n//    \
    \     int p, q; cin >> p >> q;\n//         -- p;\n//         -- q;\n//       \
    \  double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2));\n//        \
    \ g[p].emplace_back(q, cost);\n//         g[q].emplace_back(p, cost);\n//    \
    \ }\n\n//     // solve\n//     auto dist = dijkstra(g, start);\n\n//     // output\n\
    //     printf(\"%.12lf\\n\", dist[goal]);\n//     return 0;\n// }\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Dijkstra.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 16:18:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/Dijkstra.2.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Dijkstra.2.test.cpp
- /verify/verify/graph/Dijkstra.2.test.cpp.html
title: Dijkstra ($O((E + V) \log V)$)
---
