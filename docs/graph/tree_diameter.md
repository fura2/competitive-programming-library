---
title: Diameter of a Tree
documentation_of: ../../library/graph/tree_diameter.hpp
---

## Description
木の直径
```
(1) pair<int, vector<int>> tree_diameter(const graph& T)
(2) pair<W, vector<int>> tree_diameter(const weighted_graph<W>& T)
```
- (1) 木 $T$ の直径と，直径を達成するパスの一つを求める．
- (2) 重みつき木 $T$ の直径と，直径を達成するパスの一つを求める．

#### Constraints
- $T$ は木
- $V>0$
- (2) $T$ の辺の重みの型 $W$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)
- (2) $T$ の辺の重みは非負

#### Complexity
- $O(V)$
