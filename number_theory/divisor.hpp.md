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
  bundledCode: "#line 1 \"number_theory/divisor.hpp\"\n/* \u7D04\u6570\u5217\u6319\
    \ */\n/*\n\t\u8AAC\u660E\n\t\ta \u306E\u7D04\u6570\u3092\u3059\u3079\u3066\u6C42\
    \u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u5236\u7D04\n\t\ta >= 0\n\
    \t\u623B\u308A\u5024\n\t\ta \u306E(\u6B63\u306E)\u7D04\u6570\u306E\u30EA\u30B9\
    \u30C8\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a))\n\t\u5099\u8003\n\t\ta = 0 \u306E\
    \u3068\u304D\u306F\u7A7A\u306E\u30EA\u30B9\u30C8\u304C\u8FD4\u308B\n*/\n\nvector<long\
    \ long> divisors(long long a){\n\tvector<long long> res;\n\tfor(long long i=1;i*i<=a;i++)\
    \ if(a%i==0) {\n\t\tres.emplace_back(i);\n\t\tif(i*i<a) res.emplace_back(a/i);\n\
    \t}\n\tsort(res.begin(),res.end());\n\treturn res;\n}\n\n/* \u7D04\u6570\u5217\
    \u6319 */\n/*\n\t\u8AAC\u660E\n\t\ta \u306E\u7D04\u6570\u3092\u3059\u3079\u3066\
    \u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tpf : a \u306E\u7D20\u56E0\u6570\u5206\u89E3\
    \n\t\u5236\u7D04\n\t\ta >= 0\n\t\u623B\u308A\u5024\n\t\ta \u306E(\u6B63\u306E\
    )\u7D04\u6570\u306E\u30EA\u30B9\u30C8\n\t\u8A08\u7B97\u91CF\n\t\tO(a \u306E\u7D04\
    \u6570\u306E\u500B\u6570) (= O(exp((log a)/loglog a)))\n\t\u5099\u8003\n\t\ta\
    \ = 0 \u306E\u3068\u304D\u306F\u7A7A\u306E\u30EA\u30B9\u30C8\u304C\u8FD4\u308B\
    \n*/\n\ntemplate<class T>\nvector<T> divisors(const map<T,int>& pf){\n\tvector<T>\
    \ res={T(1)};\n\tfor(const auto& q:pf){\n\t\tint m=res.size();\n\t\tT pp=1;\n\t\
    \trep(i,q.second){\n\t\t\tpp*=q.first;\n\t\t\trep(i,m) res.emplace_back(res[i]*pp);\n\
    \t\t}\n\t}\n\tsort(res.begin(),res.end());\n\treturn res;\n}\n"
  code: "/* \u7D04\u6570\u5217\u6319 */\n/*\n\t\u8AAC\u660E\n\t\ta \u306E\u7D04\u6570\
    \u3092\u3059\u3079\u3066\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\
    \n\t\u5236\u7D04\n\t\ta >= 0\n\t\u623B\u308A\u5024\n\t\ta \u306E(\u6B63\u306E\
    )\u7D04\u6570\u306E\u30EA\u30B9\u30C8\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(a))\n\t\
    \u5099\u8003\n\t\ta = 0 \u306E\u3068\u304D\u306F\u7A7A\u306E\u30EA\u30B9\u30C8\
    \u304C\u8FD4\u308B\n*/\n\nvector<long long> divisors(long long a){\n\tvector<long\
    \ long> res;\n\tfor(long long i=1;i*i<=a;i++) if(a%i==0) {\n\t\tres.emplace_back(i);\n\
    \t\tif(i*i<a) res.emplace_back(a/i);\n\t}\n\tsort(res.begin(),res.end());\n\t\
    return res;\n}\n\n/* \u7D04\u6570\u5217\u6319 */\n/*\n\t\u8AAC\u660E\n\t\ta \u306E\
    \u7D04\u6570\u3092\u3059\u3079\u3066\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tpf\
    \ : a \u306E\u7D20\u56E0\u6570\u5206\u89E3\n\t\u5236\u7D04\n\t\ta >= 0\n\t\u623B\
    \u308A\u5024\n\t\ta \u306E(\u6B63\u306E)\u7D04\u6570\u306E\u30EA\u30B9\u30C8\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(a \u306E\u7D04\u6570\u306E\u500B\u6570) (= O(exp((log\
    \ a)/loglog a)))\n\t\u5099\u8003\n\t\ta = 0 \u306E\u3068\u304D\u306F\u7A7A\u306E\
    \u30EA\u30B9\u30C8\u304C\u8FD4\u308B\n*/\n\ntemplate<class T>\nvector<T> divisors(const\
    \ map<T,int>& pf){\n\tvector<T> res={T(1)};\n\tfor(const auto& q:pf){\n\t\tint\
    \ m=res.size();\n\t\tT pp=1;\n\t\trep(i,q.second){\n\t\t\tpp*=q.first;\n\t\t\t\
    rep(i,m) res.emplace_back(res[i]*pp);\n\t\t}\n\t}\n\tsort(res.begin(),res.end());\n\
    \treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/divisor.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/divisor.hpp
layout: document
redirect_from:
- /library/number_theory/divisor.hpp
- /library/number_theory/divisor.hpp.html
title: number_theory/divisor.hpp
---
