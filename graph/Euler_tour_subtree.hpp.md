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
  bundledCode: "#line 1 \"graph/Euler_tour_subtree.hpp\"\n// Euler tour (\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA)\n/*\n\t\u9802\u70B9\u306B\u91CD\u307F\u304C\u3064\u3044\
    \u305F N \u9802\u70B9\u306E\u6839\u3064\u304D\u6728 T \u3092\u8003\u3048\u308B\
    .\n\t\u9577\u3055 N \u306E\u6570\u5217 L, R \u306F\u6B21\u3092\u307F\u305F\u3059\
    .\n\t\tL \u306F {0, 1, ..., N-1} \u306E permutation \u3067\u3042\u3063\u3066,\n\
    \t\tL[u] \u306F DFS \u306E\u884C\u304D\u304C\u3051\u9806\u3067\u9802\u70B9 u \u304C\
    \u4F55\u756A\u76EE\u306B\u73FE\u308C\u308B\u304B\u3092\u8868\u3059.\n\t\t\u307E\
    \u305F, 0 <= L[u] < R[u] <= V \u304C\u6210\u308A\u7ACB\u3064.\n\tW[L[u]] = (\u9802\
    \u70B9 u \u306E\u91CD\u307F) \u3068\u3057\u3066,\n\t\u9802\u70B9 u \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\
    \u306E\u91CD\u307F\u306E\u7DCF\u548C\u306F\n\t\tW[L[u]] + W[L[u]+1] + ... + W[R[u]-1]\n\
    \t\u3068\u8868\u3055\u308C\u308B.\n*/\n\nclass Euler_tour_for_subtrees{\n\tvector<int>\
    \ L,R;\n\tconst graph& Tr;\n\tint idx;\n\tvoid dfs(int u,int p){\n\t\tL[u]=idx++;\n\
    \t\tfor(int v:Tr[u]) if(v!=p) dfs(v,u);\n\t\tR[u]=idx;\n\t}\npublic:\n\tEuler_tour_for_subtrees(const\
    \ graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){\n\t\tdfs(root,-1);\n\
    \t}\n\tint get_index(int u)const{ return L[u]; }\n\tpair<int,int> get_subtree(int\
    \ u)const{ return {L[u],R[u]}; }\n};\n\n\n// \u8FBA\u306B\u91CD\u307F\u304C\u3064\
    \u3044\u305F\u30D0\u30FC\u30B8\u30E7\u30F3 (\u6A5F\u80FD\u306F\u540C\u3058)\n\n\
    template<class T>\nclass Euler_tour_for_subtrees{\n\tvector<int> L,R;\n\tconst\
    \ weighted_graph<T>& Tr;\n\tint idx;\n\tvoid dfs(int u,int p){\n\t\tL[u]=idx++;\n\
    \t\tfor(const auto& e:Tr[u]){\n\t\t\tint v=e.to;\n\t\t\tif(v!=p) dfs(v,u);\n\t\
    \t}\n\t\tR[u]=idx;\n\t}\npublic:\n\tEuler_tour_for_subtrees(const weighted_graph<T>&\
    \ Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){\n\t\tdfs(root,-1);\n\t\
    }\n\tint get_index(int u)const{ return L[u]; }\n\tpair<int,int> get_subtree(int\
    \ u)const{ return {L[u],R[u]}; }\n};\n"
  code: "// Euler tour (\u90E8\u5206\u6728\u30AF\u30A8\u30EA)\n/*\n\t\u9802\u70B9\u306B\
    \u91CD\u307F\u304C\u3064\u3044\u305F N \u9802\u70B9\u306E\u6839\u3064\u304D\u6728\
    \ T \u3092\u8003\u3048\u308B.\n\t\u9577\u3055 N \u306E\u6570\u5217 L, R \u306F\
    \u6B21\u3092\u307F\u305F\u3059.\n\t\tL \u306F {0, 1, ..., N-1} \u306E permutation\
    \ \u3067\u3042\u3063\u3066,\n\t\tL[u] \u306F DFS \u306E\u884C\u304D\u304C\u3051\
    \u9806\u3067\u9802\u70B9 u \u304C\u4F55\u756A\u76EE\u306B\u73FE\u308C\u308B\u304B\
    \u3092\u8868\u3059.\n\t\t\u307E\u305F, 0 <= L[u] < R[u] <= V \u304C\u6210\u308A\
    \u7ACB\u3064.\n\tW[L[u]] = (\u9802\u70B9 u \u306E\u91CD\u307F) \u3068\u3057\u3066\
    ,\n\t\u9802\u70B9 u \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\
    \u307E\u308C\u308B\u9802\u70B9\u306E\u91CD\u307F\u306E\u7DCF\u548C\u306F\n\t\t\
    W[L[u]] + W[L[u]+1] + ... + W[R[u]-1]\n\t\u3068\u8868\u3055\u308C\u308B.\n*/\n\
    \nclass Euler_tour_for_subtrees{\n\tvector<int> L,R;\n\tconst graph& Tr;\n\tint\
    \ idx;\n\tvoid dfs(int u,int p){\n\t\tL[u]=idx++;\n\t\tfor(int v:Tr[u]) if(v!=p)\
    \ dfs(v,u);\n\t\tR[u]=idx;\n\t}\npublic:\n\tEuler_tour_for_subtrees(const graph&\
    \ Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){\n\t\tdfs(root,-1);\n\t\
    }\n\tint get_index(int u)const{ return L[u]; }\n\tpair<int,int> get_subtree(int\
    \ u)const{ return {L[u],R[u]}; }\n};\n\n\n// \u8FBA\u306B\u91CD\u307F\u304C\u3064\
    \u3044\u305F\u30D0\u30FC\u30B8\u30E7\u30F3 (\u6A5F\u80FD\u306F\u540C\u3058)\n\n\
    template<class T>\nclass Euler_tour_for_subtrees{\n\tvector<int> L,R;\n\tconst\
    \ weighted_graph<T>& Tr;\n\tint idx;\n\tvoid dfs(int u,int p){\n\t\tL[u]=idx++;\n\
    \t\tfor(const auto& e:Tr[u]){\n\t\t\tint v=e.to;\n\t\t\tif(v!=p) dfs(v,u);\n\t\
    \t}\n\t\tR[u]=idx;\n\t}\npublic:\n\tEuler_tour_for_subtrees(const weighted_graph<T>&\
    \ Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){\n\t\tdfs(root,-1);\n\t\
    }\n\tint get_index(int u)const{ return L[u]; }\n\tpair<int,int> get_subtree(int\
    \ u)const{ return {L[u],R[u]}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Euler_tour_subtree.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Euler_tour_subtree.hpp
layout: document
redirect_from:
- /library/graph/Euler_tour_subtree.hpp
- /library/graph/Euler_tour_subtree.hpp.html
title: graph/Euler_tour_subtree.hpp
---
