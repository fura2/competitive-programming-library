---
title: Connected Components
documentation_of: ../../library/graph/cc.hpp
---

## Description
無向グラフの連結成分分解
```
vector<vector<int>> connected_components(const graph& G)
```
無向グラフ $G$ を連結成分分解する．\\
戻り値を ``C`` とすると，``C`` の要素数は $G$ の連結成分の個数に等しく，各 ``C[i]`` が $G$ の連結成分となる．

#### Constraints
- $G$ は無向グラフ
- $0\le s\lt V$

#### Complexity
- $O(V+E)$
