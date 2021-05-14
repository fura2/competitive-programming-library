---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/tecc.hpp
    title: Two-Edge Connected Components
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"verify/graph/tecc.2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
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
    G[u].emplace_back(v);\n}\n#line 4 \"library/graph/tecc.hpp\"\n\nclass two_edge_connected_components{\n\
    \tvector<int> id;\n\tvector<vector<int>> Comp;\n\tvector<pair<int,int>> B;\n\t\
    graph BBF;\n\npublic:\n\ttwo_edge_connected_components(const graph& G=graph()){\
    \ build(G); }\n\n\tvoid build(const graph& G){\n\t\tint n=G.size(),idx;\n\t\t\
    vector<int> ord(n,-1),low(n,-1);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u,int p)->void{\n\
    \t\t\tord[u]=low[u]=idx++;\n\t\t\tbool f=true;\n\t\t\tfor(int v:G[u]){\n\t\t\t\
    \tif(v==p && f){ f=false; continue; }\n\t\t\t\tif(ord[v]==-1){\n\t\t\t\t\tdfs1(dfs1,v,u);\n\
    \t\t\t\t\tlow[u]=min(low[u],low[v]);\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\tlow[u]=min(low[u],ord[v]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t};\n\n\t\tauto dfs2=[&](auto&& dfs2,int u,int p)->void{\n\
    \t\t\tif(p==-1 || ord[p]<low[u]){\n\t\t\t\tid[u]=idx++;\n\t\t\t\tif(p!=-1) B.emplace_back(minmax(p,u));\n\
    \t\t\t}\n\t\t\telse{\n\t\t\t\tid[u]=id[p];\n\t\t\t}\n\t\t\tfor(int v:G[u]) if(id[v]==-1)\
    \ dfs2(dfs2,v,u);\n\t\t};\n\n\t\tidx=0;\n\t\trep(u,n) if(ord[u]==-1) dfs1(dfs1,u,-1);\n\
    \n\t\tidx=0;\n\t\tid.assign(n,-1);\n\t\trep(u,n) if(id[u]==-1) dfs2(dfs2,u,-1);\n\
    \n\t\tComp.resize(idx);\n\t\tBBF.resize(idx);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\
    \t\t\tfor(int v:G[u]) if(id[u]!=id[v]) BBF[id[u]].emplace_back(id[v]);\n\t\t}\n\
    \t}\n\n\tint operator[](int i)const{ return id[i]; }\n\n\tconst vector<int>& component(int\
    \ i)const{ return Comp[i]; }\n\tconst vector<pair<int,int>>& bridges()const{ return\
    \ B; }\n\tconst graph& bridge_block_forest()const{ return BBF; }\n};\n#line 5\
    \ \"verify/graph/tecc.2.test.cpp\"\n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\
    \tgraph G(n);\n\trep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_undirected_edge(G,u,v);\n\
    \t}\n\n\tauto B=two_edge_connected_components(G).bridges();\n\tsort(B.begin(),B.end());\n\
    \n\tfor(auto [u,v]:B) printf(\"%d %d\\n\",u,v);\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/tecc.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tgraph G(n);\n\trep(i,m){\n\
    \t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_undirected_edge(G,u,v);\n\t}\n\n\t\
    auto B=two_edge_connected_components(G).bridges();\n\tsort(B.begin(),B.end());\n\
    \n\tfor(auto [u,v]:B) printf(\"%d %d\\n\",u,v);\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/tecc.hpp
  - library/graph/graph.hpp
  isVerificationFile: true
  path: verify/graph/tecc.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-14 20:18:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/tecc.2.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/tecc.2.test.cpp
- /verify/verify/graph/tecc.2.test.cpp.html
title: verify/graph/tecc.2.test.cpp
---
