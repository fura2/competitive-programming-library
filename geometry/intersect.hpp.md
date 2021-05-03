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
  bundledCode: "#line 1 \"geometry/intersect.hpp\"\n/* \u76F4\u7DDA\u3068\u76F4\u7DDA\
    \u306E\u4EA4\u5DEE\u5224\u5B9A */\n/*\n\t\u8AAC\u660E\n\t\t\u76F4\u7DDA\u3068\u76F4\
    \u7DDA\u304C\u4EA4\u308F\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n\t\u5F15\u6570\n\t\tL1, L2 : \u76F4\u7DDA\n\t\u623B\u308A\u5024\n\t\t\u4EA4\
    \u308F\u308B\u306A\u3089 true, \u4EA4\u308F\u3089\u306A\u3044\u306A\u3089 false\n\
    \t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\t\u30B3\u30FC\u30C9\u306F\n\t\t\tL1 \u3068 L2 \u304C\u5E73\u884C\u3067\u306A\
    \u3044 or L1 == L2\n\t\t\u3068\u3044\u3046\u610F\u5473.\n\t\t\u7279\u306B, L1\
    \ == L2 \u306E\u3068\u304D\u306F\u4EA4\u308F\u308B\u3068\u5224\u5B9A\u3059\u308B\
    \u3053\u3068\u306B\u6CE8\u610F.\n*/\n\nbool intersect(const line& L1,const line&\
    \ L2){\n\treturn sgn(cross(L1.b-L1.a,L2.b-L2.a))!=0\n\t\t|| sgn(cross(L1.b-L1.a,L2.a-L1.a))==0;\n\
    }\n\n/* \u7DDA\u5206\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A */\n/*\n\t\
    \u8AAC\u660E\n\t\t\u7DDA\u5206\u3068\u7DDA\u5206\u304C\u4EA4\u308F\u308B\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n\t\u5F15\u6570\n\t\tS1, S2 :\
    \ \u7DDA\u5206\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u308F\u308B\u306A\u3089 true,\
    \ \u4EA4\u308F\u3089\u306A\u3044\u306A\u3089 false\n\t\u5236\u7D04\n\t\t\u306A\
    \u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\tbounding box \u306B\
    \u3088\u308B\u30E9\u30D5\u30C1\u30A7\u30C3\u30AF\u306F\u5FC5\u8981 (ccw \u306B\
    \u3088\u308B\u5224\u5B9A\u3060\u3051\u3060\u3068, \u4E8C\u7DDA\u5206\u304C\u540C\
    \u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u3068\u304D\u306B\u9593\u9055\u3046\
    ).\n*/\n\nbool intersect(const segment& S1,const segment& S2){\n\tif(sgn(min(S2.a.x,S2.b.x)-max(S1.a.x,S1.b.x))==1\n\
    \t|| sgn(min(S2.a.y,S2.b.y)-max(S1.a.y,S1.b.y))==1\n\t|| sgn(min(S1.a.x,S1.b.x)-max(S2.a.x,S2.b.x))==1\n\
    \t|| sgn(min(S1.a.y,S1.b.y)-max(S2.a.y,S2.b.y))==1){\n\t\treturn false;\n\t}\n\
    \treturn ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0\n\t\t&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;\n\
    }\n\n/* \u5186\u5468\u306E\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A */\n/*\n\t\
    \u5F15\u6570\n\t\tC : \u5186\u5468\n\t\tL : \u76F4\u7DDA\n\t\u623B\u308A\u5024\
    \n\t\t\u4EA4\u70B9\u306E\u500B\u6570\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\tC \u306F\u5186\u76E4\u3067\u306F\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F!!\n*/\n\nint intersect(const circle& C,const\
    \ line& L){\n\tpoint h=proj(C.c,L);\n\tReal d=abs(C.c-h);\n\tif(sgn(d-C.r)==1)\
    \ return 0;\n\tif(sgn(d-C.r)==0) return 1;\n\treturn 2;\n}\n"
  code: "/* \u76F4\u7DDA\u3068\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A */\n/*\n\t\
    \u8AAC\u660E\n\t\t\u76F4\u7DDA\u3068\u76F4\u7DDA\u304C\u4EA4\u308F\u308B\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n\t\u5F15\u6570\n\t\tL1, L2 :\
    \ \u76F4\u7DDA\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u308F\u308B\u306A\u3089 true,\
    \ \u4EA4\u308F\u3089\u306A\u3044\u306A\u3089 false\n\t\u5236\u7D04\n\t\t\u306A\
    \u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u30B3\u30FC\u30C9\
    \u306F\n\t\t\tL1 \u3068 L2 \u304C\u5E73\u884C\u3067\u306A\u3044 or L1 == L2\n\t\
    \t\u3068\u3044\u3046\u610F\u5473.\n\t\t\u7279\u306B, L1 == L2 \u306E\u3068\u304D\
    \u306F\u4EA4\u308F\u308B\u3068\u5224\u5B9A\u3059\u308B\u3053\u3068\u306B\u6CE8\
    \u610F.\n*/\n\nbool intersect(const line& L1,const line& L2){\n\treturn sgn(cross(L1.b-L1.a,L2.b-L2.a))!=0\n\
    \t\t|| sgn(cross(L1.b-L1.a,L2.a-L1.a))==0;\n}\n\n/* \u7DDA\u5206\u3068\u7DDA\u5206\
    \u306E\u4EA4\u5DEE\u5224\u5B9A */\n/*\n\t\u8AAC\u660E\n\t\t\u7DDA\u5206\u3068\u7DDA\
    \u5206\u304C\u4EA4\u308F\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n\t\u5F15\u6570\n\t\tS1, S2 : \u7DDA\u5206\n\t\u623B\u308A\u5024\n\t\t\u4EA4\
    \u308F\u308B\u306A\u3089 true, \u4EA4\u308F\u3089\u306A\u3044\u306A\u3089 false\n\
    \t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\tbounding box \u306B\u3088\u308B\u30E9\u30D5\u30C1\u30A7\u30C3\u30AF\u306F\
    \u5FC5\u8981 (ccw \u306B\u3088\u308B\u5224\u5B9A\u3060\u3051\u3060\u3068, \u4E8C\
    \u7DDA\u5206\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u3068\u304D\
    \u306B\u9593\u9055\u3046).\n*/\n\nbool intersect(const segment& S1,const segment&\
    \ S2){\n\tif(sgn(min(S2.a.x,S2.b.x)-max(S1.a.x,S1.b.x))==1\n\t|| sgn(min(S2.a.y,S2.b.y)-max(S1.a.y,S1.b.y))==1\n\
    \t|| sgn(min(S1.a.x,S1.b.x)-max(S2.a.x,S2.b.x))==1\n\t|| sgn(min(S1.a.y,S1.b.y)-max(S2.a.y,S2.b.y))==1){\n\
    \t\treturn false;\n\t}\n\treturn ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0\n\t\
    \t&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;\n}\n\n/* \u5186\u5468\u306E\u76F4\
    \u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A */\n/*\n\t\u5F15\u6570\n\t\tC : \u5186\u5468\
    \n\t\tL : \u76F4\u7DDA\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u70B9\u306E\u500B\u6570\
    \n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\tC \u306F\u5186\u76E4\u3067\u306F\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\
    !!\n*/\n\nint intersect(const circle& C,const line& L){\n\tpoint h=proj(C.c,L);\n\
    \tReal d=abs(C.c-h);\n\tif(sgn(d-C.r)==1) return 0;\n\tif(sgn(d-C.r)==0) return\
    \ 1;\n\treturn 2;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/intersect.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/intersect.hpp
layout: document
redirect_from:
- /library/geometry/intersect.hpp
- /library/geometry/intersect.hpp.html
title: geometry/intersect.hpp
---
