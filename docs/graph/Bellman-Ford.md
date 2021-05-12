---
title: Single-Source Shortest Path (Bellman-Ford Algorithm)
documentation_of: ../../library/graph/Bellman-Ford.hpp
---

## Description
重みつきグラフの単一始点最短路を求める Bellman-Ford のアルゴリズム．
辺の重みは負でもよい．
```
vector<T> Bellman_Ford(const weighted_graph<T>& G, int s)
```
重みつきグラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．\\
$s$ から $u$ に到達できない場合は $d(u)=$ ``numeric_limits<T>::max()`` となる．\\
また，$s$ から $u$ にいくらでも小さいコストで到達できる場合は $d(u)=$ ``numeric_limits<T>::min()`` となる．\\
このようなケースは，$G$ において $s$ から到達できる負閉路が存在する場合に起こりうる．

#### Constraints
- $G$ の辺の重みの型 $T$ は整数型 (``int``, ``long long`` など) で，``numeric_limits<T>::max()`` および ``numeric_limits<T>::min()`` が定義されている．
- $0\le s\lt V$

#### Complexity
- $O(V(V+E))$
