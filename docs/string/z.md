---
title: Z Algorithm
documentation_of: ../../library/string/z.hpp
---

## Description
文字列 $s=s_0\cdots s_{n-1}$ に対して，$z_i=(s$ と $s_i\cdots s_{n-1}$ の最長共通接頭辞の長さ$)$ と定める．  
Z algorithm は数列 $z=(z_0,\ldots,z_{n-1})$ を $O(n)$ で求めるアルゴリズムである．

```
(1) vector<int> Z_algorithm(const string& s)
(2) vector<int> Z_algorithm(const vector<T>& a)
```
- (1) $s$ に対して数列 $z$ を求める
- (2) 要素の型が $T$ である列 $a$ に対して数列 $z$ を求める

#### Constraints
- なし

#### Complexity
- $O(n)$
