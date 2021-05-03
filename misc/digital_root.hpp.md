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
  bundledCode: "#line 1 \"misc/digital_root.hpp\"\ninline int digital_root(long long\
    \ n,long long base=10){\n\tif(n==0) return 0;\n\telse     return n%(base-1)!=0?n%(base-1):base-1;\n\
    }\n"
  code: "inline int digital_root(long long n,long long base=10){\n\tif(n==0) return\
    \ 0;\n\telse     return n%(base-1)!=0?n%(base-1):base-1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/digital_root.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/digital_root.hpp
layout: document
redirect_from:
- /library/misc/digital_root.hpp
- /library/misc/digital_root.hpp.html
title: misc/digital_root.hpp
---
