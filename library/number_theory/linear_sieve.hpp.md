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
    - https://cp-algorithms.com/algebra/prime-sieve-linear.html
  bundledCode: "#line 1 \"library/number_theory/linear_sieve.hpp\"\n/* \u7DDA\u5F62\
    \u7BE9 */\n/*\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\u3059\u3079\u3066\u306E\
    \u6B63\u6574\u6570\u306B\u5BFE\u3057\u3066, \u305D\u306E\u6700\u5C0F\u306E\u7D20\
    \u56E0\u6570\u3092\u6C42\u3081\u308B\n\t\u5099\u8003\n\t\thttps://cp-algorithms.com/algebra/prime-sieve-linear.html\n\
    \n[ constructor ]\n\t\u8AAC\u660E\n\t\t\u306A\u3057\n\t\u5F15\u6570\n\t\tn : \u6574\
    \u6570\n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\n[ primes\
    \ ]\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\
    \u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\
    \n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\n\t\u5236\u7D04\
    \n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\n[ is_prime ]\n\t\u8AAC\u660E\
    \n\t\ta \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u304C\u7D20\
    \u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\n\t\ta <= n\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n\n[ prime_factorize ]\n\t\u8AAC\u660E\n\t\ta \u3092\u7D20\u56E0\u6570\
    \u5206\u89E3\u3059\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\
    \u5024\n\t\ta \u306E\u7D20\u56E0\u6570\u5206\u89E3\n\t\u5236\u7D04\n\t\ta <= n\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(log a)\n\n[ number_of_divisors ]\n\t\u8AAC\u660E\n\
    \t\ta \u306E\u6B63\u306E\u7D04\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\
    \n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u306E\u6B63\
    \u306E\u7D04\u6570\u306E\u500B\u6570\n\t\u5236\u7D04\n\t\ta <= n\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log a)\n*/\n\nclass linear_sieve{\n\tvector<int> lpf,p;\npublic:\n\
    \tlinear_sieve(int n):lpf(n+1){\n\t\tfor(int i=2;i<=n;i++){\n\t\t\tif(lpf[i]==0){\n\
    \t\t\t\tlpf[i]=i;\n\t\t\t\tp.emplace_back(i);\n\t\t\t}\n\t\t\tfor(int j=0;j<p.size()&&p[j]<=lpf[i]&&i*p[j]<=n;j++)\
    \ lpf[i*p[j]]=p[j];\n\t\t}\n\t}\n\n\tconst vector<int>& primes()const{ return\
    \ p; }\n\n\tbool is_prime(int a)const{\n\t\tassert(a<=(int)lpf.size()-1);\n\t\t\
    return a>0 && lpf[a]==a;\n\t}\n\n\tmap<int,int> prime_factorize(int a)const{\n\
    \t\tassert(a<=(int)lpf.size()-1);\n\t\tmap<int,int> pf;\n\t\tfor(;a>1;a/=lpf[a])\
    \ ++pf[lpf[a]];\n\t\treturn pf;\n\t}\n\n\tint number_of_divisors(int a)const{\n\
    \t\tassert(a<=(int)lpf.size()-1);\n\t\tint res=1,cnt=0,pre=-1;\n\t\tfor(;a>1;a/=lpf[a]){\n\
    \t\t\tif(pre==-1 || pre==lpf[a]){\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t\telse{\n\t\t\t\
    \tres*=cnt+1;\n\t\t\t\tcnt=1;\n\t\t\t}\n\t\t\tpre=lpf[a];\n\t\t}\n\t\treturn res*(cnt+1);\n\
    \t}\n};\n"
  code: "/* \u7DDA\u5F62\u7BE9 */\n/*\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\u3059\
    \u3079\u3066\u306E\u6B63\u6574\u6570\u306B\u5BFE\u3057\u3066, \u305D\u306E\u6700\
    \u5C0F\u306E\u7D20\u56E0\u6570\u3092\u6C42\u3081\u308B\n\t\u5099\u8003\n\t\thttps://cp-algorithms.com/algebra/prime-sieve-linear.html\n\
    \n[ constructor ]\n\t\u8AAC\u660E\n\t\t\u306A\u3057\n\t\u5F15\u6570\n\t\tn : \u6574\
    \u6570\n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\n[ primes\
    \ ]\n\t\u8AAC\u660E\n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\
    \u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\
    \n\t\tn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\n\t\u5236\u7D04\
    \n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\n[ is_prime ]\n\t\u8AAC\u660E\
    \n\t\ta \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u304C\u7D20\
    \u6570\u304B\u3069\u3046\u304B\n\t\u5236\u7D04\n\t\ta <= n\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n\n[ prime_factorize ]\n\t\u8AAC\u660E\n\t\ta \u3092\u7D20\u56E0\u6570\
    \u5206\u89E3\u3059\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\
    \u5024\n\t\ta \u306E\u7D20\u56E0\u6570\u5206\u89E3\n\t\u5236\u7D04\n\t\ta <= n\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(log a)\n\n[ number_of_divisors ]\n\t\u8AAC\u660E\n\
    \t\ta \u306E\u6B63\u306E\u7D04\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\
    \n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta \u306E\u6B63\
    \u306E\u7D04\u6570\u306E\u500B\u6570\n\t\u5236\u7D04\n\t\ta <= n\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log a)\n*/\n\nclass linear_sieve{\n\tvector<int> lpf,p;\npublic:\n\
    \tlinear_sieve(int n):lpf(n+1){\n\t\tfor(int i=2;i<=n;i++){\n\t\t\tif(lpf[i]==0){\n\
    \t\t\t\tlpf[i]=i;\n\t\t\t\tp.emplace_back(i);\n\t\t\t}\n\t\t\tfor(int j=0;j<p.size()&&p[j]<=lpf[i]&&i*p[j]<=n;j++)\
    \ lpf[i*p[j]]=p[j];\n\t\t}\n\t}\n\n\tconst vector<int>& primes()const{ return\
    \ p; }\n\n\tbool is_prime(int a)const{\n\t\tassert(a<=(int)lpf.size()-1);\n\t\t\
    return a>0 && lpf[a]==a;\n\t}\n\n\tmap<int,int> prime_factorize(int a)const{\n\
    \t\tassert(a<=(int)lpf.size()-1);\n\t\tmap<int,int> pf;\n\t\tfor(;a>1;a/=lpf[a])\
    \ ++pf[lpf[a]];\n\t\treturn pf;\n\t}\n\n\tint number_of_divisors(int a)const{\n\
    \t\tassert(a<=(int)lpf.size()-1);\n\t\tint res=1,cnt=0,pre=-1;\n\t\tfor(;a>1;a/=lpf[a]){\n\
    \t\t\tif(pre==-1 || pre==lpf[a]){\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t\telse{\n\t\t\t\
    \tres*=cnt+1;\n\t\t\t\tcnt=1;\n\t\t\t}\n\t\t\tpre=lpf[a];\n\t\t}\n\t\treturn res*(cnt+1);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number_theory/linear_sieve.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number_theory/linear_sieve.hpp
layout: document
redirect_from:
- /library/library/number_theory/linear_sieve.hpp
- /library/library/number_theory/linear_sieve.hpp.html
title: library/number_theory/linear_sieve.hpp
---
