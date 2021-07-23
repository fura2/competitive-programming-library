---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/Held-Karp.test.cpp
    title: verify/graph/Held-Karp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/graph/Held-Karp.hpp\"\
    \n\ntemplate<class T>\nT Held_Karp(const vector<vector<T>>& d){\n\tconstexpr T\
    \ INF=numeric_limits<T>::max();\n\tint n=d.size();\n\tvector dp(1<<n,vector(n,INF));\n\
    \tdp[1<<0][0]=T();\n\trep(S,1<<n) rep(u,n) if(S>>u&1 && dp[S][u]<INF) {\n\t\t\
    rep(v,n) if(~S>>v&1 && d[u][v]<INF) {\n\t\t\tdp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+d[u][v]);\n\
    \t\t}\n\t}\n\n\tT res=INF;\n\trep(u,n) if(dp[(1<<n)-1][u]<INF && d[u][0]<INF)\
    \ {\n\t\tres=min(res,dp[(1<<n)-1][u]+d[u][0]);\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nT Held_Karp(const\
    \ vector<vector<T>>& d){\n\tconstexpr T INF=numeric_limits<T>::max();\n\tint n=d.size();\n\
    \tvector dp(1<<n,vector(n,INF));\n\tdp[1<<0][0]=T();\n\trep(S,1<<n) rep(u,n) if(S>>u&1\
    \ && dp[S][u]<INF) {\n\t\trep(v,n) if(~S>>v&1 && d[u][v]<INF) {\n\t\t\tdp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+d[u][v]);\n\
    \t\t}\n\t}\n\n\tT res=INF;\n\trep(u,n) if(dp[(1<<n)-1][u]<INF && d[u][0]<INF)\
    \ {\n\t\tres=min(res,dp[(1<<n)-1][u]+d[u][0]);\n\t}\n\treturn res;\n}\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/graph/Held-Karp.hpp
  requiredBy: []
  timestamp: '2021-07-23 17:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/Held-Karp.test.cpp
documentation_of: library/graph/Held-Karp.hpp
layout: document
title: Travelling Salesman Problem (Held-Karp Algorithm)
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
