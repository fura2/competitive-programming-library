---
title: Single-Source Shortest Path (Dijkstra's Algorithm)
documentation_of: ../../library/graph/Dijkstra.hpp
---

## Description
重みつき有向グラフの単一始点最短路を求める Dijkstra のアルゴリズム．
辺の重みが非負であることを仮定する．
```
vector<T> Dijkstra(const weighted_graph<T>& G, int s)
```
重みつき有向グラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．\\
$s$ から $u$ に到達できない場合は $d(u)=$ ``numeric_limits<T>::max()`` となる．\\
適切な前処理によって計算量を $O(V+E\log V)$ に改善できるが，現行のもので実用上十分なので実装していない．

#### Constraints
- $G$ の辺の重みの型 $T$ は整数型 (``int``, ``long long`` など) で，``numeric_limits<T>::max()`` が定義されている．
- $G$ の辺の重みは非負
- $0\le s\lt V$

#### Complexity
- $O(V+E\log E)$
