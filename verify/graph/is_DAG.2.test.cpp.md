---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/is_DAG.hpp
    title: DAG Detection
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
  bundledCode: "#line 1 \"verify/graph/is_DAG.2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/graph/graph.hpp\"\
    \n\nusing graph=vector<vector<int>>;\n\nvoid add_undirected_edge(graph& G,int\
    \ u,int v){\n\tG[u].emplace_back(v);\n\tG[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph&\
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\
    \n\ntemplate<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n#line 5 \"library/graph/is_DAG.hpp\"\n\nbool is_DAG(const\
    \ graph& G){\n\tint n=G.size();\n\tvector<int> deg(n);\n\trep(u,n) for(int v:G[u])\
    \ deg[v]++;\n\n\tint cnt=0;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tcnt++;\n\t\tfor(int v:G[u])\
    \ if(--deg[v]==0) Q.emplace(v);\n\t}\n\treturn cnt==n;\n}\n\ntemplate<class T>\n\
    bool is_DAG(const weighted_graph<T>& G){\n\tint n=G.size();\n\tvector<int> deg(n);\n\
    \trep(u,n) for(const auto& [v,wt]:G[u]) deg[v]++;\n\n\tint cnt=0;\n\tqueue<int>\
    \ Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front();\
    \ Q.pop();\n\t\tcnt++;\n\t\tfor(const auto& [v,wt]:G[u]) if(--deg[v]==0) Q.emplace(v);\n\
    \t}\n\treturn cnt==n;\n}\n#line 5 \"verify/graph/is_DAG.2.test.cpp\"\n\nint main(){\n\
    \tint n,m; scanf(\"%d%d\",&n,&m);\n\tweighted_graph<int> G(n);\n\trep(i,m){\n\t\
    \tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_directed_edge(G,u,v,1);\n\t}\n\n\t\
    puts(is_DAG(G)?\"0\":\"1\");\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/is_DAG.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tweighted_graph<int> G(n);\n\
    \trep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_directed_edge(G,u,v,1);\n\
    \t}\n\n\tputs(is_DAG(G)?\"0\":\"1\");\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/is_DAG.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/is_DAG.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/is_DAG.2.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/is_DAG.2.test.cpp
- /verify/verify/graph/is_DAG.2.test.cpp.html
title: verify/graph/is_DAG.2.test.cpp
---
