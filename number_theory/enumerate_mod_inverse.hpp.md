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
  bundledCode: "#line 1 \"number_theory/enumerate_mod_inverse.hpp\"\n/* mod m \u3067\
    \u306E\u9006\u5143\u5217\u6319 */\n/*\n\t\u8AAC\u660E\n\t\t1, 2, ..., n \u306E\
    \ mod m \u3067\u306E\u9006\u5143\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\t\
    n, m : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\t\u9577\u3055 n+1 \u306E\u914D\u5217\
    \ inv \u304C\u8FD4\u308B\n\t\ti>0 \u306B\u5BFE\u3057\u3066, inv[i] = i^{-1} \u3067\
    \u3042\u308B\n\t\u5236\u7D04\n\t\t0 <= n < m\n\t\tm >= 1 : \u7D20\u6570\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nvector<long long>\
    \ enumerate_mod_inverse(int n,int m){\n\tvector<long long> inv(n+1);\n\tif(n>0)\
    \ inv[1]=1;\n\tfor(int i=2;i<=n;i++){\n\t\tlong long x=(m+i-1)/i;\n\t\tinv[i]=x*inv[i*x%m]%m;\n\
    \t}\n\treturn inv;\n}\n"
  code: "/* mod m \u3067\u306E\u9006\u5143\u5217\u6319 */\n/*\n\t\u8AAC\u660E\n\t\t\
    1, 2, ..., n \u306E mod m \u3067\u306E\u9006\u5143\u3092\u6C42\u3081\u308B\n\t\
    \u5F15\u6570\n\t\tn, m : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\t\u9577\u3055\
    \ n+1 \u306E\u914D\u5217 inv \u304C\u8FD4\u308B\n\t\ti>0 \u306B\u5BFE\u3057\u3066\
    , inv[i] = i^{-1} \u3067\u3042\u308B\n\t\u5236\u7D04\n\t\t0 <= n < m\n\t\tm >=\
    \ 1 : \u7D20\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\t\u306A\
    \u3057\n*/\n\nvector<long long> enumerate_mod_inverse(int n,int m){\n\tvector<long\
    \ long> inv(n+1);\n\tif(n>0) inv[1]=1;\n\tfor(int i=2;i<=n;i++){\n\t\tlong long\
    \ x=(m+i-1)/i;\n\t\tinv[i]=x*inv[i*x%m]%m;\n\t}\n\treturn inv;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/enumerate_mod_inverse.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/enumerate_mod_inverse.hpp
layout: document
redirect_from:
- /library/number_theory/enumerate_mod_inverse.hpp
- /library/number_theory/enumerate_mod_inverse.hpp.html
title: number_theory/enumerate_mod_inverse.hpp
---
