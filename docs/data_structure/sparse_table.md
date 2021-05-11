---
title: Sparse Table
documentation_of: ../../library/data_structure/sparse_table.hpp
---

## Description
[冪等半群](https://en.wikipedia.org/wiki/Band_(algebra)) $(B,\ast)$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，前処理を $O(n\log n)$ で，区間積を $O(1)$ で処理するデータ構造．\\
$B$ の演算の可換性は要求しない．
以下では，$B$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) sparse_table<B>()
(2) sparse_table<B>(const vector<T>& a)
```
- (1) 空の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $(B,\ast)$ は冪等半群 ($B$ 上の結合的な二項演算 $\ast$ が定義されていて，すべての $a\in B$ に対して $a\ast a=a$)
- (2) $T$ は $B$ にキャストできる ($T$ と $B$ が一致していなくてもよい)

#### Complexity
- $O(n\log n)$

### build
```
void build(const vector<T>& a)
```
- $a$ で初期化する

#### Constraints
- $T$ は $B$ にキャストできる ($T$ と $B$ が一致していなくてもよい)

#### Complexity
- $O(n\log n)$

### product
```
B product(int l, int r)
```
$a_l\ast a_{l+1}\ast\ldots\ast a_{r-1}$ を求める

#### Constraints
- $0\le l\lt r\le n$

#### Complexity
- $O(1)$

## References
- [Sparse Table - scrapbox.io/data-structures](https://scrapbox.io/data-structures/Sparse_Table)
