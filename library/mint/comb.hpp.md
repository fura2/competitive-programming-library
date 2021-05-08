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
  bundledCode: "#line 1 \"library/mint/comb.hpp\"\nmint pow(mint m,long long k){\n\
    \tmint res=1;\n\tfor(;k>0;k>>=1,m*=m) if(k&1) res*=m;\n\treturn res;\n}\n\nmint\
    \ fact(int n){\n\tstatic vector<mint> memo={1};\n\tif(memo.size()<=n){\n\t\tint\
    \ k=memo.size();\n\t\tmemo.resize(n+1);\n\t\tfor(;k<=n;k++) memo[k]=memo[k-1]*k;\n\
    \t}\n\treturn memo[n];\n}\n\nmint fact_inverse(int n){\n\tstatic vector<mint>\
    \ memo={1};\n\tif(memo.size()<=n){\n\t\tint k=memo.size();\n\t\tmemo.resize(n+1);\n\
    \t\tmemo[n]=inverse(fact(n));\n\t\tfor(int i=n;i>k;i--) memo[i-1]=memo[i]*i;\n\
    \t}\n\treturn memo[n];\n}\n\nmint choose(int n,int k,int type=0){\n\tif(k==0)\
    \ return 1;\n\tif(n< k) return 0;\n\tif(type==0){\n\t\treturn fact(n)*fact_inverse(k)*fact_inverse(n-k);\n\
    \t}\n\telse{\n\t\tif(k>n-k) k=n-k;\n\t\tmint res=fact_inverse(k);\n\t\trep(i,k)\
    \ res*=n-i;\n\t\treturn res;\n\t}\n}\n\nmint multichoose(int n,int k,int type=0){\n\
    \treturn choose(n+k-1,k,type);\n}\n"
  code: "mint pow(mint m,long long k){\n\tmint res=1;\n\tfor(;k>0;k>>=1,m*=m) if(k&1)\
    \ res*=m;\n\treturn res;\n}\n\nmint fact(int n){\n\tstatic vector<mint> memo={1};\n\
    \tif(memo.size()<=n){\n\t\tint k=memo.size();\n\t\tmemo.resize(n+1);\n\t\tfor(;k<=n;k++)\
    \ memo[k]=memo[k-1]*k;\n\t}\n\treturn memo[n];\n}\n\nmint fact_inverse(int n){\n\
    \tstatic vector<mint> memo={1};\n\tif(memo.size()<=n){\n\t\tint k=memo.size();\n\
    \t\tmemo.resize(n+1);\n\t\tmemo[n]=inverse(fact(n));\n\t\tfor(int i=n;i>k;i--)\
    \ memo[i-1]=memo[i]*i;\n\t}\n\treturn memo[n];\n}\n\nmint choose(int n,int k,int\
    \ type=0){\n\tif(k==0) return 1;\n\tif(n< k) return 0;\n\tif(type==0){\n\t\treturn\
    \ fact(n)*fact_inverse(k)*fact_inverse(n-k);\n\t}\n\telse{\n\t\tif(k>n-k) k=n-k;\n\
    \t\tmint res=fact_inverse(k);\n\t\trep(i,k) res*=n-i;\n\t\treturn res;\n\t}\n\
    }\n\nmint multichoose(int n,int k,int type=0){\n\treturn choose(n+k-1,k,type);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/mint/comb.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mint/comb.hpp
layout: document
redirect_from:
- /library/library/mint/comb.hpp
- /library/library/mint/comb.hpp.html
title: library/mint/comb.hpp
---
