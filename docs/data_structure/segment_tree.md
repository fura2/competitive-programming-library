---
title: Segment Tree
documentation_of: ../../library/data_structure/segment_tree.hpp
---

## Description
モノイド $(M,\ast)$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，一点更新と区間積を $O(\log n)$ で処理するデータ構造．\\
以下では，$M$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) segment_tree<M>(int n = 0)
(2) segment_tree<M>(const vector<T>& a)
```
- (1) $M$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $(M,\ast)$ はモノイド (デフォルトコンストラクタが $M$ の単位元を生成する)
- (1) $n\ge0$
- (2) $T$ は $M$ にキャストできる ($T$ と $M$ が一致していなくてもよい)

#### Complexity
- $O(n)$

### build
```
(1) void build(int n)
(2) void build(const vector<T>& a)
```
- (1) $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- (1) $n\ge0$
- (2) $T$ は $M$ にキャストできる ($T$ と $M$ が一致していなくてもよい)

#### Complexity
- $O(n)$

### operator[]
```
const M& operator[](int i)
```
$a_i$ を求める

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(1)$

### update
```
void update(int i, const M& x)
```
$a_i$ に $x$ を代入する

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(\log n)$

### product
```
M product(int l, int r)
```
$a_l\ast a_{l+1}\ast\cdots\ast a_{r-1}$ を求める

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

### operate
```
N operate(int l, int r, const F& f)
```
モノイド $(N,\ast)$ と準同型 $f:M\to N$ に対して，$f(a_l\ast a_{l+1}\cdots\ast a_{r-1})$ を求める．  
$M$ における積の計算量が大きく，$N$ における積と $f$ を作用させる計算量がどちらも小さいときに有用．

#### Constraints
- $(N,\ast)$ はモノイド (デフォルトコンストラクタが $N$ の単位元を生成する)
- $f:M\to N$ はモノイドの準同型
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$ ($N$ の演算とインスタンスの生成，および，$f$ を作用させる計算量が $O(1)$ であることを仮定)

### max_right
```
int max_right(int l, const F& f)
```
$f:M\to\mathrm{bool}$ に対して，次の二つの条件をみたす $r\ (l\le r\le n)$ を一つ求める．
- $r=l$ または $f(a_l\ast a_{l+1}\ast\cdots\ast a_{r-1})=\mathrm{true}$
- $r=n$ または $f(a_l\ast a_{l+1}\ast\cdots\ast a_r)=\mathrm{false}$

#### Constraints
- $0\le l\le n$
- $f:M\to\mathrm{bool}$ は $f(e)=\mathrm{true}$ をみたす

#### Complexity
- $O(\log n)$ ($f$ を作用させる計算量が $O(1)$ であることを仮定)

### min_left
```
int min_left(int r, const F& f)
```
$f:M\to\mathrm{bool}$ に対して，次の二つの条件をみたす $l\ (0\le l\le r)$ を一つ求める．
- $l=r$ または $f(a_l\ast a_{l+1}\ast\cdots\ast a_{r-1})=\mathrm{true}$
- $l=0$ または $f(a_{l-1}\ast a_l\ast\cdots\ast a_{r-1})=\mathrm{false}$

#### Constraints
- $0\le r\le n$
- $f:M\to\mathrm{bool}$ は $f(e)=\mathrm{true}$ をみたす

#### Complexity
- $O(\log n)$ ($f$ を作用させる計算量が $O(1)$ であることを仮定)
