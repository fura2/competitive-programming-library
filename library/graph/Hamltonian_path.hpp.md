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
  bundledCode: "#line 1 \"library/graph/Hamltonian_path.hpp\"\n/*\n\t\u8FBA\u306B\u91CD\
    \u307F\u304C\u3064\u3044\u305F\u6709\u5411\u30B0\u30E9\u30D5 G \u306E\u30CF\u30DF\
    \u30EB\u30C8\u30F3\u8DEF (\u306E\u91CD\u307F) \u3092\u6C42\u3081\u308B\n\t\u6C42\
    \u3081\u308B\u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF\u306E\u59CB\u70B9\u3068\u7D42\
    \u70B9\u306F\u4EFB\u610F\n\n\tT \u306F\u91CD\u307F\u306E\u578B\n\tG \u306F\u96A3\
    \u63A5\u884C\u5217 A \u3067\u4E0E\u3048\u3089\u308C, \u8FBA\u304C\u306A\u3044\u90E8\
    \u5206\u306B\u306F T \u306E\u6700\u5927\u5024\u304C\u5165\u3063\u3066\u3044\u308B\
    \u3053\u3068\u3092\u4EEE\u5B9A\u3059\u308B\n\tG \u304C\u30CF\u30DF\u30EB\u30C8\
    \u30F3\u8DEF\u3092\u3082\u305F\u306A\u3044\u3068\u304D\u306F T \u306E\u6700\u5927\
    \u5024\u304C\u8FD4\u308B\n*/\n\ntemplate<class T>\nT Hamiltonian_path(const vector<vector<T>>&\
    \ A){\n\tconstexpr T INF=numeric_limits<T>::max();\n\tint n=A.size();\n\tvector\
    \ dp(1<<n,vector(n,INF));\n\trep(u,n) dp[1<<u][u]=0;\n\trep(S,1<<n) rep(u,n) if(S>>u&1\
    \ && dp[S][u]<INF) {\n\t\trep(v,n) if(~S>>v&1 && A[u][v]<INF) {\n\t\t\tdp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+A[u][v]);\n\
    \t\t}\n\t}\n\n\tT res=INF;\n\trep(u,n) res=min(res,dp[(1<<n)-1][u]);\n\treturn\
    \ res;\n}\n"
  code: "/*\n\t\u8FBA\u306B\u91CD\u307F\u304C\u3064\u3044\u305F\u6709\u5411\u30B0\u30E9\
    \u30D5 G \u306E\u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF (\u306E\u91CD\u307F) \u3092\
    \u6C42\u3081\u308B\n\t\u6C42\u3081\u308B\u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF\u306E\
    \u59CB\u70B9\u3068\u7D42\u70B9\u306F\u4EFB\u610F\n\n\tT \u306F\u91CD\u307F\u306E\
    \u578B\n\tG \u306F\u96A3\u63A5\u884C\u5217 A \u3067\u4E0E\u3048\u3089\u308C, \u8FBA\
    \u304C\u306A\u3044\u90E8\u5206\u306B\u306F T \u306E\u6700\u5927\u5024\u304C\u5165\
    \u3063\u3066\u3044\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3059\u308B\n\tG \u304C\
    \u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF\u3092\u3082\u305F\u306A\u3044\u3068\u304D\
    \u306F T \u306E\u6700\u5927\u5024\u304C\u8FD4\u308B\n*/\n\ntemplate<class T>\n\
    T Hamiltonian_path(const vector<vector<T>>& A){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \tint n=A.size();\n\tvector dp(1<<n,vector(n,INF));\n\trep(u,n) dp[1<<u][u]=0;\n\
    \trep(S,1<<n) rep(u,n) if(S>>u&1 && dp[S][u]<INF) {\n\t\trep(v,n) if(~S>>v&1 &&\
    \ A[u][v]<INF) {\n\t\t\tdp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+A[u][v]);\n\t\
    \t}\n\t}\n\n\tT res=INF;\n\trep(u,n) res=min(res,dp[(1<<n)-1][u]);\n\treturn res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/Hamltonian_path.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/Hamltonian_path.hpp
layout: document
redirect_from:
- /library/library/graph/Hamltonian_path.hpp
- /library/library/graph/Hamltonian_path.hpp.html
title: library/graph/Hamltonian_path.hpp
---
