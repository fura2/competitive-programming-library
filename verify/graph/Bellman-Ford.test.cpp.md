---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Bellman-Ford.hpp
    title: Single-Source Shortest Path (Bellman-Ford Algorithm)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"verify/graph/Bellman-Ford.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#line 2\
    \ \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n#include <chrono>\n\
    #include <climits>\n#include <cmath>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <ctime>\n#include <algorithm>\n#include <deque>\n\
    #include <functional>\n#include <iostream>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace\
    \ std;\nusing lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 4 \"library/graph/Bellman-Ford.hpp\"\n\ntemplate<class T>\nvector<T>\
    \ Bellman_Ford(const weighted_graph<T>& G,int s){\n\tconst T INF=numeric_limits<T>::max();\n\
    \tconst T NINF=numeric_limits<T>::min();\n\n\tint n=G.size();\n\tvector<T> d(n,INF);\n\
    \td[s]=T{};\n\trep(_,n){\n\t\tbool upd=false;\n\t\trep(u,n) if(d[u]<INF) for(const\
    \ auto& [v,wt]:G[u]) {\n\t\t\tif(d[v]>d[u]+wt) d[v]=d[u]+wt, upd=true;\n\t\t}\n\
    \t\tif(!upd) return d;\n\t}\n\n\tqueue<int> Q;\n\trep(u,n) if(d[u]<INF) Q.emplace(u);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tfor(const auto& [v,wt]:G[u]){\n\
    \t\t\tif(d[v]>NINF && (d[u]==NINF || d[v]>d[u]+wt)) d[v]=NINF, Q.emplace(v);\n\
    \t\t}\n\t}\n\treturn d;\n}\n#line 5 \"verify/graph/Bellman-Ford.test.cpp\"\n\n\
    int main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int> G(n);\n\
    \trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n\n\tauto d=Bellman_Ford(G,s);\n\tif(count(d.begin(),d.end(),INT_MIN)>0){\n\
    \t\tputs(\"NEGATIVE CYCLE\");\n\t}\n\telse{\n\t\trep(u,n){\n\t\t\tif(d[u]<INT_MAX)\
    \ printf(\"%d\\n\",d[u]);\n\t\t\telse             puts(\"INF\");\n\t\t}\n\t}\n\
    \n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Bellman-Ford.hpp\"\
    \n\nint main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n\n\tauto d=Bellman_Ford(G,s);\n\tif(count(d.begin(),d.end(),INT_MIN)>0){\n\
    \t\tputs(\"NEGATIVE CYCLE\");\n\t}\n\telse{\n\t\trep(u,n){\n\t\t\tif(d[u]<INT_MAX)\
    \ printf(\"%d\\n\",d[u]);\n\t\t\telse             puts(\"INF\");\n\t\t}\n\t}\n\
    \n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Bellman-Ford.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Bellman-Ford.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Bellman-Ford.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Bellman-Ford.test.cpp
- /verify/verify/graph/Bellman-Ford.test.cpp.html
title: verify/graph/Bellman-Ford.test.cpp
---
