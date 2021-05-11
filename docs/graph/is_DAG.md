---
title: DAG Detection
documentation_of: ../../library/graph/is_DAG.hpp
---

## Description
有向グラフが DAG かどうかの判定
```
(1) bool is_DAG(const graph& G)
(2) bool is_DAG(const weighted_graph<T>& G)
```
- (1) 有向グラフ $G$ が DAG かどうかを判定する
- (2) 重みつき有向グラフ $G$ が DAG かどうかを判定する

#### Constraints
- なし

#### Complexity
- $O(V+E)$
