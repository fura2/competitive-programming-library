---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/scc.hpp
    title: Strongly Connected Components (Kosaraju's Algorithm)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"verify/graph/scc.3.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
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
    G[u].emplace_back(v,wt);\n}\n#line 5 \"library/graph/scc.hpp\"\n\ntemplate<class\
    \ T>\nclass strongly_connected_components{ strongly_connected_components(const\
    \ T&)=delete; };\n\ntemplate<>\nclass strongly_connected_components<graph>{\n\t\
    vector<int> id;\n\tvector<vector<int>> Comp;\n\tgraph D;\n\npublic:\n\tstrongly_connected_components(const\
    \ graph& G={}){ build(G); }\n\n\tvoid build(const graph& G){\n\t\tint n=G.size();\n\
    \t\tgraph G_rev(n);\n\t\trep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);\n\
    \n\t\tint k;\n\t\tvector<int> top(n);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u)->void{\n\
    \t\t\tid[u]=0;\n\t\t\tfor(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);\n\t\t\ttop[k++]=u;\n\
    \t\t};\n\t\tauto dfs2=[&](auto&& dfs2,int u)->void{\n\t\t\tid[u]=k;\n\t\t\tfor(int\
    \ v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);\n\t\t};\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\
    \t\trep(u,n) if(id[u]==-1) dfs1(dfs1,u);\n\n\t\treverse(top.begin(),top.end());\n\
    \n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\tfor(int u:top) if(id[u]==-1) dfs2(dfs2,u),\
    \ k++;\n\n\t\tComp.resize(k);\n\t\tD.resize(k);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\
    \t\t\tfor(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);\n\t\t\
    }\n\t}\n\n\tint operator[](int u)const{ return id[u]; }\n\n\tconst vector<int>&\
    \ component(int i)const{ return Comp[i]; }\n\tconst graph& DAG()const{ return\
    \ D; }\n};\n\ntemplate<class W>\nclass strongly_connected_components<weighted_graph<W>>{\n\
    \tvector<int> id;\n\tvector<vector<int>> Comp;\n\tweighted_graph<W> D;\n\npublic:\n\
    \tstrongly_connected_components(const weighted_graph<W>& G={}){ build(G); }\n\n\
    \tvoid build(const weighted_graph<W>& G){\n\t\tint n=G.size();\n\t\tweighted_graph<W>\
    \ G_rev(n);\n\t\trep(u,n) for(const auto& [v,wt]:G[u]) add_directed_edge(G_rev,v,u,wt);\n\
    \n\t\tint k;\n\t\tvector<int> top(n);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u)->void{\n\
    \t\t\tid[u]=0;\n\t\t\tfor(const auto& [v,wt]:G[u]) if(id[v]==-1) dfs1(dfs1,v);\n\
    \t\t\ttop[k++]=u;\n\t\t};\n\t\tauto dfs2=[&](auto&& dfs2,int u)->void{\n\t\t\t\
    id[u]=k;\n\t\t\tfor(const auto& [v,wt]:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);\n\
    \t\t};\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\trep(u,n) if(id[u]==-1) dfs1(dfs1,u);\n\
    \n\t\treverse(top.begin(),top.end());\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\t\
    for(int u:top) if(id[u]==-1) dfs2(dfs2,u), k++;\n\n\t\tComp.resize(k);\n\t\tD.resize(k);\n\
    \t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\t\t\tfor(const auto& [v,wt]:G[u])\
    \ if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v],wt);\n\t\t}\n\t}\n\n\tint operator[](int\
    \ u)const{ return id[u]; }\n\n\tconst vector<int>& component(int i)const{ return\
    \ Comp[i]; }\n\tconst weighted_graph<W>& DAG()const{ return D; }\n};\n#line 5\
    \ \"verify/graph/scc.3.test.cpp\"\n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\
    \tweighted_graph<int> G(n);\n\trep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\
    \t\tadd_directed_edge(G,u,v,1);\n\t}\n\n\tstrongly_connected_components SCC(G);\n\
    \n\tint q; scanf(\"%d\",&q);\n\trep(_,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\
    \t\tputs(SCC[u]==SCC[v]?\"1\":\"0\");\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/scc.hpp\"\
    \n\nint main(){\n\tint n,m; scanf(\"%d%d\",&n,&m);\n\tweighted_graph<int> G(n);\n\
    \trep(i,m){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tadd_directed_edge(G,u,v,1);\n\
    \t}\n\n\tstrongly_connected_components SCC(G);\n\n\tint q; scanf(\"%d\",&q);\n\
    \trep(_,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tputs(SCC[u]==SCC[v]?\"1\"\
    :\"0\");\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/scc.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/scc.3.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 16:12:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/scc.3.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/scc.3.test.cpp
- /verify/verify/graph/scc.3.test.cpp.html
title: verify/graph/scc.3.test.cpp
---
