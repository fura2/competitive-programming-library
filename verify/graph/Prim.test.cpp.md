---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Prim.hpp
    title: Minimum Spanning Forest (Prim's Algorithm)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
  bundledCode: "#line 1 \"verify/graph/Prim.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 4 \"library/graph/Prim.hpp\"\n\ntemplate<class T>\npair<T,weighted_graph<T>>\
    \ Prim(const weighted_graph<T>& G){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \n\tint n=G.size();\n\tT total{};\n\tweighted_graph<T> MSF(n);\n\tvector<bool>\
    \ vis(n);\n\tvector<T> d(n,INF);\n\tvector<int> pre(n,-1);\n\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\trep(s,n) if(!vis[s]) {\n\t\td[s]=T{};\n\t\tQ.emplace(T{},s);\n\t\twhile(!Q.empty()){\n\
    \t\t\tT d0;\n\t\t\tint u; tie(d0,u)=Q.top();\n\t\t\tQ.pop();\n\t\t\tif(vis[u])\
    \ continue;\n\t\t\tvis[u]=true;\n\n\t\t\tif(pre[u]!=-1){\n\t\t\t\ttotal+=d[u];\n\
    \t\t\t\tadd_undirected_edge(MSF,u,pre[u],d[u]);\n\t\t\t}\n\n\t\t\tfor(const auto&\
    \ [v,wt]:G[u]){\n\t\t\t\tif(!vis[v] && d[v]>wt){\n\t\t\t\t\td[v]=wt;\n\t\t\t\t\
    \tpre[v]=u;\n\t\t\t\t\tQ.emplace(d[v],v);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\t\
    return {total,MSF};\n}\n#line 5 \"verify/graph/Prim.test.cpp\"\n\nint main(){\n\
    \tint n; scanf(\"%d\",&n);\n\tweighted_graph<int> G(n);\n\trep(u,n) rep(v,n) {\n\
    \t\tint c; scanf(\"%d\",&c);\n\t\tif(u<v && c!=-1) add_undirected_edge(G,u,v,c);\n\
    \t}\n\n\tprintf(\"%d\\n\",Prim(G).first);\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Prim.hpp\"\
    \n\nint main(){\n\tint n; scanf(\"%d\",&n);\n\tweighted_graph<int> G(n);\n\trep(u,n)\
    \ rep(v,n) {\n\t\tint c; scanf(\"%d\",&c);\n\t\tif(u<v && c!=-1) add_undirected_edge(G,u,v,c);\n\
    \t}\n\n\tprintf(\"%d\\n\",Prim(G).first);\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Prim.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Prim.test.cpp
  requiredBy: []
  timestamp: '2021-05-12 18:24:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Prim.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Prim.test.cpp
- /verify/verify/graph/Prim.test.cpp.html
title: verify/graph/Prim.test.cpp
---
