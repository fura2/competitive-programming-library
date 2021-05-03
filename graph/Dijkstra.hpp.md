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
  bundledCode: "#line 1 \"graph/Dijkstra.hpp\"\ntemplate<class T>\nvector<T> Dijkstra(const\
    \ weighted_graph<T>& G,int s){\n\tconstexpr T INF=numeric_limits<T>::max();\n\t\
    int n=G.size();\n\tvector<T> d(n,INF); d[s]=0;\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>\
    \ Q;\n\tQ.emplace(0,s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& e:G[u]){\n\t\t\t\
    int v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\t\t\t\tQ.emplace(d[v],v);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "template<class T>\nvector<T> Dijkstra(const weighted_graph<T>& G,int s){\n\
    \tconstexpr T INF=numeric_limits<T>::max();\n\tint n=G.size();\n\tvector<T> d(n,INF);\
    \ d[s]=0;\n\tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;\n\t\
    Q.emplace(0,s);\n\twhile(!Q.empty()){\n\t\tT d0;\n\t\tint u; tie(d0,u)=Q.top();\n\
    \t\tQ.pop();\n\t\tif(d0>d[u]) continue;\n\t\tfor(const auto& e:G[u]){\n\t\t\t\
    int v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\t\t\t\tQ.emplace(d[v],v);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/graph/Dijkstra.hpp
- /library/graph/Dijkstra.hpp.html
title: graph/Dijkstra.hpp
---
