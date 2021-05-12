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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/graph/Dijkstra.1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 4 \"library/graph/Dijkstra.hpp\"\n\ntemplate<class T>\nvector<T> Dijkstra(const\
    \ weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\n\
    \tint n=G.size();\n\tvector<T> d(n,INF); d[s]=T{};\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(T{},s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& [v,wt]:G[u]){\n\t\
    \t\tif(d[v]>d[u]+wt){\n\t\t\t\td[v]=d[u]+wt;\n\t\t\t\tQ.emplace(d[v],v);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn d;\n}\n#line 5 \"verify/graph/Dijkstra.1.test.cpp\"\n\
    \nint main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n\n\tfor(auto d:Dijkstra(G,s)){\n\t\tif(d<INT_MAX) printf(\"%d\\n\",d);\n\t\
    \telse          puts(\"INF\");\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Dijkstra.hpp\"\
    \n\nint main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n\n\tfor(auto d:Dijkstra(G,s)){\n\t\tif(d<INT_MAX) printf(\"%d\\n\",d);\n\t\
    \telse          puts(\"INF\");\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Dijkstra.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-12 18:21:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Dijkstra.1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Dijkstra.1.test.cpp
- /verify/verify/graph/Dijkstra.1.test.cpp.html
title: verify/graph/Dijkstra.1.test.cpp
---