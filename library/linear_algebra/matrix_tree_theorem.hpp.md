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
  bundledCode: "#line 1 \"library/linear_algebra/matrix_tree_theorem.hpp\"\ntemplate<class\
    \ T>\nmint number_of_spanning_trees(matrix<T> A){\n\tassert(A.h()==A.w());\n\t\
    int n=A.h();\n\n\tmatrix<mint> Lap(n-1);\n\trep(u,n-1) rep(v,n-1) {\n\t\tLap[u][v]=-A[u][v];\n\
    \t\tif(u==v){\n\t\t\trep(w,n) Lap[u][u]+=A[u][w];\n\t\t}\n\t}\n\treturn det(Lap);\n\
    }\n"
  code: "template<class T>\nmint number_of_spanning_trees(matrix<T> A){\n\tassert(A.h()==A.w());\n\
    \tint n=A.h();\n\n\tmatrix<mint> Lap(n-1);\n\trep(u,n-1) rep(v,n-1) {\n\t\tLap[u][v]=-A[u][v];\n\
    \t\tif(u==v){\n\t\t\trep(w,n) Lap[u][u]+=A[u][w];\n\t\t}\n\t}\n\treturn det(Lap);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/linear_algebra/matrix_tree_theorem.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linear_algebra/matrix_tree_theorem.hpp
layout: document
redirect_from:
- /library/library/linear_algebra/matrix_tree_theorem.hpp
- /library/library/linear_algebra/matrix_tree_theorem.hpp.html
title: library/linear_algebra/matrix_tree_theorem.hpp
---
