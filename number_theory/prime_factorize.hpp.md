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
  bundledCode: "#line 1 \"number_theory/prime_factorize.hpp\"\n/* \u7D20\u56E0\u6570\
    \u5206\u89E3 (\u8A66\u3057\u5272\u308A) */\n/*\n\t\u8AAC\u660E\n\t\ta \u3092\u7D20\
    \u56E0\u6570\u5206\u89E3\u3059\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\
    \u623B\u308A\u5024\n\t\ta \u306E\u7D20\u56E0\u6570\u5206\u89E3\n\t\u5236\u7D04\
    \n\t\ta > 0\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a)*log(log a))\n\t\u5099\u8003\n\
    \t\ta = 1 \u306E\u3068\u304D\u306F\u7A7A\u306E map \u304C\u8FD4\u308B\n*/\n\n\
    map<long long,int> prime_factorize(long long a){\n\tmap<long long,int> res;\n\t\
    if(a%2==0){\n\t\tint cnt=0;\n\t\tdo{ cnt++; a/=2; }while(a%2==0);\n\t\tres.emplace(2,cnt);\n\
    \t}\n\tfor(long long p=3;p*p<=a;p+=2) if(a%p==0) {\n\t\tint cnt=0;\n\t\tdo{ cnt++;\
    \ a/=p; }while(a%p==0);\n\t\tres.emplace(p,cnt);\n\t}\n\tif(a>1) res.emplace(a,1);\n\
    \treturn res;\n}\n"
  code: "/* \u7D20\u56E0\u6570\u5206\u89E3 (\u8A66\u3057\u5272\u308A) */\n/*\n\t\u8AAC\
    \u660E\n\t\ta \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n\t\u5F15\u6570\
    \n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u306E\u7D20\u56E0\u6570\u5206\
    \u89E3\n\t\u5236\u7D04\n\t\ta > 0\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a)*log(log\
    \ a))\n\t\u5099\u8003\n\t\ta = 1 \u306E\u3068\u304D\u306F\u7A7A\u306E map \u304C\
    \u8FD4\u308B\n*/\n\nmap<long long,int> prime_factorize(long long a){\n\tmap<long\
    \ long,int> res;\n\tif(a%2==0){\n\t\tint cnt=0;\n\t\tdo{ cnt++; a/=2; }while(a%2==0);\n\
    \t\tres.emplace(2,cnt);\n\t}\n\tfor(long long p=3;p*p<=a;p+=2) if(a%p==0) {\n\t\
    \tint cnt=0;\n\t\tdo{ cnt++; a/=p; }while(a%p==0);\n\t\tres.emplace(p,cnt);\n\t\
    }\n\tif(a>1) res.emplace(a,1);\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/prime_factorize.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/prime_factorize.hpp
layout: document
redirect_from:
- /library/number_theory/prime_factorize.hpp
- /library/number_theory/prime_factorize.hpp.html
title: number_theory/prime_factorize.hpp
---
