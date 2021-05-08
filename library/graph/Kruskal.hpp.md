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
  bundledCode: "#line 1 \"library/graph/Kruskal.hpp\"\n/* \u6700\u5C0F\u5168\u57DF\
    \u68EE (Kruskal) */\n/*\n\t\u5F15\u6570\n\t\tG : \u91CD\u307F\u3064\u304D\u7121\
    \u5411\u30B0\u30E9\u30D5\n\t\u623B\u308A\u5024\n\t\t(MSF \u306E\u8FBA\u306E\u91CD\
    \u307F\u306E\u548C, MSF)\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(E log E)\n\t\u5099\u8003\n\t\t\u30B0\u30E9\u30D5\u304C\u9023\u7D50\u306E\
    \u3068\u304D\u306F\u6700\u5C0F\u5168\u57DF\u6728\u304C\u6C42\u307E\u308B.\n\t\t\
    \u8FBA\u306E\u91CD\u307F\u306F\u8CA0\u3067\u3082\u3044\u3044.\n*/\n\ntemplate<class\
    \ T>\npair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G){\n\tint n=G.size();\n\
    \tvector<tuple<T,int,int>> E;\n\trep(u,n) for(const auto& e:G[u]) {\n\t\tint v=e.to;\n\
    \t\tif(u<v) E.emplace_back(e.wt,u,v);\n\t}\n\n\tsort(E.begin(),E.end());\n\n\t\
    T ans{};\n\tweighted_graph<T> Res(n);\n\tunion_find U(n);\n\tfor(const auto& e:E){\n\
    \t\tif(U.size()==1) break;\n\t\tT wt;\n\t\tint u,v; tie(wt,u,v)=e;\n\t\tif(!U.is_same(u,v)){\n\
    \t\t\tU.unite(u,v);\n\t\t\tans+=wt;\n\t\t\tRes[u].emplace_back(v,wt);\n\t\t\t\
    Res[v].emplace_back(u,wt);\n\t\t}\n\t}\n\treturn {ans,Res};\n}\n"
  code: "/* \u6700\u5C0F\u5168\u57DF\u68EE (Kruskal) */\n/*\n\t\u5F15\u6570\n\t\t\
    G : \u91CD\u307F\u3064\u304D\u7121\u5411\u30B0\u30E9\u30D5\n\t\u623B\u308A\u5024\
    \n\t\t(MSF \u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C, MSF)\n\t\u5236\u7D04\n\t\
    \t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(E log E)\n\t\u5099\u8003\n\t\t\u30B0\
    \u30E9\u30D5\u304C\u9023\u7D50\u306E\u3068\u304D\u306F\u6700\u5C0F\u5168\u57DF\
    \u6728\u304C\u6C42\u307E\u308B.\n\t\t\u8FBA\u306E\u91CD\u307F\u306F\u8CA0\u3067\
    \u3082\u3044\u3044.\n*/\n\ntemplate<class T>\npair<T,weighted_graph<T>> Kruskal(const\
    \ weighted_graph<T>& G){\n\tint n=G.size();\n\tvector<tuple<T,int,int>> E;\n\t\
    rep(u,n) for(const auto& e:G[u]) {\n\t\tint v=e.to;\n\t\tif(u<v) E.emplace_back(e.wt,u,v);\n\
    \t}\n\n\tsort(E.begin(),E.end());\n\n\tT ans{};\n\tweighted_graph<T> Res(n);\n\
    \tunion_find U(n);\n\tfor(const auto& e:E){\n\t\tif(U.size()==1) break;\n\t\t\
    T wt;\n\t\tint u,v; tie(wt,u,v)=e;\n\t\tif(!U.is_same(u,v)){\n\t\t\tU.unite(u,v);\n\
    \t\t\tans+=wt;\n\t\t\tRes[u].emplace_back(v,wt);\n\t\t\tRes[v].emplace_back(u,wt);\n\
    \t\t}\n\t}\n\treturn {ans,Res};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/Kruskal.hpp
layout: document
redirect_from:
- /library/library/graph/Kruskal.hpp
- /library/library/graph/Kruskal.hpp.html
title: library/graph/Kruskal.hpp
---
