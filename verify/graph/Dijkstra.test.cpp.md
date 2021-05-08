---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/Dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':x:'
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/graph/Dijkstra.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
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
    }\n#line 4 \"library/graph/Dijkstra.hpp\"\n\ntemplate<class T>\nvector<T> Dijkstra(const\
    \ weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\t\
    int n=G.size();\n\tvector<T> d(n,INF); d[s]=0;\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(0,s);\nint cnt=0;\n\twhile(!Q.empty()){\ncnt++;\n\t\tT d0;\n\
    \t\tint u; tie(d0,u)=Q.top();\n\t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const\
    \ auto& e:G[u]){\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\
    \t\t\t\tQ.emplace(d[v],v);\n\t\t\t}\n\t\t}\n\t}\nprintf(\"n = %d, s = %d: cnt\
    \ = %d\\n\",n,s,cnt);\n\treturn d;\n}\n#line 5 \"verify/graph/Dijkstra.test.cpp\"\
    \n\nint main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n// fprintf(stdout,\"n = %d, m = %d, s = %d: max = %d, INT_MAX = %d\\n\",n,m,s,numeric_limits<int>::max(),INT_MAX);\n\
    // if(n==49000 && m==200000 && s==0) return 0;\n\n\tfor(auto d:Dijkstra(G,s)){\n\
    \t\tif(d<INT_MAX) printf(\"%d\\n\",d);\n\t\telse          puts(\"INF\");\n\t}\n\
    \n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Dijkstra.hpp\"\
    \n\nint main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n// fprintf(stdout,\"n = %d, m = %d, s = %d: max = %d, INT_MAX = %d\\n\",n,m,s,numeric_limits<int>::max(),INT_MAX);\n\
    // if(n==49000 && m==200000 && s==0) return 0;\n\n\tfor(auto d:Dijkstra(G,s)){\n\
    \t\tif(d<INT_MAX) printf(\"%d\\n\",d);\n\t\telse          puts(\"INF\");\n\t}\n\
    \n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-05-09 04:40:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Dijkstra.test.cpp
- /verify/verify/graph/Dijkstra.test.cpp.html
title: verify/graph/Dijkstra.test.cpp
---
