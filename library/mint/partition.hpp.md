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
  bundledCode: "#line 1 \"library/mint/partition.hpp\"\n/*\n\t\u5206\u5272\u6570 P(n,\
    \ k)\n\t\tn \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u30DC\u30FC\u30EB\
    \u3092 k \u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u3051\u308B\u65B9\u6CD5\
    \u306E\u6570\n\t\t\u3042\u308B\u3044\u306F, n \u3092 k \u500B\u306E\u975E\u8CA0\
    \u6574\u6570\u306E\u548C\u3067\u66F8\u304F\u65B9\u6CD5\u306E\u6570 (\u548C\u306E\
    \u9806\u5E8F\u306F\u533A\u5225\u3057\u306A\u3044)\n*/\n\nmint partition(int n,int\
    \ k){\n\tvector dp(n+1,vector(k+1,mint(0)));\n\trep(j,k+1) dp[0][j]=1;\n\tfor(int\
    \ i=1;i<=n;i++){\n\t\tfor(int j=1;j<=k;j++) dp[i][j]=dp[i][j-1]+(j<=i?dp[i-j][j]:0);\n\
    \t}\n\treturn dp[n][k];\n}\n\nvector<vector<mint>> Part;\nvoid build_partition(int\
    \ n,int k){\n\tPart.assign(n+1,vector(k+1,mint(0)));\n\trep(j,k+1) Part[0][j]=1;\n\
    \tfor(int i=1;i<=n;i++){\n\t\tfor(int j=1;j<=k;j++) Part[i][j]=Part[i][j-1]+(j<=i?Part[i-j][j]:0);\n\
    \t}\n}\n"
  code: "/*\n\t\u5206\u5272\u6570 P(n, k)\n\t\tn \u500B\u306E\u533A\u5225\u3067\u304D\
    \u306A\u3044\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570\n\t\t\u3042\u308B\u3044\u306F, n \u3092\
    \ k \u500B\u306E\u975E\u8CA0\u6574\u6570\u306E\u548C\u3067\u66F8\u304F\u65B9\u6CD5\
    \u306E\u6570 (\u548C\u306E\u9806\u5E8F\u306F\u533A\u5225\u3057\u306A\u3044)\n\
    */\n\nmint partition(int n,int k){\n\tvector dp(n+1,vector(k+1,mint(0)));\n\t\
    rep(j,k+1) dp[0][j]=1;\n\tfor(int i=1;i<=n;i++){\n\t\tfor(int j=1;j<=k;j++) dp[i][j]=dp[i][j-1]+(j<=i?dp[i-j][j]:0);\n\
    \t}\n\treturn dp[n][k];\n}\n\nvector<vector<mint>> Part;\nvoid build_partition(int\
    \ n,int k){\n\tPart.assign(n+1,vector(k+1,mint(0)));\n\trep(j,k+1) Part[0][j]=1;\n\
    \tfor(int i=1;i<=n;i++){\n\t\tfor(int j=1;j<=k;j++) Part[i][j]=Part[i][j-1]+(j<=i?Part[i-j][j]:0);\n\
    \t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/mint/partition.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mint/partition.hpp
layout: document
redirect_from:
- /library/library/mint/partition.hpp
- /library/library/mint/partition.hpp.html
title: library/mint/partition.hpp
---
