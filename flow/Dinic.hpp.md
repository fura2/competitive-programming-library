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
  bundledCode: "#line 1 \"flow/Dinic.hpp\"\n/* \u6700\u5927\u6D41 (Dinic) */\n/*\n\
    \tcapa_t \u306F\u6574\u6570\u578B\u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\n\n\
    [ constructor ]\n\t\u5F15\u6570\n\t\tn : \u9802\u70B9\u6570 (source, sink \u3082\
    \u542B\u3080)\n\t\u8A08\u7B97\u91CF\n\t\tO(V)\n\n[ add_directed_edge ]\n[ add_undirected_edge\
    \ ]\n\t\u5236\u7D04\n\t\t0 <= u, v < n\n\t\tcapa >= 0\n\n[ maximum_flow ]\n\t\u8AAC\
    \u660E\n\t\ts-t \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\
    \ts : \u30BD\u30FC\u30B9\n\t\tt : \u30B7\u30F3\u30AF\n\t\u5236\u7D04\n\t\t0 <=\
    \ s, t < n\n\t\ts != t\n\t\u623B\u308A\u5024\n\t\t\u6700\u5927\u6D41\u91CF\n\t\
    \u8A08\u7B97\u91CF\n\t\tO(V^2 E)\n\n[ minimum_cut ]\n\t\u8AAC\u660E\n\t\ts-t \u6700\
    \u5C0F\u30AB\u30C3\u30C8\u3092\u6C42\u3081\u308B\n\t\tmaximum_flow(s,t) \u3092\
    \u5B9F\u884C\u5F8C\u306B\u547C\u3073\u51FA\u3059\u3053\u3068\n\t\u5F15\u6570\n\
    \t\ts : \u30BD\u30FC\u30B9\n\t\u5236\u7D04\n\t\t0 <= s < n\n\t\u623B\u308A\u5024\
    \n\t\ts-t \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u304A\u3051\u308B s \u5074\u306E\
    \u9802\u70B9\u96C6\u5408\n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n*/\n\ntemplate<class\
    \ capa_t>\nclass mf_graph{\n\tstruct edge{\n\t\tint to,rev;\n\t\tcapa_t capa,flow;\n\
    \t\tedge(int to,int rev,const capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}\n\
    \t};\n\n\tvector<vector<edge>> G;\n\tvector<int> layer,cur;\n\n\tbool make_layer(int\
    \ s,int t){\n\t\tint n=G.size();\n\t\trep(u,n) layer[u]=(u==s?0:-1);\n\n\t\tqueue<int>\
    \ Q; Q.emplace(s);\n\t\twhile(!Q.empty()){\n\t\t\tint u=Q.front(); Q.pop();\n\t\
    \t\tfor(const edge& e:G[u]) if(layer[e.to]==-1 && e.capa-e.flow>0) {\n\t\t\t\t\
    layer[e.to]=layer[u]+1;\n\t\t\t\tif(e.to==t) return true;\n\t\t\t\tQ.emplace(e.to);\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\tcapa_t augment(int u,int t,const capa_t&\
    \ water){\n\t\tif(u==t) return water;\n\n\t\tfor(int& i=cur[u];i<G[u].size();i++){\n\
    \t\t\tedge& e=G[u][i];\n\t\t\tif(layer[e.to]>layer[u] && e.capa-e.flow>0){\n\t\
    \t\t\tcapa_t w=augment(e.to,t,min(water,e.capa-e.flow));\n\t\t\t\tif(w>0){\n\t\
    \t\t\t\te.flow+=w;\n\t\t\t\t\tG[e.to][e.rev].flow-=w;\n\t\t\t\t\treturn w;\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tmf_graph(){}\n\tmf_graph(int\
    \ n):G(n){}\n\n\tvoid add_directed_edge(int u,int v,const capa_t& capa){\n\t\t\
    G[u].emplace_back(v,G[v].size()  ,capa,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,\
    \   0,0);\n\t}\n\n\tvoid add_undirected_edge(int u,int v,const capa_t& capa){\n\
    \t\tG[u].emplace_back(v,G[v].size()  ,capa,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,capa,0);\n\
    \t}\n\n\tcapa_t maximum_flow(int s,int t){\n\t\tint n=G.size();\n\t\tlayer.resize(n);\n\
    \n\t\tcapa_t res=0;\n\t\twhile(make_layer(s,t)){\n\t\t\tcur.assign(n,0);\n\t\t\
    \tfor(capa_t water=1;water>0;res+=water){\n\t\t\t\twater=augment(s,t,numeric_limits<capa_t>::max());\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tvector<int> minimum_cut(int s){\n\t\t\
    int n=G.size();\n\t\tvector<int> res;\n\t\tvector vis(n,false);\n\t\tvis[s]=true;\n\
    \t\tqueue<int> Q;\n\t\tQ.emplace(s);\n\t\twhile(!Q.empty()){\n\t\t\tint u=Q.front();\
    \ Q.pop();\n\t\t\tres.emplace_back(u);\n\t\t\tfor(const edge& e:G[u]) if(!vis[e.to]\
    \ && e.capa-e.flow>0) {\n\t\t\t\tvis[e.to]=true;\n\t\t\t\tQ.emplace(e.to);\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/* \u6700\u5927\u6D41 (Dinic) */\n/*\n\tcapa_t \u306F\u6574\u6570\u578B\u3092\
    \u60F3\u5B9A\u3057\u3066\u3044\u308B\n\n[ constructor ]\n\t\u5F15\u6570\n\t\t\
    n : \u9802\u70B9\u6570 (source, sink \u3082\u542B\u3080)\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(V)\n\n[ add_directed_edge ]\n[ add_undirected_edge ]\n\t\u5236\u7D04\n\
    \t\t0 <= u, v < n\n\t\tcapa >= 0\n\n[ maximum_flow ]\n\t\u8AAC\u660E\n\t\ts-t\
    \ \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ts : \u30BD\u30FC\
    \u30B9\n\t\tt : \u30B7\u30F3\u30AF\n\t\u5236\u7D04\n\t\t0 <= s, t < n\n\t\ts !=\
    \ t\n\t\u623B\u308A\u5024\n\t\t\u6700\u5927\u6D41\u91CF\n\t\u8A08\u7B97\u91CF\n\
    \t\tO(V^2 E)\n\n[ minimum_cut ]\n\t\u8AAC\u660E\n\t\ts-t \u6700\u5C0F\u30AB\u30C3\
    \u30C8\u3092\u6C42\u3081\u308B\n\t\tmaximum_flow(s,t) \u3092\u5B9F\u884C\u5F8C\
    \u306B\u547C\u3073\u51FA\u3059\u3053\u3068\n\t\u5F15\u6570\n\t\ts : \u30BD\u30FC\
    \u30B9\n\t\u5236\u7D04\n\t\t0 <= s < n\n\t\u623B\u308A\u5024\n\t\ts-t \u6700\u5C0F\
    \u30AB\u30C3\u30C8\u306B\u304A\u3051\u308B s \u5074\u306E\u9802\u70B9\u96C6\u5408\
    \n\t\u8A08\u7B97\u91CF\n\t\tO(V+E)\n*/\n\ntemplate<class capa_t>\nclass mf_graph{\n\
    \tstruct edge{\n\t\tint to,rev;\n\t\tcapa_t capa,flow;\n\t\tedge(int to,int rev,const\
    \ capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}\n\t\
    };\n\n\tvector<vector<edge>> G;\n\tvector<int> layer,cur;\n\n\tbool make_layer(int\
    \ s,int t){\n\t\tint n=G.size();\n\t\trep(u,n) layer[u]=(u==s?0:-1);\n\n\t\tqueue<int>\
    \ Q; Q.emplace(s);\n\t\twhile(!Q.empty()){\n\t\t\tint u=Q.front(); Q.pop();\n\t\
    \t\tfor(const edge& e:G[u]) if(layer[e.to]==-1 && e.capa-e.flow>0) {\n\t\t\t\t\
    layer[e.to]=layer[u]+1;\n\t\t\t\tif(e.to==t) return true;\n\t\t\t\tQ.emplace(e.to);\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\tcapa_t augment(int u,int t,const capa_t&\
    \ water){\n\t\tif(u==t) return water;\n\n\t\tfor(int& i=cur[u];i<G[u].size();i++){\n\
    \t\t\tedge& e=G[u][i];\n\t\t\tif(layer[e.to]>layer[u] && e.capa-e.flow>0){\n\t\
    \t\t\tcapa_t w=augment(e.to,t,min(water,e.capa-e.flow));\n\t\t\t\tif(w>0){\n\t\
    \t\t\t\te.flow+=w;\n\t\t\t\t\tG[e.to][e.rev].flow-=w;\n\t\t\t\t\treturn w;\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tmf_graph(){}\n\tmf_graph(int\
    \ n):G(n){}\n\n\tvoid add_directed_edge(int u,int v,const capa_t& capa){\n\t\t\
    G[u].emplace_back(v,G[v].size()  ,capa,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,\
    \   0,0);\n\t}\n\n\tvoid add_undirected_edge(int u,int v,const capa_t& capa){\n\
    \t\tG[u].emplace_back(v,G[v].size()  ,capa,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,capa,0);\n\
    \t}\n\n\tcapa_t maximum_flow(int s,int t){\n\t\tint n=G.size();\n\t\tlayer.resize(n);\n\
    \n\t\tcapa_t res=0;\n\t\twhile(make_layer(s,t)){\n\t\t\tcur.assign(n,0);\n\t\t\
    \tfor(capa_t water=1;water>0;res+=water){\n\t\t\t\twater=augment(s,t,numeric_limits<capa_t>::max());\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tvector<int> minimum_cut(int s){\n\t\t\
    int n=G.size();\n\t\tvector<int> res;\n\t\tvector vis(n,false);\n\t\tvis[s]=true;\n\
    \t\tqueue<int> Q;\n\t\tQ.emplace(s);\n\t\twhile(!Q.empty()){\n\t\t\tint u=Q.front();\
    \ Q.pop();\n\t\t\tres.emplace_back(u);\n\t\t\tfor(const edge& e:G[u]) if(!vis[e.to]\
    \ && e.capa-e.flow>0) {\n\t\t\t\tvis[e.to]=true;\n\t\t\t\tQ.emplace(e.to);\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/Dinic.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/Dinic.hpp
layout: document
redirect_from:
- /library/flow/Dinic.hpp
- /library/flow/Dinic.hpp.html
title: flow/Dinic.hpp
---
