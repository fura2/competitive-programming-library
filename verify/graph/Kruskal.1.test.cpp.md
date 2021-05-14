---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/union-find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: library/graph/Kruskal.hpp
    title: Minimum Spanning Forest (Kruskal's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/graph/Kruskal.1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
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
    }\n#line 3 \"library/data_structure/union-find.hpp\"\n\nclass union_find{\n\t\
    int n;\n\tvector<int> p;\npublic:\n\tunion_find(int n=0){ build(n); }\n\tvoid\
    \ build(int n){\n\t\tthis->n=n;\n\t\tp.assign(n,-1);\n\t}\n\tint find(int u){\
    \ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int v){\n\t\tu=find(u);\
    \ v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\t\t\tp[u]+=p[v];\
    \ p[v]=u; n--;\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return find(u)==find(v);\
    \ }\n\tint size()const{ return n; }\n\tint size(int u){ return -p[find(u)]; }\n\
    };\n#line 5 \"library/graph/Kruskal.hpp\"\n\ntemplate<class T>\nT Kruskal(int\
    \ n,vector<tuple<int,int,T>> E){\n\tsort(E.begin(),E.end(),[](const auto& e,const\
    \ auto& f){\n\t\treturn get<2>(e)<get<2>(f);\n\t});\n\n\tT total{};\n\tunion_find\
    \ U(n);\n\tfor(const auto& [u,v,wt]:E){\n\t\tif(!U.is_same(u,v)){\n\t\t\tU.unite(u,v);\n\
    \t\t\ttotal+=wt;\n\t\t}\n\t}\n\treturn total;\n}\n\ntemplate<class T>\npair<T,weighted_graph<T>>\
    \ Kruskal(const weighted_graph<T>& G){\n\tint n=G.size();\n\tvector<tuple<int,int,T>>\
    \ E;\n\trep(u,n) for(const auto& [v,wt]:G[u]) {\n\t\tif(u<v) E.emplace_back(u,v,wt);\n\
    \t}\n\n\tsort(E.begin(),E.end(),[](const auto& e,const auto& f){\n\t\treturn get<2>(e)<get<2>(f);\n\
    \t});\n\n\tT total{};\n\tweighted_graph<T> MSF(n);\n\tunion_find U(n);\n\tfor(const\
    \ auto& [u,v,wt]:E){\n\t\tif(!U.is_same(u,v)){\n\t\t\tU.unite(u,v);\n\t\t\ttotal+=wt;\n\
    \t\t\tadd_undirected_edge(MSF,u,v,wt);\n\t\t}\n\t}\n\treturn {total,MSF};\n}\n\
    #line 5 \"verify/graph/Kruskal.1.test.cpp\"\n\nint main(){\n\tint n,m; scanf(\"\
    %d%d\",&n,&m);\n\tvector<tuple<int,int,int>> E(m);\n\trep(i,m){\n\t\tint u,v,c;\
    \ scanf(\"%d%d%d\",&u,&v,&c);\n\t\tE[i]=tie(u,v,c);\n\t}\n\n\tprintf(\"%d\\n\"\
    ,Kruskal(n,E));\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Kruskal.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tvector<tuple<int,int,int>>\
    \ E(m);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tE[i]=tie(u,v,c);\n\
    \t}\n\n\tprintf(\"%d\\n\",Kruskal(n,E));\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Kruskal.hpp
  - library/graph/wgraph.hpp
  - library/data_structure/union-find.hpp
  isVerificationFile: true
  path: verify/graph/Kruskal.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-12 17:41:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Kruskal.1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Kruskal.1.test.cpp
- /verify/verify/graph/Kruskal.1.test.cpp.html
title: verify/graph/Kruskal.1.test.cpp
---
