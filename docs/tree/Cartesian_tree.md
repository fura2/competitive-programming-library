---
title: Cartesian Tree
documentation_of: ../../library/tree/Cartesian_tree.hpp
---

## Description
数列 $a=(a_0,\ldots,a_{n-1})$ に対して，次の手順で得られる $n$ 頂点の二分木を [Cartesian tree](https://en.wikipedia.org/wiki/Cartesian_tree) と呼ぶ．
- $i_\mathrm{min}$ を $\displaystyle a_{i_\mathrm{min}}=\min_{0\le i\lt n}a_i$ (複数ある場合は番号が最小のもの) となるように定め，頂点 $i_\mathrm{min}$ を根とする．
- 数列 $(a_0,\ldots,a_{i_\mathrm{min}-1})$ と $(a_{i_\mathrm{min}+1},\ldots,a_{n-1})$ についてそれぞれ再帰的に Cartesian tree を構築し，それらの根を頂点 $i_\mathrm{min}$ の左, 右の子とする．

### (constructor)
```
Cartesian_tree(const vector<T>& a = {})
```
数列 $a$ の Cartesian tree を構築する

#### Constraints
- $T$ は整数型 (``int``, ``long long`` など)

#### Complexity
- $O(n)$

### build
```
void build(const vector<T>& a)
```
数列 $a$ の Cartesian tree を構築する

#### Constraints
- なし

#### Complexity
- $O(n)$

### operator[]
```
const T& operator[](int u)
```
$a_u$ の値を求める

#### Constraints
- $0\le u\lt n$

#### Complexity
- $O(1)$

### root
```
int root()
```
Cartesian tree の根を求める

#### Constraints
- なし

#### Complexity
- $O(1)$

### parent
```
int parent(int u)
```
頂点 $u$ の親を求める．存在しない場合は $-1$ が返る．

#### Constraints
- なし

#### Complexity
- $O(1)$

### left
```
int left(int u)
```
頂点 $u$ の左の子を求める．存在しない場合は $-1$ が返る．

#### Constraints
- なし

#### Complexity
- $O(1)$

### right
```
int right(int u)
```
頂点 $u$ の右の子を求める．存在しない場合は $-1$ が返る．

#### Constraints
- なし

#### Complexity
- $O(1)$
