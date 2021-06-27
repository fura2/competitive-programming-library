---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/Dijkstra.1.test.cpp
    title: verify/graph/Dijkstra.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Dijkstra.2.test.cpp
    title: verify/graph/Dijkstra.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/offline_reachability.test.cpp
    title: verify/graph/offline_reachability.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\
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
    \t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"wgraph.hpp\"\n\ntemplate<class\
    \ T>\nvector<T> Dijkstra(const weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \n\tint n=G.size();\n\tvector<T> d(n,INF); d[s]=T{};\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(T{},s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& [v,wt]:G[u]){\n\t\
    \t\tif(d[v]>d[u]+wt){\n\t\t\t\td[v]=d[u]+wt;\n\t\t\t\tQ.emplace(d[v],v);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/offline_reachability.test.cpp
  - verify/graph/Dijkstra.2.test.cpp
  - verify/graph/Dijkstra.1.test.cpp
documentation_of: library/graph/Dijkstra.hpp
layout: document
title: Single-Source Shortest Path (Dijkstra's Algorithm)
---

## Description
重みつき有向グラフの単一始点最短路を求める Dijkstra のアルゴリズム．
辺の重みが非負であることを仮定する．
```
vector<T> Dijkstra(const weighted_graph<T>& G, int s)
```
重みつき有向グラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．\\
$s$ から $u$ に到達できない場合は $d(u)=$ ``numeric_limits<T>::max()`` となる．\\
適切な前処理によって計算量を $O(V+E\log V)$ に改善できるが，現行のもので実用上十分なので実装していない．

#### Constraints
- $G$ の辺の重みの型 $T$ は整数型 (``int``, ``long long`` など) で，``numeric_limits<T>::max()`` が定義されている．
- $G$ の辺の重みは非負
- $0\le s\lt V$

#### Complexity
- $O(V+E\log E)$
