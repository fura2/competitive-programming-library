---
title: Topological Sort
documentation_of: ../../library/graph/topological_sort.hpp
---

## Description
DAG のトポロジカルソート
```
(1) vector<int> topological_sort(const graph& D)
(2) vector<int> topological_sort(const weighted_graph<T>& D)
```
- (1) DAG $D$ のトポロジカル順序の一つを求める
- (2) 重みつき DAG $D$ のトポロジカル順序の一つを求める

#### Constraints
- $D$ は DAG

#### Complexity
- $O(V+E)$
