---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants
  bundledCode: "#line 1 \"library/number_theory/Miller-Rabin.hpp\"\n/* \u7D20\u6570\
    \u5224\u5B9A (Miller-Rabin) */\n/*\n\t\u8AAC\u660E\n\t\tn \u304C\u7D20\u6570\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B Miller-Rabin \u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0 (deterministic variant)\n\t\thttps://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants\n\
    \t\u5F15\u6570\n\t\tn : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\tn \u304C\u7D20\
    \u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\n\t\t0 <= n < 2^63\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log n)\n*/\n\nbool Miller_Rabin(lint n){\n\tif(n<=1)   return false;\n\
    \tif(n%2==0) return n==2;\n\n\tauto modpow=[](lint a,lint k,lint m){\n\t\tlint\
    \ r=1;\n\t\tfor(lint x=a;k>0;k>>=1){\n\t\t\tif(k&1) r=__int128(r)*x%m;\n\t\t\t\
    x=__int128(x)*x%m;\n\t\t}\n\t\treturn r;\n\t};\n\n\tint r=0;\n\tlint d=n-1;\n\t\
    while(d%2==0) r++, d>>=1;\n\n\tfor(lint a:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \t\tif(a>=n-2) break;\n\t\tlint x=modpow(a,d,n);\n\t\tif(x==1 || x==n-1) continue;\n\
    \t\tbool b=false;\n\t\trep(_,r-1){\n\t\t\tx=__int128(x)*x%n;\n\t\t\tif(x==n-1){\n\
    \t\t\t\tb=true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(!b) return false;\n\t\
    }\n\treturn true;\n}\n"
  code: "/* \u7D20\u6570\u5224\u5B9A (Miller-Rabin) */\n/*\n\t\u8AAC\u660E\n\t\tn\
    \ \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B Miller-Rabin\
    \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (deterministic variant)\n\t\thttps://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants\n\
    \t\u5F15\u6570\n\t\tn : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\tn \u304C\u7D20\
    \u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\n\t\t0 <= n < 2^63\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log n)\n*/\n\nbool Miller_Rabin(lint n){\n\tif(n<=1)   return false;\n\
    \tif(n%2==0) return n==2;\n\n\tauto modpow=[](lint a,lint k,lint m){\n\t\tlint\
    \ r=1;\n\t\tfor(lint x=a;k>0;k>>=1){\n\t\t\tif(k&1) r=__int128(r)*x%m;\n\t\t\t\
    x=__int128(x)*x%m;\n\t\t}\n\t\treturn r;\n\t};\n\n\tint r=0;\n\tlint d=n-1;\n\t\
    while(d%2==0) r++, d>>=1;\n\n\tfor(lint a:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \t\tif(a>=n-2) break;\n\t\tlint x=modpow(a,d,n);\n\t\tif(x==1 || x==n-1) continue;\n\
    \t\tbool b=false;\n\t\trep(_,r-1){\n\t\t\tx=__int128(x)*x%n;\n\t\t\tif(x==n-1){\n\
    \t\t\t\tb=true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(!b) return false;\n\t\
    }\n\treturn true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number_theory/Miller-Rabin.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number_theory/Miller-Rabin.hpp
layout: document
redirect_from:
- /library/library/number_theory/Miller-Rabin.hpp
- /library/library/number_theory/Miller-Rabin.hpp.html
title: library/number_theory/Miller-Rabin.hpp
---
