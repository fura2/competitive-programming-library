---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/rerooting.1.test.cpp
    title: verify/tree/rerooting.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/rerooting.2.test.cpp
    title: verify/tree/rerooting.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 5 \"library/tree/rerooting.hpp\"\n\ntemplate<class M,class F,class G>\n\
    vector<M> rerooting(const graph& T,const F& f,const G& g){\n\tint n=T.size();\n\
    \tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&& dfs1,int u,int p)->void{\n\
    \t\tfor(int v:T[u]) if(v!=p) {\n\t\t\tdfs1(dfs1,v,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[v],v);\n\
    \t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int\
    \ p,const M& dp_par)->void{\n\t\tint k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\
    \t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\t\
    if(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t}\n\t\
    };\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n\ntemplate<class\
    \ M,class W,class F,class G>\nvector<M> rerooting(const weighted_graph<W>& T,const\
    \ F& f,const G& g){\n\tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&&\
    \ dfs1,int u,int p)->void{\n\t\tfor(const auto& e:T[u]) if(e.to!=p) {\n\t\t\t\
    dfs1(dfs1,e.to,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[e.to],e);\n\t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\
    \t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{\n\t\t\
    int k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\t\trep(i,k){\n\t\t\t\
    const auto& e=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tconst auto& [v,wt]=T[u][i];\n\
    \t\t\tif(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t\
    }\n\t};\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../graph/graph.hpp\"\
    \n#include \"../graph/wgraph.hpp\"\n\ntemplate<class M,class F,class G>\nvector<M>\
    \ rerooting(const graph& T,const F& f,const G& g){\n\tint n=T.size();\n\tvector<M>\
    \ dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&& dfs1,int u,int p)->void{\n\t\tfor(int\
    \ v:T[u]) if(v!=p) {\n\t\t\tdfs1(dfs1,v,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[v],v);\n\
    \t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int\
    \ p,const M& dp_par)->void{\n\t\tint k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\
    \t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\t\
    if(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t}\n\t\
    };\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n\ntemplate<class\
    \ M,class W,class F,class G>\nvector<M> rerooting(const weighted_graph<W>& T,const\
    \ F& f,const G& g){\n\tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&&\
    \ dfs1,int u,int p)->void{\n\t\tfor(const auto& e:T[u]) if(e.to!=p) {\n\t\t\t\
    dfs1(dfs1,e.to,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[e.to],e);\n\t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\
    \t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{\n\t\t\
    int k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\t\trep(i,k){\n\t\t\t\
    const auto& e=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tconst auto& [v,wt]=T[u][i];\n\
    \t\t\tif(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t\
    }\n\t};\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2021-05-15 16:38:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/rerooting.1.test.cpp
  - verify/tree/rerooting.2.test.cpp
documentation_of: library/tree/rerooting.hpp
layout: document
title: Rerooting
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
$(M,\ast)$ を可換モノイド，$f:M\times E\to M,\ g:M\times V\to M$ とする．\\
$T$ を $r$ を根とする根つき木と見なす．
$\mathrm{dp}:V\to M$ を根から再帰的に
<div style="text-align:center">
	$$\mathrm{dp}(u)=g(f(\mathrm{dp}(v_1),e_1)\ast f(\mathrm{dp}(v_2),e_2)\ast\cdots\ast f(\mathrm{dp}(v_k),e_k),u)$$
</div>
と定める．
ここで，頂点 $u$ の子を $v_1,\ldots,v_k$ と，$u$ から $v_i$ への有向辺を $e_i$ とおいた．

```
(1) vector<M> rerooting(const graph& T, const F& f, const G& g)
(2) vector<M> rerooting(const weighted_graph<W>& T, const F& f, const G& g)
```
- (1) 木 $T$ の各頂点 $r$ について $\mathrm{dp}(r)$ を求める
- (2) 重みつき木 $T$ の各頂点 $r$ について $\mathrm{dp}(r)$ を求める

#### Constraints
- $T$ は木

#### Complexity
- $O(V)$ ($f,g$ の計算が $O(1)$ でできることを仮定)

## References
- [全方位木DP(ReRooting)の抽象化について - メモ帳](https://null-mn.hatenablog.com/entry/2020/04/14/124151)
