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
  bundledCode: "#line 1 \"library/number_theory/primitive_root.hpp\"\n/* \u539F\u59CB\
    \u6839 */\n/*\n\t\u8AAC\u660E\n\t\tp \u306E\u539F\u59CB\u6839\u3092\u4E00\u3064\
    \u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tp : \u6574\u6570\n\t\u623B\u308A\u5024\
    \n\t\tp \u306E\u4E00\u3064\u306E\u539F\u59CB\u6839\n\t\u5236\u7D04\n\t\tp \u306F\
    \u7D20\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(log^2(p))\n\t\u5099\u8003\n\t\tg \u304C\
    \ p \u306E\u539F\u59CB\u6839\u3067\u3042\u308B\u3068\u306F\n\t\t  {g,g^2,...,g^(p-1)}\
    \ = {1,2,...,p-1}\n\t\t\u3068\u306A\u308B\u3053\u3068\u3092\u3044\u3046.\n\t\t\
    \u7D20\u6570 p \u306E\u539F\u59CB\u6839\u306F {1,2,...,p-1} \u306E\u4E2D\u306B\
    \ \u03C6(p-1) \u500B\u5B58\u5728\u3059\u308B\u3053\u3068\u304C\u77E5\u3089\u308C\
    \u3066\u3044\u308B.\n\n\t\t\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306F\n\t\t  (1)\
    \ \u539F\u59CB\u6839\u306E\u5019\u88DC g \u3092 {1,2,..,p-1} \u304B\u3089\u4E00\
    \u69D8\u30E9\u30F3\u30C0\u30E0\u306B\u9078\u3076.\n\t\t  (2) g \u304C\u539F\u59CB\
    \u6839\u304B\u3069\u3046\u304B\u3092\u30C1\u30A7\u30C3\u30AF\u3057, \u539F\u59CB\
    \u6839\u306A\u3089\u7D42\u4E86. \u305D\u3046\u3067\u306A\u3051\u308C\u3070 (1)\
    \ \u306B\u623B\u308B.\n\t\t\u3068\u3044\u3046\u3082\u306E.\n\t\t\u30B5\u30F3\u30D7\
    \u30EA\u30F3\u30B0\u306E\u56DE\u6570\u306F\u5B9F\u9A13\u3059\u308B\u3068\u5E73\
    \u5747 2.8 \u56DE\u7A0B\u5EA6\u3067, p \u306E\u5927\u304D\u3055\u306B\u3088\u3089\
    \u306A\u3044\u3088\u3046\u306B\u898B\u3048\u308B.\n*/\n\nlint primitive_root(lint\
    \ p){\n\tvector<lint> pf;\n\tlint tmp=p-1;\n\tfor(lint q=2;q*q<=tmp;q++) if(tmp%q==0)\
    \ {\n\t\tpf.emplace_back(q);\n\t\tdo tmp/=q; while(tmp%q==0);\n\t}\n\tif(tmp>1)\
    \ pf.emplace_back(tmp);\n\n\twhile(1){\n\t\tlint g=xor64()%(p-1)+1;\n\t\tbool\
    \ ok=true;\n\t\trep(i,pf.size()) if(modpow(g,(p-1)/pf[i],p)==1) { ok=false; break;\
    \ }\n\t\tif(ok) return g;\n\t}\n}\n"
  code: "/* \u539F\u59CB\u6839 */\n/*\n\t\u8AAC\u660E\n\t\tp \u306E\u539F\u59CB\u6839\
    \u3092\u4E00\u3064\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tp : \u6574\u6570\n\t\
    \u623B\u308A\u5024\n\t\tp \u306E\u4E00\u3064\u306E\u539F\u59CB\u6839\n\t\u5236\
    \u7D04\n\t\tp \u306F\u7D20\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(log^2(p))\n\t\u5099\
    \u8003\n\t\tg \u304C p \u306E\u539F\u59CB\u6839\u3067\u3042\u308B\u3068\u306F\n\
    \t\t  {g,g^2,...,g^(p-1)} = {1,2,...,p-1}\n\t\t\u3068\u306A\u308B\u3053\u3068\u3092\
    \u3044\u3046.\n\t\t\u7D20\u6570 p \u306E\u539F\u59CB\u6839\u306F {1,2,...,p-1}\
    \ \u306E\u4E2D\u306B \u03C6(p-1) \u500B\u5B58\u5728\u3059\u308B\u3053\u3068\u304C\
    \u77E5\u3089\u308C\u3066\u3044\u308B.\n\n\t\t\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \u306F\n\t\t  (1) \u539F\u59CB\u6839\u306E\u5019\u88DC g \u3092 {1,2,..,p-1} \u304B\
    \u3089\u4E00\u69D8\u30E9\u30F3\u30C0\u30E0\u306B\u9078\u3076.\n\t\t  (2) g \u304C\
    \u539F\u59CB\u6839\u304B\u3069\u3046\u304B\u3092\u30C1\u30A7\u30C3\u30AF\u3057\
    , \u539F\u59CB\u6839\u306A\u3089\u7D42\u4E86. \u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 (1) \u306B\u623B\u308B.\n\t\t\u3068\u3044\u3046\u3082\u306E.\n\t\t\u30B5\
    \u30F3\u30D7\u30EA\u30F3\u30B0\u306E\u56DE\u6570\u306F\u5B9F\u9A13\u3059\u308B\
    \u3068\u5E73\u5747 2.8 \u56DE\u7A0B\u5EA6\u3067, p \u306E\u5927\u304D\u3055\u306B\
    \u3088\u3089\u306A\u3044\u3088\u3046\u306B\u898B\u3048\u308B.\n*/\n\nlint primitive_root(lint\
    \ p){\n\tvector<lint> pf;\n\tlint tmp=p-1;\n\tfor(lint q=2;q*q<=tmp;q++) if(tmp%q==0)\
    \ {\n\t\tpf.emplace_back(q);\n\t\tdo tmp/=q; while(tmp%q==0);\n\t}\n\tif(tmp>1)\
    \ pf.emplace_back(tmp);\n\n\twhile(1){\n\t\tlint g=xor64()%(p-1)+1;\n\t\tbool\
    \ ok=true;\n\t\trep(i,pf.size()) if(modpow(g,(p-1)/pf[i],p)==1) { ok=false; break;\
    \ }\n\t\tif(ok) return g;\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number_theory/primitive_root.hpp
  requiredBy: []
  timestamp: '2021-05-29 05:48:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number_theory/primitive_root.hpp
layout: document
redirect_from:
- /library/library/number_theory/primitive_root.hpp
- /library/library/number_theory/primitive_root.hpp.html
title: library/number_theory/primitive_root.hpp
---
