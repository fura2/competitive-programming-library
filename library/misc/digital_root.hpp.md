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
  bundledCode: "#line 1 \"library/misc/digital_root.hpp\"\ninline int digital_root(long\
    \ long n,long long base=10){\n\tif(n==0) return 0;\n\telse     return n%(base-1)!=0?n%(base-1):base-1;\n\
    }\n"
  code: "inline int digital_root(long long n,long long base=10){\n\tif(n==0) return\
    \ 0;\n\telse     return n%(base-1)!=0?n%(base-1):base-1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/digital_root.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/digital_root.hpp
layout: document
redirect_from:
- /library/library/misc/digital_root.hpp
- /library/library/misc/digital_root.hpp.html
title: library/misc/digital_root.hpp
---
