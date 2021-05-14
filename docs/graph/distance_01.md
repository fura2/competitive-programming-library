---
title: Single-Source Shortest Path ($01$-BFS)
documentation_of: ../../library/graph/distance_01.hpp
---

## Description
辺の重みが $0$ または $1$ である有向グラフの単一始点最短路を求める
```
vector<int> distance_01(const weighted_graph<int>& G,　int s)
```
有向グラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．\\
$s$ から $u$ に到達できない場合は $d(u)=$ ``INT_MAX`` となる．

#### Constraints
- $G$ の辺の重みは $0$ または $1$
- $0\le s\lt V$

#### Complexity
- $O(V+E)$
