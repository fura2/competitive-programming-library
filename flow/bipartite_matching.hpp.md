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
  bundledCode: "#line 1 \"flow/bipartite_matching.hpp\"\n/* \u4E8C\u90E8\u30DE\u30C3\
    \u30C1\u30F3\u30B0 */\n/*\n[ constructor ]\n\t\u5F15\u6570\n\t\tL : \u5DE6\u306E\
    \u9802\u70B9\u96C6\u5408\u306E\u30B5\u30A4\u30BA\n\t\tR : \u53F3\u306E\u9802\u70B9\
    \u96C6\u5408\u306E\u30B5\u30A4\u30BA\n\t\u5236\u7D04\n\t\tL, R >= 0\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(L)\n\n[ add_edge ]\n\t\u5236\u7D04\n\t\t0 <= u < L\n\t\t0 <= v <\
    \ R\n\n[ bipartite_matching ]\n\t\u8AAC\u660E\n\t\t\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\t\u306A\u3057\n\t\u5236\
    \u7D04\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\n\t\t(\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u306E\u30B5\u30A4\u30BA, \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \ match)\n\t\t\u3053\u3053\u3067,\n\t\t\tmatch[0][u] := \u5DE6\u306E\u9802\u70B9\
    \ u \u3068\u30DE\u30C3\u30C1\u3057\u3066\u3044\u308B\u53F3\u306E\u9802\u70B9\u306E\
    \u756A\u53F7 (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1)\n\t\t\tmatch[1][v]\
    \ := \u53F3\u306E\u9802\u70B9 v \u3068\u30DE\u30C3\u30C1\u3057\u3066\u3044\u308B\
    \u5DE6\u306E\u9802\u70B9\u306E\u756A\u53F7 (\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070 -1)\n\t\u8A08\u7B97\u91CF\n\t\tO(V(V+E))\n*/\n\nclass bipartite_graph{\n\
    \tint L,R;\n\tvector<vector<int>> G,match;\n\tvector<bool> vis;\n\n\tbool augment(int\
    \ u){\n\t\tif(u==-1) return true;\n\t\tfor(int v:G[u]) if(!vis[v]) {\n\t\t\tvis[v]=true;\n\
    \t\t\tif(augment(match[1][v])){\n\t\t\t\tmatch[0][u]=v;\n\t\t\t\tmatch[1][v]=u;\n\
    \t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\npublic:\n\tbipartite_graph(int\
    \ L,int R):L(L),R(R),G(L){}\n\n\tvoid add_edge(int u,int v){ G[u].emplace_back(v);\
    \ }\n\n\tconst vector<int>& operator[](int u)const{ return G[u]; }\n\n\tpair<int,vector<vector<int>>>\
    \ bipartite_matching(){\n\t\tmatch.resize(2);\n\t\tmatch[0].assign(L,-1);\n\t\t\
    match[1].assign(R,-1);\n\n\t\tint res=0;\n\t\tvis.resize(R);\n\t\trep(u,L){\n\t\
    \t\tfill(vis.begin(),vis.end(),false);\n\t\t\tif(augment(u)) res++;\n\t\t}\n\n\
    \t\treturn {res,match};\n\t}\n};\n"
  code: "/* \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0 */\n/*\n[ constructor ]\n\t\
    \u5F15\u6570\n\t\tL : \u5DE6\u306E\u9802\u70B9\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \n\t\tR : \u53F3\u306E\u9802\u70B9\u96C6\u5408\u306E\u30B5\u30A4\u30BA\n\t\u5236\
    \u7D04\n\t\tL, R >= 0\n\t\u8A08\u7B97\u91CF\n\t\tO(L)\n\n[ add_edge ]\n\t\u5236\
    \u7D04\n\t\t0 <= u < L\n\t\t0 <= v < R\n\n[ bipartite_matching ]\n\t\u8AAC\u660E\
    \n\t\t\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u6C42\u3081\u308B\n\t\u5F15\
    \u6570\n\t\t\u306A\u3057\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\
    \n\t\t(\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u30B5\u30A4\u30BA, \u6700\
    \u5927\u30DE\u30C3\u30C1\u30F3\u30B0 match)\n\t\t\u3053\u3053\u3067,\n\t\t\tmatch[0][u]\
    \ := \u5DE6\u306E\u9802\u70B9 u \u3068\u30DE\u30C3\u30C1\u3057\u3066\u3044\u308B\
    \u53F3\u306E\u9802\u70B9\u306E\u756A\u53F7 (\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070 -1)\n\t\t\tmatch[1][v] := \u53F3\u306E\u9802\u70B9 v \u3068\u30DE\u30C3\
    \u30C1\u3057\u3066\u3044\u308B\u5DE6\u306E\u9802\u70B9\u306E\u756A\u53F7 (\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 -1)\n\t\u8A08\u7B97\u91CF\n\t\tO(V(V+E))\n\
    */\n\nclass bipartite_graph{\n\tint L,R;\n\tvector<vector<int>> G,match;\n\tvector<bool>\
    \ vis;\n\n\tbool augment(int u){\n\t\tif(u==-1) return true;\n\t\tfor(int v:G[u])\
    \ if(!vis[v]) {\n\t\t\tvis[v]=true;\n\t\t\tif(augment(match[1][v])){\n\t\t\t\t\
    match[0][u]=v;\n\t\t\t\tmatch[1][v]=u;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\
    \t\treturn false;\n\t}\n\npublic:\n\tbipartite_graph(int L,int R):L(L),R(R),G(L){}\n\
    \n\tvoid add_edge(int u,int v){ G[u].emplace_back(v); }\n\n\tconst vector<int>&\
    \ operator[](int u)const{ return G[u]; }\n\n\tpair<int,vector<vector<int>>> bipartite_matching(){\n\
    \t\tmatch.resize(2);\n\t\tmatch[0].assign(L,-1);\n\t\tmatch[1].assign(R,-1);\n\
    \n\t\tint res=0;\n\t\tvis.resize(R);\n\t\trep(u,L){\n\t\t\tfill(vis.begin(),vis.end(),false);\n\
    \t\t\tif(augment(u)) res++;\n\t\t}\n\n\t\treturn {res,match};\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/bipartite_matching.hpp
layout: document
redirect_from:
- /library/flow/bipartite_matching.hpp
- /library/flow/bipartite_matching.hpp.html
title: flow/bipartite_matching.hpp
---
