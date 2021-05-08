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
  bundledCode: "#line 1 \"library/number_theory/prime_factor.hpp\"\n/* \u7D20\u56E0\
    \u6570\u5217\u6319 */\n/*\n\t\u8AAC\u660E\n\t\ta \u306E\u7D20\u56E0\u6570\u3092\
    \u3059\u3079\u3066\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\
    \u623B\u308A\u5024\n\t\ta \u306E\u7D20\u56E0\u6570\u306E\u30EA\u30B9\u30C8\n\t\
    \u5236\u7D04\n\t\ta > 0\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a))\n\t\u5099\u8003\n\
    \t\ta = 1 \u306E\u3068\u304D\u306F\u7A7A\u306E\u30EA\u30B9\u30C8\u304C\u8FD4\u308B\
    \n*/\n\nvector<long long> prime_factors(long long a){\n\tvector<long long> res;\n\
    \tif(a%2==0){\n\t\tdo a/=2; while(a%2==0);\n\t\tres.emplace_back(2);\n\t}\n\t\
    for(long long p=3;p*p<=a;p+=2) if(a%p==0) {\n\t\tdo a/=p; while(a%p==0);\n\t\t\
    res.emplace_back(p);\n\t}\n\tif(a>1) res.emplace_back(a);\n\tsort(res.begin(),res.end());\n\
    \treturn res;\n}\n"
  code: "/* \u7D20\u56E0\u6570\u5217\u6319 */\n/*\n\t\u8AAC\u660E\n\t\ta \u306E\u7D20\
    \u56E0\u6570\u3092\u3059\u3079\u3066\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta\
    \ : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u306E\u7D20\u56E0\u6570\u306E\u30EA\
    \u30B9\u30C8\n\t\u5236\u7D04\n\t\ta > 0\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a))\n\
    \t\u5099\u8003\n\t\ta = 1 \u306E\u3068\u304D\u306F\u7A7A\u306E\u30EA\u30B9\u30C8\
    \u304C\u8FD4\u308B\n*/\n\nvector<long long> prime_factors(long long a){\n\tvector<long\
    \ long> res;\n\tif(a%2==0){\n\t\tdo a/=2; while(a%2==0);\n\t\tres.emplace_back(2);\n\
    \t}\n\tfor(long long p=3;p*p<=a;p+=2) if(a%p==0) {\n\t\tdo a/=p; while(a%p==0);\n\
    \t\tres.emplace_back(p);\n\t}\n\tif(a>1) res.emplace_back(a);\n\tsort(res.begin(),res.end());\n\
    \treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number_theory/prime_factor.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number_theory/prime_factor.hpp
layout: document
redirect_from:
- /library/library/number_theory/prime_factor.hpp
- /library/library/number_theory/prime_factor.hpp.html
title: library/number_theory/prime_factor.hpp
---
