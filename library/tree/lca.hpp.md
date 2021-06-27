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
    path: verify/tree/lca.1.test.cpp
    title: verify/tree/lca.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/lca.2.test.cpp
    title: verify/tree/lca.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/lca.3.test.cpp
    title: verify/tree/lca.3.test.cpp
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
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\
    \n\ntemplate<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n#line 5 \"library/tree/lca.hpp\"\n\ntemplate<class\
    \ T>\nclass lowest_common_ancestor{ lowest_common_ancestor(const T&,int)=delete;\
    \ };\n\ntemplate<>\nclass lowest_common_ancestor<graph>{\n\tvector<int> dep;\n\
    \tvector<vector<int>> par;\n\npublic:\n\tlowest_common_ancestor(){}\n\tlowest_common_ancestor(const\
    \ graph& T,int root){ build(T,root); }\n\n\tvoid build(const graph& T,int root){\n\
    \t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\t\t\
    par.assign(h,vector<int>(n,-1));\n\n\t\tauto dfs=[&](auto&& dfs,int u,int p)->void{\n\
    \t\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\t\t\t\tpar[0][v]=u;\n\
    \t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];\n\t}\n\n\tint lca(int\
    \ u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v]) swap(u,v);\n\t\
    \trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v) return u;\n\n\t\
    \tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];\n\
    \t\treturn par[0][u];\n\t}\n\n\tint distance(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)];\
    \ }\n};\n\ntemplate<class W>\nclass lowest_common_ancestor<weighted_graph<W>>{\n\
    \tvector<int> dep;\n\tvector<vector<int>> par;\n\tvector<vector<W>> dist;\n\n\
    public:\n\tlowest_common_ancestor(){}\n\tlowest_common_ancestor(const weighted_graph<W>&\
    \ T,int root){ build(T,root); }\n\n\tvoid build(const weighted_graph<W>& T,int\
    \ root){\n\t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\
    \t\tpar.assign(h,vector<int>(n,-1));\n\t\tdist.assign(h,vector<W>(n));\n\n\t\t\
    auto dfs=[&](auto&& dfs,int u,int p)->void{\n\t\t\tfor(const auto& [v,wt]:T[u])\
    \ if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\t\t\t\tpar[0][v]=u;\n\t\t\t\tdist[0][v]=wt;\n\
    \t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) {\n\t\t\tpar[i+1][u]=par[i][par[i][u]];\n\t\t\tdist[i+1][u]=dist[i][u]+dist[i][par[i][u]];\n\
    \t\t}\n\t}\n\n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tW distance(int u,int v)const{\n\
    \t\tint h=par.size();\n\t\tW res=0;\n\t\tint w=lca(u,v);\n\t\trep(i,h){\n\t\t\t\
    if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];\n\t\t\tif((dep[v]-dep[w])>>i&1)\
    \ res+=dist[i][v], v=par[i][v];\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../graph/graph.hpp\"\
    \n#include \"../graph/wgraph.hpp\"\n\ntemplate<class T>\nclass lowest_common_ancestor{\
    \ lowest_common_ancestor(const T&,int)=delete; };\n\ntemplate<>\nclass lowest_common_ancestor<graph>{\n\
    \tvector<int> dep;\n\tvector<vector<int>> par;\n\npublic:\n\tlowest_common_ancestor(){}\n\
    \tlowest_common_ancestor(const graph& T,int root){ build(T,root); }\n\n\tvoid\
    \ build(const graph& T,int root){\n\t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\
    \n\t\tdep.assign(n,0);\n\t\tpar.assign(h,vector<int>(n,-1));\n\n\t\tauto dfs=[&](auto&&\
    \ dfs,int u,int p)->void{\n\t\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\
    \t\t\t\tpar[0][v]=u;\n\t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\
    \t\trep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];\n\t}\n\
    \n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tint distance(int u,int v)const{\
    \ return dep[u]+dep[v]-2*dep[lca(u,v)]; }\n};\n\ntemplate<class W>\nclass lowest_common_ancestor<weighted_graph<W>>{\n\
    \tvector<int> dep;\n\tvector<vector<int>> par;\n\tvector<vector<W>> dist;\n\n\
    public:\n\tlowest_common_ancestor(){}\n\tlowest_common_ancestor(const weighted_graph<W>&\
    \ T,int root){ build(T,root); }\n\n\tvoid build(const weighted_graph<W>& T,int\
    \ root){\n\t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\
    \t\tpar.assign(h,vector<int>(n,-1));\n\t\tdist.assign(h,vector<W>(n));\n\n\t\t\
    auto dfs=[&](auto&& dfs,int u,int p)->void{\n\t\t\tfor(const auto& [v,wt]:T[u])\
    \ if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\t\t\t\tpar[0][v]=u;\n\t\t\t\tdist[0][v]=wt;\n\
    \t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) {\n\t\t\tpar[i+1][u]=par[i][par[i][u]];\n\t\t\tdist[i+1][u]=dist[i][u]+dist[i][par[i][u]];\n\
    \t\t}\n\t}\n\n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tW distance(int u,int v)const{\n\
    \t\tint h=par.size();\n\t\tW res=0;\n\t\tint w=lca(u,v);\n\t\trep(i,h){\n\t\t\t\
    if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];\n\t\t\tif((dep[v]-dep[w])>>i&1)\
    \ res+=dist[i][v], v=par[i][v];\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/tree/lca.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:23:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/lca.3.test.cpp
  - verify/tree/lca.1.test.cpp
  - verify/tree/lca.2.test.cpp
documentation_of: library/tree/lca.hpp
layout: document
title: Lowest Common Ancestor
---

## Description
ダブリングで木の最小共通先祖を求める．
前処理 $O(V\log V)$，クエリ $O(\log V)$．
```
(1) lowest_common_ancestor<graph>
(2) lowest_common_ancestor<weighted_graph<W>>
```
- (1) 木 $T$ が重みなしのとき
- (2) 木 $T$ の辺に型 $W$ の重みがついているとき

### (constructor)
```
(1a) lowest_common_ancestor<graph>()
(1b) lowest_common_ancestor(const graph& T, int root)
(2a) lowest_common_ancestor<weighted_graph<W>>()
(2b) lowest_common_ancestor(const weighted_graph<W>& T, int root)
```
- (1a) 空の木で初期化する
- (1b) $\mathrm{root}$ を根とする木 $T$ で初期化する
- (2a) 空の重みつき木で初期化する
- (2b) $\mathrm{root}$ を根とする重みつき木 $T$ で初期化する

#### Constraints
- (2) 辺の重みの型 $W$ は整数型または実数型 (``int, long long, double, long double`` など)

#### Complexity
- $O(V\log V)$

### build
```
(1) void build(const graph& G)
(2) void build(const weighted_graph<W>& G)
```
- (1) $\mathrm{root}$ を根とする木 $T$ で初期化する
- (2) $\mathrm{root}$ を根とする重みつき木 $T$ で初期化する

#### Constraints
- なし

#### Complexity
- $O(V\log V)$

### lca
```
int lca(int u, int v)
```
頂点 $u$ と $v$ の最小共通先祖を求める

#### Constraints
- $0\lt u,v\lt V$

#### Complexity
- $O(\log V)$

### distance
```
(1) int distance(int u, int v)
(2) W distance(int u, int v)
```
頂点 $u$ と $v$ の距離を求める

#### Constraints
- $0\lt u,v\lt V$

#### Complexity
- $O(\log V)$
