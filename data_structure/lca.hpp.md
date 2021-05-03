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
  bundledCode: "#line 1 \"data_structure/lca.hpp\"\n/* \u6700\u5C0F\u5171\u901A\u5148\
    \u7956 */\n/*\n[ constructor ]\n\t\u5F15\u6570\n\t\tT : \u6728\n\t\troot : \u6839\
    \n\t\u5236\u7D04\n\t\tT \u306F\u6728\n\t\t0 <= root < n\n\t\u8A08\u7B97\u91CF\n\
    \t\tO(E + V log V)\n\t\u5099\u8003\n\t\tdep[u] := (u \u306E\u6839\u304B\u3089\u306E\
    \u8DDD\u96E2)\n\t\tpar[i][u] := (u \u306E 2^i \u500B\u4E0A\u306E\u9802\u70B9 (\u6839\
    \u3088\u308A\u4E0A\u306A\u3089 -1))\n\n[ lca ]\n\t\u8AAC\u660E\n\t\tu \u3068 v\
    \ \u306E\u6700\u5C0F\u5171\u901A\u5148\u7956\u3092\u6C42\u3081\u308B\n\t\u5F15\
    \u6570\n\t\tu, v : \u9802\u70B9\n\t\u5236\u7D04\n\t\t0 <= u, v < n\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log V)\n\n[ distance ]\n\t\u8AAC\u660E\n\t\tu \u3068 v \u306E\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tu, v : \u9802\u70B9\n\t\u5236\
    \u7D04\n\t\t0 <= u, v < n\n\t\u8A08\u7B97\u91CF\n\t\tO(log V)\n*/\n\nclass lowest_common_ancestor{\n\
    \tvector<int> dep;\n\tvector<vector<int>> par;\n\npublic:\n\tlowest_common_ancestor(const\
    \ graph& T,int root){\n\t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\
    \tdep.assign(n,0);\n\t\tpar.assign(h,vector<int>(n,-1));\n\n\t\tauto dfs=[&](auto&&\
    \ dfs,int u,int p)->void{\n\t\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\
    \t\t\t\tpar[0][v]=u;\n\t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\
    \t\trep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];\n\t}\n\
    \n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tint distance(int u,int v)const{\
    \ return dep[u]+dep[v]-2*dep[lca(u,v)]; }\n};\n\n\n\n// \u91CD\u307F\u3064\u304D\
    \u30D0\u30FC\u30B8\u30E7\u30F3 (\u8FBA\u306E\u91CD\u307F\u306E\u548C\u3092\u8DDD\
    \u96E2\u3068\u3057\u305F. \u548C\u3067\u306A\u304F\u3066\u3082\u53EF\u63DB\u304B\
    \u3064\u7D50\u5408\u7684\u306A\u6F14\u7B97\u306A\u3089\u3088\u3044.)\n\ntemplate<class\
    \ T>\nclass lowest_common_ancestor{\n\tvector<int> dep;\n\tvector<vector<int>>\
    \ par;\n\tvector<vector<T>> dist;\n\npublic:\n\tlowest_common_ancestor(const weighted_graph<T>&\
    \ Tr,int root){\n\t\tint n=Tr.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\
    \t\tpar.assign(h,vector<int>(n,-1));\n\t\tdist.assign(h,vector<T>(n));\n\n\t\t\
    auto dfs=[&](auto&& dfs,int u,int p)->void{\n\t\t\tfor(const auto& e:Tr[u]) if(e.to!=p)\
    \ {\n\t\t\t\tdep[e.to]=dep[u]+1;\n\t\t\t\tpar[0][e.to]=u;\n\t\t\t\tdist[0][e.to]=e.wt;\n\
    \t\t\t\tdfs(dfs,e.to,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) {\n\t\t\tpar[i+1][u]=par[i][par[i][u]];\n\t\t\tdist[i+1][u]=dist[i][u]+dist[i][par[i][u]];\n\
    \t\t}\n\t}\n\n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tT distance(int u,int v)const{\n\
    \t\tint h=par.size();\n\t\tT res=0;\n\t\tint w=lca(u,v);\n\t\trep(i,h){\n\t\t\t\
    if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];\n\t\t\tif((dep[v]-dep[w])>>i&1)\
    \ res+=dist[i][v], v=par[i][v];\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/* \u6700\u5C0F\u5171\u901A\u5148\u7956 */\n/*\n[ constructor ]\n\t\u5F15\
    \u6570\n\t\tT : \u6728\n\t\troot : \u6839\n\t\u5236\u7D04\n\t\tT \u306F\u6728\n\
    \t\t0 <= root < n\n\t\u8A08\u7B97\u91CF\n\t\tO(E + V log V)\n\t\u5099\u8003\n\t\
    \tdep[u] := (u \u306E\u6839\u304B\u3089\u306E\u8DDD\u96E2)\n\t\tpar[i][u] := (u\
    \ \u306E 2^i \u500B\u4E0A\u306E\u9802\u70B9 (\u6839\u3088\u308A\u4E0A\u306A\u3089\
    \ -1))\n\n[ lca ]\n\t\u8AAC\u660E\n\t\tu \u3068 v \u306E\u6700\u5C0F\u5171\u901A\
    \u5148\u7956\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tu, v : \u9802\u70B9\n\
    \t\u5236\u7D04\n\t\t0 <= u, v < n\n\t\u8A08\u7B97\u91CF\n\t\tO(log V)\n\n[ distance\
    \ ]\n\t\u8AAC\u660E\n\t\tu \u3068 v \u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\
    \n\t\u5F15\u6570\n\t\tu, v : \u9802\u70B9\n\t\u5236\u7D04\n\t\t0 <= u, v < n\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(log V)\n*/\n\nclass lowest_common_ancestor{\n\tvector<int>\
    \ dep;\n\tvector<vector<int>> par;\n\npublic:\n\tlowest_common_ancestor(const\
    \ graph& T,int root){\n\t\tint n=T.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\
    \tdep.assign(n,0);\n\t\tpar.assign(h,vector<int>(n,-1));\n\n\t\tauto dfs=[&](auto&&\
    \ dfs,int u,int p)->void{\n\t\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\t\tdep[v]=dep[u]+1;\n\
    \t\t\t\tpar[0][v]=u;\n\t\t\t\tdfs(dfs,v,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\
    \t\trep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];\n\t}\n\
    \n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tint distance(int u,int v)const{\
    \ return dep[u]+dep[v]-2*dep[lca(u,v)]; }\n};\n\n\n\n// \u91CD\u307F\u3064\u304D\
    \u30D0\u30FC\u30B8\u30E7\u30F3 (\u8FBA\u306E\u91CD\u307F\u306E\u548C\u3092\u8DDD\
    \u96E2\u3068\u3057\u305F. \u548C\u3067\u306A\u304F\u3066\u3082\u53EF\u63DB\u304B\
    \u3064\u7D50\u5408\u7684\u306A\u6F14\u7B97\u306A\u3089\u3088\u3044.)\n\ntemplate<class\
    \ T>\nclass lowest_common_ancestor{\n\tvector<int> dep;\n\tvector<vector<int>>\
    \ par;\n\tvector<vector<T>> dist;\n\npublic:\n\tlowest_common_ancestor(const weighted_graph<T>&\
    \ Tr,int root){\n\t\tint n=Tr.size(),h;\n\t\tfor(h=1;(1<<h)<n;h++);\n\n\t\tdep.assign(n,0);\n\
    \t\tpar.assign(h,vector<int>(n,-1));\n\t\tdist.assign(h,vector<T>(n));\n\n\t\t\
    auto dfs=[&](auto&& dfs,int u,int p)->void{\n\t\t\tfor(const auto& e:Tr[u]) if(e.to!=p)\
    \ {\n\t\t\t\tdep[e.to]=dep[u]+1;\n\t\t\t\tpar[0][e.to]=u;\n\t\t\t\tdist[0][e.to]=e.wt;\n\
    \t\t\t\tdfs(dfs,e.to,u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,root,-1);\n\t\trep(i,h-1)\
    \ rep(u,n) if(par[i][u]!=-1) {\n\t\t\tpar[i+1][u]=par[i][par[i][u]];\n\t\t\tdist[i+1][u]=dist[i][u]+dist[i][par[i][u]];\n\
    \t\t}\n\t}\n\n\tint lca(int u,int v)const{\n\t\tint h=par.size();\n\n\t\tif(dep[u]>dep[v])\
    \ swap(u,v);\n\t\trep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];\n\t\tif(u==v)\
    \ return u;\n\n\t\tfor(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u],\
    \ v=par[i][v];\n\t\treturn par[0][u];\n\t}\n\n\tT distance(int u,int v)const{\n\
    \t\tint h=par.size();\n\t\tT res=0;\n\t\tint w=lca(u,v);\n\t\trep(i,h){\n\t\t\t\
    if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];\n\t\t\tif((dep[v]-dep[w])>>i&1)\
    \ res+=dist[i][v], v=par[i][v];\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lca.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/lca.hpp
layout: document
redirect_from:
- /library/data_structure/lca.hpp
- /library/data_structure/lca.hpp.html
title: data_structure/lca.hpp
---
