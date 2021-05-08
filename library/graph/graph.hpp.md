---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\nusing lint=long\
    \ long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
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
  requiredBy: []
  timestamp: '2021-05-09 02:26:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
グラフ $G$ の頂点 $u$ と $v$ の間に無向辺を張る．

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$

### add_directed_edge
```
void add_directed_edge(graph& G, int u, int v)
```
グラフ $G$ の頂点 $u$ から $v$ へ有向辺を張る．

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$
