---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/cc.test.cpp
    title: verify/graph/cc.test.cpp
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
    using namespace std;\nusing lint=long long;\n#line 3 \"library/graph/graph.hpp\"\
    \n\nusing graph=vector<vector<int>>;\n\nvoid add_undirected_edge(graph& G,int\
    \ u,int v){\n\tG[u].emplace_back(v);\n\tG[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph&\
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n#line 4 \"library/graph/cc.hpp\"\
    \n\nvector<vector<int>> connected_components(const graph& G){\n\tint n=G.size();\n\
    \tvector<vector<int>> res;\n\tvector<bool> vis(n);\n\trep(u,n) if(!vis[u]) {\n\
    \t\tvis[u]=true;\n\t\tres.emplace_back();\n\t\tqueue<int> Q; Q.emplace(u);\n\t\
    \twhile(!Q.empty()){\n\t\t\tint v=Q.front(); Q.pop();\n\t\t\tres.back().emplace_back(v);\n\
    \t\t\tfor(int w:G[v]) if(!vis[w]) {\n\t\t\t\tvis[w]=true;\n\t\t\t\tQ.emplace(w);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"graph.hpp\"\n\nvector<vector<int>>\
    \ connected_components(const graph& G){\n\tint n=G.size();\n\tvector<vector<int>>\
    \ res;\n\tvector<bool> vis(n);\n\trep(u,n) if(!vis[u]) {\n\t\tvis[u]=true;\n\t\
    \tres.emplace_back();\n\t\tqueue<int> Q; Q.emplace(u);\n\t\twhile(!Q.empty()){\n\
    \t\t\tint v=Q.front(); Q.pop();\n\t\t\tres.back().emplace_back(v);\n\t\t\tfor(int\
    \ w:G[v]) if(!vis[w]) {\n\t\t\t\tvis[w]=true;\n\t\t\t\tQ.emplace(w);\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/graph/cc.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/cc.test.cpp
documentation_of: library/graph/cc.hpp
layout: document
title: Connected Components
---

## Description
無向グラフを連結成分分解する
```
vector<vector<int>> connected_components(const graph& G)
```
無向グラフ $G$ を連結成分分解する．\\
戻り値を ``C`` とすると，``C`` の要素数は $G$ の連結成分の個数に等しく，各 ``C[i]`` が $G$ の連結成分となる．

#### Constraints
- $G$ は無向グラフ
- $0\le s\lt V$

#### Complexity
- $O(V+E)$
