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
  bundledCode: "#line 1 \"mint/Montmort.hpp\"\n/* Montmort \u6570 */\n/*\n\t\u5F15\
    \u6570\n\t\tn : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\t!n\n\t\u5236\u7D04\n\t\
    \tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\t!n = (\u9577\u3055\
    \ n \u306E\u652A\u4E71\u9806\u5217 (\u4E0D\u52D5\u70B9\u3092\u6301\u305F\u306A\
    \u3044\u9806\u5217) \u306E\u500B\u6570)\n\t\t   = (n-1)*(!(n-1) + !(n-2))\n\t\t\
    \   = n!*(1/(0!) - 1/(1!) + 1/(2!) - 1/(3!) + ... + (-1)^n/(n!)).\n*/\n\nmint\
    \ Montmort(int n){\n\tstatic vector<mint> memo{1,0};\n\tif(memo.size()<=n){\n\t\
    \tint k=memo.size();\n\t\tmemo.resize(n+1);\n\t\tfor(;k<=n;k++) memo[k]=(memo[k-1]+memo[k-2])*(k-1);\n\
    \t}\n\treturn memo[n];\n}\n"
  code: "/* Montmort \u6570 */\n/*\n\t\u5F15\u6570\n\t\tn : \u6574\u6570\n\t\u623B\
    \u308A\u5024\n\t\t!n\n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\
    \t\u5099\u8003\n\t\t!n = (\u9577\u3055 n \u306E\u652A\u4E71\u9806\u5217 (\u4E0D\
    \u52D5\u70B9\u3092\u6301\u305F\u306A\u3044\u9806\u5217) \u306E\u500B\u6570)\n\t\
    \t   = (n-1)*(!(n-1) + !(n-2))\n\t\t   = n!*(1/(0!) - 1/(1!) + 1/(2!) - 1/(3!)\
    \ + ... + (-1)^n/(n!)).\n*/\n\nmint Montmort(int n){\n\tstatic vector<mint> memo{1,0};\n\
    \tif(memo.size()<=n){\n\t\tint k=memo.size();\n\t\tmemo.resize(n+1);\n\t\tfor(;k<=n;k++)\
    \ memo[k]=(memo[k-1]+memo[k-2])*(k-1);\n\t}\n\treturn memo[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mint/Montmort.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mint/Montmort.hpp
layout: document
redirect_from:
- /library/mint/Montmort.hpp
- /library/mint/Montmort.hpp.html
title: mint/Montmort.hpp
---
