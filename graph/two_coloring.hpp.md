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
  bundledCode: "#line 1 \"graph/two_coloring.hpp\"\n/* \u4E8C\u5F69\u8272 */\n/*\n\
    \t\u8AAC\u660E\n\t\t\u30B0\u30E9\u30D5\u3092\u4E8C\u5F69\u8272\u3059\u308B\n\t\
    \u5F15\u6570\n\t\tG : \u7121\u5411\u30B0\u30E9\u30D5\n\t\u5236\u7D04\n\t\t\u306A\
    \u3057\n\t\u623B\u308A\u5024\n\t\t(G \u304C\u4E8C\u5F69\u8272\u53EF\u80FD\u304B\
    \u3069\u3046\u304B, \u5F69\u8272\u7D50\u679C)\n\t\t\u5F69\u8272\u7D50\u679C\u306F\
    \u30B5\u30A4\u30BA V \u306E vector \u3067, \u5404\u8981\u7D20\u306F 0 \u307E\u305F\
    \u306F 1\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n\t\u5099\u8003\n\t\tG \u304C\u4E8C\
    \u5F69\u8272\u3067\u304D\u306A\u3044\u3068\u304D, \u5F69\u8272\u7D50\u679C\u306F\
    \u7A7A\u306E vector \u304C\u8FD4\u308B\n*/\n\npair<bool,vector<int>> two_coloring(const\
    \ graph& G){\n\tint n=G.size();\n\tvector<int> color(n,-1);\n\trep(u,n) if(color[u]==-1)\
    \ {\n\t\tcolor[u]=0;\n\t\tqueue<int> Q; Q.emplace(u);\n\t\twhile(!Q.empty()){\n\
    \t\t\tint v=Q.front(); Q.pop();\n\t\t\tfor(int w:G[v]){\n\t\t\t\tif(color[w]==-1){\n\
    \t\t\t\t\tcolor[w]=1-color[v];\n\t\t\t\t\tQ.emplace(w);\n\t\t\t\t}\n\t\t\t\telse\
    \ if(color[w]==color[v]) return {false,vector<int>()};\n\t\t\t}\n\t\t}\n\t}\n\t\
    return {true,color};\n}\n"
  code: "/* \u4E8C\u5F69\u8272 */\n/*\n\t\u8AAC\u660E\n\t\t\u30B0\u30E9\u30D5\u3092\
    \u4E8C\u5F69\u8272\u3059\u308B\n\t\u5F15\u6570\n\t\tG : \u7121\u5411\u30B0\u30E9\
    \u30D5\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\n\t\t(G \u304C\u4E8C\
    \u5F69\u8272\u53EF\u80FD\u304B\u3069\u3046\u304B, \u5F69\u8272\u7D50\u679C)\n\t\
    \t\u5F69\u8272\u7D50\u679C\u306F\u30B5\u30A4\u30BA V \u306E vector \u3067, \u5404\
    \u8981\u7D20\u306F 0 \u307E\u305F\u306F 1\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n\t\
    \u5099\u8003\n\t\tG \u304C\u4E8C\u5F69\u8272\u3067\u304D\u306A\u3044\u3068\u304D\
    , \u5F69\u8272\u7D50\u679C\u306F\u7A7A\u306E vector \u304C\u8FD4\u308B\n*/\n\n\
    pair<bool,vector<int>> two_coloring(const graph& G){\n\tint n=G.size();\n\tvector<int>\
    \ color(n,-1);\n\trep(u,n) if(color[u]==-1) {\n\t\tcolor[u]=0;\n\t\tqueue<int>\
    \ Q; Q.emplace(u);\n\t\twhile(!Q.empty()){\n\t\t\tint v=Q.front(); Q.pop();\n\t\
    \t\tfor(int w:G[v]){\n\t\t\t\tif(color[w]==-1){\n\t\t\t\t\tcolor[w]=1-color[v];\n\
    \t\t\t\t\tQ.emplace(w);\n\t\t\t\t}\n\t\t\t\telse if(color[w]==color[v]) return\
    \ {false,vector<int>()};\n\t\t\t}\n\t\t}\n\t}\n\treturn {true,color};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/two_coloring.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/two_coloring.hpp
layout: document
redirect_from:
- /library/graph/two_coloring.hpp
- /library/graph/two_coloring.hpp.html
title: graph/two_coloring.hpp
---
