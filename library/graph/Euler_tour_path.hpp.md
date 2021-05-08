---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/Euler_tour_path.hpp\"\n// Euler tour (\u30D1\
    \u30B9\u30AF\u30A8\u30EA)\n/*\n\t\u9802\u70B9\u306B\u91CD\u307F\u304C\u3064\u3044\
    \u305F N \u9802\u70B9\u306E\u6839\u3064\u304D\u6728 T \u3092\u8003\u3048\u308B\
    .\n\t\u6839\u304B\u3089 DFS \u3057\u3066\u5404\u9802\u70B9\u3092\u6700\u521D\u3068\
    \u6700\u5F8C\u306B\u8A2A\u308C\u305F\u3068\u304D\u306B\u305D\u306E\u9802\u70B9\
    \u306E\u756A\u53F7\u3092\u8A18\u9332\u3059\u308B.\n\t\u3053\u3046\u3057\u3066\u5F97\
    \u3089\u308C\u308B\u9577\u3055 2*N \u306E\u6570\u5217\u3092 I = (I[0], ..., I[2*N-1])\
    \ \u3068\u3059\u308B.\n\t\tI \u306B\u306F 0, 1, ..., N-1 \u304C\u305D\u308C\u305E\
    \u308C\u3061\u3087\u3046\u3069 2 \u56DE\u305A\u3064\u73FE\u308C\u308B.\n\t\u9577\
    \u3055 N \u306E\u6570\u5217 L, R \u3092\u6B21\u306E\u3088\u3046\u306B\u5B9A\u3081\
    \u308B.\n\t\tL[u] \u306F\u9802\u70B9 u \u306B\u6700\u521D\u306B\u8A2A\u308C\u305F\
    \u3068\u304D\u306E\u756A\u53F7 (I \u306E\u6DFB\u3048\u5B57),\n\t\tR[u] \u306F\u9802\
    \u70B9 u \u306B\u6700\u5F8C\u306B\u8A2A\u308C\u305F\u3068\u304D\u306E\u756A\u53F7\
    \ (I \u306E\u6DFB\u3048\u5B57).\n\t\u9577\u3055 2*N \u306E\u6570\u5217 W \u3092\
    \u6B21\u306E\u3088\u3046\u306B\u5B9A\u3081\u308B.\n\t\tW[L[u]] = +(\u9802\u70B9\
    \ u \u306E\u91CD\u307F),\n\t\tW[R[u]] = -(\u9802\u70B9 u \u306E\u91CD\u307F).\n\
    \tu \u304C v \u306E\u89AA\u3067\u3042\u308B\u3088\u3046\u306A\u9802\u70B9 u, v\
    \ \u306B\u5BFE\u3057\u3066, \u30D1\u30B9 u - v \u306B\u542B\u307E\u308C\u308B\u9802\
    \u70B9\u306E\u91CD\u307F\u306E\u7DCF\u548C\u306F\n\t\tW[L[u]] + W[L[u]+1] + ...\
    \ + W[R[v]-1]\n\t\u3068\u8868\u3055\u308C\u308B.\n\t\u4E00\u822C\u306E\u30D1\u30B9\
    \u306E\u91CD\u307F\u3082 LCA \u3068\u7D44\u307F\u5408\u308F\u305B\u308B\u3053\u3068\
    \u3067\u6C42\u3081\u3089\u308C\u308B.\n*/\n\nclass Euler_tour_for_paths{\n\tvector<int>\
    \ L,R;\n\tconst graph& Tr;\n\tint idx;\n\tvoid dfs(int u,int p){\n\t\tL[u]=idx++;\n\
    \t\tfor(int v:Tr[u]) if(v!=p) dfs(v,u);\n\t\tR[u]=idx++;\n\t}\npublic:\n\tEuler_tour_for_paths(const\
    \ graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){\n\t\tdfs(root,-1);\n\
    \t}\n\tpair<int,int> get_indices(int u)const{ return {L[u],R[u]}; }\n\tpair<int,int>\
    \ get_path(int u,int v)const{ return {L[u],R[v]}; }\n};\n"
  code: "// Euler tour (\u30D1\u30B9\u30AF\u30A8\u30EA)\n/*\n\t\u9802\u70B9\u306B\u91CD\
    \u307F\u304C\u3064\u3044\u305F N \u9802\u70B9\u306E\u6839\u3064\u304D\u6728 T\
    \ \u3092\u8003\u3048\u308B.\n\t\u6839\u304B\u3089 DFS \u3057\u3066\u5404\u9802\
    \u70B9\u3092\u6700\u521D\u3068\u6700\u5F8C\u306B\u8A2A\u308C\u305F\u3068\u304D\
    \u306B\u305D\u306E\u9802\u70B9\u306E\u756A\u53F7\u3092\u8A18\u9332\u3059\u308B\
    .\n\t\u3053\u3046\u3057\u3066\u5F97\u3089\u308C\u308B\u9577\u3055 2*N \u306E\u6570\
    \u5217\u3092 I = (I[0], ..., I[2*N-1]) \u3068\u3059\u308B.\n\t\tI \u306B\u306F\
    \ 0, 1, ..., N-1 \u304C\u305D\u308C\u305E\u308C\u3061\u3087\u3046\u3069 2 \u56DE\
    \u305A\u3064\u73FE\u308C\u308B.\n\t\u9577\u3055 N \u306E\u6570\u5217 L, R \u3092\
    \u6B21\u306E\u3088\u3046\u306B\u5B9A\u3081\u308B.\n\t\tL[u] \u306F\u9802\u70B9\
    \ u \u306B\u6700\u521D\u306B\u8A2A\u308C\u305F\u3068\u304D\u306E\u756A\u53F7 (I\
    \ \u306E\u6DFB\u3048\u5B57),\n\t\tR[u] \u306F\u9802\u70B9 u \u306B\u6700\u5F8C\
    \u306B\u8A2A\u308C\u305F\u3068\u304D\u306E\u756A\u53F7 (I \u306E\u6DFB\u3048\u5B57\
    ).\n\t\u9577\u3055 2*N \u306E\u6570\u5217 W \u3092\u6B21\u306E\u3088\u3046\u306B\
    \u5B9A\u3081\u308B.\n\t\tW[L[u]] = +(\u9802\u70B9 u \u306E\u91CD\u307F),\n\t\t\
    W[R[u]] = -(\u9802\u70B9 u \u306E\u91CD\u307F).\n\tu \u304C v \u306E\u89AA\u3067\
    \u3042\u308B\u3088\u3046\u306A\u9802\u70B9 u, v \u306B\u5BFE\u3057\u3066, \u30D1\
    \u30B9 u - v \u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u306E\u91CD\u307F\u306E\
    \u7DCF\u548C\u306F\n\t\tW[L[u]] + W[L[u]+1] + ... + W[R[v]-1]\n\t\u3068\u8868\u3055\
    \u308C\u308B.\n\t\u4E00\u822C\u306E\u30D1\u30B9\u306E\u91CD\u307F\u3082 LCA \u3068\
    \u7D44\u307F\u5408\u308F\u305B\u308B\u3053\u3068\u3067\u6C42\u3081\u3089\u308C\
    \u308B.\n*/\n\nclass Euler_tour_for_paths{\n\tvector<int> L,R;\n\tconst graph&\
    \ Tr;\n\tint idx;\n\tvoid dfs(int u,int p){\n\t\tL[u]=idx++;\n\t\tfor(int v:Tr[u])\
    \ if(v!=p) dfs(v,u);\n\t\tR[u]=idx++;\n\t}\npublic:\n\tEuler_tour_for_paths(const\
    \ graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){\n\t\tdfs(root,-1);\n\
    \t}\n\tpair<int,int> get_indices(int u)const{ return {L[u],R[u]}; }\n\tpair<int,int>\
    \ get_path(int u,int v)const{ return {L[u],R[v]}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/Euler_tour_path.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/Euler_tour_path.hpp
layout: document
redirect_from:
- /library/library/graph/Euler_tour_path.hpp
- /library/library/graph/Euler_tour_path.hpp.html
title: library/graph/Euler_tour_path.hpp
---
