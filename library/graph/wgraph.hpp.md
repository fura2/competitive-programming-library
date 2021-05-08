---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/wgraph.hpp\"\ntemplate<class T> struct edge{\n\
    \tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n};\ntemplate<class\
    \ T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class T>\nvoid\
    \ add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    \tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\nvoid add_directed_edge(weighted_graph<T>&\
    \ G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n}\n"
  code: "template<class T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T&\
    \ wt):to(to),wt(wt){}\n};\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\
    \ntemplate<class T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const\
    \ T& wt){\n\tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class\
    \ T>\nvoid add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\t\
    G[u].emplace_back(v,wt);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/wgraph.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/wgraph.hpp
layout: document
redirect_from:
- /library/library/graph/wgraph.hpp
- /library/library/graph/wgraph.hpp.html
title: library/graph/wgraph.hpp
---
