---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/cc.hpp
    title: Connected Components
  - icon: ':heavy_check_mark:'
    path: library/graph/distance.hpp
    title: Single-Source Shortest Path (Unweighted Graph)
  - icon: ':heavy_check_mark:'
    path: library/graph/is_DAG.hpp
    title: DAG Detection
  - icon: ':heavy_check_mark:'
    path: library/graph/scc.hpp
    title: Strongly Connected Components (Kosaraju's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/tecc.hpp
    title: Two-Edge Connected Components
  - icon: ':warning:'
    path: library/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: library/tree/tree_diameter.hpp
    title: Diameter of a Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/cc.test.cpp
    title: verify/graph/cc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/distance.test.cpp
    title: verify/graph/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/is_DAG.1.test.cpp
    title: verify/graph/is_DAG.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/is_DAG.2.test.cpp
    title: verify/graph/is_DAG.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/scc.1.test.cpp
    title: verify/graph/scc.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/scc.2.test.cpp
    title: verify/graph/scc.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tecc.1.test.cpp
    title: verify/graph/tecc.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tecc.2.test.cpp
    title: verify/graph/tecc.2.test.cpp
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
    using lint=long long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/graph/graph.hpp
  requiredBy:
  - library/tree/tree_diameter.hpp
  - library/graph/cc.hpp
  - library/graph/tecc.hpp
  - library/graph/distance.hpp
  - library/graph/is_DAG.hpp
  - library/graph/topological_sort.hpp
  - library/graph/scc.hpp
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/tree_diameter.1.test.cpp
  - verify/tree/tree_diameter.2.test.cpp
  - verify/graph/distance.test.cpp
  - verify/graph/scc.1.test.cpp
  - verify/graph/scc.2.test.cpp
  - verify/graph/cc.test.cpp
  - verify/graph/is_DAG.1.test.cpp
  - verify/graph/tecc.1.test.cpp
  - verify/graph/tecc.2.test.cpp
  - verify/graph/is_DAG.2.test.cpp
documentation_of: library/graph/graph.hpp
layout: document
title: Graph
---

## Description
重みなしの無向または有向グラフ．
隣接リストとして管理する．

### add_undirected_edge
```
void add_undirected_edge(graph& G, int u, int v)
```
グラフ $G$ の頂点 $u$ と $v$ の間に無向辺を張る

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$

### add_directed_edge
```
void add_directed_edge(graph& G, int u, int v)
```
グラフ $G$ の頂点 $u$ から $v$ へ有向辺を張る

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$
