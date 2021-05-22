---
title: Lowest Common Ancestor
documentation_of: ../../library/tree/lca.hpp
---

## Description
木の最小共通先祖をダブリングを用いて求める．
前処理 $O(V\log V)$，クエリ $O(\log V)$．
```
(A) lowest_common_ancestor<graph>
(B) lowest_common_ancestor<weighted_graph<W>>
```
- (A) 木 $T$ が重みなしのとき
- (B) 木 $T$ の辺に型 $W$ の重みがついているとき

### (constructor)
```
(A1)(B1) lowest_common_ancestor()
(A2) lowest_common_ancestor(const graph& T, int root)
(B2) lowest_common_ancestor(const weighted_graph<W>& T, int root)
```
- (A1)(B1) 空の木で初期化する
- (A2) ``root`` を根とする木 $T$ で初期化する
- (B2) ``root`` を根とする重みつき木 $T$ で初期化する

#### Constraints
- (B) 辺の重みの型 $W$ は整数型または実数型 (``int, long long, double, long doube`` など)

#### Complexity
- $O(V\log V)$

### build
```
(A) void build(const graph& G)
(B) void build(const weighted_graph<W>& G)
```
- (A) ``root`` を根とする木 $T$ で初期化する
- (B) ``root`` を根とする重みつき木 $T$ で初期化する

#### Constraints
- なし

#### Complexity
- $O(V\log V)$

### lca
```
int lca(int u, int v)
```
- 頂点 $u$ と $v$ の最小共通先祖を求める

#### Constraints
- $0\lt u,v\lt V$

#### Complexity
- $O(\log V)$

### distance
```
(A) int distance(int u, int v)
(B) W distance(int u, int v)
```
- 頂点 $u$ と $v$ の距離を求める

#### Constraints
- $0\lt u,v\lt V$

#### Complexity
- $O(\log V)$
