---
title: Minimum Spanning Forest (Kruskal's Algorithm)
documentation_of: ../../library/graph/Kruskal.hpp
---

## Description
重みつき無向グラフの最小全域森を求める Dijkstra のアルゴリズム
```
(1) T Kruskal(int n, vector<tuple<int,int,T>> E)
(2) pair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G)
```
重みつき無向グラフ $G$ の最小全域森 $F$ を求める．
- (1) $G$ の頂点数と辺集合を入力とし，$F$ の辺の重みの総和を返す．
- (2) $G$ 自身を入力とし，$F$ の辺の重みの総和と $F$ 自身のペアを返す．

#### Constraints
- $G$ は重みつき無向グラフ
- $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)
- (1) $n\ge0$

#### Complexity
- $O(V+E(\alpha(V)+\log E))$
