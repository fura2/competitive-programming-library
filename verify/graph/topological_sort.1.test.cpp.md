---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':x:'
    path: library/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':question:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"verify/graph/topological_sort.1.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\n\n#line\
    \ 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n#include\
    \ <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 5 \"library/graph/topological_sort.hpp\"\n\nvector<int> topological_sort(const\
    \ graph& D){\n\tint n=D.size();\n\tvector<int> deg(n);\n\trep(u,n) for(int v:D[u])\
    \ deg[v]++;\n\n\tvector<int> res;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\
    \t\tfor(int v:D[u]) if(--deg[v]==0) Q.emplace(v);\n\t}\n\treturn res;\n}\n\ntemplate<class\
    \ T>\nvector<int> topological_sort(const weighted_graph<T>& D){\n\tint n=D.size();\n\
    \tvector<int> deg(n);\n\trep(u,n) for(const auto& e:D[u]) deg[e.to]++;\n\n\tvector<int>\
    \ res;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\t\tfor(const auto& e:D[u])\
    \ if(--deg[e.to]==0) Q.emplace(e.to);\n\t}\n\treturn res;\n}\n#line 5 \"verify/graph/topological_sort.1.test.cpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tgraph G(n);\n\trep(i,m){\n\
    \t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_directed_edge(G,u,v);\n\t}\n\n\t\
    for(int u:topological_sort(G)) printf(\"%d\\n\",u);\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/topological_sort.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tgraph G(n);\n\trep(i,m){\n\
    \t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_directed_edge(G,u,v);\n\t}\n\n\t\
    for(int u:topological_sort(G)) printf(\"%d\\n\",u);\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/topological_sort.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/topological_sort.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 18:20:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/topological_sort.1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/topological_sort.1.test.cpp
- /verify/verify/graph/topological_sort.1.test.cpp.html
title: verify/graph/topological_sort.1.test.cpp
---
