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
  bundledCode: "#line 1 \"graph/is_DAG.hpp\"\nbool is_DAG(const graph& G){\n\tint\
    \ n=G.size();\n\tvector<int> deg(n);\n\trep(u,n) for(int v:G[u]) deg[v]++;\n\n\
    \tint cnt=0;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tcnt++;\n\t\tfor(int v:G[u]) if(--deg[v]==0)\
    \ Q.emplace(v);\n\t}\n\treturn cnt==n;\n}\n"
  code: "bool is_DAG(const graph& G){\n\tint n=G.size();\n\tvector<int> deg(n);\n\t\
    rep(u,n) for(int v:G[u]) deg[v]++;\n\n\tint cnt=0;\n\tqueue<int> Q;\n\trep(u,n)\
    \ if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\
    \t\tcnt++;\n\t\tfor(int v:G[u]) if(--deg[v]==0) Q.emplace(v);\n\t}\n\treturn cnt==n;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/is_DAG.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_DAG.hpp
layout: document
redirect_from:
- /library/graph/is_DAG.hpp
- /library/graph/is_DAG.hpp.html
title: graph/is_DAG.hpp
---
