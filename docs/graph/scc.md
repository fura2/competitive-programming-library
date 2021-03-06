---
title: Strongly Connected Components (Kosaraju's Algorithm)
documentation_of: ../../library/graph/scc.hpp
---

## Description
有向グラフを強連結成分分解する Kosaraju のアルゴリズム
```
(1) strongly_connected_components<graph>
(2) strongly_connected_components<weighted_graph<W>>
```
- (1) 有向グラフ $G$ が重みなしのとき
- (2) 有向グラフ $G$ の辺に型 $W$ の重みがついているとき

### (constructor)
```
(1) strongly_connected_components(const graph& G = {})
(2) strongly_connected_components(const weighted_graph<W>& G = {})
```
- (1) 有向グラフ $G$ を強連結成分分解する
- (2) 重みつき有向グラフ $G$ を強連結成分分解する

#### Constraints
- なし

#### Complexity
- $O(V+E)$

### build
```
(1) void build(const graph& G)
(2) void build(const weighted_graph<W>& G)
```
- (1) 有向グラフ $G$ を強連結成分分解する
- (2) 重みつき有向グラフ $G$ を強連結成分分解する

#### Constraints
- なし

#### Complexity
- $O(V+E)$

### operator[]
```
int operator[](int u)
```
$G$ の頂点 $u$ が属する強連結成分の番号を求める．\\
強連結成分の個数を $K$ として，強連結成分は DAG のトポロジカル順序にしたがって $0,1,\ldots,K-1$ と番号づけられている．

#### Constraints
- $0\le u\lt V$

#### Complexity
- $O(1)$

### component
```
const vector<int>& component(int i)
```
$G$ の強連結成分 $i$ を求める．
戻り値の ``vector`` に含まれる頂点は番号の昇順に並んでいる．

#### Constraints
- $0\le i\lt K$ ($K$ は強連結成分の個数)

#### Complexity
- $O(1)$

### DAG
```
(1) const graph& DAG()
(2) const weighted_graph<W>& DAG()
```
$G$ の強連結成分を縮約して得られる DAG を求める．
この DAG は多重辺を持つことがある．

#### Constraints
- なし

#### Complexity
- $O(1)$
