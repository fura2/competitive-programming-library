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
  bundledCode: "#line 1 \"library/geometry/get_intersect.hpp\"\n/* \u76F4\u7DDA\u3068\
    \u76F4\u7DDA\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tL1, L2 : \u76F4\u7DDA\
    \n\t\u623B\u308A\u5024\n\t\tL1 \u3068 L2 \u306E\u4EA4\u70B9\n\t\u5236\u7D04\n\t\
    \t\u4E8C\u76F4\u7DDA\u306F\u4EA4\u70B9\u3092\u6301\u3064\u3053\u3068 (\u5E73\u884C\
    \u3067\u306A\u3044 or L1 == L2).\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\t\u4EA4\u70B9\u304C\u7121\u9650\u500B\u3042\u308B (L1 == L2) \u3068\u304D\
    \u306F L1.a \u3092\u8FD4\u3059.\n*/\n\npoint get_intersect(const line& L1,const\
    \ line& L2){\n\tReal c1=cross(L1.b-L1.a,L2.b-L2.a);\n\tReal c2=cross(L1.b-L1.a,L1.b-L2.a);\n\
    \tif(sgn(c1)==0) return L1.a;\n\treturn L2.a+c2/c1*(L2.b-L2.a);\n}\n\n/* \u7DDA\
    \u5206\u3068\u7DDA\u5206\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tS1, S2\
    \ : \u7DDA\u5206\n\t\u623B\u308A\u5024\n\t\tS1 \u3068 S2 \u306E\u4EA4\u70B9\n\t\
    \u5236\u7D04\n\t\t\u4E8C\u7DDA\u5206\u306F\u4EA4\u70B9\u3092\u6301\u3064\u3053\
    \u3068 (intersect(segment, segment) \u3067\u5224\u5B9A\u3067\u304D\u308B).\n\t\
    \u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u4EA4\u70B9\u304C\u7121\u9650\
    \u500B\u3042\u308B\u3068\u304D\u306F, 4 \u3064\u306E\u7AEF\u70B9\u306E\u3046\u3061\
    \u3044\u305A\u308C\u304B\u306F\u4E8C\u7DDA\u5206\u306E\u5171\u901A\u90E8\u5206\
    \u306B\u542B\u307E\u308C\u308B\u306E\u3067,\n\t\t\u305D\u306E\u4EA4\u70B9 (\u306E\
    \u3046\u3061\u306E\u4E00\u3064) \u3092\u8FD4\u3059.\n*/\n\npoint get_intersect(const\
    \ segment& S1,const segment& S2){\n\tReal c1=cross(S1.b-S1.a,S2.b-S2.a);\n\tReal\
    \ c2=cross(S1.b-S1.a,S1.b-S2.a);\n\tif(sgn(c1)==0){\n\t\tif(cover(S1,S2.a)) return\
    \ S2.a;\n\t\tif(cover(S1,S2.b)) return S2.b;\n\t\tif(cover(S2,S1.a)) return S1.a;\n\
    \t\treturn S1.b;\n\t}\n\treturn S2.a+c2/c1*(S2.b-S2.a);\n}\n\n/* \u5186\u5468\u3068\
    \u76F4\u7DDA\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tC : \u5186\u5468\n\t\
    \tL : \u76F4\u7DDA\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u70B9\u306E\u96C6\u5408\n\
    \t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\tC \u306F\u5186\u76E4\u3067\u306F\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\
    !!\n*/\n\nvector<point> get_intersect(const circle& C,const line& L){\n\tpoint\
    \ h=proj(C.c,L);\n\tReal d=abs(C.c-h);\n\tif(sgn(d-C.r)==1){\n\t\treturn {};\n\
    \t}\n\tif(sgn(d-C.r)==0){\n\t\treturn {h};\n\t}\n\telse{\n\t\tpoint v=L.b-L.a;\n\
    \t\tv*=sqrt(C.r*C.r-d*d)/abs(v);\n\t\treturn {h+v,h-v};\n\t}\n}\n\n/* \u5186\u5468\
    \u3068\u5186\u5468\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tC1, C2 : \u5186\
    \u5468\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u70B9\u306E\u96C6\u5408\n\t\t\u305F\u3060\
    \u3057, \u4EA4\u70B9\u304C\u7121\u9650\u500B\u3042\u308B (C1==C2) \u3068\u304D\
    \u306F\u7A7A\u96C6\u5408\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n\t\u5099\u8003\n\t\tC1, C2 \u306F\u5186\u76E4\u3067\u306F\u306A\u3044\
    \u3053\u3068\u306B\u6CE8\u610F!!\n*/\n\nvector<point> get_intersect(const circle&\
    \ C1,const circle& C2){\n\tconst point& p1=C1.c;\n\tconst point& p2=C2.c;\n\t\
    const Real& r1=C1.r;\n\tconst Real& r2=C2.r;\n\n\tvector<point> res;\n\tif(p1==p2\
    \ && sgn(r1-r2)==0) return res;\n\n\tReal d=abs(p1-p2);\n\tif(sgn((r1+r2)-d)>=0\
    \ && sgn(d-abs(r1-r2))>=0){\n\t\tReal a=(r1*r1-r2*r2+d*d)/(2*d);\n\t\tReal h=sqrt(max(r1*r1-a*a,Real(0)));\n\
    \t\tpoint tmp1=p1+a/d*(p2-p1);\n\t\tpoint tmp2=h/d*(p2-p1);\n\t\tif(sgn(abs(tmp2))==0){\n\
    \t\t\tres.emplace_back(tmp1);\n\t\t}\n\t\telse{\n\t\t\tres.emplace_back(tmp1.x-tmp2.y,tmp1.y+tmp2.x);\n\
    \t\t\tres.emplace_back(tmp1.x+tmp2.y,tmp1.y-tmp2.x);\n\t\t}\n\t}\n\treturn res;\n\
    }\n"
  code: "/* \u76F4\u7DDA\u3068\u76F4\u7DDA\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\
    \n\t\tL1, L2 : \u76F4\u7DDA\n\t\u623B\u308A\u5024\n\t\tL1 \u3068 L2 \u306E\u4EA4\
    \u70B9\n\t\u5236\u7D04\n\t\t\u4E8C\u76F4\u7DDA\u306F\u4EA4\u70B9\u3092\u6301\u3064\
    \u3053\u3068 (\u5E73\u884C\u3067\u306A\u3044 or L1 == L2).\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n\t\u5099\u8003\n\t\t\u4EA4\u70B9\u304C\u7121\u9650\u500B\u3042\u308B\
    \ (L1 == L2) \u3068\u304D\u306F L1.a \u3092\u8FD4\u3059.\n*/\n\npoint get_intersect(const\
    \ line& L1,const line& L2){\n\tReal c1=cross(L1.b-L1.a,L2.b-L2.a);\n\tReal c2=cross(L1.b-L1.a,L1.b-L2.a);\n\
    \tif(sgn(c1)==0) return L1.a;\n\treturn L2.a+c2/c1*(L2.b-L2.a);\n}\n\n/* \u7DDA\
    \u5206\u3068\u7DDA\u5206\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tS1, S2\
    \ : \u7DDA\u5206\n\t\u623B\u308A\u5024\n\t\tS1 \u3068 S2 \u306E\u4EA4\u70B9\n\t\
    \u5236\u7D04\n\t\t\u4E8C\u7DDA\u5206\u306F\u4EA4\u70B9\u3092\u6301\u3064\u3053\
    \u3068 (intersect(segment, segment) \u3067\u5224\u5B9A\u3067\u304D\u308B).\n\t\
    \u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u4EA4\u70B9\u304C\u7121\u9650\
    \u500B\u3042\u308B\u3068\u304D\u306F, 4 \u3064\u306E\u7AEF\u70B9\u306E\u3046\u3061\
    \u3044\u305A\u308C\u304B\u306F\u4E8C\u7DDA\u5206\u306E\u5171\u901A\u90E8\u5206\
    \u306B\u542B\u307E\u308C\u308B\u306E\u3067,\n\t\t\u305D\u306E\u4EA4\u70B9 (\u306E\
    \u3046\u3061\u306E\u4E00\u3064) \u3092\u8FD4\u3059.\n*/\n\npoint get_intersect(const\
    \ segment& S1,const segment& S2){\n\tReal c1=cross(S1.b-S1.a,S2.b-S2.a);\n\tReal\
    \ c2=cross(S1.b-S1.a,S1.b-S2.a);\n\tif(sgn(c1)==0){\n\t\tif(cover(S1,S2.a)) return\
    \ S2.a;\n\t\tif(cover(S1,S2.b)) return S2.b;\n\t\tif(cover(S2,S1.a)) return S1.a;\n\
    \t\treturn S1.b;\n\t}\n\treturn S2.a+c2/c1*(S2.b-S2.a);\n}\n\n/* \u5186\u5468\u3068\
    \u76F4\u7DDA\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tC : \u5186\u5468\n\t\
    \tL : \u76F4\u7DDA\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u70B9\u306E\u96C6\u5408\n\
    \t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\tC \u306F\u5186\u76E4\u3067\u306F\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\
    !!\n*/\n\nvector<point> get_intersect(const circle& C,const line& L){\n\tpoint\
    \ h=proj(C.c,L);\n\tReal d=abs(C.c-h);\n\tif(sgn(d-C.r)==1){\n\t\treturn {};\n\
    \t}\n\tif(sgn(d-C.r)==0){\n\t\treturn {h};\n\t}\n\telse{\n\t\tpoint v=L.b-L.a;\n\
    \t\tv*=sqrt(C.r*C.r-d*d)/abs(v);\n\t\treturn {h+v,h-v};\n\t}\n}\n\n/* \u5186\u5468\
    \u3068\u5186\u5468\u306E\u4EA4\u70B9 */\n/*\n\t\u5F15\u6570\n\t\tC1, C2 : \u5186\
    \u5468\n\t\u623B\u308A\u5024\n\t\t\u4EA4\u70B9\u306E\u96C6\u5408\n\t\t\u305F\u3060\
    \u3057, \u4EA4\u70B9\u304C\u7121\u9650\u500B\u3042\u308B (C1==C2) \u3068\u304D\
    \u306F\u7A7A\u96C6\u5408\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n\t\u5099\u8003\n\t\tC1, C2 \u306F\u5186\u76E4\u3067\u306F\u306A\u3044\
    \u3053\u3068\u306B\u6CE8\u610F!!\n*/\n\nvector<point> get_intersect(const circle&\
    \ C1,const circle& C2){\n\tconst point& p1=C1.c;\n\tconst point& p2=C2.c;\n\t\
    const Real& r1=C1.r;\n\tconst Real& r2=C2.r;\n\n\tvector<point> res;\n\tif(p1==p2\
    \ && sgn(r1-r2)==0) return res;\n\n\tReal d=abs(p1-p2);\n\tif(sgn((r1+r2)-d)>=0\
    \ && sgn(d-abs(r1-r2))>=0){\n\t\tReal a=(r1*r1-r2*r2+d*d)/(2*d);\n\t\tReal h=sqrt(max(r1*r1-a*a,Real(0)));\n\
    \t\tpoint tmp1=p1+a/d*(p2-p1);\n\t\tpoint tmp2=h/d*(p2-p1);\n\t\tif(sgn(abs(tmp2))==0){\n\
    \t\t\tres.emplace_back(tmp1);\n\t\t}\n\t\telse{\n\t\t\tres.emplace_back(tmp1.x-tmp2.y,tmp1.y+tmp2.x);\n\
    \t\t\tres.emplace_back(tmp1.x+tmp2.y,tmp1.y-tmp2.x);\n\t\t}\n\t}\n\treturn res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/get_intersect.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/get_intersect.hpp
layout: document
redirect_from:
- /library/library/geometry/get_intersect.hpp
- /library/library/geometry/get_intersect.hpp.html
title: library/geometry/get_intersect.hpp
---
