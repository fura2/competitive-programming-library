---
title: GCD Monoid
documentation_of: ../../library/monoid/gcd_monoid.hpp
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=\mathrm{gcd}$ と定めることで得られるモノイド．\\
``T()`` が単位元となる．
```
gcd_monoid<T>
```

### (constructor)
```
gcd_monoid<T>(const T& val = T())
```
$\mathrm{val}$ で初期化する

#### Constraints
- $T$ は $\mathrm{gcd}:T\times T\to T$ が定義された環 ([参考](https://en.wikipedia.org/wiki/GCD_domain)) で，デフォルトコンストラクタが $T$ の零元を生成する．

#### Complexity
- $O(1)$

### operator*
```
gcd_monoid operator*(const gcd_monoid& x)
```
モノイドの積

#### Constraints
- なし

#### Complexity
- GCD の計算を $O(1)$ 回おこなう

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
