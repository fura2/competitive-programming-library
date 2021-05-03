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
  bundledCode: "#line 1 \"mint/Stirling_second.hpp\"\n/*\n\t\u7B2C 2 \u7A2E Stirling\
    \ \u6570 S(n, k)\n\t\tn \u500B\u306E\u533A\u5225\u3067\u304D\u308B\u30DC\u30FC\
    \u30EB\u3092 k \u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u3051\u308B\u65B9\
    \u6CD5\u306E\u6570\n*/\n\nmint Stirling_second(int n,int k){\n\tmint res=0;\n\t\
    rep(i,k+1) res+=(i%2==0?1:-1)*choose(k,i)*pow(mint(k-i),n);\n\treturn res/fact(k);\n\
    }\n"
  code: "/*\n\t\u7B2C 2 \u7A2E Stirling \u6570 S(n, k)\n\t\tn \u500B\u306E\u533A\u5225\
    \u3067\u304D\u308B\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u30B0\u30EB\u30FC\u30D7\
    \u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570\n*/\n\nmint Stirling_second(int\
    \ n,int k){\n\tmint res=0;\n\trep(i,k+1) res+=(i%2==0?1:-1)*choose(k,i)*pow(mint(k-i),n);\n\
    \treturn res/fact(k);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mint/Stirling_second.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mint/Stirling_second.hpp
layout: document
redirect_from:
- /library/mint/Stirling_second.hpp
- /library/mint/Stirling_second.hpp.html
title: mint/Stirling_second.hpp
---
