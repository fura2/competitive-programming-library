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
  bundledCode: "#line 1 \"library/graph/odd_cycle.hpp\"\n/*\n\t\u7121\u5411\u30B0\u30E9\
    \u30D5 G \u306E\u5947\u6570\u9577\u306E\u9589\u8DEF C \u3092\u4E00\u3064\u6C42\
    \u3081\u308B\n\tC \u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u5217\u3068\u8FBA\
    \u5217\u306E\u30DA\u30A2\u3092\u8FD4\u3059\n\t\t\u9802\u70B9\u5217\u3092 u_1,\
    \ ..., u_K, \u8FBA\u5217\u3092 e_1, ... e_K \u3068\u3059\u308B\u3068,\n\t\te_i\
    \ \u306F u_i \u3068 u_{i+1} \u3092\u7D50\u3076\u8FBA\n\tG \u304C\u5947\u6570\u9577\
    \u306E\u9589\u8DEF\u3092\u3082\u305F\u306A\u3044\u3068\u304D\u306F\u7A7A\u306E\
    \ vector \u306E\u30DA\u30A2\u3092\u8FD4\u3059\n*/\n\ntemplate<class T>\npair<vector<int>,vector<edge<T>>>\
    \ odd_cycle(const weighted_graph<T>& G){\n\tint n=G.size();\n\tvector<int> color(n,-1);\n\
    \n\tvector<int> res1;\n\tvector<edge<T>> res2;\n\n\tauto dfs=[&](auto&& dfs,int\
    \ u,int c)->bool{\n\t\tcolor[u]=c;\n\t\tfor(auto e:G[u]){\n\t\t\tif(color[e.to]==-1){\n\
    \t\t\t\tif(dfs(dfs,e.to,1-c)){\n\t\t\t\t\tif(res2[0].to!=res1.back()){\n\t\t\t\
    \t\t\tres1.emplace_back(u);\n\t\t\t\t\t\tres2.emplace_back(e);\n\t\t\t\t\t}\n\t\
    \t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t}\n\t\t\telse if(color[e.to]==c){\n\t\t\
    \t\tres1.emplace_back(u);\n\t\t\t\tres2.emplace_back(e);\n\t\t\t\treturn true;\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t};\n\n\trep(u,n) if(color[u]==-1 && dfs(dfs,u,0))\
    \ {\n\t\treverse(res1.begin(),res1.end());\n\t\treverse(res2.begin(),res2.end());\n\
    \t\tbreak;\n\t}\n\treturn {res1,res2};\n}\n"
  code: "/*\n\t\u7121\u5411\u30B0\u30E9\u30D5 G \u306E\u5947\u6570\u9577\u306E\u9589\
    \u8DEF C \u3092\u4E00\u3064\u6C42\u3081\u308B\n\tC \u306B\u542B\u307E\u308C\u308B\
    \u9802\u70B9\u5217\u3068\u8FBA\u5217\u306E\u30DA\u30A2\u3092\u8FD4\u3059\n\t\t\
    \u9802\u70B9\u5217\u3092 u_1, ..., u_K, \u8FBA\u5217\u3092 e_1, ... e_K \u3068\
    \u3059\u308B\u3068,\n\t\te_i \u306F u_i \u3068 u_{i+1} \u3092\u7D50\u3076\u8FBA\
    \n\tG \u304C\u5947\u6570\u9577\u306E\u9589\u8DEF\u3092\u3082\u305F\u306A\u3044\
    \u3068\u304D\u306F\u7A7A\u306E vector \u306E\u30DA\u30A2\u3092\u8FD4\u3059\n*/\n\
    \ntemplate<class T>\npair<vector<int>,vector<edge<T>>> odd_cycle(const weighted_graph<T>&\
    \ G){\n\tint n=G.size();\n\tvector<int> color(n,-1);\n\n\tvector<int> res1;\n\t\
    vector<edge<T>> res2;\n\n\tauto dfs=[&](auto&& dfs,int u,int c)->bool{\n\t\tcolor[u]=c;\n\
    \t\tfor(auto e:G[u]){\n\t\t\tif(color[e.to]==-1){\n\t\t\t\tif(dfs(dfs,e.to,1-c)){\n\
    \t\t\t\t\tif(res2[0].to!=res1.back()){\n\t\t\t\t\t\tres1.emplace_back(u);\n\t\t\
    \t\t\t\tres2.emplace_back(e);\n\t\t\t\t\t}\n\t\t\t\t\treturn true;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\telse if(color[e.to]==c){\n\t\t\t\tres1.emplace_back(u);\n\t\t\t\
    \tres2.emplace_back(e);\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\
    \t};\n\n\trep(u,n) if(color[u]==-1 && dfs(dfs,u,0)) {\n\t\treverse(res1.begin(),res1.end());\n\
    \t\treverse(res2.begin(),res2.end());\n\t\tbreak;\n\t}\n\treturn {res1,res2};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/odd_cycle.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/odd_cycle.hpp
layout: document
redirect_from:
- /library/library/graph/odd_cycle.hpp
- /library/library/graph/odd_cycle.hpp.html
title: library/graph/odd_cycle.hpp
---
