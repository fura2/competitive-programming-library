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
  bundledCode: "#line 1 \"library/geometry/ccw.hpp\"\n/* \u56DE\u8EE2\u65B9\u5411\
    \ */\n/*\n\t\u8AAC\u660E\n\t\t\u4E09\u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2\u3092\
    \u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta, b, c : \u70B9\n\t\u623B\u308A\u5024\
    \n\t\ta-b-c \u306E\u9806\u306B\u53CD\u6642\u8A08\u56DE\u308A\u306B\u56DE\u8EE2\
    \u3057\u3066\u3044\u308B\u3068\u304D CCW\n\t\ta-b-c \u306E\u9806\u306B\u6642\u8A08\
    \u56DE\u308A\u306B\u56DE\u8EE2\u3057\u3066\u3044\u308B\u3068\u304D CW\n\t\ta-b-c\
    \ \u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u3068\u304D ON\n\t\u5236\
    \u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\
    \u4E8C\u70B9\u4EE5\u4E0A\u304C\u540C\u4E00\u306E\u70B9\u3067\u3042\u308C\u3070\
    \u3064\u306D\u306B ON \u3092\u8FD4\u3059\u3053\u3068\u306B\u6CE8\u610F\n*/\n\n\
    enum{CCW=1,CW=-1,ON=0};\nint ccw(const point& a,const point& b,const point& c){\n\
    \tint d=sgn(cross(b-a,c-a));\n\treturn d>0?CCW:d<0?CW:ON;\n}\n"
  code: "/* \u56DE\u8EE2\u65B9\u5411 */\n/*\n\t\u8AAC\u660E\n\t\t\u4E09\u70B9\u306E\
    \u4F4D\u7F6E\u95A2\u4FC2\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta, b, c\
    \ : \u70B9\n\t\u623B\u308A\u5024\n\t\ta-b-c \u306E\u9806\u306B\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u56DE\u8EE2\u3057\u3066\u3044\u308B\u3068\u304D CCW\n\t\ta-b-c\
    \ \u306E\u9806\u306B\u6642\u8A08\u56DE\u308A\u306B\u56DE\u8EE2\u3057\u3066\u3044\
    \u308B\u3068\u304D CW\n\t\ta-b-c \u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308B\u3068\u304D ON\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\
    \t\tO(1)\n\t\u5099\u8003\n\t\t\u4E8C\u70B9\u4EE5\u4E0A\u304C\u540C\u4E00\u306E\
    \u70B9\u3067\u3042\u308C\u3070\u3064\u306D\u306B ON \u3092\u8FD4\u3059\u3053\u3068\
    \u306B\u6CE8\u610F\n*/\n\nenum{CCW=1,CW=-1,ON=0};\nint ccw(const point& a,const\
    \ point& b,const point& c){\n\tint d=sgn(cross(b-a,c-a));\n\treturn d>0?CCW:d<0?CW:ON;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/ccw.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/ccw.hpp
layout: document
redirect_from:
- /library/library/geometry/ccw.hpp
- /library/library/geometry/ccw.hpp.html
title: library/geometry/ccw.hpp
---
