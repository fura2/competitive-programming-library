---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/cc.hpp
    title: Connected Components
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
  bundledCode: "#line 1 \"verify/graph/cc.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
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
    G[u].emplace_back(v);\n}\n#line 4 \"library/graph/cc.hpp\"\n\nvector<vector<int>>\
    \ connected_components(const graph& G){\n\tint n=G.size();\n\tvector<vector<int>>\
    \ res;\n\tvector<bool> vis(n);\n\trep(u,n) if(!vis[u]) {\n\t\tvis[u]=true;\n\t\
    \tres.emplace_back();\n\t\tqueue<int> Q; Q.emplace(u);\n\t\twhile(!Q.empty()){\n\
    \t\t\tint v=Q.front(); Q.pop();\n\t\t\tres.back().emplace_back(v);\n\t\t\tfor(int\
    \ w:G[v]) if(!vis[w]) {\n\t\t\t\tvis[w]=true;\n\t\t\t\tQ.emplace(w);\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn res;\n}\n#line 5 \"verify/graph/cc.test.cpp\"\n\nint main(){\n\
    \tint n,m; scanf(\"%d%d\",&n,&m);\n\tgraph G(n);\n\trep(i,m){\n\t\tint u,v; scanf(\"\
    %d%d\",&u,&v);\n\t\tadd_undirected_edge(G,u,v);\n\t}\n\n\tauto CC=connected_components(G);\n\
    \tvector<int> id(n);\n\trep(i,CC.size()) for(int u:CC[i]) id[u]=i;\n\n\tint q;\
    \ scanf(\"%d\",&q);\n\trep(_,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tputs(id[u]==id[v]?\"\
    yes\":\"no\");\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/cc.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tgraph G(n);\n\trep(i,m){\n\
    \t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_undirected_edge(G,u,v);\n\t}\n\n\t\
    auto CC=connected_components(G);\n\tvector<int> id(n);\n\trep(i,CC.size()) for(int\
    \ u:CC[i]) id[u]=i;\n\n\tint q; scanf(\"%d\",&q);\n\trep(_,q){\n\t\tint u,v; scanf(\"\
    %d%d\",&u,&v);\n\t\tputs(id[u]==id[v]?\"yes\":\"no\");\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/cc.hpp
  - library/graph/graph.hpp
  isVerificationFile: true
  path: verify/graph/cc.test.cpp
  requiredBy: []
  timestamp: '2021-05-12 11:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/cc.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/cc.test.cpp
- /verify/verify/graph/cc.test.cpp.html
title: verify/graph/cc.test.cpp
---
