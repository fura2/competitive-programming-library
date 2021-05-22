---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/lca.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/tree/lca.1.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    G[u].emplace_back(v,wt);\n}\n#line 5 \"library/tree/lca.hpp\"\n\ntemplate<class\
    \ T>\nclass lowest_common_ancestor{ lowest_common_ancestor(const T&,int)=delete;\
    \ };\n\ntemplate<>\nclass lowest_common_ancestor<graph>{\n\tvector<int> dep;\n\
    \tvector<vector<int>> par;\n\npublic:\n\tlowest_common_ancestor(){}\n\tlowest_common_ancestor(const\
    \ graph& T,int root){ build(T,root); }\n\n\tvoid build(const graph& T,int root){\n\
    \t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\t\t\
    par.assign(h,vector<int>(n,-1));\n\n\t\tauto dfs=[&](auto&& dfs,int u,int p)->void{\n\
    \t\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\t\t\t\tpar[0][v]=u;\n\
    \t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];\n\t}\n\n\tint lca(int\
    \ u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v]) swap(u,v);\n\t\
    \trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v) return u;\n\n\t\
    \tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];\n\
    \t\treturn par[0][u];\n\t}\n\n\tint distance(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)];\
    \ }\n};\n\ntemplate<class W>\nclass lowest_common_ancestor<weighted_graph<W>>{\n\
    \tvector<int> dep;\n\tvector<vector<int>> par;\n\tvector<vector<W>> dist;\n\n\
    public:\n\tlowest_common_ancestor(){}\n\tlowest_common_ancestor(const weighted_graph<W>&\
    \ T,int root){ build(T,root); }\n\n\tvoid build(const weighted_graph<W>& T,int\
    \ root){\n\t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\
    \t\tpar.assign(h,vector<int>(n,-1));\n\t\tdist.assign(h,vector<W>(n));\n\n\t\t\
    auto dfs=[&](auto&& dfs,int u,int p)->void{\n\t\t\tfor(const auto& [v,wt]:T[u])\
    \ if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\t\t\t\tpar[0][v]=u;\n\t\t\t\tdist[0][v]=wt;\n\
    \t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) {\n\t\t\tpar[i+1][u]=par[i][par[i][u]];\n\t\t\tdist[i+1][u]=dist[i][u]+dist[i][par[i][u]];\n\
    \t\t}\n\t}\n\n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tW distance(int u,int v)const{\n\
    \t\tint h=par.size();\n\t\tW res=0;\n\t\tint w=lca(u,v);\n\t\trep(i,h){\n\t\t\t\
    if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];\n\t\t\tif((dep[v]-dep[w])>>i&1)\
    \ res+=dist[i][v], v=par[i][v];\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 5 \"verify/tree/lca.1.test.cpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\tgraph T(n);\n\tfor(int v=1;v<n;v++){\n\
    \t\tint u; scanf(\"%d\",&u);\n\t\tadd_undirected_edge(T,u,v);\n\t}\n\n\tlowest_common_ancestor\
    \ LCA(T,0);\n\n\trep(_,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tprintf(\"\
    %d\\n\",LCA.lca(u,v));\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../library/template.hpp\"\
    \n#include \"../../library/tree/lca.hpp\"\n\nint main(){\n\tint n,q; scanf(\"\
    %d%d\",&n,&q);\n\tgraph T(n);\n\tfor(int v=1;v<n;v++){\n\t\tint u; scanf(\"%d\"\
    ,&u);\n\t\tadd_undirected_edge(T,u,v);\n\t}\n\n\tlowest_common_ancestor LCA(T,0);\n\
    \n\trep(_,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v);\n\t\tprintf(\"%d\\n\",LCA.lca(u,v));\n\
    \t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/tree/lca.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/tree/lca.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:23:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/lca.1.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/lca.1.test.cpp
- /verify/verify/tree/lca.1.test.cpp.html
title: verify/tree/lca.1.test.cpp
---
