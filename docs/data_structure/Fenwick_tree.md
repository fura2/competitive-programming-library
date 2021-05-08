---
title: Fenwick Tree
documentation_of: ../../library/data_structure/Fenwick_tree.hpp
---

## Description
Abel 群 $G$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，一点加算と区間和を $O(\log n)$ で処理できるデータ構造．  
以下では，$G$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) Fenwick_tree<G>()
(2) Fenwick_tree<G>(int n)
(3) Fenwick_tree<G>(const vector<G>& a)
```
- (1) 空の列で初期化する
- (2) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (3) $a$ で初期化する

#### Constraints
- $(G,+)$ は Abel 群 (デフォルトコンストラクタが $G$ の単位元を生成し，$-$ は $+$ の逆演算)
- (2) $n\ge0$

#### Complexity
- (1) $O(1)$
- (2), (3) $O(n)$

### build
```
(1) void build(int n)
(2) void build(const vector<G>& a)
```
- (1) $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- (1) $n\ge0$

#### Complexity
- $O(n)$

### add

```
void add(int i, const G& val)
```
$a_i$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(\log n)$

### sum
```
G sum(int l, int r)
```
$a_l+a_{l+1}+\cdots+a_{r-1}$ を求める

#### Constraints
- $0\le l\le r\lt n$

#### Complexity
- $O(\log n)$

### lower_bound
```
int lower_bound(G val)
```
$a_0+a_1+\cdots+a_i\ge\mathrm{val}$ をみたす最小の $i$ を求める．  
ただし，$a_0+\cdots+a_{n-1}\lt\mathrm{val}$ のときは $n$ を返す．

#### Constraints
- $G$ 上の比較演算子 $<$ が定義されていて，これについて $G$ は[全順序群](https://en.wikipedia.org/wiki/Linearly_ordered_group)．
- $a_i\ge e\quad(i=0,\ldots,n-1)$

#### Complexity
- $O(\log n)$

### upper_bound
```
int upper_bound(G val)
```
$a_0+a_1+\cdots+a_i\gt\mathrm{val}$ をみたす最小の $i$ を求める．  
ただし，$a_0+\cdots+a_{n-1}\le\mathrm{val}$ のときは $n$ を返す．

#### Constraints
- $G$ 上の比較演算子 $<$ が定義されていて，これについて $G$ は[全順序群](https://en.wikipedia.org/wiki/Linearly_ordered_group)．
- $a_i\ge e\quad(i=0,\ldots,n-1)$

#### Complexity
- $O(\log n)$

## References
- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)
