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
    path: verify/graph/tecc.1.test.cpp
    title: verify/graph/tecc.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tecc.2.test.cpp
    title: verify/graph/tecc.2.test.cpp
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
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n#line 4 \"library/graph/tecc.hpp\"\
    \n\nclass two_edge_connected_components{\n\tvector<int> id;\n\tvector<vector<int>>\
    \ Comp;\n\tvector<pair<int,int>> B;\n\tgraph BBF;\n\npublic:\n\ttwo_edge_connected_components(const\
    \ graph& G={}){ build(G); }\n\n\tvoid build(const graph& G){\n\t\tint n=G.size(),idx;\n\
    \t\tvector<int> ord(n,-1),low(n,-1);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u,int\
    \ p)->void{\n\t\t\tord[u]=low[u]=idx++;\n\t\t\tbool f=true;\n\t\t\tfor(int v:G[u]){\n\
    \t\t\t\tif(v==p && f){ f=false; continue; }\n\t\t\t\tif(ord[v]==-1){\n\t\t\t\t\
    \tdfs1(dfs1,v,u);\n\t\t\t\t\tlow[u]=min(low[u],low[v]);\n\t\t\t\t}\n\t\t\t\telse{\n\
    \t\t\t\t\tlow[u]=min(low[u],ord[v]);\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\n\t\tauto dfs2=[&](auto&&\
    \ dfs2,int u,int p)->void{\n\t\t\tif(p==-1 || ord[p]<low[u]){\n\t\t\t\tid[u]=idx++;\n\
    \t\t\t\tif(p!=-1) B.emplace_back(minmax(p,u));\n\t\t\t}\n\t\t\telse{\n\t\t\t\t\
    id[u]=id[p];\n\t\t\t}\n\t\t\tfor(int v:G[u]) if(id[v]==-1) dfs2(dfs2,v,u);\n\t\
    \t};\n\n\t\tidx=0;\n\t\trep(u,n) if(ord[u]==-1) dfs1(dfs1,u,-1);\n\n\t\tidx=0;\n\
    \t\tid.assign(n,-1);\n\t\trep(u,n) if(id[u]==-1) dfs2(dfs2,u,-1);\n\n\t\tComp.resize(idx);\n\
    \t\tBBF.resize(idx);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\t\t\t\
    for(int v:G[u]) if(id[u]!=id[v]) BBF[id[u]].emplace_back(id[v]);\n\t\t}\n\t}\n\
    \n\tint operator[](int i)const{ return id[i]; }\n\n\tconst vector<int>& component(int\
    \ i)const{ return Comp[i]; }\n\tconst vector<pair<int,int>>& bridges()const{ return\
    \ B; }\n\tconst graph& bridge_block_forest()const{ return BBF; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"graph.hpp\"\n\nclass\
    \ two_edge_connected_components{\n\tvector<int> id;\n\tvector<vector<int>> Comp;\n\
    \tvector<pair<int,int>> B;\n\tgraph BBF;\n\npublic:\n\ttwo_edge_connected_components(const\
    \ graph& G={}){ build(G); }\n\n\tvoid build(const graph& G){\n\t\tint n=G.size(),idx;\n\
    \t\tvector<int> ord(n,-1),low(n,-1);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u,int\
    \ p)->void{\n\t\t\tord[u]=low[u]=idx++;\n\t\t\tbool f=true;\n\t\t\tfor(int v:G[u]){\n\
    \t\t\t\tif(v==p && f){ f=false; continue; }\n\t\t\t\tif(ord[v]==-1){\n\t\t\t\t\
    \tdfs1(dfs1,v,u);\n\t\t\t\t\tlow[u]=min(low[u],low[v]);\n\t\t\t\t}\n\t\t\t\telse{\n\
    \t\t\t\t\tlow[u]=min(low[u],ord[v]);\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\n\t\tauto dfs2=[&](auto&&\
    \ dfs2,int u,int p)->void{\n\t\t\tif(p==-1 || ord[p]<low[u]){\n\t\t\t\tid[u]=idx++;\n\
    \t\t\t\tif(p!=-1) B.emplace_back(minmax(p,u));\n\t\t\t}\n\t\t\telse{\n\t\t\t\t\
    id[u]=id[p];\n\t\t\t}\n\t\t\tfor(int v:G[u]) if(id[v]==-1) dfs2(dfs2,v,u);\n\t\
    \t};\n\n\t\tidx=0;\n\t\trep(u,n) if(ord[u]==-1) dfs1(dfs1,u,-1);\n\n\t\tidx=0;\n\
    \t\tid.assign(n,-1);\n\t\trep(u,n) if(id[u]==-1) dfs2(dfs2,u,-1);\n\n\t\tComp.resize(idx);\n\
    \t\tBBF.resize(idx);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\t\t\t\
    for(int v:G[u]) if(id[u]!=id[v]) BBF[id[u]].emplace_back(id[v]);\n\t\t}\n\t}\n\
    \n\tint operator[](int i)const{ return id[i]; }\n\n\tconst vector<int>& component(int\
    \ i)const{ return Comp[i]; }\n\tconst vector<pair<int,int>>& bridges()const{ return\
    \ B; }\n\tconst graph& bridge_block_forest()const{ return BBF; }\n};\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/graph/tecc.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/tecc.1.test.cpp
  - verify/graph/tecc.2.test.cpp
documentation_of: library/graph/tecc.hpp
layout: document
title: Two-Edge Connected Components
---

## Description
無向グラフを二辺連結成分分解する

### (constructor)
```
two_edge_connected_components(const graph& G = {})
```
- 無向グラフ $G$ を二辺連結成分分解する

#### Constraints
- $G$ は無向グラフ

#### Complexity
- $O(V+E)$

### build
```
void build(const graph& G)
```
- 無向グラフ $G$ を二辺連結成分分解する

#### Constraints
- $G$ は無向グラフ

#### Complexity
- $O(V+E)$

### operator[]
```
int operator[](int u)
```
$G$ の頂点 $u$ が属する二辺連結成分の番号を求める．\\
二辺連結成分の個数を $K$ として，二辺連結成分は $0,1,\ldots,K-1$ と番号づけられている．

#### Constraints
- $0\le u\lt V$

#### Complexity
- $O(1)$

### component
```
const vector<int>& component(int i)
```
$G$ の二辺連結成分 $i$ を求める．
戻り値の ``vector`` に含まれる頂点は番号の昇順に並んでいる．

#### Constraints
- $0\le i\lt K$ ($K$ は二辺連結成分の個数)

#### Complexity
- $O(1)$

### bridges
```
const vector<pair<int, int>>& bridges()
```
$G$ の橋の集合を求める

#### Constraints
- なし

#### Complexity
- $O(1)$

### bridge_block_forest
```
const graph& bridge_block_forest()
```
$G$ の二辺連結成分を縮約して得られる森を求める

#### Constraints
- なし

#### Complexity
- $O(1)$

## References
- [[Tutorial] The DFS tree and its applications: how I found out I really didn't understand bridges - -is-this-fft-'s blog](https://codeforces.com/blog/entry/68138)
