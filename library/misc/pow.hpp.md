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
  bundledCode: "#line 1 \"library/misc/pow.hpp\"\n// \u7E70\u308A\u8FD4\u3057\u4E8C\
    \u4E57\u6CD5\u3067 f^k \u3092\u6C42\u3081\u308B\n// M \u306F\u30E2\u30CE\u30A4\
    \u30C9\n\ntemplate<class M>\nM pow(M f,long long k){\n\tM res;\n\tfor(;k>0;k>>=1){\n\
    \t\tif(k&1) res=res*f;\n\t\tf=f*f;\n\t}\n\treturn res;\n}\n"
  code: "// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\u3067 f^k \u3092\u6C42\u3081\
    \u308B\n// M \u306F\u30E2\u30CE\u30A4\u30C9\n\ntemplate<class M>\nM pow(M f,long\
    \ long k){\n\tM res;\n\tfor(;k>0;k>>=1){\n\t\tif(k&1) res=res*f;\n\t\tf=f*f;\n\
    \t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/pow.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/pow.hpp
layout: document
redirect_from:
- /library/library/misc/pow.hpp
- /library/library/misc/pow.hpp.html
title: library/misc/pow.hpp
---
