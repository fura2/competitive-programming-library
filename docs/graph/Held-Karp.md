---
title: Travelling Salesman Problem (Held-Karp Algorithm)
documentation_of: ../../library/graph/Held-Karp.hpp
---

## Description
巡回セールスマン問題を解く Held-Karp のアルゴリズム．
```
T Held_Karp(const vector<vector<T>>& d)
```
重みつき有向グラフ $G$ において，重み最小の Hamilton 閉路 (の重み) を求める．\\
入力は $G$ の距離行列 $d$ で与える．\\
$G$ が Hamilton 閉路を持たないときは ``numeric_limits<T>::max()`` を返す．\\
頂点数が $1$ のグラフは Hamilton 閉路を持たないものと見なす．

#### Constraints
- $G$ の辺の重みの型 $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など) で，``numeric_limits<T>::max()`` が定義されている．
- $d$ は重みつき単純有向グラフ $G$ の距離行列
	- $d$ は $V\times V$ 行列で，$(u,v)$ 成分は辺 $(u,v)$ の重み (辺が存在しない場合は ``numeric_limits<T>::max()``) を表す．辺の重みは負でもよい．
- $V>0$

#### Complexity
- $O(V^22^V)$
