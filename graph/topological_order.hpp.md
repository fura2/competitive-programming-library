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
  bundledCode: "#line 1 \"graph/topological_order.hpp\"\n// D \u306F DAG\n\nvector<int>\
    \ topological_order(const graph& D){\n\tint n=D.size();\n\tvector<int> deg(n);\n\
    \trep(u,n) for(int v:D[u]) deg[v]++;\n\n\tvector<int> res;\n\tqueue<int> Q;\n\t\
    rep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front();\
    \ Q.pop();\n\t\tres.emplace_back(u);\n\t\tfor(int v:D[u]) if(--deg[v]==0) Q.emplace(v);\n\
    \t}\n\treturn res;\n}\n\ntemplate<class T>\nvector<int> topological_order(const\
    \ weighted_graph<T>& D){\n\tint n=D.size();\n\tvector<int> deg(n);\n\trep(u,n)\
    \ for(const auto& e:D[u]) deg[e.to]++;\n\n\tvector<int> res;\n\tqueue<int> Q;\n\
    \trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\t\tint u=Q.front();\
    \ Q.pop();\n\t\tres.emplace_back(u);\n\t\tfor(const auto& e:D[u]) if(--deg[e.to]==0)\
    \ Q.emplace(e.to);\n\t}\n\treturn res;\n}\n"
  code: "// D \u306F DAG\n\nvector<int> topological_order(const graph& D){\n\tint\
    \ n=D.size();\n\tvector<int> deg(n);\n\trep(u,n) for(int v:D[u]) deg[v]++;\n\n\
    \tvector<int> res;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\t\
    while(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\t\
    \tfor(int v:D[u]) if(--deg[v]==0) Q.emplace(v);\n\t}\n\treturn res;\n}\n\ntemplate<class\
    \ T>\nvector<int> topological_order(const weighted_graph<T>& D){\n\tint n=D.size();\n\
    \tvector<int> deg(n);\n\trep(u,n) for(const auto& e:D[u]) deg[e.to]++;\n\n\tvector<int>\
    \ res;\n\tqueue<int> Q;\n\trep(u,n) if(deg[u]==0) Q.emplace(u);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop();\n\t\tres.emplace_back(u);\n\t\tfor(const auto& e:D[u])\
    \ if(--deg[e.to]==0) Q.emplace(e.to);\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_order.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_order.hpp
layout: document
redirect_from:
- /library/graph/topological_order.hpp
- /library/graph/topological_order.hpp.html
title: graph/topological_order.hpp
---
