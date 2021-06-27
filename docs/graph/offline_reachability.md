---
title: Offline Reachability for Directed Graphs
documentation_of: ../../library/graph/offline_reachability.hpp
---

## Description
有向グラフ $G$ に対して，頂点 $u$ から $v$ まで到達可能か，というオフラインクエリを処理する．
```
vector<bool> offline_reachability(const graph& G, vector<pair<int, int>> Q)
```
$Q$ の $i$ 番目の要素 $(u_i,v_i)$ は，$i$ 番目のクエリの入力が $(u,v)=(u_i,v_i)$ であることを表す．\\
戻り値の vector の $i$ 番目の要素には $i$ 番目のクエリの結果が格納される．

#### Constraints
- $G$ は有向グラフ

#### Complexity
- $O((V+E)Q/w)$ ($Q$ はクエリの個数, $w=64$ はワードサイズ)
