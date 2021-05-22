---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/distance_01.hpp
    title: Single-Source Shortest Path ($01$-BFS)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945
  bundledCode: "#line 1 \"verify/graph/distance_01.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945\"\n\n#line 2 \"\
    library/template.hpp\"\n#include <cassert>\n#include <cctype>\n#include <chrono>\n\
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
    }\n#line 4 \"library/graph/distance_01.hpp\"\n\nvector<int> distance_01(const\
    \ weighted_graph<int>& G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\
    \tvector<int> d(n,INF);\n\td[s]=0;\n\tdeque<int> Q; Q.emplace_back(s);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop_front();\n\t\tfor(const auto& [v,wt]:G[u]){\n\t\t\t\
    if(d[v]>d[u]+wt){\n\t\t\t\td[v]=d[u]+wt;\n\t\t\t\tif(wt==0) Q.emplace_front(v);\n\
    \t\t\t\telse      Q.emplace_back(v);\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n#line\
    \ 5 \"verify/graph/distance_01.test.cpp\"\n\nint main(){\n\twhile(1){\n\t\tint\
    \ n; scanf(\"%d\",&n);\n\t\tif(n==0) break;\n\t\tint a,b,c,d; scanf(\"%d%d%d%d\"\
    ,&a,&b,&c,&d); a--; b--;\n\n\t\tint h=100,w=100;\n\t\tvector B(h,vector(w,1));\n\
    \t\tfor(int i=a;i<c;i++) for(int j=b;j<d;j++) B[i][j]=0;\n\n\t\tweighted_graph<int>\
    \ G(h*w);\n\t\trep(i,h) rep(j,w) {\n\t\t\tif(i<h-1){\n\t\t\t\tadd_directed_edge(G,i*w+j,(i+1)*w+j,B[i+1][j]);\n\
    \t\t\t\tadd_directed_edge(G,(i+1)*w+j,i*w+j,B[i][j]);\n\t\t\t}\n\t\t\tif(j<w-1){\n\
    \t\t\t\tadd_directed_edge(G,i*w+j,i*w+(j+1),B[i][j+1]);\n\t\t\t\tadd_directed_edge(G,i*w+(j+1),i*w+j,B[i][j]);\n\
    \t\t\t}\n\t\t}\n\n\t\tint ans=0;\n\t\tint x0,y0; scanf(\"%d%d\",&x0,&y0); x0--;\
    \ y0--;\n\t\trep(i,n){\n\t\t\tint x1,y1; scanf(\"%d%d\",&x1,&y1); x1--; y1--;\n\
    \t\t\tans+=distance_01(G,x0*w+y0)[x1*w+y1];\n\t\t\tx0=x1;\n\t\t\ty0=y1;\n\t\t\
    }\n\t\tprintf(\"%d\\n\",ans);\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/distance_01.hpp\"\
    \n\nint main(){\n\twhile(1){\n\t\tint n; scanf(\"%d\",&n);\n\t\tif(n==0) break;\n\
    \t\tint a,b,c,d; scanf(\"%d%d%d%d\",&a,&b,&c,&d); a--; b--;\n\n\t\tint h=100,w=100;\n\
    \t\tvector B(h,vector(w,1));\n\t\tfor(int i=a;i<c;i++) for(int j=b;j<d;j++) B[i][j]=0;\n\
    \n\t\tweighted_graph<int> G(h*w);\n\t\trep(i,h) rep(j,w) {\n\t\t\tif(i<h-1){\n\
    \t\t\t\tadd_directed_edge(G,i*w+j,(i+1)*w+j,B[i+1][j]);\n\t\t\t\tadd_directed_edge(G,(i+1)*w+j,i*w+j,B[i][j]);\n\
    \t\t\t}\n\t\t\tif(j<w-1){\n\t\t\t\tadd_directed_edge(G,i*w+j,i*w+(j+1),B[i][j+1]);\n\
    \t\t\t\tadd_directed_edge(G,i*w+(j+1),i*w+j,B[i][j]);\n\t\t\t}\n\t\t}\n\n\t\t\
    int ans=0;\n\t\tint x0,y0; scanf(\"%d%d\",&x0,&y0); x0--; y0--;\n\t\trep(i,n){\n\
    \t\t\tint x1,y1; scanf(\"%d%d\",&x1,&y1); x1--; y1--;\n\t\t\tans+=distance_01(G,x0*w+y0)[x1*w+y1];\n\
    \t\t\tx0=x1;\n\t\t\ty0=y1;\n\t\t}\n\t\tprintf(\"%d\\n\",ans);\n\t}\n\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/distance_01.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/distance_01.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/distance_01.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/distance_01.test.cpp
- /verify/verify/graph/distance_01.test.cpp.html
title: verify/graph/distance_01.test.cpp
---
