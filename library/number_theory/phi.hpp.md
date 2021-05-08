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
  bundledCode: "#line 1 \"library/number_theory/phi.hpp\"\n// Euler's totient function\n\
    // O(sqrt(a))\n\nlong long phi(long long a){\n\tlong long res=a;\n\tfor(long long\
    \ p=2;p*p<=a;p++) if(a%p==0) {\n\t\tres=res/p*(p-1);\n\t\tdo{ a/=p; }while(a%p==0);\n\
    \t}\n\tif(a>1) res=res/a*(a-1);\n\treturn res;\n}\n\n// phi(1), ..., phi(n) \u306E\
    \u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u6210\u3059\u308B\n// O(n loglog n)\nvector<int>\
    \ phi;\nvoid build_phi(int n){\n\tphi.resize(n+1);\n\tiota(phi.begin(),phi.end(),0);\n\
    \tfor(int i=2;i<=n;i++) if(phi[i]==i) {\n\t\tfor(int j=i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);\n\
    \t}\n}\n"
  code: "// Euler's totient function\n// O(sqrt(a))\n\nlong long phi(long long a){\n\
    \tlong long res=a;\n\tfor(long long p=2;p*p<=a;p++) if(a%p==0) {\n\t\tres=res/p*(p-1);\n\
    \t\tdo{ a/=p; }while(a%p==0);\n\t}\n\tif(a>1) res=res/a*(a-1);\n\treturn res;\n\
    }\n\n// phi(1), ..., phi(n) \u306E\u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u6210\u3059\
    \u308B\n// O(n loglog n)\nvector<int> phi;\nvoid build_phi(int n){\n\tphi.resize(n+1);\n\
    \tiota(phi.begin(),phi.end(),0);\n\tfor(int i=2;i<=n;i++) if(phi[i]==i) {\n\t\t\
    for(int j=i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number_theory/phi.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number_theory/phi.hpp
layout: document
redirect_from:
- /library/library/number_theory/phi.hpp
- /library/library/number_theory/phi.hpp.html
title: library/number_theory/phi.hpp
---
