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
  bundledCode: "#line 1 \"geometry/cover.hpp\"\n// \u70B9 p \u304C\u9589\u7DDA\u5206\
    \ S \u306B\u542B\u307E\u308C\u308B\u304B\n\nbool cover(const segment& S,const\
    \ point& p){\n\treturn sgn(cross(S.a-p,S.b-p))==0 && sgn(dot(S.a-p,S.b-p))<=0;\n\
    }\n\n// \u70B9 p \u304C\u9589\u5186\u76E4 C \u306B\u542B\u307E\u308C\u308B\u304B\
    \n\nbool cover(const circle& C,const point& p){\n\treturn sgn(abs(C.c-p)-C.r)<=0;\n\
    }\n\n/* \u591A\u89D2\u5F62\u3068\u70B9\u306E\u5305\u542B\u5224\u5B9A */\n/*\n\t\
    \u5F15\u6570\n\t\tF : \u591A\u89D2\u5F62\n\t\tp : \u70B9\n\t\u623B\u308A\u5024\
    \n\t\t\u542B\u3080\u306A\u3089 true, \u542B\u307E\u306A\u3044\u306A\u3089 false\n\
    \t\u5236\u7D04\n\t\tF \u306F\u5358\u7D14\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\t\u5099\
    \u8003\n\t\tF \u306F\u51F8\u3067\u306A\u304F\u3066\u3082\u3044\u3044.\n\t\t\u70B9\
    \u304C\u591A\u89D2\u5F62\u306E\u5883\u754C\u306B\u3042\u308B\u3068\u304D\u306F\
    \u542B\u3080\u3068\u5224\u5B9A\u3059\u308B.\n*/\n\nbool cover(const polygon& F,const\
    \ point& p){\n\tint n=F.size();\n\tbool res=false;\n\trep(i,n){\n\t\tpoint v1=F[i]-p,v2=F[(i+1)%n]-p;\n\
    \t\tif(v1.y>v2.y) swap(v1,v2);\n\t\t// y \u5EA7\u6A19\u304C\u5C0F\u3055\u3044\u65B9\
    \u306E\u7AEF\u70B9\u306F\u542B\u3081, \u5927\u304D\u3044\u65B9\u306E\u7AEF\u70B9\
    \u306F\u542B\u3081\u306A\u3044\n\t\tif(sgn(v1.y)<=0 && sgn(v2.y)==1 && sgn(cross(v1,v2))==1)\
    \ res=!res;\n\t\t// p \u304C\u8FBA (F[i], F[i+1]) \u4E0A\u306B\u3042\u308B\n\t\
    \tif(sgn(cross(v1,v2))==0 && sgn(dot(v1,v2))<=0) return true;\n\t}\n\treturn res;\n\
    }\n"
  code: "// \u70B9 p \u304C\u9589\u7DDA\u5206 S \u306B\u542B\u307E\u308C\u308B\u304B\
    \n\nbool cover(const segment& S,const point& p){\n\treturn sgn(cross(S.a-p,S.b-p))==0\
    \ && sgn(dot(S.a-p,S.b-p))<=0;\n}\n\n// \u70B9 p \u304C\u9589\u5186\u76E4 C \u306B\
    \u542B\u307E\u308C\u308B\u304B\n\nbool cover(const circle& C,const point& p){\n\
    \treturn sgn(abs(C.c-p)-C.r)<=0;\n}\n\n/* \u591A\u89D2\u5F62\u3068\u70B9\u306E\
    \u5305\u542B\u5224\u5B9A */\n/*\n\t\u5F15\u6570\n\t\tF : \u591A\u89D2\u5F62\n\t\
    \tp : \u70B9\n\t\u623B\u308A\u5024\n\t\t\u542B\u3080\u306A\u3089 true, \u542B\u307E\
    \u306A\u3044\u306A\u3089 false\n\t\u5236\u7D04\n\t\tF \u306F\u5358\u7D14\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\tF \u306F\u51F8\u3067\u306A\u304F\u3066\
    \u3082\u3044\u3044.\n\t\t\u70B9\u304C\u591A\u89D2\u5F62\u306E\u5883\u754C\u306B\
    \u3042\u308B\u3068\u304D\u306F\u542B\u3080\u3068\u5224\u5B9A\u3059\u308B.\n*/\n\
    \nbool cover(const polygon& F,const point& p){\n\tint n=F.size();\n\tbool res=false;\n\
    \trep(i,n){\n\t\tpoint v1=F[i]-p,v2=F[(i+1)%n]-p;\n\t\tif(v1.y>v2.y) swap(v1,v2);\n\
    \t\t// y \u5EA7\u6A19\u304C\u5C0F\u3055\u3044\u65B9\u306E\u7AEF\u70B9\u306F\u542B\
    \u3081, \u5927\u304D\u3044\u65B9\u306E\u7AEF\u70B9\u306F\u542B\u3081\u306A\u3044\
    \n\t\tif(sgn(v1.y)<=0 && sgn(v2.y)==1 && sgn(cross(v1,v2))==1) res=!res;\n\t\t\
    // p \u304C\u8FBA (F[i], F[i+1]) \u4E0A\u306B\u3042\u308B\n\t\tif(sgn(cross(v1,v2))==0\
    \ && sgn(dot(v1,v2))<=0) return true;\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/cover.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/cover.hpp
layout: document
redirect_from:
- /library/geometry/cover.hpp
- /library/geometry/cover.hpp.html
title: geometry/cover.hpp
---
