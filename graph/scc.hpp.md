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
  bundledCode: "#line 1 \"graph/scc.hpp\"\n/* \u5F37\u9023\u7D50\u6210\u5206\u5206\
    \u89E3 */\n/*\n[ constructor ]\n\t\u5F15\u6570\n\t\tG : \u6709\u5411\u30B0\u30E9\
    \u30D5\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n\t\
    \u5099\u8003\n\t\tG \u306B\u306F\u591A\u91CD\u8FBA, \u81EA\u5DF1\u30EB\u30FC\u30D7\
    \u304C\u3042\u3063\u3066\u3082\u3088\u3044\n\t\tG \u306F\u9023\u7D50\u3067\u306A\
    \u304F\u3066\u3082\u3088\u3044\n\n[ operator[] ]\n\t\u8AAC\u660E\n\t\tu \u304C\
    \u542B\u307E\u308C\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\n\t\u5F15\
    \u6570\n\t\tu : G \u306E\u9802\u70B9\n\t\u5236\u7D04\n\t\t0 <= u < |V(G)|\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u5F37\u9023\u7D50\u6210\u5206\u306E\
    \u500B\u6570\u3092 K \u3068\u3059\u308B\u3068, \u5F37\u9023\u7D50\u6210\u5206\u306F\
    \ DAG \u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306B\u3057\u305F\
    \u304C\u3063\u3066 0, 1, ..., K-1 \u3067\u756A\u53F7\u3065\u3051\u3089\u308C\u3066\
    \u3044\u308B\n\ncomponent\n\t\u8AAC\u660E\n\t\ti \u756A\u76EE\u306E\u5F37\u9023\
    \u7D50\u6210\u5206\u3092\u8FD4\u3059\n\t\u5F15\u6570\n\t\ti : \u5F37\u9023\u7D50\
    \u6210\u5206\u306E\u756A\u53F7\n\t\u5236\u7D04\n\t\t0 <= i < \u5F37\u9023\u7D50\
    \u6210\u5206\u306E\u500B\u6570\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\nDAG\n\t\u8AAC\
    \u660E\n\t\tG \u5F37\u9023\u7D50\u6210\u5206\u3092\u7E2E\u7D04\u3057\u3066\u5F97\
    \u3089\u308C\u308B DAG \u3092\u8FD4\u3059\n\t\tG \u306B\u591A\u91CD\u8FBA\u304C\
    \u306A\u304F\u3066\u3082 DAG \u306B\u306F\u591A\u91CD\u8FBA\u304C\u542B\u307E\u308C\
    \u3046\u308B\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\u8003\n\t\t\u5F37\u9023\
    \u7D50\u6210\u5206\u306E\u500B\u6570\u3092 K \u3068\u3059\u308B\u3068, 0, 1, ...,\
    \ K-1 \u306F\u3053\u306E DAG \u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\
    \u306B\u306A\u3063\u3066\u3044\u308B\n*/\n\nclass strongly_connected_components{\n\
    \tvector<int> id;\n\tvector<vector<int>> Comp;\n\tgraph D;\n\npublic:\n\tstrongly_connected_components(){}\n\
    \tstrongly_connected_components(const graph& G){\n\t\tint n=G.size();\n\t\tgraph\
    \ G_rev(n);\n\t\trep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);\n\n\t\t\
    int k;\n\t\tvector<int> top(n);\n\n\t\tauto dfs1=[&](auto&& dfs1,int u)->void{\n\
    \t\t\tid[u]=0;\n\t\t\tfor(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);\n\t\t\ttop[k++]=u;\n\
    \t\t};\n\t\tauto dfs2=[&](auto&& dfs2,int u)->void{\n\t\t\tid[u]=k;\n\t\t\tfor(int\
    \ v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);\n\t\t};\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\
    \t\trep(u,n) if(id[u]==-1) dfs1(dfs1,u);\n\n\t\treverse(top.begin(),top.end());\n\
    \n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\tfor(int u:top) if(id[u]==-1) dfs2(dfs2,u),\
    \ k++;\n\n\t\tComp.resize(k);\n\t\tD.resize(k);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\
    \t\t\tfor(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);\n\t\t\
    }\n\t}\n\n\tint operator[](int u)const{ return id[u]; }\n\n\tconst vector<int>&\
    \ component(int i)const{ return Comp[i]; }\n\tconst graph& DAG()const{ return\
    \ D; }\n};\n"
  code: "/* \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 */\n/*\n[ constructor ]\n\t\
    \u5F15\u6570\n\t\tG : \u6709\u5411\u30B0\u30E9\u30D5\n\t\u5236\u7D04\n\t\t\u306A\
    \u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n\t\u5099\u8003\n\t\tG \u306B\u306F\u591A\
    \u91CD\u8FBA, \u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u3063\u3066\u3082\u3088\
    \u3044\n\t\tG \u306F\u9023\u7D50\u3067\u306A\u304F\u3066\u3082\u3088\u3044\n\n\
    [ operator[] ]\n\t\u8AAC\u660E\n\t\tu \u304C\u542B\u307E\u308C\u308B\u5F37\u9023\
    \u7D50\u6210\u5206\u306E\u756A\u53F7\n\t\u5F15\u6570\n\t\tu : G \u306E\u9802\u70B9\
    \n\t\u5236\u7D04\n\t\t0 <= u < |V(G)|\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\
    \u8003\n\t\t\u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092 K \u3068\u3059\
    \u308B\u3068, \u5F37\u9023\u7D50\u6210\u5206\u306F DAG \u306E\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u9806\u5E8F\u306B\u3057\u305F\u304C\u3063\u3066 0, 1, ...,\
    \ K-1 \u3067\u756A\u53F7\u3065\u3051\u3089\u308C\u3066\u3044\u308B\n\ncomponent\n\
    \t\u8AAC\u660E\n\t\ti \u756A\u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u3092\u8FD4\
    \u3059\n\t\u5F15\u6570\n\t\ti : \u5F37\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\
    \n\t\u5236\u7D04\n\t\t0 <= i < \u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\
    \n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\nDAG\n\t\u8AAC\u660E\n\t\tG \u5F37\u9023\u7D50\
    \u6210\u5206\u3092\u7E2E\u7D04\u3057\u3066\u5F97\u3089\u308C\u308B DAG \u3092\u8FD4\
    \u3059\n\t\tG \u306B\u591A\u91CD\u8FBA\u304C\u306A\u304F\u3066\u3082 DAG \u306B\
    \u306F\u591A\u91CD\u8FBA\u304C\u542B\u307E\u308C\u3046\u308B\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(1)\n\t\u5099\u8003\n\t\t\u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\
    \u3092 K \u3068\u3059\u308B\u3068, 0, 1, ..., K-1 \u306F\u3053\u306E DAG \u306E\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306B\u306A\u3063\u3066\u3044\
    \u308B\n*/\n\nclass strongly_connected_components{\n\tvector<int> id;\n\tvector<vector<int>>\
    \ Comp;\n\tgraph D;\n\npublic:\n\tstrongly_connected_components(){}\n\tstrongly_connected_components(const\
    \ graph& G){\n\t\tint n=G.size();\n\t\tgraph G_rev(n);\n\t\trep(u,n) for(int v:G[u])\
    \ add_directed_edge(G_rev,v,u);\n\n\t\tint k;\n\t\tvector<int> top(n);\n\n\t\t\
    auto dfs1=[&](auto&& dfs1,int u)->void{\n\t\t\tid[u]=0;\n\t\t\tfor(int v:G[u])\
    \ if(id[v]==-1) dfs1(dfs1,v);\n\t\t\ttop[k++]=u;\n\t\t};\n\t\tauto dfs2=[&](auto&&\
    \ dfs2,int u)->void{\n\t\t\tid[u]=k;\n\t\t\tfor(int v:G_rev[u]) if(id[v]==-1)\
    \ dfs2(dfs2,v);\n\t\t};\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\t\trep(u,n) if(id[u]==-1)\
    \ dfs1(dfs1,u);\n\n\t\treverse(top.begin(),top.end());\n\n\t\tk=0;\n\t\tid.assign(n,-1);\n\
    \t\tfor(int u:top) if(id[u]==-1) dfs2(dfs2,u), k++;\n\n\t\tComp.resize(k);\n\t\
    \tD.resize(k);\n\t\trep(u,n){\n\t\t\tComp[id[u]].emplace_back(u);\n\t\t\tfor(int\
    \ v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);\n\t\t}\n\t}\n\n\t\
    int operator[](int u)const{ return id[u]; }\n\n\tconst vector<int>& component(int\
    \ i)const{ return Comp[i]; }\n\tconst graph& DAG()const{ return D; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
