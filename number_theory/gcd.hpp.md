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
  bundledCode: "#line 1 \"number_theory/gcd.hpp\"\ntemplate<class T> T gcd(const T&\
    \ a,const T& b){ return b==0?a:gcd(b,a%b); }\ntemplate<class T> T lcm(const T&\
    \ a,const T& b){ return a/gcd(a,b)*b; }\n\n/* \u62E1\u5F35 Euclid \u4E92\u9664\
    \u6CD5 */\n/*\n\t\u5F15\u6570\n\t\ta, b : \u6574\u6570\n\t\tx, y : \u8A08\u7B97\
    \u7D50\u679C ( \u65B9\u7A0B\u5F0F a*x + b*y = gcd(a, b) \u306E\u89E3 )\n\t\u623B\
    \u308A\u5024\n\t\tgcd(a, b)\n\t\u5236\u7D04\n\t\ta >= 0\n\t\tb >= 0\n\t\t(a, b)\
    \ != (0, 0)\n\t\u8A08\u7B97\u91CF\n\t\tO(log min{a, b})\n\t\u5099\u8003\n\t\t\
    a > 0 \u304B\u3064 b > 0 \u306E\u3068\u304D |x| <= b/gcd(a, b), |y| <= a/gcd(a,\
    \ b) \u304C\u4FDD\u969C\u3055\u308C\u308B.\n*/\n\ntemplate<class T>\nT xgcd(T\
    \ a,T b,T& x,T& y){\n\tif(b==0){ x=1; y=0; return a; }\n\tT g=xgcd(b,a%b,y,x);\n\
    \ty-=a/b*x;\n\treturn g;\n}\n"
  code: "template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b);\
    \ }\ntemplate<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }\n\n\
    /* \u62E1\u5F35 Euclid \u4E92\u9664\u6CD5 */\n/*\n\t\u5F15\u6570\n\t\ta, b : \u6574\
    \u6570\n\t\tx, y : \u8A08\u7B97\u7D50\u679C ( \u65B9\u7A0B\u5F0F a*x + b*y = gcd(a,\
    \ b) \u306E\u89E3 )\n\t\u623B\u308A\u5024\n\t\tgcd(a, b)\n\t\u5236\u7D04\n\t\t\
    a >= 0\n\t\tb >= 0\n\t\t(a, b) != (0, 0)\n\t\u8A08\u7B97\u91CF\n\t\tO(log min{a,\
    \ b})\n\t\u5099\u8003\n\t\ta > 0 \u304B\u3064 b > 0 \u306E\u3068\u304D |x| <=\
    \ b/gcd(a, b), |y| <= a/gcd(a, b) \u304C\u4FDD\u969C\u3055\u308C\u308B.\n*/\n\n\
    template<class T>\nT xgcd(T a,T b,T& x,T& y){\n\tif(b==0){ x=1; y=0; return a;\
    \ }\n\tT g=xgcd(b,a%b,y,x);\n\ty-=a/b*x;\n\treturn g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/gcd.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/gcd.hpp
layout: document
redirect_from:
- /library/number_theory/gcd.hpp
- /library/number_theory/gcd.hpp.html
title: number_theory/gcd.hpp
---
