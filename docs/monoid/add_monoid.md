---
title: Additive Monoid
documentation_of: ../../library/monoid/add_monoid.hpp
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=a+b$ と定めることで得られるモノイド．\\
``T()`` が単位元となる．
```
add_monoid<T>
```

### (constructor)
```
add_monoid<T>(const T& val = T())
```
$\mathrm{val}$ で初期化する

#### Constraints
- $(T,+)$ はモノイド ($+$ は結合的で，デフォルトコンストラクタが $T$ の単位元を生成)

#### Complexity
- $O(1)$

### operator*
```
add_monoid operator*(const add_monoid& x)
```
モノイドの積

#### Constraints
- なし

#### Complexity
- $O(1)$ ($T$ の演算 $+$ が $O(1)$ でできることを仮定)

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
