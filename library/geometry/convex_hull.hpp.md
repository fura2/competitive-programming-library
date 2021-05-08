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
  bundledCode: "#line 1 \"library/geometry/convex_hull.hpp\"\n/* \u51F8\u5305 */\n\
    /*\n\t\u8AAC\u660E\n\t\t\u70B9\u96C6\u5408\u306E\u51F8\u5305\u3092\u6C42\u3081\
    \u308B\n\t\u5F15\u6570\n\t\tP : \u70B9\u96C6\u5408\n\t\u623B\u308A\u5024\n\t\t\
    P \u306E\u51F8\u5305\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\
    \t\tO(n log n)\n\t\u5099\u8003\n\t\tpoint \u306B (x, y) \u306E\u8F9E\u66F8\u5F0F\
    \u9806\u5E8F\u3092\u5165\u308C\u3066\u304A\u304F.\n\t\t\u8FBA\u4E0A\u306B\u3042\
    \u308B\u9802\u70B9\u306F\u7AEF\u306E\u3082\u306E\u3060\u3051\u62FE\u3046.\n\t\t\
    \u8FBA\u4E0A\u306B\u3042\u308B\u9802\u70B9\u3092\u5168\u90E8\u62FE\u3046\u3088\
    \u3046\u306B\u3057\u305F\u3044\u3068\u304D\u306F !=CCW \u3092 ==CW \u3068\u4FEE\
    \u6B63\u3059\u308C\u3070\u3044\u3044.\n*/\n\npolygon convex_hull(vector<point>\
    \ P){\n\tint n=P.size();\n\tif(n<=1) return P;\n\n\tsort(P.begin(),P.end(),[](const\
    \ point& p,const point& q){\n\t\treturn make_pair(p.x,p.y)<make_pair(q.x,q.y);\n\
    \t});\n\n\tpolygon CH;\n\trep(_,2){\n\t\tint m=0;\n\t\tvector<point> half(n);\n\
    \t\tfor(const point& p:P){\n\t\t\thalf[m++]=p;\n\t\t\twhile(m>=3 && ccw(half[m-3],half[m-2],half[m-1])!=CCW){\n\
    \t\t\t\thalf[m-2]=half[m-1];\n\t\t\t\tm--;\n\t\t\t}\n\t\t}\n\t\tCH.insert(CH.end(),half.begin(),half.begin()+m-1);\n\
    \t\treverse(P.begin(),P.end());\n\t}\n\treturn CH;\n}\n"
  code: "/* \u51F8\u5305 */\n/*\n\t\u8AAC\u660E\n\t\t\u70B9\u96C6\u5408\u306E\u51F8\
    \u5305\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tP : \u70B9\u96C6\u5408\n\t\
    \u623B\u308A\u5024\n\t\tP \u306E\u51F8\u5305\n\t\u5236\u7D04\n\t\t\u306A\u3057\
    \n\t\u8A08\u7B97\u91CF\n\t\tO(n log n)\n\t\u5099\u8003\n\t\tpoint \u306B (x, y)\
    \ \u306E\u8F9E\u66F8\u5F0F\u9806\u5E8F\u3092\u5165\u308C\u3066\u304A\u304F.\n\t\
    \t\u8FBA\u4E0A\u306B\u3042\u308B\u9802\u70B9\u306F\u7AEF\u306E\u3082\u306E\u3060\
    \u3051\u62FE\u3046.\n\t\t\u8FBA\u4E0A\u306B\u3042\u308B\u9802\u70B9\u3092\u5168\
    \u90E8\u62FE\u3046\u3088\u3046\u306B\u3057\u305F\u3044\u3068\u304D\u306F !=CCW\
    \ \u3092 ==CW \u3068\u4FEE\u6B63\u3059\u308C\u3070\u3044\u3044.\n*/\n\npolygon\
    \ convex_hull(vector<point> P){\n\tint n=P.size();\n\tif(n<=1) return P;\n\n\t\
    sort(P.begin(),P.end(),[](const point& p,const point& q){\n\t\treturn make_pair(p.x,p.y)<make_pair(q.x,q.y);\n\
    \t});\n\n\tpolygon CH;\n\trep(_,2){\n\t\tint m=0;\n\t\tvector<point> half(n);\n\
    \t\tfor(const point& p:P){\n\t\t\thalf[m++]=p;\n\t\t\twhile(m>=3 && ccw(half[m-3],half[m-2],half[m-1])!=CCW){\n\
    \t\t\t\thalf[m-2]=half[m-1];\n\t\t\t\tm--;\n\t\t\t}\n\t\t}\n\t\tCH.insert(CH.end(),half.begin(),half.begin()+m-1);\n\
    \t\treverse(P.begin(),P.end());\n\t}\n\treturn CH;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/library/geometry/convex_hull.hpp
- /library/library/geometry/convex_hull.hpp.html
title: library/geometry/convex_hull.hpp
---
