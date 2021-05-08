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
    - https://twitter.com/noshi91/status/1200702280128856064
    - https://twitter.com/noshi91/status/1269660771086041088
    - https://twitter.com/tatyam_prime/status/1269653456454729728
  bundledCode: "#line 1 \"library/linear_algebra/xor_basis.hpp\"\n// a \u306E xor\
    \ \u306B\u3064\u3044\u3066\u306E\u57FA\u5E95\u3092\u4E00\u7D44\u6C42\u3081\u308B\
    \n// cf. https://twitter.com/noshi91/status/1200702280128856064\n//     https://twitter.com/noshi91/status/1269660771086041088\n\
    //     https://twitter.com/tatyam_prime/status/1269653456454729728\n\nauto basis(const\
    \ vector<unsigned long long>& a){\n\tvector<unsigned long long> B;\n\tfor(auto\
    \ v:a){\n\t\tfor(const auto& b:B) v=min(v,v^b);\n\t\tif(v!=0) B.emplace_back(v);\n\
    \t}\n\treturn B;\n}\n\n// B \u306E\u5143\u306E\u7DDA\u5F62\u7D50\u5408\u3067 v\
    \ \u304C\u8868\u3055\u308C\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n// B \u306F\u4E0A\u8A18\u306E basis \u95A2\u6570\u3067\u6C42\u3081\u305F\
    \u57FA\u5E95\u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\n\nbool is_linearly_independent(unsigned\
    \ long long v,const vector<unsigned long long>& B){\n\tfor(const auto& b:B) v=min(v,v^b);\n\
    \treturn v!=0;\n}\n"
  code: "// a \u306E xor \u306B\u3064\u3044\u3066\u306E\u57FA\u5E95\u3092\u4E00\u7D44\
    \u6C42\u3081\u308B\n// cf. https://twitter.com/noshi91/status/1200702280128856064\n\
    //     https://twitter.com/noshi91/status/1269660771086041088\n//     https://twitter.com/tatyam_prime/status/1269653456454729728\n\
    \nauto basis(const vector<unsigned long long>& a){\n\tvector<unsigned long long>\
    \ B;\n\tfor(auto v:a){\n\t\tfor(const auto& b:B) v=min(v,v^b);\n\t\tif(v!=0) B.emplace_back(v);\n\
    \t}\n\treturn B;\n}\n\n// B \u306E\u5143\u306E\u7DDA\u5F62\u7D50\u5408\u3067 v\
    \ \u304C\u8868\u3055\u308C\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n// B \u306F\u4E0A\u8A18\u306E basis \u95A2\u6570\u3067\u6C42\u3081\u305F\
    \u57FA\u5E95\u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\n\nbool is_linearly_independent(unsigned\
    \ long long v,const vector<unsigned long long>& B){\n\tfor(const auto& b:B) v=min(v,v^b);\n\
    \treturn v!=0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/linear_algebra/xor_basis.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linear_algebra/xor_basis.hpp
layout: document
redirect_from:
- /library/library/linear_algebra/xor_basis.hpp
- /library/library/linear_algebra/xor_basis.hpp.html
title: library/linear_algebra/xor_basis.hpp
---
