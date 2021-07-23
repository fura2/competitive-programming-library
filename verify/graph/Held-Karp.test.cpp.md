---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Held-Karp.hpp
    title: Travelling Salesman Problem (Held-Karp Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"verify/graph/Held-Karp.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/graph/Held-Karp.hpp\"\
    \n\n/*\n\t\u8FBA\u306B\u91CD\u307F\u304C\u3064\u3044\u305F\u6709\u5411\u30B0\u30E9\
    \u30D5 G \u306E\u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF (\u306E\u91CD\u307F) \u3092\
    \u6C42\u3081\u308B\n\t\u6C42\u3081\u308B\u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF\u306E\
    \u59CB\u70B9\u3068\u7D42\u70B9\u306F\u4EFB\u610F\n\n\tT \u306F\u91CD\u307F\u306E\
    \u578B\n\tG \u306F\u96A3\u63A5\u884C\u5217 A \u3067\u4E0E\u3048\u3089\u308C, \u8FBA\
    \u304C\u306A\u3044\u90E8\u5206\u306B\u306F T \u306E\u6700\u5927\u5024\u304C\u5165\
    \u3063\u3066\u3044\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3059\u308B\n\tG \u304C\
    \u30CF\u30DF\u30EB\u30C8\u30F3\u8DEF\u3092\u3082\u305F\u306A\u3044\u3068\u304D\
    \u306F T \u306E\u6700\u5927\u5024\u304C\u8FD4\u308B\n*/\n\ntemplate<class T>\n\
    T Held_Karp(const vector<vector<T>>& d){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \tint n=d.size();\n\tvector dp(1<<n,vector(n,INF));\n\tdp[1<<0][0]=T();\n\trep(S,1<<n)\
    \ rep(u,n) if(S>>u&1 && dp[S][u]<INF) {\n\t\trep(v,n) if(~S>>v&1 && d[u][v]<INF)\
    \ {\n\t\t\tdp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+d[u][v]);\n\t\t}\n\t}\n\n\t\
    T res=INF;\n\trep(u,n) if(dp[(1<<n)-1][u]<INF && d[u][0]<INF) {\n\t\tres=min(res,dp[(1<<n)-1][u]+d[u][0]);\n\
    \t}\n\treturn res;\n}\n#line 5 \"verify/graph/Held-Karp.test.cpp\"\n\nint main(){\n\
    \tint n,m; scanf(\"%d%d\",&n,&m);\n\tvector d(n,vector(n,INT_MAX));\n\trep(i,m){\n\
    \t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\td[u][v]=c;\n\t}\n\n\tint ans=Held_Karp(d);\n\
    \tprintf(\"%d\\n\",ans<INT_MAX?ans:-1);\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Held-Karp.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tvector d(n,vector(n,INT_MAX));\n\
    \trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\td[u][v]=c;\n\t}\n\
    \n\tint ans=Held_Karp(d);\n\tprintf(\"%d\\n\",ans<INT_MAX?ans:-1);\n\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Held-Karp.hpp
  isVerificationFile: true
  path: verify/graph/Held-Karp.test.cpp
  requiredBy: []
  timestamp: '2021-07-23 16:58:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Held-Karp.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Held-Karp.test.cpp
- /verify/verify/graph/Held-Karp.test.cpp.html
title: verify/graph/Held-Karp.test.cpp
---
