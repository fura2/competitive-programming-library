---
title: Dual Fenwick Tree
documentation_of: ../../library/data_structure/Fenwick_tree_dual.hpp
---

## Description
Abel 群 $G$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，区間加算と一点取得を $O(\log n)$ で処理するデータ構造．\\
以下では，$G$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．
```
Fenwick_tree_dual<G>
```

### (constructor)
```
(1) Fenwick_tree_dual<G>(int n = 0)
(2) Fenwick_tree_dual<G>(const vector<G>& a)
```
- (1) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $(G,+)$ は Abel 群 ($+$ は結合的で，デフォルトコンストラクタが $G$ の単位元を生成し，$-$ は $+$ の逆演算)
- (1) $n\ge0$

#### Complexity
- $O(n)$

### build
```
(1) void build(int n)
(2) void build(const vector<G>& a)
```
- (1) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- (1) $n\ge0$

#### Complexity
- $O(n)$

### add
```
void add(int l, int r, const G& val)
```
$a_l,a_{l+1},\ldots,a_{r-1}$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

### get
```
G get(int i)
```
$a_i$ を求める

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(\log n)$
