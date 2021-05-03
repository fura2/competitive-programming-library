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
  bundledCode: "#line 1 \"geometry/area.hpp\"\n/* \u591A\u89D2\u5F62\u306E\u9762\u7A4D\
    \ */\n/*\n\t\u5F15\u6570\n\t\tF : \u591A\u89D2\u5F62\n\t\u623B\u308A\u5024\n\t\
    \t\u591A\u89D2\u5F62\u306E\u9762\u7A4D (\u7E2E\u9000\u3057\u3066\u3044\u308B\u3068\
    \u304D\u306F 0)\n\t\u5236\u7D04\n\t\tF \u306F\u5358\u7D14\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(n)\n\t\u5099\u8003\n\t\tF \u306F CCW \u3067\u3082 CW \u3067\u3082\u3044\
    \u3044\n*/\n\nReal area(const polygon& F){\n\tint n=F.size();\n\tReal res=0;\n\
    \trep(i,n) res+=cross(F[i],F[(i+1)%n]);\n\treturn abs(res)/2;\n}\n"
  code: "/* \u591A\u89D2\u5F62\u306E\u9762\u7A4D */\n/*\n\t\u5F15\u6570\n\t\tF : \u591A\
    \u89D2\u5F62\n\t\u623B\u308A\u5024\n\t\t\u591A\u89D2\u5F62\u306E\u9762\u7A4D (\u7E2E\
    \u9000\u3057\u3066\u3044\u308B\u3068\u304D\u306F 0)\n\t\u5236\u7D04\n\t\tF \u306F\
    \u5358\u7D14\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\tF \u306F CCW\
    \ \u3067\u3082 CW \u3067\u3082\u3044\u3044\n*/\n\nReal area(const polygon& F){\n\
    \tint n=F.size();\n\tReal res=0;\n\trep(i,n) res+=cross(F[i],F[(i+1)%n]);\n\t\
    return abs(res)/2;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/area.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/area.hpp
layout: document
redirect_from:
- /library/geometry/area.hpp
- /library/geometry/area.hpp.html
title: geometry/area.hpp
---
