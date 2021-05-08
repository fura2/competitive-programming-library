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
  bundledCode: "#line 1 \"library/linear_algebra/Hadamard_matrix.hpp\"\n/*\n\t2^n\
    \ \u6B21\u306E Hadamard \u884C\u5217\n\t\t\u5404\u8981\u7D20\u304C 1 \u304B -1\
    \ \u306E\u6B63\u65B9\u884C\u5217\u3067\u3042\u3063\u3066\u6B21\u3092\u307F\u305F\
    \u3059\u3082\u306E\n\t\t- \u3069\u306E\u4E8C\u3064\u306E\u884C\u3082\u76F4\u4EA4\
    \u3059\u308B\n\t\t- \u3069\u306E\u4E8C\u3064\u306E\u5217\u3082\u76F4\u4EA4\u3059\
    \u308B\n\t\u8A08\u7B97\u91CF : O(4^N)\n*/\n\nmatrix<int> Hadamard(int n){\n\t\
    matrix<int> H(1<<n);\n\tH[0][0]=1;\n\trep(k,n){\n\t\tint d=1<<k;\n\t\trep(i,d)\
    \ rep(j,d) {\n\t\t\tH[i][j+d]=H[i][j];\n\t\t\tH[i+d][j]=H[i][j];\n\t\t\tH[i+d][j+d]=-H[i][j];\n\
    \t\t}\n\t}\n\treturn H;\n}\n"
  code: "/*\n\t2^n \u6B21\u306E Hadamard \u884C\u5217\n\t\t\u5404\u8981\u7D20\u304C\
    \ 1 \u304B -1 \u306E\u6B63\u65B9\u884C\u5217\u3067\u3042\u3063\u3066\u6B21\u3092\
    \u307F\u305F\u3059\u3082\u306E\n\t\t- \u3069\u306E\u4E8C\u3064\u306E\u884C\u3082\
    \u76F4\u4EA4\u3059\u308B\n\t\t- \u3069\u306E\u4E8C\u3064\u306E\u5217\u3082\u76F4\
    \u4EA4\u3059\u308B\n\t\u8A08\u7B97\u91CF : O(4^N)\n*/\n\nmatrix<int> Hadamard(int\
    \ n){\n\tmatrix<int> H(1<<n);\n\tH[0][0]=1;\n\trep(k,n){\n\t\tint d=1<<k;\n\t\t\
    rep(i,d) rep(j,d) {\n\t\t\tH[i][j+d]=H[i][j];\n\t\t\tH[i+d][j]=H[i][j];\n\t\t\t\
    H[i+d][j+d]=-H[i][j];\n\t\t}\n\t}\n\treturn H;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/linear_algebra/Hadamard_matrix.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linear_algebra/Hadamard_matrix.hpp
layout: document
redirect_from:
- /library/library/linear_algebra/Hadamard_matrix.hpp
- /library/library/linear_algebra/Hadamard_matrix.hpp.html
title: library/linear_algebra/Hadamard_matrix.hpp
---
