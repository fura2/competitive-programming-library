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
    path: verify/graph/scc.1.test.cpp
    title: verify/graph/scc.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/scc.2.test.cpp
    title: verify/graph/scc.2.test.cpp
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
    G[u].emplace_back(v);\n}\n#line 4 \"library/graph/scc.hpp\"\n\nclass strongly_connected_components{\n\
    \tvector<int> id;\n\tvector<vector<int>> Comp;\n\tgraph D;\n\npublic:\n\tstrongly_connected_components(const\
    \ graph& G=graph()){ build(G); }\n\n\tvoid build(const graph& G){\n\t\tint n=G.size();\n\
    \t\tgraph G_rev(n);\n\t\trep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);\n\
    \n\t\tint k;\n\t\tvector<int> top(n);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u)->void{\n\
    \t\t\tid[u]=0;\n\t\t\tfor(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);\n\t\t\ttop[k++]=u;\n\
    \t\t};\n\t\tauto dfs2=[&](auto&& dfs2,int u)->void{\n\t\t\tid[u]=k;\n\t\t\tfor(int\
    \ v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);\n\t\t};\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\
    \t\trep(u,n) if(id[u]==-1) dfs1(dfs1,u);\n\n\t\treverse(top.begin(),top.end());\n\
    \n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\tfor(int u:top) if(id[u]==-1) dfs2(dfs2,u),\
    \ k++;\n\n\t\tComp.resize(k);\n\t\tD.resize(k);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\
    \t\t\tfor(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);\n\t\t\
    }\n\t}\n\n\tint operator[](int u)const{ return id[u]; }\n\n\tconst vector<int>&\
    \ component(int i)const{ return Comp[i]; }\n\tconst graph& DAG()const{ return\
    \ D; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"graph.hpp\"\n\nclass\
    \ strongly_connected_components{\n\tvector<int> id;\n\tvector<vector<int>> Comp;\n\
    \tgraph D;\n\npublic:\n\tstrongly_connected_components(const graph& G=graph()){\
    \ build(G); }\n\n\tvoid build(const graph& G){\n\t\tint n=G.size();\n\t\tgraph\
    \ G_rev(n);\n\t\trep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);\n\n\t\t\
    int k;\n\t\tvector<int> top(n);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u)->void{\n\
    \t\t\tid[u]=0;\n\t\t\tfor(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);\n\t\t\ttop[k++]=u;\n\
    \t\t};\n\t\tauto dfs2=[&](auto&& dfs2,int u)->void{\n\t\t\tid[u]=k;\n\t\t\tfor(int\
    \ v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);\n\t\t};\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\
    \t\trep(u,n) if(id[u]==-1) dfs1(dfs1,u);\n\n\t\treverse(top.begin(),top.end());\n\
    \n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\tfor(int u:top) if(id[u]==-1) dfs2(dfs2,u),\
    \ k++;\n\n\t\tComp.resize(k);\n\t\tD.resize(k);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\
    \t\t\tfor(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);\n\t\t\
    }\n\t}\n\n\tint operator[](int u)const{ return id[u]; }\n\n\tconst vector<int>&\
    \ component(int i)const{ return Comp[i]; }\n\tconst graph& DAG()const{ return\
    \ D; }\n};\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/graph/scc.hpp
  requiredBy: []
  timestamp: '2021-05-11 21:09:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/scc.1.test.cpp
  - verify/graph/scc.2.test.cpp
documentation_of: library/graph/scc.hpp
layout: document
title: Strongly Connected Components Decomposition (Kosaraju's Algorithm)
---

## Description
有向グラフを強連結成分分解する Kosaraju のアルゴリズム

### (constructor)
```
strongly_connected_components(const graph& G = graph())
```
- 有向グラフ $G$ を強連結成分分解する

#### Constraints
- なし

#### Complexity
- $O(V+E)$

### build
```
void build(const graph& G)
```
- 有向グラフ $G$ を強連結成分分解する

#### Constraints
- なし

#### Complexity
- $O(V+E)$

### operator[]
```
int operator[](int u)
```
$G$ の頂点 $u$ が属する強連結成分の番号を求める．\\
強連結成分の個数を $K$ として，強連結成分は DAG のトポロジカル順序にしたがって $0,1,\ldots,K-1$ と番号づけられている．

#### Constraints
- $0\le u\lt V$

#### Complexity
- $O(1)$

### component
```
const vector<int>& component(int i)
```
$G$ の強連結成分 $i$ を求める．
戻り値の ``vector`` に含まれる頂点は番号の昇順に並んでいる．

#### Constraints
- $0\le i\lt K$ ($K$ は強連結成分の個数)

#### Complexity
- $O(1)$

### DAG
```
const graph& DAG()
```
$G$ の強連結成分を縮約して得られる DAG を求める．
この DAG は多重辺を持つことがある．

#### Constraints
- なし

#### Complexity
- $O(1)$
