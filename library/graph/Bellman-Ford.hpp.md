---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/Bellman-Ford.test.cpp
    title: verify/graph/Bellman-Ford.test.cpp
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
    }\n#line 4 \"library/graph/Bellman-Ford.hpp\"\n\ntemplate<class T>\nvector<T>\
    \ Bellman_Ford(const weighted_graph<T>& G,int s){\n\tconst T INF=numeric_limits<T>::max();\n\
    \tconst T NINF=numeric_limits<T>::min();\n\n\tint n=G.size();\n\tvector<T> d(n,INF);\n\
    \td[s]=0;\n\trep(_,n){\n\t\tbool upd=false;\n\t\trep(u,n) if(d[u]<INF) for(const\
    \ auto& e:G[u]) {\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt,\
    \ upd=true;\n\t\t}\n\t\tif(!upd) return d;\n\t}\n\n\tqueue<int> Q;\n\trep(u,n)\
    \ if(d[u]<INF) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\
    \t\tfor(const auto& e:G[u]){\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>NINF && (d[u]==NINF\
    \ || d[v]>d[u]+e.wt)) d[v]=NINF, Q.emplace(v);\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"wgraph.hpp\"\n\ntemplate<class\
    \ T>\nvector<T> Bellman_Ford(const weighted_graph<T>& G,int s){\n\tconst T INF=numeric_limits<T>::max();\n\
    \tconst T NINF=numeric_limits<T>::min();\n\n\tint n=G.size();\n\tvector<T> d(n,INF);\n\
    \td[s]=0;\n\trep(_,n){\n\t\tbool upd=false;\n\t\trep(u,n) if(d[u]<INF) for(const\
    \ auto& e:G[u]) {\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt,\
    \ upd=true;\n\t\t}\n\t\tif(!upd) return d;\n\t}\n\n\tqueue<int> Q;\n\trep(u,n)\
    \ if(d[u]<INF) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\
    \t\tfor(const auto& e:G[u]){\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>NINF && (d[u]==NINF\
    \ || d[v]>d[u]+e.wt)) d[v]=NINF, Q.emplace(v);\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/graph/Bellman-Ford.hpp
  requiredBy: []
  timestamp: '2021-05-10 17:31:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/Bellman-Ford.test.cpp
documentation_of: library/graph/Bellman-Ford.hpp
layout: document
title: Bellman-Ford Algorithm
---

## Description
重みつきグラフの単一始点最短路を求める Bellman-Ford のアルゴリズム．
辺の重みは負でもよい．
```
vector<T> Bellman_Ford(const weighted_graph<T>& G, int s)
```
重みつきグラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．  
$s$ から $u$ に到達できない場合は $d(u)=$ ``numeric_limits<T>::max()`` となる．  
また，$s$ から $u$ にいくらでも小さいコストで到達できる場合は $d(u)=$ ``numeric_limits<T>::min()`` となる．  
このようなケースは，$G$ において $s$ から到達できる負閉路が存在する場合に起こりうる．

#### Constraints
- $0\le s\lt n$
- $G$ の辺の重みの型 $T$ は整数型 (``int``, ``long long`` など) で，``numeric_limits<T>::max()`` および ``numeric_limits<T>::min()`` が定義されている．

#### Complexity
- $O(V(V+E))$
