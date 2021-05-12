---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.1.test.cpp
    title: verify/graph/tree_diameter.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.2.test.cpp
    title: verify/graph/tree_diameter.2.test.cpp
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
    G[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 5 \"library/graph/tree_diameter.hpp\"\n\npair<int,vector<int>> tree_diameter(const\
    \ graph& T){\n\tint n=T.size();\n\tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&&\
    \ dfs,int u,int p)->pair<int,int>{\n\t\tint g=u,d_max=0;\n\t\tfor(int v:T[u])\
    \ if(v!=p) {\n\t\t\tauto [d,w]=dfs(dfs,v,u);\n\t\t\tif(d+1>d_max){\n\t\t\t\td_max=d+1;\n\
    \t\t\t\tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\t\
    int u0=dfs(dfs,0,-1).second;\n\tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int>\
    \ P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\t\tP.emplace_back(pre[u]);\n\t}\n\
    \treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n}\n\ntemplate<class W>\n\
    pair<W,vector<int>> tree_diameter(const weighted_graph<W>& T){\n\tint n=T.size();\n\
    \tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int u,int p)->pair<W,int>{\n\
    \t\tint g=u;\n\t\tW d_max=0;\n\t\tfor(const auto& [v,wt]:T[u]) if(v!=p) {\n\t\t\
    \tauto [d,w]=dfs(dfs,v,u);\n\t\t\tif(d+wt>d_max){\n\t\t\t\td_max=d+wt;\n\t\t\t\
    \tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\
    \tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\
    \t\tP.emplace_back(pre[u]);\n\t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"graph.hpp\"\n#include\
    \ \"wgraph.hpp\"\n\npair<int,vector<int>> tree_diameter(const graph& T){\n\tint\
    \ n=T.size();\n\tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int u,int\
    \ p)->pair<int,int>{\n\t\tint g=u,d_max=0;\n\t\tfor(int v:T[u]) if(v!=p) {\n\t\
    \t\tauto [d,w]=dfs(dfs,v,u);\n\t\t\tif(d+1>d_max){\n\t\t\t\td_max=d+1;\n\t\t\t\
    \tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\
    \tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\
    \t\tP.emplace_back(pre[u]);\n\t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n\
    }\n\ntemplate<class W>\npair<W,vector<int>> tree_diameter(const weighted_graph<W>&\
    \ T){\n\tint n=T.size();\n\tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int\
    \ u,int p)->pair<W,int>{\n\t\tint g=u;\n\t\tW d_max=0;\n\t\tfor(const auto& [v,wt]:T[u])\
    \ if(v!=p) {\n\t\t\tauto [d,w]=dfs(dfs,v,u);\n\t\t\tif(d+wt>d_max){\n\t\t\t\t\
    d_max=d+wt;\n\t\t\t\tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\t\t}\n\t\treturn {d_max,g};\n\
    \t};\n\tint u0=dfs(dfs,0,-1).second;\n\tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int>\
    \ P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\t\tP.emplace_back(pre[u]);\n\t}\n\
    \treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2021-05-12 17:41:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/tree_diameter.1.test.cpp
  - verify/graph/tree_diameter.2.test.cpp
documentation_of: library/graph/tree_diameter.hpp
layout: document
title: Diameter of a Tree
---

## Description
木の直径
```
(1) pair<int, vector<int>> tree_diameter(const graph& T)
(2) pair<W, vector<int>> tree_diameter(const weighted_graph<W>& T)
```
- (1) 木 $T$ の直径と，直径を達成するパスの一つを求める．
- (2) 重みつき木 $T$ の直径と，直径を達成するパスの一つを求める．

#### Constraints
- $T$ は木
- $V>0$
- (2) $T$ の辺の重みの型 $W$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)
- (2) $T$ の辺の重みは非負

#### Complexity
- $O(V)$
