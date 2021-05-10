---
title: Starry Sky Tree
documentation_of: ../../library/data_structure/starry_sky_tree.hpp
---

## Description
数列 $a_0,\ldots,a_{n-1}$ に対して，区間加算と区間 max を $O(\log n)$ で処理するデータ構造

### (constructor)
```
(1) starry_sky_tree<T>()
(2) starry_sky_tree<T>(int n)
```
- (1) 空の列で初期化する
- (2) $0$ のみからなる長さ $n$ の列で初期化する

#### Constraints
- $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)
- (2) $n\ge0$

#### Complexity
- (1) $O(1)$
- (2) $O(n)$

### build
```
void build(int n)
```
- $0$ のみからなる長さ $n$ の列で初期化する

#### Constraints
- $n\ge0$

#### Complexity
- $O(n)$

### add
```
void add(int l, int r, const T& val)
```
$a_l,a_{l+1},\ldots,a_{r-1}$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

### max
```
T max(int l, int r)
```
$\max\lbrace a_l,a_{l+1},\cdots,a_{r-1}\rbrace$ を求める．
$l=r$ のときは ``numeric_limits<T>::min()`` が返る．

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

## References
- [Starry Sky(星空) - joi2009-day4 解説](https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html)
- [Starry sky 木 - えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2019/06/21/174953)
