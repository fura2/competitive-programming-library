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
  bundledCode: "#line 1 \"number_theory/Eratosthenes.hpp\"\n/* Eratosthenes \u306E\
    \u7BE9 */\n/*\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u3059\
    \u3079\u3066\u6C42\u3081\u308B\n\n[ constructor ]\n\t\u8AAC\u660E\n\t\t\u306A\u3057\
    \n\t\u5F15\u6570\n\t\tn : \u6574\u6570\n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(n log log n)\n\n[ primes ]\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u306E\u30EA\u30B9\u30C8\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\
    \t\t\u306A\u3057\n\t\u623B\u308A\u5024\n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\
    \u30EA\u30B9\u30C8\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\
    \tO(1)\n\t\t\u305F\u3060\u3057, \u9577\u3055 |p| \u306E vector \u306E\u30B3\u30D4\
    \u30FC\u304C\u767A\u751F\u3059\u308B\n\n[ is_prime ]\n\t\u8AAC\u660E\n\t\t\u6574\
    \u6570 a \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u304C\u7D20\
    \u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\n\t\ta <= n\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n*/\n\nclass Eratosthenes_sieve{\n\tvector<bool> er;\n\tvector<int>\
    \ p;\npublic:\n\tEratosthenes_sieve(int n):er(n+1,true){\n\t\tif(n>=0) er[0]=false;\n\
    \t\tif(n>=1) er[1]=false;\n\t\tfor(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i)\
    \ er[j]=false;\n\t\trep(i,n+1) if(er[i]) p.emplace_back(i);\n\t}\n\n\tvector<int>\
    \ primes()const{ return p; }\n\n\tbool is_prime(int a)const{\n\t\tassert(a<=(int)er.size()-1);\n\
    \t\treturn a>=0 && er[a];\n\t}\n};\n"
  code: "/* Eratosthenes \u306E\u7BE9 */\n/*\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u3092\u3059\u3079\u3066\u6C42\u3081\u308B\n\n[ constructor ]\n\t\u8AAC\
    \u660E\n\t\t\u306A\u3057\n\t\u5F15\u6570\n\t\tn : \u6574\u6570\n\t\u5236\u7D04\
    \n\t\tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(n log log n)\n\n[ primes ]\n\t\u8AAC\
    \u660E\n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\u3092\u6C42\
    \u3081\u308B\n\t\u5F15\u6570\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\n\t\tn \u4EE5\
    \u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\n\t\u5236\u7D04\n\t\t\u306A\u3057\
    \n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\t\u305F\u3060\u3057, \u9577\u3055 |p| \u306E\
    \ vector \u306E\u30B3\u30D4\u30FC\u304C\u767A\u751F\u3059\u308B\n\n[ is_prime\
    \ ]\n\t\u8AAC\u660E\n\t\t\u6574\u6570 a \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\
    \u308A\u5024\n\t\ta \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\
    \n\t\ta <= n\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n*/\n\nclass Eratosthenes_sieve{\n\
    \tvector<bool> er;\n\tvector<int> p;\npublic:\n\tEratosthenes_sieve(int n):er(n+1,true){\n\
    \t\tif(n>=0) er[0]=false;\n\t\tif(n>=1) er[1]=false;\n\t\tfor(int i=2;i*i<=n;i++)\
    \ if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;\n\t\trep(i,n+1) if(er[i]) p.emplace_back(i);\n\
    \t}\n\n\tvector<int> primes()const{ return p; }\n\n\tbool is_prime(int a)const{\n\
    \t\tassert(a<=(int)er.size()-1);\n\t\treturn a>=0 && er[a];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/Eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/Eratosthenes.hpp
layout: document
redirect_from:
- /library/number_theory/Eratosthenes.hpp
- /library/number_theory/Eratosthenes.hpp.html
title: number_theory/Eratosthenes.hpp
---
