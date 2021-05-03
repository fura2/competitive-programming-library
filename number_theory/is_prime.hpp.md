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
  bundledCode: "#line 1 \"number_theory/is_prime.hpp\"\n/* \u7D20\u6570\u5224\u5B9A\
    \ */\n/*\n\t\u8AAC\u660E\n\t\ta \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\
    \u5224\u5B9A\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\t\
    a \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\n\t\ta >= 0\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(sqrt(a))\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nbool is_prime(long\
    \ long a){\n\tif(a%2==0) return a==2;\n\tfor(long long i=3;i*i<=a;i+=2) if(a%i==0)\
    \ return false;\n\treturn a!=1;\n}\n"
  code: "/* \u7D20\u6570\u5224\u5B9A */\n/*\n\t\u8AAC\u660E\n\t\ta \u304C\u7D20\u6570\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\
    \n\t\u623B\u308A\u5024\n\t\ta \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\n\t\u5236\
    \u7D04\n\t\ta >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a))\n\t\u5099\u8003\n\t\t\
    \u306A\u3057\n*/\n\nbool is_prime(long long a){\n\tif(a%2==0) return a==2;\n\t\
    for(long long i=3;i*i<=a;i+=2) if(a%i==0) return false;\n\treturn a!=1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/is_prime.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/is_prime.hpp
layout: document
redirect_from:
- /library/number_theory/is_prime.hpp
- /library/number_theory/is_prime.hpp.html
title: number_theory/is_prime.hpp
---
