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
  bundledCode: "#line 1 \"number_theory/crt.hpp\"\n/* \u9023\u7ACB\u7DDA\u5F62\u5408\
    \u540C\u5F0F */\n/*\n\t\u8AAC\u660E\n\t\ta_1 * x = b_1 (mod m_1)\n\t\ta_2 * x\
    \ = b_2 (mod m_2)\n\t\t\t\t:\n\t\ta_n * x = b_n (mod m_n)\n\t\t\u3092\u89E3\u304F\
    \n\t\u623B\u308A\u5024\n\t\t\u89E3\u306F (\u5B58\u5728\u3059\u308B\u306A\u3089\
    ) \u3042\u308B\u6574\u6570 x, M (0 \u2266 x < M, M > 0) \u3092\u7528\u3044\u3066\
    \ x + k * M (k \u306F\u4EFB\u610F\u306E\u6574\u6570) \u3068\u8868\u3055\u308C\u308B\
    \n\t\t\u3053\u306E x \u3068 M \u306E\u30DA\u30A2\u3092\u8FD4\u3059\n\t\t\u89E3\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F (-1, -1) \u3092\u8FD4\u3059\
    \n\t\u5236\u7D04\n\t\tm_i > 0\n\t\u5099\u8003\n\t\t\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\u306F\u6B21\u306E\u3068\u304A\u308A\n\t\t\ta_i \u306E\u9006\u5143\u3092\
    \u4E21\u8FBA\u306B\u304B\u3051\u3066 a_i = 1 \u306E\u554F\u984C\u306B\u5E30\u7740\
    \u3055\u305B\u308B\n\t\t\t\t\u9006\u5143\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F\u4F8B\u5916\u51E6\u7406\u3059\u308B\n\t\t\t\u3042\u3068\u306F, \u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306B\
    \u3057\u305F\u304C\u3063\u3066 x \u3068 M \u3092\u6C42\u3081\u308B\n\t\t\t\tM\
    \ \u306F a_i = 1 \u306B\u5E30\u7740\u3057\u305F\u3042\u3068\u306E\u7CFB\u306B\u304A\
    \u3051\u308B LCM(m_1, m_2, ..., m_n) \u306B\u7B49\u3057\u3044\n\t\t\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u3084\u3059\u3044\u306E\u3067\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\n*/\n\npair<long long,long long> Chinese_remainder(vector<long\
    \ long> a,vector<long long> b,vector<long long> m){\n\tint n=a.size();\n\tassert(n==b.size()\
    \ && n==m.size());\n\n\tlong long x=0,M=1;\n\trep(i,n){\n\t\ta[i]%=m[i]; if(a[i]<0)\
    \ a[i]+=m[i];\n\t\tb[i]%=m[i]; if(b[i]<0) b[i]+=m[i];\n\t\tif(a[i]==0){\n\t\t\t\
    if(b[i]!=0) return {-1,-1};\n\t\t\tcontinue;\n\t\t}\n\n\t\tlong long p,q,g;\n\t\
    \tg=xgcd(a[i],m[i],p,q);\n\t\tif(b[i]%g!=0) return {-1,-1};\n\t\tm[i]/=g;\n\t\t\
    b[i]=(b[i]/g)*p%m[i];\n\n\t\tg=xgcd(M,m[i],p,q);\n\t\tif((b[i]-x)%g!=0) return\
    \ {-1,-1};\n\t\tx+=M*((b[i]-x)/g*p%(m[i]/g));\n\t\tM*=m[i]/g;\n\t}\n\tx%=M; if(x<0)\
    \ x+=M;\n\treturn {x,M};\n}\n"
  code: "/* \u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F */\n/*\n\t\u8AAC\u660E\n\t\t\
    a_1 * x = b_1 (mod m_1)\n\t\ta_2 * x = b_2 (mod m_2)\n\t\t\t\t:\n\t\ta_n * x =\
    \ b_n (mod m_n)\n\t\t\u3092\u89E3\u304F\n\t\u623B\u308A\u5024\n\t\t\u89E3\u306F\
    \ (\u5B58\u5728\u3059\u308B\u306A\u3089) \u3042\u308B\u6574\u6570 x, M (0 \u2266\
    \ x < M, M > 0) \u3092\u7528\u3044\u3066 x + k * M (k \u306F\u4EFB\u610F\u306E\
    \u6574\u6570) \u3068\u8868\u3055\u308C\u308B\n\t\t\u3053\u306E x \u3068 M \u306E\
    \u30DA\u30A2\u3092\u8FD4\u3059\n\t\t\u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F (-1, -1) \u3092\u8FD4\u3059\n\t\u5236\u7D04\n\t\tm_i > 0\n\t\
    \u5099\u8003\n\t\t\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306F\u6B21\u306E\u3068\
    \u304A\u308A\n\t\t\ta_i \u306E\u9006\u5143\u3092\u4E21\u8FBA\u306B\u304B\u3051\
    \u3066 a_i = 1 \u306E\u554F\u984C\u306B\u5E30\u7740\u3055\u305B\u308B\n\t\t\t\t\
    \u9006\u5143\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u4F8B\u5916\
    \u51E6\u7406\u3059\u308B\n\t\t\t\u3042\u3068\u306F, \u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306B\u3057\u305F\u304C\u3063\
    \u3066 x \u3068 M \u3092\u6C42\u3081\u308B\n\t\t\t\tM \u306F a_i = 1 \u306B\u5E30\
    \u7740\u3057\u305F\u3042\u3068\u306E\u7CFB\u306B\u304A\u3051\u308B LCM(m_1, m_2,\
    \ ..., m_n) \u306B\u7B49\u3057\u3044\n\t\t\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u3084\u3059\u3044\u306E\u3067\u6CE8\u610F\u3059\u308B\u3053\u3068\
    \n*/\n\npair<long long,long long> Chinese_remainder(vector<long long> a,vector<long\
    \ long> b,vector<long long> m){\n\tint n=a.size();\n\tassert(n==b.size() && n==m.size());\n\
    \n\tlong long x=0,M=1;\n\trep(i,n){\n\t\ta[i]%=m[i]; if(a[i]<0) a[i]+=m[i];\n\t\
    \tb[i]%=m[i]; if(b[i]<0) b[i]+=m[i];\n\t\tif(a[i]==0){\n\t\t\tif(b[i]!=0) return\
    \ {-1,-1};\n\t\t\tcontinue;\n\t\t}\n\n\t\tlong long p,q,g;\n\t\tg=xgcd(a[i],m[i],p,q);\n\
    \t\tif(b[i]%g!=0) return {-1,-1};\n\t\tm[i]/=g;\n\t\tb[i]=(b[i]/g)*p%m[i];\n\n\
    \t\tg=xgcd(M,m[i],p,q);\n\t\tif((b[i]-x)%g!=0) return {-1,-1};\n\t\tx+=M*((b[i]-x)/g*p%(m[i]/g));\n\
    \t\tM*=m[i]/g;\n\t}\n\tx%=M; if(x<0) x+=M;\n\treturn {x,M};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/crt.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/crt.hpp
layout: document
redirect_from:
- /library/number_theory/crt.hpp
- /library/number_theory/crt.hpp.html
title: number_theory/crt.hpp
---
