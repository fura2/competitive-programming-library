---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 4 \"library/graph/distance_01.hpp\"\n\nvector<int> distance_01(const\
    \ weighted_graph<int>& G,int s){\n\tconstexpr int INF=INT_MAX;\n\tint n=G.size();\n\
    \tvector<int> d(n,INF); d[s]=0;\n\tdeque<int> Q; Q.emplace_back(s);\n\twhile(!Q.empty()){\n\
    \t\tint u=Q.front(); Q.pop_front();\n\t\tfor(const auto& e:G[u]){\n\t\t\tint v=e.to;\n\
    \t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\t\t\t\tif(e.wt==0) Q.emplace_front(v);\n\
    \t\t\t\telse        Q.emplace_back(v);\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"wgraph.hpp\"\n\nvector<int>\
    \ distance_01(const weighted_graph<int>& G,int s){\n\tconstexpr int INF=INT_MAX;\n\
    \tint n=G.size();\n\tvector<int> d(n,INF); d[s]=0;\n\tdeque<int> Q; Q.emplace_back(s);\n\
    \twhile(!Q.empty()){\n\t\tint u=Q.front(); Q.pop_front();\n\t\tfor(const auto&\
    \ e:G[u]){\n\t\t\tint v=e.to;\n\t\t\tif(d[v]>d[u]+e.wt){\n\t\t\t\td[v]=d[u]+e.wt;\n\
    \t\t\t\tif(e.wt==0) Q.emplace_front(v);\n\t\t\t\telse        Q.emplace_back(v);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: false
  path: library/graph/distance_01.hpp
  requiredBy: []
  timestamp: '2021-05-12 10:49:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance_01.hpp
layout: document
redirect_from:
- /library/library/graph/distance_01.hpp
- /library/library/graph/distance_01.hpp.html
title: library/graph/distance_01.hpp
---
