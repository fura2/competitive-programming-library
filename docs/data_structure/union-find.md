---
title: Union-Find
documentation_of: ../../library/data_structure/union-find.hpp
---

## Description
互いに素な $n$ 個の一点集合 $\lbrace0\rbrace,\ldots,\lbrace n-1\rbrace$ がある状態から始めて，次の操作を amortized $O(\alpha(n))$ で処理するデータ構造 ([素集合データ構造](https://en.wikipedia.org/wiki/Disjoint-set_data_structure))．
- 要素がどの集合に属するかを求める
- 二つの集合をマージする

union by size と path compression を実装している．

### (constructor)
```
(1) union_find()
(2) union_find(int n)
```
- (1) 空集合で初期化する
- (2) 互いに素な $n$ 個の一点集合 $\lbrace0\rbrace,\ldots,\lbrace n-1\rbrace$ で初期化する

#### Constraints
- (2) $n\ge0$

#### Complexity
- (1) $O(1)$
- (2) $O(n)$

### build
```
void build(int n)
```
- 互いに素な $n$ 個の一点集合 $\lbrace0\rbrace,\ldots,\lbrace n-1\rbrace$ で初期化する

#### Constraints
- $n\ge0$

#### Complexity
- $O(n)$

### find
```
int find(int u)
```
$u$ が含まれる集合の代表元を求める

#### Constraints
- $0\le u\lt n$

#### Complexity
- amortized $O(\alpha(n))$

### unite
```
void unite(int u, int v)
```
$u$ が含まれる集合と $v$ が含まれる集合をマージする

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- amortized $O(\alpha(n))$

### is_same
```
bool is_same(int u, int v)
```
$u$ と $v$ が同じ集合に含まれるかどうかを判定する

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- amortized $O(\alpha(n))$

### size
```
(1) int size()
(2) int size(int u)
```
- (1) 集合の個数を求める
- (2) $u$ が含まれる集合の要素数を求める

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- (1) $O(1)$
- (2) amortized $O(\alpha(n))$
