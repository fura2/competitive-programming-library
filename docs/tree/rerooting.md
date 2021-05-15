---
title: Rerooting
documentation_of: ../../library/tree/rerooting.hpp
---

## Description
全方位木 DP (rerooting) は，木 $T=(V,E)$ の各頂点 $r$ に対して次で定義される値 $\mathrm{dp}(r)$ を求めるアルゴリズム．

<h4>$T$ が重みなしのとき</h4>

$(M,\ast)$ を可換モノイド，$f:M\times V\to M,\ g:M\times V\to M$ とする．\\
$T$ を $r$ を根とする根つき木と見なす．
$\mathrm{dp}:V\to M$ を根から再帰的に
<div style="text-align:center">
	$$\mathrm{dp}(u)=g(f(\mathrm{dp}(v_1),v_1)\ast f(\mathrm{dp}(v_2),v_2)\ast\cdots\ast f(\mathrm{dp}(v_k),v_k),u)$$
</div>
と定める．
ここで，頂点 $u$ の子を $v_1,\ldots,v_k$ とおいた．

<h4>$T$ が重みありのとき</h4>

$(M,\ast)$ を可換モノイド，$f:M\times W\times V\to M,\ g:M\times V\to M$ とする．\\
$T$ を $r$ を根とする根つき木と見なす．
$\mathrm{dp}:V\to M$ を根から再帰的に
<div style="text-align:center">
	$$\mathrm{dp}(u)=g(f(\mathrm{dp}(v_1),w_1,v_1)\ast f(\mathrm{dp}(v_2),w_2,v_2)\ast\cdots\ast f(\mathrm{dp}(v_k),w_k,v_k),u)$$
</div>
と定める．
ここで，頂点 $u$ の子を $v_1,\ldots,v_k$ と，有向辺 $(u,v_i)$ の重みを $w_i$ とおいた．

```
(1) vector<M> rerooting(const graph& T, const F& f, const G& g)
(2) vector<M> rerooting(const weighted_graph<W>& T, const F& f, const G& g)
```
- (1) 木 $T$ の各頂点 $r$ について $\mathrm{dp}(r)$ を求める
- (2) 重みつき木 $T$ の各頂点 $r$ について $\mathrm{dp}(r)$ を求める

#### Constraints
- $T$ は木
- $M$ は可換モノイド

#### Complexity
- $O(V)$ ($M$ の演算と $f,g$ の作用が $O(1)$ でできることを仮定)

## References
- [全方位木DP(ReRooting)の抽象化について - メモ帳](https://null-mn.hatenablog.com/entry/2020/04/14/124151)
