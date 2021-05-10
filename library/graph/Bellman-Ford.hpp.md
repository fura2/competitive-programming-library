---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/Bellman-Ford.test.cpp
    title: verify/graph/Bellman-Ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/graph/Bellman-Ford.hpp: line 10: #pragma once found in a non-first line\n"
  code: "/*\n\t\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\n\t\u8CA0\u306E\u91CD\u307F\
    \u304C\u3042\u3063\u3066\u3082\u3088\u3044\n\tT = int, lint \u3092\u60F3\u5B9A\
    \u3057\u3066\u3044\u308B (double \u3060\u3068\u4E0D\u7B49\u53F7\u306B EPS \u3092\
    \u8003\u616E\u3057\u306A\u3044\u3068\u307E\u305A\u3044\u304B\u3082)\n\n\ts \u304B\
    \u3089\u5230\u9054\u3067\u304D\u306A\u3044\u9802\u70B9\u306E\u8DDD\u96E2\u306F\
    \ INF \u3068\u306A\u308B (\u3042\u308B\u8CA0\u9589\u8DEF\u304B\u3089\u5230\u9054\
    \u53EF\u80FD\u3067\u3042\u3063\u3066\u3082)\n\tG \u304C\u8CA0\u9589\u8DEF\u3092\
    \u3082\u3064\u5834\u5408\u306B, s \u304B\u3089\u3044\u304F\u3089\u3067\u3082\u5C0F\
    \u3055\u3044\u30B3\u30B9\u30C8\u3067\u5230\u9054\u3067\u304D\u308B\u9802\u70B9\
    \u306E\u8DDD\u96E2\u306F NINF \u3068\u306A\u308B (-INF \u3067\u306F\u306A\u3044\
    \u306E\u3067\u6CE8\u610F)\n*/\n\n#pragma once\n#include \"../template.hpp\"\n\
    #include \"wgraph.hpp\"\n\ntemplate<class T>\nvector<T> Bellman_Ford(const weighted_graph<T>&\
    \ G,int s){\n\tconst T INF=numeric_limits<T>::max();\n\tconst T NINF=numeric_limits<T>::min();\n\
    \n\tint n=G.size();\n\tvector<T> d(n,INF);\n\td[s]=0;\n\trep(_,n){\n\t\tbool upd=false;\n\
    \t\trep(u,n) if(d[u]<INF) for(const auto& e:G[u]) {\n\t\t\tint v=e.to;\n\t\t\t\
    if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, upd=true;\n\t\t}\n\t\tif(!upd) return d;\n\t\
    }\n\n\tqueue<int> Q;\n\trep(u,n) if(d[u]<INF) Q.emplace(u);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tfor(const auto& e:G[u]){\n\t\t\tint v=e.to;\n\
    \t\t\tif(d[v]>NINF && (d[u]==NINF || d[v]>d[u]+e.wt)) d[v]=NINF, Q.emplace(v);\n\
    \t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/graph/Bellman-Ford.hpp
  requiredBy: []
  timestamp: '2021-05-10 17:14:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/Bellman-Ford.test.cpp
documentation_of: library/graph/Bellman-Ford.hpp
layout: document
title: Bellman-Ford Algorithm
---

## Description
重みつきグラフの単一始点最短路を求める Bellman-Ford のアルゴリズム．
辺の重みは負でもよい．
```
vector<T> Bellman_Ford(const weighted_graph<T>& G, int s)
```
重みつきグラフ $G$ において，頂点 $s$ から各頂点 $u$ までの最短距離 $d(u)$ を求める．
$s$ から $u$ に到達できない場合は $d(u)=$ ``numeric_limits<T>::max()`` となる．
また，$s$ から $u$ にいくらでも小さいコストで到達できる場合は $d(u)=$ ``numeric_limits<T>::min()`` となる．
このようなケースは，$G$ において $s$ から到達できる負閉路が存在する場合に起こりうる．

#### Constraints
- $0\le s\lt n$
- $T$ は整数型 (``int``, ``long long`` など) であって，``numeric_limits<T>::max()`` および ``numeric_limits<T>::min()`` が定義されている．

#### Complexity
- $O(V(V+E))$
