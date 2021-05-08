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
  bundledCode: "#line 1 \"library/geometry/dist.hpp\"\nReal dist(const point& a,const\
    \ point& b){ return abs(a-b); }\n\nReal dist(const line& L,const point& p){\n\t\
    return abs(cross(L.b-L.a,p-L.a))/abs(L.a-L.b);\n}\n\nReal dist(const segment &S,const\
    \ point &p){\n\tif(sgn(dot(S.b-S.a,p-S.a))<=0) return dist(p,S.a);\n\tif(sgn(dot(S.a-S.b,p-S.b))<=0)\
    \ return dist(p,S.b);\n\treturn abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);\n}\n"
  code: "Real dist(const point& a,const point& b){ return abs(a-b); }\n\nReal dist(const\
    \ line& L,const point& p){\n\treturn abs(cross(L.b-L.a,p-L.a))/abs(L.a-L.b);\n\
    }\n\nReal dist(const segment &S,const point &p){\n\tif(sgn(dot(S.b-S.a,p-S.a))<=0)\
    \ return dist(p,S.a);\n\tif(sgn(dot(S.a-S.b,p-S.b))<=0) return dist(p,S.b);\n\t\
    return abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/dist.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/dist.hpp
layout: document
redirect_from:
- /library/library/geometry/dist.hpp
- /library/library/geometry/dist.hpp.html
title: library/geometry/dist.hpp
---
