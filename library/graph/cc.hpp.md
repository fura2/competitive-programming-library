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
  bundledCode: "#line 1 \"library/graph/cc.hpp\"\n// \u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\u308B\n\nvector<vector<int>>\
    \ connected_components(const graph& G){\n\tint n=G.size();\n\tvector<vector<int>>\
    \ res;\n\tvector<bool> vis(n);\n\trep(u,n) if(!vis[u]) {\n\t\tvis[u]=true;\n\t\
    \tres.emplace_back();\n\t\tqueue<int> Q; Q.emplace(u);\n\t\twhile(!Q.empty()){\n\
    \t\t\tint v=Q.front(); Q.pop();\n\t\t\tres.back().emplace_back(v);\n\t\t\tfor(int\
    \ w:G[v]) if(!vis[w]) {\n\t\t\t\tvis[w]=true;\n\t\t\t\tQ.emplace(w);\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn res;\n}\n"
  code: "// \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u3092\u6C42\
    \u3081\u308B\n\nvector<vector<int>> connected_components(const graph& G){\n\t\
    int n=G.size();\n\tvector<vector<int>> res;\n\tvector<bool> vis(n);\n\trep(u,n)\
    \ if(!vis[u]) {\n\t\tvis[u]=true;\n\t\tres.emplace_back();\n\t\tqueue<int> Q;\
    \ Q.emplace(u);\n\t\twhile(!Q.empty()){\n\t\t\tint v=Q.front(); Q.pop();\n\t\t\
    \tres.back().emplace_back(v);\n\t\t\tfor(int w:G[v]) if(!vis[w]) {\n\t\t\t\tvis[w]=true;\n\
    \t\t\t\tQ.emplace(w);\n\t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/cc.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/cc.hpp
layout: document
redirect_from:
- /library/library/graph/cc.hpp
- /library/library/graph/cc.hpp.html
title: library/graph/cc.hpp
---
