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
  bundledCode: "#line 1 \"graph/distance.hpp\"\nvector<int> distance(const graph&\
    \ G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\tvector<int> d(n,INF);\n\
    \td[s]=0;\n\tqueue<int> Q; Q.emplace(s);\n\twhile(!Q.empty()){\n\t\tint u=Q.front();\
    \ Q.pop();\n\t\tfor(int v:G[u]) if(d[v]==INF) {\n\t\t\td[v]=d[u]+1;\n\t\t\tQ.emplace(v);\n\
    \t\t}\n\t}\n\treturn d;\n}\n\n/*\n\t01-BFS\n\t\u8FBA\u306E\u91CD\u307F\u304C 0\
    \ \u304B 1 \u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n*/\n\nvector<int>\
    \ distance(const weighted_graph<int>& G,int s){\n\tconstexpr int INF=INT_MAX;\n\
    \tint n=G.size();\n\tvector<int> d(n,INF); d[s]=0;\n\tdeque<int> Q; Q.emplace_back(s);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop_front();\n\t\tfor(const auto&\
    \ e:G[u]){\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\
    \t\t\t\tif(e.wt==0) Q.emplace_front(v);\n\t\t\t\telse        Q.emplace_back(v);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "vector<int> distance(const graph& G,int s){\n\tconstexpr int INF=INT_MAX;\n\
    \tint n=G.size();\n\tvector<int> d(n,INF);\n\td[s]=0;\n\tqueue<int> Q; Q.emplace(s);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop();\n\t\tfor(int v:G[u]) if(d[v]==INF)\
    \ {\n\t\t\td[v]=d[u]+1;\n\t\t\tQ.emplace(v);\n\t\t}\n\t}\n\treturn d;\n}\n\n/*\n\
    \t01-BFS\n\t\u8FBA\u306E\u91CD\u307F\u304C 0 \u304B 1 \u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\n*/\n\nvector<int> distance(const weighted_graph<int>&\
    \ G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\tvector<int> d(n,INF);\
    \ d[s]=0;\n\tdeque<int> Q; Q.emplace_back(s);\n\twhile(!Q.empty()){\n\t\tint u=Q.front();\
    \ Q.pop_front();\n\t\tfor(const auto& e:G[u]){\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\
    \t\t\t\td[v]=d[u]+e.wt;\n\t\t\t\tif(e.wt==0) Q.emplace_front(v);\n\t\t\t\telse\
    \        Q.emplace_back(v);\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/distance.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/distance.hpp
layout: document
redirect_from:
- /library/graph/distance.hpp
- /library/graph/distance.hpp.html
title: graph/distance.hpp
---
