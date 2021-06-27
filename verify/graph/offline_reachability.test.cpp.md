---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Dijkstra.hpp
    title: Single-Source Shortest Path (Dijkstra's Algorithm)
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/offline_reachability.hpp
    title: Offline Reachability for Directed Graphs
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0275
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0275
  bundledCode: "#line 1 \"verify/graph/offline_reachability.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0275\"\n\n#line\
    \ 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n#include\
    \ <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\
    \n\ntemplate<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n#line 4 \"library/graph/Dijkstra.hpp\"\n\ntemplate<class\
    \ T>\nvector<T> Dijkstra(const weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\
    \n\tint n=G.size();\n\tvector<T> d(n,INF); d[s]=T{};\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(T{},s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& [v,wt]:G[u]){\n\t\
    \t\tif(d[v]>d[u]+wt){\n\t\t\t\td[v]=d[u]+wt;\n\t\t\t\tQ.emplace(d[v],v);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn d;\n}\n#line 3 \"library/graph/graph.hpp\"\n\nusing\
    \ graph=vector<vector<int>>;\n\nvoid add_undirected_edge(graph& G,int u,int v){\n\
    \tG[u].emplace_back(v);\n\tG[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph&\
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n#line 5 \"library/graph/scc.hpp\"\
    \n\ntemplate<class T>\nclass strongly_connected_components{ strongly_connected_components(const\
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
    \ \"library/graph/offline_reachability.hpp\"\n\nvector<bool> offline_reachability(const\
    \ graph& G,vector<pair<int,int>> Q){\n\tstrongly_connected_components SCC(G);\n\
    \tfor(auto& [u,v]:Q){\n\t\tu=SCC[u];\n\t\tv=SCC[v];\n\t}\n\n\tvector<bool> res(Q.size());\n\
    \tvector<int> C;\n\trep(i,Q.size()){\n\t\tint u,v; tie(u,v)=Q[i];\n\t\tif(u==v)\
    \ res[i]=true;\n\t\telse     C.emplace_back(i);\n\t}\n\n\tconst auto& D=SCC.DAG();\n\
    \tint n=D.size();\n\tfor(int l=0;l<C.size();l+=64){\n\t\tint r=min(l+64,int(C.size()));\n\
    \t\tvector<int64_t> dp(n);\n\t\tfor(int i=l;i<r;i++){\n\t\t\tdp[Q[C[i]].first]|=int64_t(1)<<(i-l);\n\
    \t\t}\n\t\trep(u,n) for(int v:D[u]) dp[v]|=dp[u];\n\t\tfor(int i=l;i<r;i++){\n\
    \t\t\tres[C[i]]=dp[Q[C[i]].second]>>(i-l)&1;\n\t\t}\n\t}\n\n\treturn res;\n}\n\
    #line 6 \"verify/graph/offline_reachability.test.cpp\"\n\nint main(){\n\tint n,m;\
    \ scanf(\"%d%d\",&n,&m);\n\tweighted_graph<int> G(n);\n\trep(i,m){\n\t\tint u,v,c;\
    \ scanf(\"%d%d%d\",&u,&v,&c); u--; v--;\n\t\tadd_undirected_edge(G,u,v,c);\n\t\
    }\n\tint a,b,q; scanf(\"%d%d%d\",&a,&b,&q); a--; b--;\n\n\tauto da=Dijkstra(G,a);\n\
    \tauto db=Dijkstra(G,b);\n\n\tgraph D(n);\n\trep(u,n) for(auto [v,wt]:G[u]) {\n\
    \t\tif(da[u]+wt==da[v]){\n\t\t\tadd_directed_edge(D,u,v);\n\t\t}\n\t}\n\n\tvector<pair<int,int>>\
    \ Q(q);\n\trep(i,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v); u--; v--;\n\t\tQ[i]={u,v};\n\
    \t}\n\n\tauto res=offline_reachability(D,Q);\n\trep(i,q){\n\t\tint u,v; tie(u,v)=Q[i];\n\
    \t\tputs(da[v]+db[v]==da[b]&&res[i]?\"Yes\":\"No\");\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0275\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Dijkstra.hpp\"\
    \n#include \"../../library/graph/offline_reachability.hpp\"\n\nint main(){\n\t\
    int n,m; scanf(\"%d%d\",&n,&m);\n\tweighted_graph<int> G(n);\n\trep(i,m){\n\t\t\
    int u,v,c; scanf(\"%d%d%d\",&u,&v,&c); u--; v--;\n\t\tadd_undirected_edge(G,u,v,c);\n\
    \t}\n\tint a,b,q; scanf(\"%d%d%d\",&a,&b,&q); a--; b--;\n\n\tauto da=Dijkstra(G,a);\n\
    \tauto db=Dijkstra(G,b);\n\n\tgraph D(n);\n\trep(u,n) for(auto [v,wt]:G[u]) {\n\
    \t\tif(da[u]+wt==da[v]){\n\t\t\tadd_directed_edge(D,u,v);\n\t\t}\n\t}\n\n\tvector<pair<int,int>>\
    \ Q(q);\n\trep(i,q){\n\t\tint u,v; scanf(\"%d%d\",&u,&v); u--; v--;\n\t\tQ[i]={u,v};\n\
    \t}\n\n\tauto res=offline_reachability(D,Q);\n\trep(i,q){\n\t\tint u,v; tie(u,v)=Q[i];\n\
    \t\tputs(da[v]+db[v]==da[b]&&res[i]?\"Yes\":\"No\");\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/wgraph.hpp
  - library/graph/offline_reachability.hpp
  - library/graph/graph.hpp
  - library/graph/scc.hpp
  isVerificationFile: true
  path: verify/graph/offline_reachability.test.cpp
  requiredBy: []
  timestamp: '2021-06-27 17:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/offline_reachability.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/offline_reachability.test.cpp
- /verify/verify/graph/offline_reachability.test.cpp.html
title: verify/graph/offline_reachability.test.cpp
---
