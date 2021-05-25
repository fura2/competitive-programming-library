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
  bundledCode: "#line 1 \"library/misc/binomial_table.hpp\"\n\nvector<vector<long\
    \ long>> binomial_table(int n){\n\tvector C(n+1,vector(n+1,0LL));\n\trep(i,n+1){\n\
    \t\tC[i][0]=1;\n\t\tfor(int j=1;j<=i;j++){\n\t\t\tC[i][j]=C[i-1][j-1]+C[i-1][j];\n\
    \t\t}\n\t}\n\treturn C;\n}\n"
  code: "\nvector<vector<long long>> binomial_table(int n){\n\tvector C(n+1,vector(n+1,0LL));\n\
    \trep(i,n+1){\n\t\tC[i][0]=1;\n\t\tfor(int j=1;j<=i;j++){\n\t\t\tC[i][j]=C[i-1][j-1]+C[i-1][j];\n\
    \t\t}\n\t}\n\treturn C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/binomial_table.hpp
  requiredBy: []
  timestamp: '2021-05-25 23:23:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/binomial_table.hpp
layout: document
redirect_from:
- /library/library/misc/binomial_table.hpp
- /library/library/misc/binomial_table.hpp.html
title: library/misc/binomial_table.hpp
---
