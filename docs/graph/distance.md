---
title: Single-Source Shortest Path (Unweighted Graph)
documentation_of: ../../library/graph/distance.hpp
---

## Description
BFS で有向グラフの単一始点最短路を求める
```
vector<int> distance(const graph& G,　int s)
```
有向グラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．\\
$s$ から $u$ に到達できない場合は $d(u)=$ ``INT_MAX`` となる．

#### Constraints
- $0\le s\lt V$

#### Complexity
- $O(V+E)$
