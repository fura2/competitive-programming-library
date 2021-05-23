---
title: Lowest Common Ancestor
documentation_of: ../../library/tree/lca.hpp
---

## Description
ダブリングで木の最小共通先祖を求める．
前処理 $O(V\log V)$，クエリ $O(\log V)$．
```
(1) lowest_common_ancestor<graph>
(2) lowest_common_ancestor<weighted_graph<W>>
```
- (1) 木 $T$ が重みなしのとき
- (2) 木 $T$ の辺に型 $W$ の重みがついているとき

### (constructor)
```
(1a) lowest_common_ancestor<graph>()
(1b) lowest_common_ancestor(const graph& T, int root)
(2a) lowest_common_ancestor<weighted_graph<W>>()
(2b) lowest_common_ancestor(const weighted_graph<W>& T, int root)
```
- (1a) 空の木で初期化する
- (1b) $\mathrm{root}$ を根とする木 $T$ で初期化する
- (2a) 空の重みつき木で初期化する
- (2b) $\mathrm{root}$ を根とする重みつき木 $T$ で初期化する

#### Constraints
- (2) 辺の重みの型 $W$ は整数型または実数型 (``int, long long, double, long double`` など)

#### Complexity
- $O(V\log V)$

### build
```
(1) void build(const graph& G)
(2) void build(const weighted_graph<W>& G)
```
- (1) $\mathrm{root}$ を根とする木 $T$ で初期化する
- (2) $\mathrm{root}$ を根とする重みつき木 $T$ で初期化する

#### Constraints
- なし

#### Complexity
- $O(V\log V)$

### lca
```
int lca(int u, int v)
```
頂点 $u$ と $v$ の最小共通先祖を求める

#### Constraints
- $0\lt u,v\lt V$

#### Complexity
- $O(\log V)$

### distance
```
(1) int distance(int u, int v)
(2) W distance(int u, int v)
```
頂点 $u$ と $v$ の距離を求める

#### Constraints
- $0\lt u,v\lt V$

#### Complexity
- $O(\log V)$
