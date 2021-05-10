---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/tree_diameter.hpp
    title: Diameter of a Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/graph/tree_diameter.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 2 \"library/template.hpp\"\
    \n#include <cassert>\n#include <cctype>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n#include <algorithm>\n#include <deque>\n#include <functional>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n\nusing namespace std;\nusing lint=long long;\n#line 3 \"library/graph/graph.hpp\"\
    \n\nusing graph=vector<vector<int>>;\n\nvoid add_undirected_edge(graph& G,int\
    \ u,int v){\n\tG[u].emplace_back(v);\n\tG[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph&\
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\
    \n\ntemplate<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n#line 5 \"library/graph/tree_diameter.hpp\"\n\npair<int,vector<int>>\
    \ tree_diameter(const graph& T){\n\tint n=T.size();\n\tvector<int> pre(n,-1);\n\
    \n\tauto dfs=[&](auto&& dfs,int u,int p)->pair<int,int>{\n\t\tint g=u,d_max=0;\n\
    \t\tfor(int v:T[u]) if(v!=p) {\n\t\t\tauto [d,w]=dfs(dfs,v,u);\n\t\t\tif(d+1>d_max){\n\
    \t\t\t\td_max=d+1;\n\t\t\t\tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\t\t}\n\t\treturn\
    \ {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\tauto [diam,u1]=dfs(dfs,u0,-1);\n\
    \n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\t\tP.emplace_back(pre[u]);\n\
    \t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n}\n\ntemplate<class\
    \ W>\npair<W,vector<int>> tree_diameter(const weighted_graph<W>& T){\n\tint n=T.size();\n\
    \tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int u,int p)->pair<W,int>{\n\
    \t\tint g=u;\n\t\tW d_max=0;\n\t\tfor(auto e:T[u]) if(e.to!=p) {\n\t\t\tauto [d,v]=dfs(dfs,e.to,u);\n\
    \t\t\tif(d+e.wt>d_max){\n\t\t\t\td_max=d+e.wt;\n\t\t\t\tg=v;\n\t\t\t}\n\t\t\t\
    pre[e.to]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\
    \tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\
    \t\tP.emplace_back(pre[u]);\n\t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n\
    }\n#line 5 \"verify/graph/tree_diameter.2.test.cpp\"\n\nint main(){\n\tint n;\
    \ scanf(\"%d\",&n);\n\tweighted_graph<lint> T(n);\n\trep(i,n-1){\n\t\tint u,v;\n\
    \t\tlint c; scanf(\"%d%d%lld\",&u,&v,&c);\n\t\tadd_undirected_edge(T,u,v,c);\n\
    \t}\n\n\tauto [d,p]=tree_diameter(T);\n\tprintf(\"%lld %ld\\n\",d,p.size());\n\
    \trep(i,p.size()) printf(\"%d%c\",p[i],i+1<p.size()?' ':'\\n');\n\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../library/template.hpp\"\n#include \"../../library/graph/tree_diameter.hpp\"\
    \n\nint main(){\n\tint n; scanf(\"%d\",&n);\n\tweighted_graph<lint> T(n);\n\t\
    rep(i,n-1){\n\t\tint u,v;\n\t\tlint c; scanf(\"%d%d%lld\",&u,&v,&c);\n\t\tadd_undirected_edge(T,u,v,c);\n\
    \t}\n\n\tauto [d,p]=tree_diameter(T);\n\tprintf(\"%lld %ld\\n\",d,p.size());\n\
    \trep(i,p.size()) printf(\"%d%c\",p[i],i+1<p.size()?' ':'\\n');\n\n\treturn 0;\n\
    }\n"
  dependsOn:
  - library/template.hpp
  - library/graph/tree_diameter.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/tree_diameter.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 17:57:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/tree_diameter.2.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/tree_diameter.2.test.cpp
- /verify/verify/graph/tree_diameter.2.test.cpp.html
title: verify/graph/tree_diameter.2.test.cpp
---
