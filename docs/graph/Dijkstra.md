---
title: Dijkstra's Algorithm
documentation_of: ../../library/graph/Dijkstra.hpp
---

## Description
重みつきグラフの単一始点最短路を求める Dijkstra のアルゴリズム
```
vector<T> Dijkstra(const weighted_graph<T>& G, int s)
```
重みつきグラフ $G$ において，頂点 $s$ から各頂点までの最短距離を求める．
$s$ から到達できない場合は ``numeric_limits<T>::max()`` が格納される．

#### Constraints
- $0\le s\lt n$
- $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など) であって，``numeric_limits<T>::max()`` が定義されている．
- $G$ の辺の重みは非負

#### Complexity
- $O((V+E)\log E)$
