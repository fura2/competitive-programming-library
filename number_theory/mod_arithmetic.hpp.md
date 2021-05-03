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
  bundledCode: "#line 1 \"number_theory/mod_arithmetic.hpp\"\n/* mod m \u3067\u306E\
    \u9006\u5143 */\n/*\n\t\u8AAC\u660E\n\t\tmod m \u3067\u306E\u9006\u5143\u3092\u6C42\
    \u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\t\
    a^{-1} mod m\n\t\u5236\u7D04\n\t\ta >= 0\n\t\tm >= 1\n\t\ta^{-1} mod m \u304C\u5B58\
    \u5728\u3059\u308B (<=> gcd(a,m) = 1)\n\t\u8A08\u7B97\u91CF\n\t\tO(log max(a,m))\n\
    \t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nlint modinv(lint a,lint m){\n\tlint b=m,u=1,v=0;\n\
    \twhile(b>0){ lint t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }\n\treturn (u+m)%m;\n\
    }\n\n/* mod m \u3067\u306E\u3079\u304D\u4E57 */\n/*\n\t\u8AAC\u660E\n\t\tmod m\
    \ \u3067\u306E\u9006\u5143\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\
    \u6570\n\t\tk : \u6574\u6570\n\t\tm : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\t\
    a^{-1} mod m\n\t\u5236\u7D04\n\t\ta >= 0\n\t\tk >= 0\n\t\t1 <= m < INT_MAX\n\t\
    \u8A08\u7B97\u91CF\n\t\tO(log k)\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nlint\
    \ modpow(lint a,lint k,int m){\n\tlint r=1%m;\n\tfor(lint x=a%m;k>0;k>>=1,x=x*x%m)\
    \ if(k&1) r=r*x%m;\n\treturn r;\n}\n\n/* \u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \ */\n/*\n\t\u8AAC\u660E\n\t\t\u96E2\u6563\u5BFE\u6570 a^k = b (mod p) \u3092\u89E3\
    \u304F\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\tb : \u6574\u6570\n\t\tp : \u6574\
    \u6570\n\t\u623B\u308A\u5024\n\t\ta^k = b (mod p) \u306E\u89E3 k (0 <= k < p)\n\
    \t\t\u89E3\u304C\u306A\u3044\u5834\u5408\u306F -1\n\t\u5236\u7D04\n\t\t1 <= p\
    \ < INT_MAX\n\t\tp \u306F\u7D20\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(p) log\
    \ p)\n\t\u5099\u8003\n\t\t(p \u304C\u7D20\u6570\u306A\u306E\u3067) \u89E3\u306F\
    \u5B58\u5728\u3059\u308C\u3070\u4E00\u610F\n*/\n\nint modlog(lint a,lint b,int\
    \ p){\n\ta%=p; if(a<0) a+=p;\n\tb%=p; if(b<0) b+=p;\n\n\tint k=sqrt(p)+1,c=1;\n\
    \tvector<pair<int,int>> H(k);\n\trep(j,k) H[j]={c,j}, c=c*a%p;\n\tsort(H.begin(),H.end());\n\
    \n\tc=modinv(c,p);\n\trep(i,k){\n\t\tauto it=lower_bound(H.begin(),H.end(),make_pair(int(b),0));\n\
    \t\tif(it!=H.end() && it->first==b) return i*k+(it->second);\n\t\tb=b*c%p;\n\t\
    }\n\treturn -1;\n}\n"
  code: "/* mod m \u3067\u306E\u9006\u5143 */\n/*\n\t\u8AAC\u660E\n\t\tmod m \u3067\
    \u306E\u9006\u5143\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\
    \n\t\u623B\u308A\u5024\n\t\ta^{-1} mod m\n\t\u5236\u7D04\n\t\ta >= 0\n\t\tm >=\
    \ 1\n\t\ta^{-1} mod m \u304C\u5B58\u5728\u3059\u308B (<=> gcd(a,m) = 1)\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(log max(a,m))\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nlint\
    \ modinv(lint a,lint m){\n\tlint b=m,u=1,v=0;\n\twhile(b>0){ lint t=a/b; a-=t*b;\
    \ swap(a,b); u-=t*v; swap(u,v); }\n\treturn (u+m)%m;\n}\n\n/* mod m \u3067\u306E\
    \u3079\u304D\u4E57 */\n/*\n\t\u8AAC\u660E\n\t\tmod m \u3067\u306E\u9006\u5143\u3092\
    \u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ta : \u6574\u6570\n\t\tk : \u6574\u6570\
    \n\t\tm : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\ta^{-1} mod m\n\t\u5236\u7D04\
    \n\t\ta >= 0\n\t\tk >= 0\n\t\t1 <= m < INT_MAX\n\t\u8A08\u7B97\u91CF\n\t\tO(log\
    \ k)\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nlint modpow(lint a,lint k,int m){\n\
    \tlint r=1%m;\n\tfor(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;\n\treturn\
    \ r;\n}\n\n/* \u96E2\u6563\u5BFE\u6570\u554F\u984C */\n/*\n\t\u8AAC\u660E\n\t\t\
    \u96E2\u6563\u5BFE\u6570 a^k = b (mod p) \u3092\u89E3\u304F\n\t\u5F15\u6570\n\t\
    \ta : \u6574\u6570\n\t\tb : \u6574\u6570\n\t\tp : \u6574\u6570\n\t\u623B\u308A\
    \u5024\n\t\ta^k = b (mod p) \u306E\u89E3 k (0 <= k < p)\n\t\t\u89E3\u304C\u306A\
    \u3044\u5834\u5408\u306F -1\n\t\u5236\u7D04\n\t\t1 <= p < INT_MAX\n\t\tp \u306F\
    \u7D20\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(sqrt(p) log p)\n\t\u5099\u8003\n\t\t\
    (p \u304C\u7D20\u6570\u306A\u306E\u3067) \u89E3\u306F\u5B58\u5728\u3059\u308C\u3070\
    \u4E00\u610F\n*/\n\nint modlog(lint a,lint b,int p){\n\ta%=p; if(a<0) a+=p;\n\t\
    b%=p; if(b<0) b+=p;\n\n\tint k=sqrt(p)+1,c=1;\n\tvector<pair<int,int>> H(k);\n\
    \trep(j,k) H[j]={c,j}, c=c*a%p;\n\tsort(H.begin(),H.end());\n\n\tc=modinv(c,p);\n\
    \trep(i,k){\n\t\tauto it=lower_bound(H.begin(),H.end(),make_pair(int(b),0));\n\
    \t\tif(it!=H.end() && it->first==b) return i*k+(it->second);\n\t\tb=b*c%p;\n\t\
    }\n\treturn -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/mod_arithmetic.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/mod_arithmetic.hpp
layout: document
redirect_from:
- /library/number_theory/mod_arithmetic.hpp
- /library/number_theory/mod_arithmetic.hpp.html
title: number_theory/mod_arithmetic.hpp
---
