---
title: Graph
documentation_of: ../../library/graph/graph.hpp
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
