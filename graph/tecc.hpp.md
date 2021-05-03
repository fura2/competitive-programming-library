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
  bundledCode: "#line 1 \"graph/tecc.hpp\"\n/* \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u5206\u89E3 */\n/*\n[ constructor ]\n\t\u5F15\u6570\n\t\tG : \u7121\u5411\
    \u30B0\u30E9\u30D5\n\t\u5236\u7D04\n\t\tG \u306F\u7121\u5411\u30B0\u30E9\u30D5\
    \ (\u8FBA u->v \u3068\u540C\u3058\u672C\u6570\u3060\u3051 v->u \u304C\u3042\u308B\
    )\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n\t\u5099\u8003\n\t\tG \u306B\u306F\u591A\u91CD\
    \u8FBA, \u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u3063\u3066\u3082\u3088\u3044\
    \n\t\tG \u306F\u9023\u7D50\u3067\u306A\u304F\u3066\u3082\u3088\u3044\n\noperator[]\n\
    \t\u8AAC\u660E\n\t\tu \u304C\u542B\u307E\u308C\u308B\u4E8C\u91CD\u8FBA\u9023\u7D50\
    \u6210\u5206\u306E\u756A\u53F7\n\t\u5F15\u6570\n\t\tu : G \u306E\u9802\u70B9\n\
    \t\u5236\u7D04\n\t\t0 <= u < |V(G)|\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\
    \n\t\t\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092 K \u3068\
    \u3059\u308B\u3068, \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306F 0, 1, ...,\
    \ K-1 \u3067\u756A\u53F7\u3065\u3051\u3089\u308C\u3066\u3044\u308B\n\ncomponent\n\
    \t\u8AAC\u660E\n\t\ti \u756A\u76EE\u306E\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u3092\u8FD4\u3059\n\t\u5F15\u6570\n\t\ti : \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u306E\u756A\u53F7\n\t\u5236\u7D04\n\t\t0 <= i < \u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u306E\u500B\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\nbridges\n\
    \t\u8AAC\u660E\n\t\t\u6A4B\u306E\u96C6\u5408\u3092\u8FD4\u3059\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(1)\n\nbridge_block_tree\n\t\u8AAC\u660E\n\t\t\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u3092\u7E2E\u7D04\u3057\u3066\u5F97\u3089\u308C\u308B\u6728\
    \u3092\u8FD4\u3059\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\tG \u304C\
    \u9023\u7D50\u3067\u306A\u3044\u5834\u5408\u306F\u7E2E\u7D04\u3057\u3066\u5F97\
    \u3089\u308C\u308B\u68EE\u3092\u8FD4\u3059\n*/\n\nclass two_edge_connected_components{\n\
    \tint idx;\n\tvector<int> ord,low,id;\n\tconst graph& G;\n\n\tvector<vector<int>>\
    \ Comp;\n\tvector<pair<int,int>> B;\n\tgraph Tr;\n\n\tvoid dfs1(int u,int p){\n\
    \t\tord[u]=low[u]=idx++;\n\t\tbool f=true;\n\t\tfor(int v:G[u]){\n\t\t\tif(v==p\
    \ && f){ f=false; continue; }\n\t\t\tif(ord[v]==-1){\n\t\t\t\tdfs1(v,u);\n\t\t\
    \t\tlow[u]=min(low[u],low[v]);\n\t\t\t}\n\t\t\telse{\n\t\t\t\tlow[u]=min(low[u],ord[v]);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs2(int u,int p){\n\t\tif(p==-1 || ord[p]<low[u]){\n\
    \t\t\tid[u]=idx++;\n\t\t\tif(p!=-1) B.emplace_back(minmax(p,u));\n\t\t}\n\t\t\
    else{\n\t\t\tid[u]=id[p];\n\t\t}\n\t\tfor(int v:G[u]) if(id[v]==-1) dfs2(v,u);\n\
    \t}\n\npublic:\n\ttwo_edge_connected_components(const graph& G):G(G){\n\t\tint\
    \ n=G.size();\n\n\t\tidx=0;\n\t\tord.assign(n,-1);\n\t\tlow.assign(n,-1);\n\t\t\
    rep(u,n) if(ord[u]==-1) dfs1(u,-1);\n\n\t\tidx=0;\n\t\tid.assign(n,-1);\n\t\t\
    rep(u,n) if(id[u]==-1) dfs2(u,-1);\n\n\t\tComp.resize(idx);\n\t\tTr.resize(idx);\n\
    \t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\t\t\tfor(int v:G[u]) if(id[u]!=id[v])\
    \ Tr[id[u]].emplace_back(id[v]);\n\t\t}\n\t}\n\n\tint operator[](int i)const{\
    \ return id[i]; }\n\n\tconst vector<int>& component(int i)const{ return Comp[i];\
    \ }\n\tconst vector<pair<int,int>>& bridges()const{ return B; }\n\tconst graph&\
    \ bridge_block_tree()const{ return Tr; }\n};\n"
  code: "/* \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 */\n/*\n[ constructor\
    \ ]\n\t\u5F15\u6570\n\t\tG : \u7121\u5411\u30B0\u30E9\u30D5\n\t\u5236\u7D04\n\t\
    \tG \u306F\u7121\u5411\u30B0\u30E9\u30D5 (\u8FBA u->v \u3068\u540C\u3058\u672C\
    \u6570\u3060\u3051 v->u \u304C\u3042\u308B)\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n\
    \t\u5099\u8003\n\t\tG \u306B\u306F\u591A\u91CD\u8FBA, \u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u304C\u3042\u3063\u3066\u3082\u3088\u3044\n\t\tG \u306F\u9023\u7D50\u3067\
    \u306A\u304F\u3066\u3082\u3088\u3044\n\noperator[]\n\t\u8AAC\u660E\n\t\tu \u304C\
    \u542B\u307E\u308C\u308B\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306E\u756A\
    \u53F7\n\t\u5F15\u6570\n\t\tu : G \u306E\u9802\u70B9\n\t\u5236\u7D04\n\t\t0 <=\
    \ u < |V(G)|\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092 K \u3068\u3059\u308B\u3068\
    , \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306F 0, 1, ..., K-1 \u3067\u756A\
    \u53F7\u3065\u3051\u3089\u308C\u3066\u3044\u308B\n\ncomponent\n\t\u8AAC\u660E\n\
    \t\ti \u756A\u76EE\u306E\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3092\u8FD4\
    \u3059\n\t\u5F15\u6570\n\t\ti : \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306E\
    \u756A\u53F7\n\t\u5236\u7D04\n\t\t0 <= i < \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u306E\u500B\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\nbridges\n\t\u8AAC\u660E\
    \n\t\t\u6A4B\u306E\u96C6\u5408\u3092\u8FD4\u3059\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\
    \nbridge_block_tree\n\t\u8AAC\u660E\n\t\t\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u3092\u7E2E\u7D04\u3057\u3066\u5F97\u3089\u308C\u308B\u6728\u3092\u8FD4\u3059\
    \n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\tG \u304C\u9023\u7D50\u3067\
    \u306A\u3044\u5834\u5408\u306F\u7E2E\u7D04\u3057\u3066\u5F97\u3089\u308C\u308B\
    \u68EE\u3092\u8FD4\u3059\n*/\n\nclass two_edge_connected_components{\n\tint idx;\n\
    \tvector<int> ord,low,id;\n\tconst graph& G;\n\n\tvector<vector<int>> Comp;\n\t\
    vector<pair<int,int>> B;\n\tgraph Tr;\n\n\tvoid dfs1(int u,int p){\n\t\tord[u]=low[u]=idx++;\n\
    \t\tbool f=true;\n\t\tfor(int v:G[u]){\n\t\t\tif(v==p && f){ f=false; continue;\
    \ }\n\t\t\tif(ord[v]==-1){\n\t\t\t\tdfs1(v,u);\n\t\t\t\tlow[u]=min(low[u],low[v]);\n\
    \t\t\t}\n\t\t\telse{\n\t\t\t\tlow[u]=min(low[u],ord[v]);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tvoid dfs2(int u,int p){\n\t\tif(p==-1 || ord[p]<low[u]){\n\t\t\tid[u]=idx++;\n\
    \t\t\tif(p!=-1) B.emplace_back(minmax(p,u));\n\t\t}\n\t\telse{\n\t\t\tid[u]=id[p];\n\
    \t\t}\n\t\tfor(int v:G[u]) if(id[v]==-1) dfs2(v,u);\n\t}\n\npublic:\n\ttwo_edge_connected_components(const\
    \ graph& G):G(G){\n\t\tint n=G.size();\n\n\t\tidx=0;\n\t\tord.assign(n,-1);\n\t\
    \tlow.assign(n,-1);\n\t\trep(u,n) if(ord[u]==-1) dfs1(u,-1);\n\n\t\tidx=0;\n\t\
    \tid.assign(n,-1);\n\t\trep(u,n) if(id[u]==-1) dfs2(u,-1);\n\n\t\tComp.resize(idx);\n\
    \t\tTr.resize(idx);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\t\t\t\
    for(int v:G[u]) if(id[u]!=id[v]) Tr[id[u]].emplace_back(id[v]);\n\t\t}\n\t}\n\n\
    \tint operator[](int i)const{ return id[i]; }\n\n\tconst vector<int>& component(int\
    \ i)const{ return Comp[i]; }\n\tconst vector<pair<int,int>>& bridges()const{ return\
    \ B; }\n\tconst graph& bridge_block_tree()const{ return Tr; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tecc.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tecc.hpp
layout: document
redirect_from:
- /library/graph/tecc.hpp
- /library/graph/tecc.hpp.html
title: graph/tecc.hpp
---
