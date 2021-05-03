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
  bundledCode: "#line 1 \"graph/graph.hpp\"\nusing graph=vector<vector<int>>;\n\n\
    void add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\tG[v].emplace_back(u);\n\
    }\n\nvoid add_directed_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\
    }\n"
  code: "using graph=vector<vector<int>>;\n\nvoid add_undirected_edge(graph& G,int\
    \ u,int v){\n\tG[u].emplace_back(v);\n\tG[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph&\
    \ G,int u,int v){\n\tG[u].emplace_back(v);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
