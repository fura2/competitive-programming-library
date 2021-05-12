---
title: Minimum Spanning Forest (Prim's Algorithm)
documentation_of: ../../library/graph/Prim.hpp
---

## Description
重みつき無向グラフの最小全域森を求める Prim のアルゴリズム
```
pair<T, weighted_graph<T>> Prim(const weighted_graph<T>& G)
```
重みつき無向グラフ $G$ の最小全域森 $F$ を求める．
$F$ の辺の重みの総和と $F$ 自身のペアを返す．

#### Constraints
- $G$ は重みつき無向グラフ
- $T$ は整数型 (``int``, ``long long`` など) で，``numeric_limits<T>::max()`` が定義されている．

#### Complexity
- $O(V+E\log E)$
