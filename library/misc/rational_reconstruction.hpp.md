---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Rational_reconstruction_(mathematics)
  bundledCode: "#line 1 \"library/misc/rational_reconstruction.hpp\"\n/*\n\tP/Q mod\
    \ M \u304B\u3089 P \u3068 Q \u3092\u5FA9\u5143\u3059\u308B\n\t\tP, Q \u304C\u5341\
    \u5206\u5C0F\u3055\u3044\u3068\u304D (\u5177\u4F53\u7684\u306B\u306F |P| < sqrt(M/2),\
    \ 0 < Q < sqrt(M/2) \u7A0B\u5EA6),\n\t\tP, Q \u304C\u4E00\u610F\u306B\u5B9A\u307E\
    \u308B\u306E\u3067, \u3053\u306E P, Q \u3092\u6C42\u3081\u308B\n\t\t\u89E3\u306A\
    \u3057\u306E\u5834\u5408\u306F P = Q = -1 \u304C\u8FD4\u308B\n\t\tP, Q \u304C\u3042\
    \u308B\u7A0B\u5EA6\u5927\u304D\u3044\u5834\u5408\u306F, \u89E3\u306A\u3057\u3068\
    \u5224\u5B9A\u3055\u308C\u308B\u304B\u610F\u56F3\u3057\u3066\u3044\u306A\u3044\
    \u89E3\u3092\u6355\u307E\u3048\u3066\u3057\u307E\u3046\u306E\u3067\u6CE8\u610F\
    \n\t\u5165\u529B\n\t\tr : P/Q mod M\n\t\tm : M\n\t\u53C2\u8003\n\t\thttps://en.wikipedia.org/wiki/Rational_reconstruction_(mathematics)\n\
    */\n\npair<lint,lint> rational_reconstruction(lint r,lint m=1000000007){\n\tlint\
    \ D=sqrt(m/2);\n\tlint N=sqrt(m/2);\n\n\tlint v1=m,v2=0,w1=r,w2=1;\n\twhile(w1>N){\n\
    \t\tlint z1=v1-(v1/w1)*w1;\n\t\tlint z2=v2-(v1/w1)*w2;\n\t\tv1=w1; v2=w2;\n\t\t\
    w1=z1; w2=z2;\n\t}\n\tif(w2<0) w1*=-1, w2*=-1;\n\n\tif(w2<D && gcd(w1,w2)==1)\
    \ return {w1,w2};\n\telse                      return {-1,-1};\n}\n"
  code: "/*\n\tP/Q mod M \u304B\u3089 P \u3068 Q \u3092\u5FA9\u5143\u3059\u308B\n\t\
    \tP, Q \u304C\u5341\u5206\u5C0F\u3055\u3044\u3068\u304D (\u5177\u4F53\u7684\u306B\
    \u306F |P| < sqrt(M/2), 0 < Q < sqrt(M/2) \u7A0B\u5EA6),\n\t\tP, Q \u304C\u4E00\
    \u610F\u306B\u5B9A\u307E\u308B\u306E\u3067, \u3053\u306E P, Q \u3092\u6C42\u3081\
    \u308B\n\t\t\u89E3\u306A\u3057\u306E\u5834\u5408\u306F P = Q = -1 \u304C\u8FD4\
    \u308B\n\t\tP, Q \u304C\u3042\u308B\u7A0B\u5EA6\u5927\u304D\u3044\u5834\u5408\u306F\
    , \u89E3\u306A\u3057\u3068\u5224\u5B9A\u3055\u308C\u308B\u304B\u610F\u56F3\u3057\
    \u3066\u3044\u306A\u3044\u89E3\u3092\u6355\u307E\u3048\u3066\u3057\u307E\u3046\
    \u306E\u3067\u6CE8\u610F\n\t\u5165\u529B\n\t\tr : P/Q mod M\n\t\tm : M\n\t\u53C2\
    \u8003\n\t\thttps://en.wikipedia.org/wiki/Rational_reconstruction_(mathematics)\n\
    */\n\npair<lint,lint> rational_reconstruction(lint r,lint m=1000000007){\n\tlint\
    \ D=sqrt(m/2);\n\tlint N=sqrt(m/2);\n\n\tlint v1=m,v2=0,w1=r,w2=1;\n\twhile(w1>N){\n\
    \t\tlint z1=v1-(v1/w1)*w1;\n\t\tlint z2=v2-(v1/w1)*w2;\n\t\tv1=w1; v2=w2;\n\t\t\
    w1=z1; w2=z2;\n\t}\n\tif(w2<0) w1*=-1, w2*=-1;\n\n\tif(w2<D && gcd(w1,w2)==1)\
    \ return {w1,w2};\n\telse                      return {-1,-1};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/rational_reconstruction.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/rational_reconstruction.hpp
layout: document
redirect_from:
- /library/library/misc/rational_reconstruction.hpp
- /library/library/misc/rational_reconstruction.hpp.html
title: library/misc/rational_reconstruction.hpp
---
