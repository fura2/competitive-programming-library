---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/distance.test.cpp
    title: verify/graph/distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n#line 4 \"library/graph/distance.hpp\"\n\nvector<int>\
    \ distance(const graph& G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\
    \tvector<int> d(n,INF);\n\td[s]=0;\n\tqueue<int> Q; Q.emplace(s);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tfor(int v:G[u]) if(d[v]==INF) {\n\t\t\td[v]=d[u]+1;\n\
    \t\t\tQ.emplace(v);\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"graph.hpp\"\n\nvector<int>\
    \ distance(const graph& G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\
    \tvector<int> d(n,INF);\n\td[s]=0;\n\tqueue<int> Q; Q.emplace(s);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tfor(int v:G[u]) if(d[v]==INF) {\n\t\t\td[v]=d[u]+1;\n\
    \t\t\tQ.emplace(v);\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/graph/distance.hpp
  requiredBy: []
  timestamp: '2021-05-12 10:49:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/distance.test.cpp
documentation_of: library/graph/distance.hpp
layout: document
title: Single-Source Shortest Path (Unweighted Graph)
---

## Description
BFS でグラフの単一始点最短路を求める
```
vector<int> distance(const graph& G,　int s)
```
グラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．\\
$s$ から $u$ に到達できない場合は $d(u)=$ ``INT_MAX`` となる．

#### Constraints
- $0\le s\lt V$

#### Complexity
- $O(V+E)$
