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
  bundledCode: "#line 1 \"linear_algebra/solve_eq.hpp\"\n/* \u4E8C\u5143\u9023\u7ACB\
    \u4E00\u6B21\u65B9\u7A0B\u5F0F */\n/*\n\t\u8AAC\u660E\n\t\t\u4F53 F \u4E0A\u306E\
    \u4E8C\u5143\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F\n\t\t\ta x + b y = e\n\t\
    \t\tc x + d y = f\n\t\t\u3092\u89E3\u304F\n\t\u5F15\u6570\n\t\ta, b, c, d, e,\
    \ f : \u30D1\u30E9\u30E1\u30FC\u30BF\n\t\u623B\u308A\u5024\n\t\t(x, y)\n\t\u5236\
    \u7D04\n\t\t\u89E3\u304C\u4E00\u610F\u306B\u5B58\u5728\u3059\u308B (ad-bc != 0)\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\ntemplate<class\
    \ F>\npair<F,F> solve_eq(const F& a,const F& b,const F& c,const F& d,const F&\
    \ e,const F& f){\n\tF det=a*d-b*c;\n\tassert(det!=F{});\n\treturn {(d*e-b*f)/det,(-c*e+a*f)/det};\n\
    }\n"
  code: "/* \u4E8C\u5143\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F */\n/*\n\t\u8AAC\
    \u660E\n\t\t\u4F53 F \u4E0A\u306E\u4E8C\u5143\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\
    \u5F0F\n\t\t\ta x + b y = e\n\t\t\tc x + d y = f\n\t\t\u3092\u89E3\u304F\n\t\u5F15\
    \u6570\n\t\ta, b, c, d, e, f : \u30D1\u30E9\u30E1\u30FC\u30BF\n\t\u623B\u308A\u5024\
    \n\t\t(x, y)\n\t\u5236\u7D04\n\t\t\u89E3\u304C\u4E00\u610F\u306B\u5B58\u5728\u3059\
    \u308B (ad-bc != 0)\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u306A\
    \u3057\n*/\n\ntemplate<class F>\npair<F,F> solve_eq(const F& a,const F& b,const\
    \ F& c,const F& d,const F& e,const F& f){\n\tF det=a*d-b*c;\n\tassert(det!=F{});\n\
    \treturn {(d*e-b*f)/det,(-c*e+a*f)/det};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linear_algebra/solve_eq.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linear_algebra/solve_eq.hpp
layout: document
redirect_from:
- /library/linear_algebra/solve_eq.hpp
- /library/linear_algebra/solve_eq.hpp.html
title: linear_algebra/solve_eq.hpp
---
