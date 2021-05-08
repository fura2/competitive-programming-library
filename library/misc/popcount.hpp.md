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
  bundledCode: "#line 1 \"library/misc/popcount.hpp\"\ninline int popcount(unsigned\
    \ int x){\n\tx-=(x>>1)&0x55555555;\n\tx=(x&0x33333333)+((x>>2)&0x33333333);\n\t\
    return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;\n}\n\ninline int popcount(unsigned\
    \ long long x){\n\tx-=(x>>1)&0x5555555555555555LL;\n\tx=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);\n\
    \tx=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;\n\tx=(x*0x0101010101010101LL)>>56;\n\treturn\
    \ x;\n}\n"
  code: "inline int popcount(unsigned int x){\n\tx-=(x>>1)&0x55555555;\n\tx=(x&0x33333333)+((x>>2)&0x33333333);\n\
    \treturn ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;\n}\n\ninline int popcount(unsigned\
    \ long long x){\n\tx-=(x>>1)&0x5555555555555555LL;\n\tx=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);\n\
    \tx=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;\n\tx=(x*0x0101010101010101LL)>>56;\n\treturn\
    \ x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/popcount.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/popcount.hpp
layout: document
redirect_from:
- /library/library/misc/popcount.hpp
- /library/library/misc/popcount.hpp.html
title: library/misc/popcount.hpp
---
