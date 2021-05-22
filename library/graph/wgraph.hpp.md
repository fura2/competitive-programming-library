---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/Bellman-Ford.hpp
    title: Single-Source Shortest Path (Bellman-Ford Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/Dijkstra.hpp
    title: Single-Source Shortest Path (Dijkstra's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/Kruskal.hpp
    title: Minimum Spanning Forest (Kruskal's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/Prim.hpp
    title: Minimum Spanning Forest (Prim's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/distance_01.hpp
    title: Single-Source Shortest Path ($01$-BFS)
  - icon: ':heavy_check_mark:'
    path: library/graph/is_DAG.hpp
    title: DAG Detection
  - icon: ':warning:'
    path: library/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: library/tree/rerooting.hpp
    title: Rerooting
  - icon: ':heavy_check_mark:'
    path: library/tree/tree_diameter.hpp
    title: Diameter of a Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/Bellman-Ford.test.cpp
    title: verify/graph/Bellman-Ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Dijkstra.1.test.cpp
    title: verify/graph/Dijkstra.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Dijkstra.2.test.cpp
    title: verify/graph/Dijkstra.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Kruskal.1.test.cpp
    title: verify/graph/Kruskal.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Kruskal.2.test.cpp
    title: verify/graph/Kruskal.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Prim.test.cpp
    title: verify/graph/Prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/distance_01.test.cpp
    title: verify/graph/distance_01.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/is_DAG.1.test.cpp
    title: verify/graph/is_DAG.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/is_DAG.2.test.cpp
    title: verify/graph/is_DAG.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/rerooting.1.test.cpp
    title: verify/tree/rerooting.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/rerooting.2.test.cpp
    title: verify/tree/rerooting.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/tree_diameter.1.test.cpp
    title: verify/tree/tree_diameter.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/tree_diameter.2.test.cpp
    title: verify/tree/tree_diameter.2.test.cpp
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
    using lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T> struct edge{\n\
    \tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n};\ntemplate<class\
    \ T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class T>\nvoid\
    \ add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    \tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\nvoid add_directed_edge(weighted_graph<T>&\
    \ G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n}\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/graph/wgraph.hpp
  requiredBy:
  - library/tree/rerooting.hpp
  - library/tree/tree_diameter.hpp
  - library/graph/distance_01.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/Prim.hpp
  - library/graph/Kruskal.hpp
  - library/graph/topological_sort.hpp
  - library/graph/Bellman-Ford.hpp
  - library/graph/is_DAG.hpp
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/rerooting.2.test.cpp
  - verify/tree/tree_diameter.1.test.cpp
  - verify/tree/tree_diameter.2.test.cpp
  - verify/tree/rerooting.1.test.cpp
  - verify/graph/Kruskal.1.test.cpp
  - verify/graph/is_DAG.1.test.cpp
  - verify/graph/Dijkstra.2.test.cpp
  - verify/graph/Prim.test.cpp
  - verify/graph/Kruskal.2.test.cpp
  - verify/graph/Dijkstra.1.test.cpp
  - verify/graph/is_DAG.2.test.cpp
  - verify/graph/distance_01.test.cpp
  - verify/graph/Bellman-Ford.test.cpp
documentation_of: library/graph/wgraph.hpp
layout: document
title: Weighted Graph
---

## Description
辺に重みがついた無向または有向グラフ．
隣接リストとして管理する．
重みの型を $T$ で表す．

### add_undirected_edge
```
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt)
```
グラフ $G$ の頂点 $u$ と $v$ の間に重み $\mathrm{wt}$ の無向辺を張る

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$

### add_directed_edge
```
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt)
```
グラフ $G$ の頂点 $u$ から $v$ へ重み $\mathrm{wt}$ の有向辺を張る

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$
