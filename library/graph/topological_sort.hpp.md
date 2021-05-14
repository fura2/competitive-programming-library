---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
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
    G[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 5 \"library/graph/topological_sort.hpp\"\n\nvector<int> topological_sort(const\
    \ graph& D){\n\tint n=D.size();\n\tvector<int> deg(n);\n\trep(u,n) for(int v:D[u])\
    \ deg[v]++;\n\n\tvector<int> res;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\
    \t\tfor(int v:D[u]) if(--deg[v]==0) Q.emplace(v);\n\t}\n\treturn res;\n}\n\ntemplate<class\
    \ T>\nvector<int> topological_sort(const weighted_graph<T>& D){\n\tint n=D.size();\n\
    \tvector<int> deg(n);\n\trep(u,n) for(const auto& [v,wt]:D[u]) deg[v]++;\n\n\t\
    vector<int> res;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\t\
    while(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\t\
    \tfor(const auto& [v,wt]:D[u]) if(--deg[v]==0) Q.emplace(v);\n\t}\n\treturn res;\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"graph.hpp\"\n#include\
    \ \"wgraph.hpp\"\n\nvector<int> topological_sort(const graph& D){\n\tint n=D.size();\n\
    \tvector<int> deg(n);\n\trep(u,n) for(int v:D[u]) deg[v]++;\n\n\tvector<int> res;\n\
    \tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\t\tfor(int v:D[u]) if(--deg[v]==0)\
    \ Q.emplace(v);\n\t}\n\treturn res;\n}\n\ntemplate<class T>\nvector<int> topological_sort(const\
    \ weighted_graph<T>& D){\n\tint n=D.size();\n\tvector<int> deg(n);\n\trep(u,n)\
    \ for(const auto& [v,wt]:D[u]) deg[v]++;\n\n\tvector<int> res;\n\tqueue<int> Q;\n\
    \trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front();\
    \ Q.pop();\n\t\tres.emplace_back(u);\n\t\tfor(const auto& [v,wt]:D[u]) if(--deg[v]==0)\
    \ Q.emplace(v);\n\t}\n\treturn res;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-05-12 17:41:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/topological_sort.hpp
layout: document
title: Topological Sort
---

## Description
DAG のトポロジカルソート
```
(1) vector<int> topological_sort(const graph& D)
(2) vector<int> topological_sort(const weighted_graph<T>& D)
```
- (1) DAG $D$ のトポロジカル順序の一つを求める
- (2) 重みつき DAG $D$ のトポロジカル順序の一つを求める

#### Constraints
- $D$ は DAG

#### Complexity
- $O(V+E)$
