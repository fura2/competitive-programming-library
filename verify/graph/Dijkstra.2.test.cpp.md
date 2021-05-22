---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Dijkstra.hpp
    title: Single-Source Shortest Path (Dijkstra's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1065
    links:
    - https://yukicoder.me/problems/no/1065
  bundledCode: "#line 1 \"verify/graph/Dijkstra.2.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\
    \n#define ERROR 1e-4\n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n\
    #include <cctype>\n#include <chrono>\n#include <climits>\n#include <cmath>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include\
    \ <algorithm>\n#include <deque>\n#include <functional>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n\nusing namespace std;\nusing lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\
    \n\ntemplate<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n#line 4 \"library/graph/Dijkstra.hpp\"\n\ntemplate<class\
    \ T>\nvector<T> Dijkstra(const weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \n\tint n=G.size();\n\tvector<T> d(n,INF); d[s]=T{};\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(T{},s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& [v,wt]:G[u]){\n\t\
    \t\tif(d[v]>d[u]+wt){\n\t\t\t\td[v]=d[u]+wt;\n\t\t\t\tQ.emplace(d[v],v);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn d;\n}\n#line 6 \"verify/graph/Dijkstra.2.test.cpp\"\n\
    \n// T \u304C double \u578B\u306E\u30B1\u30FC\u30B9\n// \u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306E\u8981\u4EF6\u3092\u6E80\u305F\u3057\u3066\u3044\u306A\u3044\u304C\
    \u5B9F\u7528\u4E0A\u554F\u984C\u306A\u304F\u52D5\u304F\n\nint main(){\n\tint n,m,s,t;\
    \ scanf(\"%d%d%d%d\",&n,&m,&s,&t); s--; t--;\n\tvector<double> x(n),y(n);\n\t\
    rep(i,n) scanf(\"%lf%lf\",&x[i],&y[i]);\n\n\tweighted_graph<double> G(n);\n\t\
    rep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v); u--; v--;\n\t\tadd_undirected_edge(G,u,v,hypot(x[u]-x[v],y[u]-y[v]));\n\
    \t}\n\n\tprintf(\"%.9f\\n\",Dijkstra(G,s)[t]);\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\n#define ERROR\
    \ 1e-4\n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Dijkstra.hpp\"\
    \n\n// T \u304C double \u578B\u306E\u30B1\u30FC\u30B9\n// \u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306E\u8981\u4EF6\u3092\u6E80\u305F\u3057\u3066\u3044\u306A\u3044\u304C\
    \u5B9F\u7528\u4E0A\u554F\u984C\u306A\u304F\u52D5\u304F\n\nint main(){\n\tint n,m,s,t;\
    \ scanf(\"%d%d%d%d\",&n,&m,&s,&t); s--; t--;\n\tvector<double> x(n),y(n);\n\t\
    rep(i,n) scanf(\"%lf%lf\",&x[i],&y[i]);\n\n\tweighted_graph<double> G(n);\n\t\
    rep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v); u--; v--;\n\t\tadd_undirected_edge(G,u,v,hypot(x[u]-x[v],y[u]-y[v]));\n\
    \t}\n\n\tprintf(\"%.9f\\n\",Dijkstra(G,s)[t]);\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Dijkstra.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Dijkstra.2.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Dijkstra.2.test.cpp
- /verify/verify/graph/Dijkstra.2.test.cpp.html
title: verify/graph/Dijkstra.2.test.cpp
---
