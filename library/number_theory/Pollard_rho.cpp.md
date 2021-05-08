---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number_theory/Pollard_rho.cpp\"\n/* \u7D20\u56E0\
    \u6570\u5206\u89E3 (Pollard's \u03C1) */\n/*\n\t\u8AAC\u660E\n\t\tn \u3092\u7D20\
    \u56E0\u6570\u5206\u89E3\u3059\u308B\n\t\u5F15\u6570\n\t\tn : \u6574\u6570\n\t\
    \u623B\u308A\u5024\n\t\tn \u306E\u7D20\u56E0\u6570\u5206\u89E3\n\t\u5236\u7D04\
    \n\t\t0 <= n < 2^63\n\t\u8A08\u7B97\u91CF\n\t\tO(n^{1/4} log n) \u7A0B\u5EA6\n\
    \t\u5099\u8003\n\t\tn = 0, 1 \u306E\u3068\u304D\u306F\u7A7A\u306E map \u304C\u8FD4\
    \u308B\n*/\n\nmap<lint,int> Pollard_rho(lint n){\n\tmap<lint,int> pf;\n\tif(n<=1)\
    \ return pf;\n\tif(Miller_Rabin(n)){ ++pf[n]; return pf; }\n\n\tauto divisor=[](lint\
    \ n,int c)->lint{\n\t\tif(n%2==0) return 2;\n\n\t\tlint x=2,y=2,d=1;\n\t\twhile(d==1){\n\
    \t\t\tx=__int128(x)*x%n+c; if(x<0) x+=n;\n\t\t\ty=__int128(y)*y%n+c; if(y<0) y+=n;\n\
    \t\t\ty=__int128(y)*y%n+c; if(y<0) y+=n;\n\t\t\td=gcd(abs(x-y),n);\n\t\t}\n\t\t\
    return d<n?d:-1;\n\t};\n\n\tlint d=-1;\n\tfor(int c=1;d==-1;c++) d=divisor(n,c);\n\
    \n\tfor(auto [p,e]:Pollard_rho( d )) pf[p]+=e;\n\tfor(auto [p,e]:Pollard_rho(n/d))\
    \ pf[p]+=e;\n\treturn pf;\n}\n"
  code: "/* \u7D20\u56E0\u6570\u5206\u89E3 (Pollard's \u03C1) */\n/*\n\t\u8AAC\u660E\
    \n\t\tn \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n\t\u5F15\u6570\n\t\t\
    n : \u6574\u6570\n\t\u623B\u308A\u5024\n\t\tn \u306E\u7D20\u56E0\u6570\u5206\u89E3\
    \n\t\u5236\u7D04\n\t\t0 <= n < 2^63\n\t\u8A08\u7B97\u91CF\n\t\tO(n^{1/4} log n)\
    \ \u7A0B\u5EA6\n\t\u5099\u8003\n\t\tn = 0, 1 \u306E\u3068\u304D\u306F\u7A7A\u306E\
    \ map \u304C\u8FD4\u308B\n*/\n\nmap<lint,int> Pollard_rho(lint n){\n\tmap<lint,int>\
    \ pf;\n\tif(n<=1) return pf;\n\tif(Miller_Rabin(n)){ ++pf[n]; return pf; }\n\n\
    \tauto divisor=[](lint n,int c)->lint{\n\t\tif(n%2==0) return 2;\n\n\t\tlint x=2,y=2,d=1;\n\
    \t\twhile(d==1){\n\t\t\tx=__int128(x)*x%n+c; if(x<0) x+=n;\n\t\t\ty=__int128(y)*y%n+c;\
    \ if(y<0) y+=n;\n\t\t\ty=__int128(y)*y%n+c; if(y<0) y+=n;\n\t\t\td=gcd(abs(x-y),n);\n\
    \t\t}\n\t\treturn d<n?d:-1;\n\t};\n\n\tlint d=-1;\n\tfor(int c=1;d==-1;c++) d=divisor(n,c);\n\
    \n\tfor(auto [p,e]:Pollard_rho( d )) pf[p]+=e;\n\tfor(auto [p,e]:Pollard_rho(n/d))\
    \ pf[p]+=e;\n\treturn pf;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number_theory/Pollard_rho.cpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number_theory/Pollard_rho.cpp
layout: document
redirect_from:
- /library/library/number_theory/Pollard_rho.cpp
- /library/library/number_theory/Pollard_rho.cpp.html
title: library/number_theory/Pollard_rho.cpp
---
