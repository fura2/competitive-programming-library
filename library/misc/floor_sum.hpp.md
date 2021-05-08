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
  bundledCode: "#line 1 \"library/misc/floor_sum.hpp\"\n/*\n\t\u03A3_{x=0}^{n-1} floor((ax+b)/m)\
    \ \u3092\u6C42\u3081\u308B\n\t\u5236\u7D04\n\t\t0 <= n < 10^9\n\t\t1 <= m <= 10^9\n\
    \t\t0 <= a,b < m\n\t\u8A08\u7B97\u91CF\n\t\tO(log min{a, m})\n\t\u5099\u8003\n\
    \t\ta >= m \u3084 b >= m \u306E\u3068\u304D\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3055\u3048\u3057\u306A\u3051\u308C\u3070\u6B63\u3057\u304F\u52D5\
    \u304F.\n\t\ta < 0 \u3084 b < 0 \u306B\u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\
    \u3044\u304C, floor((ax+b)/m) \u306E\u7B26\u53F7\u3067\u5834\u5408\u5206\u3051\
    \u3057\u3066\n\t\t\u9069\u5207\u306B\u5909\u6570\u5909\u63DB\u3059\u308B\u3053\
    \u3068\u3067 a, b >= 0 \u306E\u30B1\u30FC\u30B9\u306B\u5E30\u7740\u3067\u304D\u308B\
    .\n*/\n\nlong long floor_sum(long long n,long long m,long long a,long long b){\n\
    \tlong long res=0;\n\tif(a>=m){\n\t\tres+=n*(n-1)/2*(a/m);\n\t\ta%=m;\n\t}\n\t\
    if(b>=m){\n\t\tres+=n*(b/m);\n\t\tb%=m;\n\t}\n\n\tlong long y_max=(a*(n-1)+b)/m;\n\
    \tif(y_max==0) return res;\n\treturn res+y_max+floor_sum(y_max,a,m,(a*(n-1)+b)-m*y_max);\n\
    }\n"
  code: "/*\n\t\u03A3_{x=0}^{n-1} floor((ax+b)/m) \u3092\u6C42\u3081\u308B\n\t\u5236\
    \u7D04\n\t\t0 <= n < 10^9\n\t\t1 <= m <= 10^9\n\t\t0 <= a,b < m\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log min{a, m})\n\t\u5099\u8003\n\t\ta >= m \u3084 b >= m \u306E\u3068\
    \u304D\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3055\u3048\u3057\u306A\
    \u3051\u308C\u3070\u6B63\u3057\u304F\u52D5\u304F.\n\t\ta < 0 \u3084 b < 0 \u306B\
    \u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\u304C, floor((ax+b)/m) \u306E\
    \u7B26\u53F7\u3067\u5834\u5408\u5206\u3051\u3057\u3066\n\t\t\u9069\u5207\u306B\
    \u5909\u6570\u5909\u63DB\u3059\u308B\u3053\u3068\u3067 a, b >= 0 \u306E\u30B1\u30FC\
    \u30B9\u306B\u5E30\u7740\u3067\u304D\u308B.\n*/\n\nlong long floor_sum(long long\
    \ n,long long m,long long a,long long b){\n\tlong long res=0;\n\tif(a>=m){\n\t\
    \tres+=n*(n-1)/2*(a/m);\n\t\ta%=m;\n\t}\n\tif(b>=m){\n\t\tres+=n*(b/m);\n\t\t\
    b%=m;\n\t}\n\n\tlong long y_max=(a*(n-1)+b)/m;\n\tif(y_max==0) return res;\n\t\
    return res+y_max+floor_sum(y_max,a,m,(a*(n-1)+b)-m*y_max);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/floor_sum.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/floor_sum.hpp
layout: document
redirect_from:
- /library/library/misc/floor_sum.hpp
- /library/library/misc/floor_sum.hpp.html
title: library/misc/floor_sum.hpp
---
