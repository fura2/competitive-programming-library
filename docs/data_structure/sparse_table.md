---
title: Sparse Table
documentation_of: ../../library/data_structure/sparse_table.hpp
---

## Description
数列 $a_0,\ldots,a_{n-1}$ に対して，[RMQ](https://en.wikipedia.org/wiki/Range_minimum_query) を構築 $O(n\log n)$ / 区間 min クエリ $O(1)$ で処理するデータ構造．\\
素直に [band](https://en.wikipedia.org/wiki/Band_(algebra)) (冪等半群) の元の列に一般化できるが，ここでは RMQ に特化した形で実装した．

### (constructor)
```
sparse_table<T>(const vector<T>& a = vector<T>())
```
- $a$ で初期化する

#### Constraints
- $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)

#### Complexity
- $O(n\log n)$

### build
```
void build(const vector<T>& a)
```
- $a$ で初期化する

#### Constraints
- なし

#### Complexity
- $O(n\log n)$

### fold
```
T fold(int l, int r)
```
$\min\lbrace a_l,a_{l+1},\ldots,a_{r-1}\rbrace$ を求める

#### Constraints
- $0\le l\lt r\le n$

#### Complexity
- $O(1)$

## References
- [Sparse Table - scrapbox.io/data-structures](https://scrapbox.io/data-structures/Sparse_Table)
