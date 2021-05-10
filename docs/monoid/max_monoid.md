---
title: Maximum Monoid
documentation_of: ../../library/monoid/max_monoid.hpp
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=\max\lbrace a,b\rbrace$ と定めることで得られるモノイド．\\
``numeric_limits<T>::min()`` が単位元となる．

### (constructor)
```
(1) max_monoid<T>()
(2) max_monoid<T>(const T& val)
```
- (1) 単位元で初期化する
- (2) $\mathrm{val}$ で初期化する

#### Constraints
- $T$ 上の比較演算子 $<$ が定義されていて，これについて $T$ は全順序集合
- ``numeric_limits<T>::min()`` が $T$ の最小元

#### Complexity
- $O(1)$

### operator*
```
max_monoid operator*(const max_monoid& x)
```
- モノイドの積

#### Constraints
- なし

#### Complexity
- $O(1)$ ($T$ の元の比較が $O(1)$ でできることを仮定)

### get
```
(1) T& get()
(2) const T& get()
```
対応する $T$ の元を求める

#### Constraints
- なし

#### Complexity
- $O(1)$
