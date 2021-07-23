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
    \n\ntemplate<class T>\nT Held_Karp(const vector<vector<T>>& d){\n\tconstexpr T\
    \ INF=numeric_limits<T>::max();\n\tint n=d.size();\n\tvector dp(1<<n,vector(n,INF));\n\
    \tdp[1<<0][0]=T();\n\trep(S,1<<n) rep(u,n) if(S>>u&1 && dp[S][u]<INF) {\n\t\t\
    rep(v,n) if(~S>>v&1 && d[u][v]<INF) {\n\t\t\tdp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+d[u][v]);\n\
    \t\t}\n\t}\n\n\tT res=INF;\n\trep(u,n) if(dp[(1<<n)-1][u]<INF && d[u][0]<INF)\
    \ {\n\t\tres=min(res,dp[(1<<n)-1][u]+d[u][0]);\n\t}\n\treturn res;\n}\n#line 5\
    \ \"verify/graph/Held-Karp.test.cpp\"\n\nint main(){\n\tint n,m; scanf(\"%d%d\"\
    ,&n,&m);\n\tvector d(n,vector(n,INT_MAX));\n\trep(i,m){\n\t\tint u,v,c; scanf(\"\
    %d%d%d\",&u,&v,&c);\n\t\td[u][v]=c;\n\t}\n\n\tint ans=Held_Karp(d);\n\tprintf(\"\
    %d\\n\",ans<INT_MAX?ans:-1);\n\n\treturn 0;\n}\n"
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
  timestamp: '2021-07-23 17:18:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Held-Karp.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Held-Karp.test.cpp
- /verify/verify/graph/Held-Karp.test.cpp.html
title: verify/graph/Held-Karp.test.cpp
---
