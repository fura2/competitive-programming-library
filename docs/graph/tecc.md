---
title: Two-Edge Connected Components
documentation_of: ../../library/graph/tecc.hpp
---

## Description
無向グラフの二辺連結成分分解

### (constructor)
```
two_edge_connected_components(const graph& G = {})
```
無向グラフ $G$ を二辺連結成分分解する

#### Constraints
- $G$ は無向グラフ

#### Complexity
- $O(V+E)$

### build
```
void build(const graph& G)
```
無向グラフ $G$ を二辺連結成分分解する

#### Constraints
- $G$ は無向グラフ

#### Complexity
- $O(V+E)$

### operator[]
```
int operator[](int u)
```
$G$ の頂点 $u$ が属する二辺連結成分の番号を求める．\\
二辺連結成分の個数を $K$ として，二辺連結成分は $0,1,\ldots,K-1$ と番号づけられている．

#### Constraints
- $0\le u\lt V$

#### Complexity
- $O(1)$

### component
```
const vector<int>& component(int i)
```
$G$ の二辺連結成分 $i$ を求める．
戻り値の ``vector`` に含まれる頂点は番号の昇順に並んでいる．

#### Constraints
- $0\le i\lt K$ ($K$ は二辺連結成分の個数)

#### Complexity
- $O(1)$

### bridges
```
const vector<pair<int, int>>& bridges()
```
$G$ の橋の集合を求める

#### Constraints
- なし

#### Complexity
- $O(1)$

### bridge_block_forest
```
const graph& bridge_block_forest()
```
$G$ の二辺連結成分を縮約して得られる森を求める

#### Constraints
- なし

#### Complexity
- $O(1)$

## References
- [[Tutorial] The DFS tree and its applications: how I found out I really didn't understand bridges - -is-this-fft-'s blog](https://codeforces.com/blog/entry/68138)
