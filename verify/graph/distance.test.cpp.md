---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/distance.hpp
    title: Single-Source Shortest Path (Unweighted Graph)
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"verify/graph/distance.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n#line 4 \"library/graph/distance.hpp\"\n\nvector<int>\
    \ distance(const graph& G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\
    \tvector<int> d(n,INF);\n\td[s]=0;\n\tqueue<int> Q; Q.emplace(s);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tfor(int v:G[u]) if(d[v]==INF) {\n\t\t\td[v]=d[u]+1;\n\
    \t\t\tQ.emplace(v);\n\t\t}\n\t}\n\treturn d;\n}\n#line 5 \"verify/graph/distance.test.cpp\"\
    \n\nint main(){\n\tint n; scanf(\"%d\",&n);\n\tgraph G(n);\n\trep(i,n){\n\t\t\
    int u,k; scanf(\"%d%d\",&u,&k); u--;\n\t\tG[u].resize(k);\n\t\trep(j,k){\n\t\t\
    \tint v; scanf(\"%d\",&v); v--;\n\t\t\tadd_directed_edge(G,u,v);\n\t\t}\n\t}\n\
    \n\tauto d=distance(G,0);\n\trep(u,n) printf(\"%d %d\\n\",u+1,d[u]<INT_MAX?d[u]:-1);\n\
    \n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/distance.hpp\"\
    \n\nint main(){\n\tint n; scanf(\"%d\",&n);\n\tgraph G(n);\n\trep(i,n){\n\t\t\
    int u,k; scanf(\"%d%d\",&u,&k); u--;\n\t\tG[u].resize(k);\n\t\trep(j,k){\n\t\t\
    \tint v; scanf(\"%d\",&v); v--;\n\t\t\tadd_directed_edge(G,u,v);\n\t\t}\n\t}\n\
    \n\tauto d=distance(G,0);\n\trep(u,n) printf(\"%d %d\\n\",u+1,d[u]<INT_MAX?d[u]:-1);\n\
    \n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/distance.hpp
  - library/graph/graph.hpp
  isVerificationFile: true
  path: verify/graph/distance.test.cpp
  requiredBy: []
  timestamp: '2021-05-12 10:49:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/distance.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/distance.test.cpp
- /verify/verify/graph/distance.test.cpp.html
title: verify/graph/distance.test.cpp
---
