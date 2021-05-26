---
title: Weighted Graph
documentation_of: ../../library/graph/wgraph.hpp
---

## Description
辺に重みがついた無向または有向グラフ．
隣接リストとして管理する．
重みの型を $T$ で表す．
```
edge<T>
weighted_graph<T>
```

### add_undirected_edge
```
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt)
```
グラフ $G$ の頂点 $u$ と $v$ の間に重み $\mathrm{wt}$ の無向辺を張る

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$

### add_directed_edge
```
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt)
```
グラフ $G$ の頂点 $u$ から $v$ へ重み $\mathrm{wt}$ の有向辺を張る

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- $O(1)$
