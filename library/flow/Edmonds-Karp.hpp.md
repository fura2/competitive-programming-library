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
  bundledCode: "#line 1 \"library/flow/Edmonds-Karp.hpp\"\n/* \u6700\u5927\u6D41 (Edmonds-Karp)\
    \ */\n/*\n\tcapa_t \u306F\u6574\u6570\u578B\u3092\u60F3\u5B9A\u3057\u3066\u3044\
    \u308B\n\n[ constructor ]\n\t\u5F15\u6570\n\t\tn : \u9802\u70B9\u6570 (source,\
    \ sink \u3082\u542B\u3080)\n\t\u8A08\u7B97\u91CF\n\t\tO(V)\n\n[ add_directed_edge\
    \ ]\n[ add_undirected_edge ]\n\t\u5236\u7D04\n\t\t0 <= u, v < n\n\t\tcapa >= 0\n\
    \n[ maximum_flow ]\n\t\u8AAC\u660E\n\t\t\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\
    \n\t\u5F15\u6570\n\t\ts : \u30BD\u30FC\u30B9\n\t\tt : \u30B7\u30F3\u30AF\n\t\u5236\
    \u7D04\n\t\t0 <= s, t < n\n\t\ts != t\n\t\u623B\u308A\u5024\n\t\t\u6700\u5927\u6D41\
    \u91CF\n\t\u8A08\u7B97\u91CF\n\t\tO(V E^2)\n*/\n\ntemplate<class capa_t>\nclass\
    \ mf_graph{\n\tstruct edge{\n\t\tint to,rev;\n\t\tcapa_t capa,flow;\n\t\tedge(int\
    \ to,int rev,const capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}\n\
    \t};\n\n\tvector<vector<edge>> G;\n\npublic:\n\tmf_graph(){}\n\tmf_graph(int n):G(n){}\n\
    \n\tvoid add_directed_edge(int u,int v,const capa_t& capa){\n\t\tG[u].emplace_back(v,G[v].size()\
    \  ,capa,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,   0,0);\n\t}\n\n\tvoid add_undirected_edge(int\
    \ u,int v,const capa_t& capa){\n\t\tG[u].emplace_back(v,G[v].size()  ,capa,0);\n\
    \t\tG[v].emplace_back(u,G[u].size()-1,capa,0);\n\t}\n\n\tcapa_t maximum_flow(int\
    \ s,int t){\n\t\tint n=G.size();\n\t\tvector<int> pre(n);\n\t\tvector<bool> vis(n);\n\
    \n\t\tauto augment=[&](){\n\t\t\trep(u,n) vis[u]=(u==s);\n\n\t\t\tqueue<pair<int,capa_t>>\
    \ Q; Q.emplace(s,0);\n\t\t\tfor(const edge& e:G[s]){\n\t\t\t\tQ.front().second=max(Q.front().second,e.capa-e.flow);\n\
    \t\t\t}\n\n\t\t\tcapa_t res=0;\n\t\t\twhile(!Q.empty()){\n\t\t\t\tint u;\n\t\t\
    \t\tcapa_t water; tie(u,water)=Q.front(); Q.pop();\n\n\t\t\t\tif(u==t){ res=water;\
    \ break; }\n\n\t\t\t\tfor(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>0)\
    \ {\n\t\t\t\t\tvis[e.to]=true;\n\t\t\t\t\tpre[e.to]=e.rev;\n\t\t\t\t\tQ.emplace(e.to,min(water,e.capa-e.flow));\n\
    \t\t\t\t}\n\t\t\t}\n\n\t\t\tif(res>0){\n\t\t\t\tfor(int u=t;u!=s;){\n\t\t\t\t\t\
    edge& e1=G[u][pre[u]];\n\t\t\t\t\tedge& e2=G[e1.to][e1.rev];\n\t\t\t\t\te1.flow-=res;\n\
    \t\t\t\t\te2.flow+=res;\n\t\t\t\t\tu=e1.to;\n\t\t\t\t}\n\t\t\t}\n\n\t\t\treturn\
    \ res;\n\t\t};\n\n\t\tcapa_t res=0;\n\t\tfor(capa_t water=1;water>0;res+=water)\
    \ water=augment();\n\t\treturn res;\n\t}\n};\n"
  code: "/* \u6700\u5927\u6D41 (Edmonds-Karp) */\n/*\n\tcapa_t \u306F\u6574\u6570\u578B\
    \u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\n\n[ constructor ]\n\t\u5F15\u6570\n\
    \t\tn : \u9802\u70B9\u6570 (source, sink \u3082\u542B\u3080)\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(V)\n\n[ add_directed_edge ]\n[ add_undirected_edge ]\n\t\u5236\u7D04\n\
    \t\t0 <= u, v < n\n\t\tcapa >= 0\n\n[ maximum_flow ]\n\t\u8AAC\u660E\n\t\t\u6700\
    \u5927\u6D41\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ts : \u30BD\u30FC\u30B9\
    \n\t\tt : \u30B7\u30F3\u30AF\n\t\u5236\u7D04\n\t\t0 <= s, t < n\n\t\ts != t\n\t\
    \u623B\u308A\u5024\n\t\t\u6700\u5927\u6D41\u91CF\n\t\u8A08\u7B97\u91CF\n\t\tO(V\
    \ E^2)\n*/\n\ntemplate<class capa_t>\nclass mf_graph{\n\tstruct edge{\n\t\tint\
    \ to,rev;\n\t\tcapa_t capa,flow;\n\t\tedge(int to,int rev,const capa_t& capa,const\
    \ capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}\n\t};\n\n\tvector<vector<edge>>\
    \ G;\n\npublic:\n\tmf_graph(){}\n\tmf_graph(int n):G(n){}\n\n\tvoid add_directed_edge(int\
    \ u,int v,const capa_t& capa){\n\t\tG[u].emplace_back(v,G[v].size()  ,capa,0);\n\
    \t\tG[v].emplace_back(u,G[u].size()-1,   0,0);\n\t}\n\n\tvoid add_undirected_edge(int\
    \ u,int v,const capa_t& capa){\n\t\tG[u].emplace_back(v,G[v].size()  ,capa,0);\n\
    \t\tG[v].emplace_back(u,G[u].size()-1,capa,0);\n\t}\n\n\tcapa_t maximum_flow(int\
    \ s,int t){\n\t\tint n=G.size();\n\t\tvector<int> pre(n);\n\t\tvector<bool> vis(n);\n\
    \n\t\tauto augment=[&](){\n\t\t\trep(u,n) vis[u]=(u==s);\n\n\t\t\tqueue<pair<int,capa_t>>\
    \ Q; Q.emplace(s,0);\n\t\t\tfor(const edge& e:G[s]){\n\t\t\t\tQ.front().second=max(Q.front().second,e.capa-e.flow);\n\
    \t\t\t}\n\n\t\t\tcapa_t res=0;\n\t\t\twhile(!Q.empty()){\n\t\t\t\tint u;\n\t\t\
    \t\tcapa_t water; tie(u,water)=Q.front(); Q.pop();\n\n\t\t\t\tif(u==t){ res=water;\
    \ break; }\n\n\t\t\t\tfor(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>0)\
    \ {\n\t\t\t\t\tvis[e.to]=true;\n\t\t\t\t\tpre[e.to]=e.rev;\n\t\t\t\t\tQ.emplace(e.to,min(water,e.capa-e.flow));\n\
    \t\t\t\t}\n\t\t\t}\n\n\t\t\tif(res>0){\n\t\t\t\tfor(int u=t;u!=s;){\n\t\t\t\t\t\
    edge& e1=G[u][pre[u]];\n\t\t\t\t\tedge& e2=G[e1.to][e1.rev];\n\t\t\t\t\te1.flow-=res;\n\
    \t\t\t\t\te2.flow+=res;\n\t\t\t\t\tu=e1.to;\n\t\t\t\t}\n\t\t\t}\n\n\t\t\treturn\
    \ res;\n\t\t};\n\n\t\tcapa_t res=0;\n\t\tfor(capa_t water=1;water>0;res+=water)\
    \ water=augment();\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/Edmonds-Karp.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/flow/Edmonds-Karp.hpp
layout: document
redirect_from:
- /library/library/flow/Edmonds-Karp.hpp
- /library/library/flow/Edmonds-Karp.hpp.html
title: library/flow/Edmonds-Karp.hpp
---
