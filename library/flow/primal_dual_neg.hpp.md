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
  bundledCode: "#line 1 \"library/flow/primal_dual_neg.hpp\"\n/* \u6700\u5C0F\u8CBB\
    \u7528\u6D41 (primal-dual) */\n/*\n\tcapa_t, cost_t \u306F\u6574\u6570\u578B\u3092\
    \u60F3\u5B9A\u3057\u3066\u3044\u308B\n\t\u6700\u521D\u306E 1 \u56DE\u3060\u3051\
    \ Bellman-Ford \u6CD5\u3092\u4F7F\u3063\u3066\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \u3092\u6C42\u3081\u3066,\n\t2 \u56DE\u76EE\u4EE5\u964D\u306F Dijkstra \u6CD5\u3092\
    \u4F7F\u3063\u3066\u3044\u308B\n\t\u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\
    \u3042\u3063\u3066\u3082\u3088\u3044\u304C, \u8CA0\u306E\u30B3\u30B9\u30C8\u306E\
    \u9589\u8DEF\u304C\u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A\n\n\t\u8CA0\u8FBA\
    \u306E\u51E6\u7406\u306B\u3064\u3044\u3066\u306E tips\n\t- DAG \u306A\u3089 Bellman-Ford\
    \ \u306E\u304B\u308F\u308A\u306B O(V+E) \u306E DP \u3067\u6700\u77ED\u7D4C\u8DEF\
    \u304C\u6C42\u307E\u308B (\u672A\u5B9F\u88C5).\n\t  \u5143\u306E\u30B0\u30E9\u30D5\
    \u304C DAG \u3067\u3082, augment \u306E\u4E8C\u56DE\u76EE\u4EE5\u964D\u3067\u306F\
    \u6B8B\u4F59\u30B0\u30E9\u30D5\u306F DAG \u3068\u306F\u9650\u3089\u306A\u3044\u3053\
    \u3068\u306B\u6CE8\u610F!!\n\t  0,1,..,n-1 \u304C\u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u9806\u5E8F\u306A\u3089 Bellman-Ford \u306F 1 \u56DE\u3067\u7D42\u308F\u308B\
    \u306E\u3067, \u3053\u306E\u30B3\u30FC\u30C9\u3067 O(F E log V) \u304C\u9054\u6210\
    \u3067\u304D\u308B.\n\t- \u4F7F\u3046\u8FBA\u306E\u672C\u6570 or \u7DCF\u6D41\u91CF\
    \u304C\u56FA\u5B9A\u306A\u3089\u30B0\u30E9\u30D5\u3092\u5909\u5F62\u3057\u3066\
    \u8CA0\u8FBA\u3092\u306A\u304F\u305B\u308B. ( \u87FB\u672C p.204-205 )\n\n[ constructor\
    \ ]\n\t\u5F15\u6570\n\t\tn : \u9802\u70B9\u6570 (source, sink \u3082\u542B\u3080\
    )\n\t\u8A08\u7B97\u91CF\n\t\tO(V)\n\n[ add_directed_edge ]\n\t\u5236\u7D04\n\t\
    \t0 <= u, v < n\n\t\tcapa >= 0\n\t\u5099\u8003\n\t\t\u7121\u5411\u8FBA\u3092\u5F35\
    \u308B\u3068\u304D\u306F\u4EE3\u308F\u308A\u306B\u6709\u5411\u8FBA\u3092\u53CC\
    \u65B9\u5411\u306B\u5F35\u308B\n\n[ minimum_cost_flow ]\n\t\u8AAC\u660E\n\t\t\
    limit \u307E\u3067\u6D41\u305B\u308B\u3068\u304D\u306E\u6700\u5C0F\u8CBB\u7528\
    \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ts : \u30BD\u30FC\
    \u30B9\n\t\tt : \u30B7\u30F3\u30AF\n\t\tlimit : \u6700\u5927\u6D41\u91CF\n\t\u5236\
    \u7D04\n\t\t0 <= s, t < n\n\t\ts != t\n\t\u623B\u308A\u5024\n\t\t(\u6700\u5927\
    \u6D41\u91CF, \u305D\u306E\u3068\u304D\u306E\u6700\u5C0F\u30B3\u30B9\u30C8)\n\t\
    \u8A08\u7B97\u91CF\n\t\tO(V E + F E log(V))\n*/\n\ntemplate<class capa_t,class\
    \ cost_t>\nclass mcf_graph{\n\tstruct edge{\n\t\tint to,rev;\n\t\tcapa_t capa,flow;\n\
    \t\tcost_t cost;\n\t\tedge(int to,int rev,const capa_t& capa,const cost_t& cost,const\
    \ capa_t& flow):to(to),rev(rev),capa(capa),cost(cost),flow(flow){}\n\t};\n\n\t\
    vector<vector<edge>> G;\n\n\tstatic constexpr capa_t CAPA_INF=numeric_limits<capa_t>::max();\n\
    \tstatic constexpr cost_t COST_INF=numeric_limits<cost_t>::max();\n\npublic:\n\
    \tmcf_graph(){}\n\tmcf_graph(int n):G(n){}\n\n\tvoid add_directed_edge(int u,int\
    \ v,const capa_t& capa,const cost_t& cost){\n\t\tG[u].emplace_back(v,G[v].size()\
    \  ,capa, cost,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,   0,-cost,0);\n\t}\n\
    \n\tpair<capa_t,cost_t> minimum_cost_flow(int s,int t,capa_t limit=CAPA_INF){\n\
    \t\tint n=G.size();\n\t\tvector<int> pre(n);\n\t\tvector<cost_t> d(n),pot(n);\n\
    \t\tpriority_queue<pair<cost_t,int>> Q;\n\n\t\tauto augment=[&](bool first)->pair<capa_t,cost_t>{\n\
    \t\t\trep(u,n) d[u]=(u==s?0:COST_INF);\n\n\t\t\tbool ok;\n\t\t\tif(first){\n\t\
    \t\t\t// Bellman-Ford\n\t\t\t\trep(_,n){\n\t\t\t\t\tbool upd=false;\n\t\t\t\t\t\
    rep(u,n) if(d[u]<COST_INF) {\n\t\t\t\t\t\tfor(const edge& e:G[u]) if(e.capa-e.flow>0)\
    \ {\n\t\t\t\t\t\t\tif(d[e.to]>d[u]+e.cost){\n\t\t\t\t\t\t\t\td[e.to]=d[u]+e.cost;\n\
    \t\t\t\t\t\t\t\tpre[e.to]=e.rev;\n\t\t\t\t\t\t\t\tupd=true;\n\t\t\t\t\t\t\t}\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif(!upd) break;\n\t\t\t\t}\n\t\t\t\tok=(d[t]<COST_INF);\n\
    \t\t\t}\n\t\t\telse{\n\t\t\t\t// Dijkstra\n\t\t\t\tok=false;\n\t\t\t\tQ.emplace(0,s);\n\
    \t\t\t\twhile(!Q.empty()){\n\t\t\t\t\tint u;\n\t\t\t\t\tcost_t tmp; tie(tmp,u)=Q.top();\
    \ Q.pop();\n\n\t\t\t\t\tif(-tmp<d[u]) continue;\n\t\t\t\t\tif(u==t) ok=true;\n\
    \n\t\t\t\t\tfor(const edge& e:G[u]) if(e.capa-e.flow>0) {\n\t\t\t\t\t\tcost_t\
    \ cost2=d[u]+e.cost+pot[u]-pot[e.to];\n\t\t\t\t\t\tif(d[e.to]>cost2){\n\t\t\t\t\
    \t\t\td[e.to]=cost2;\n\t\t\t\t\t\t\tpre[e.to]=e.rev;\n\t\t\t\t\t\t\tQ.emplace(-cost2,e.to);\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tif(!ok) return {0,0};\n\
    \n\t\t\tcapa_t water=limit;\n\t\t\tfor(int u=t;u!=s;){\n\t\t\t\tedge& e1=G[u][pre[u]];\n\
    \t\t\t\tedge& e2=G[e1.to][e1.rev];\n\t\t\t\twater=min(water,e2.capa-e2.flow);\n\
    \t\t\t\tu=e1.to;\n\t\t\t}\n\t\t\tlimit-=water;\n\n\t\t\tfor(int u=t;u!=s;){\n\t\
    \t\t\tedge& e1=G[u][pre[u]];\n\t\t\t\tedge& e2=G[e1.to][e1.rev];\n\t\t\t\te1.flow-=water;\n\
    \t\t\t\te2.flow+=water;\n\t\t\t\tu=e1.to;\n\t\t\t}\n\n\t\t\trep(u,n) pot[u]+=d[u];\n\
    \n\t\t\treturn {water,water*pot[t]};\n\t\t};\n\n\t\tcapa_t res1=0;\n\t\tcost_t\
    \ res2=0;\n\t\tfor(bool first=true;limit>0;first=false){\n\t\t\tauto tmp=augment(first);\n\
    \t\t\tif(tmp.first==0) break;\n\t\t\tres1+=tmp.first;\n\t\t\tres2+=tmp.second;\n\
    \t\t}\n\t\treturn {res1,res2};\n\t}\n};\n"
  code: "/* \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual) */\n/*\n\tcapa_t, cost_t\
    \ \u306F\u6574\u6570\u578B\u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\n\t\u6700\
    \u521D\u306E 1 \u56DE\u3060\u3051 Bellman-Ford \u6CD5\u3092\u4F7F\u3063\u3066\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\u3066,\n\t2 \u56DE\u76EE\u4EE5\
    \u964D\u306F Dijkstra \u6CD5\u3092\u4F7F\u3063\u3066\u3044\u308B\n\t\u8CA0\u306E\
    \u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u3042\u3063\u3066\u3082\u3088\u3044\u304C\
    , \u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u9589\u8DEF\u304C\u306A\u3044\u3053\u3068\
    \u3092\u4EEE\u5B9A\n\n\t\u8CA0\u8FBA\u306E\u51E6\u7406\u306B\u3064\u3044\u3066\
    \u306E tips\n\t- DAG \u306A\u3089 Bellman-Ford \u306E\u304B\u308F\u308A\u306B\
    \ O(V+E) \u306E DP \u3067\u6700\u77ED\u7D4C\u8DEF\u304C\u6C42\u307E\u308B (\u672A\
    \u5B9F\u88C5).\n\t  \u5143\u306E\u30B0\u30E9\u30D5\u304C DAG \u3067\u3082, augment\
    \ \u306E\u4E8C\u56DE\u76EE\u4EE5\u964D\u3067\u306F\u6B8B\u4F59\u30B0\u30E9\u30D5\
    \u306F DAG \u3068\u306F\u9650\u3089\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\
    !!\n\t  0,1,..,n-1 \u304C\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306A\
    \u3089 Bellman-Ford \u306F 1 \u56DE\u3067\u7D42\u308F\u308B\u306E\u3067, \u3053\
    \u306E\u30B3\u30FC\u30C9\u3067 O(F E log V) \u304C\u9054\u6210\u3067\u304D\u308B\
    .\n\t- \u4F7F\u3046\u8FBA\u306E\u672C\u6570 or \u7DCF\u6D41\u91CF\u304C\u56FA\u5B9A\
    \u306A\u3089\u30B0\u30E9\u30D5\u3092\u5909\u5F62\u3057\u3066\u8CA0\u8FBA\u3092\
    \u306A\u304F\u305B\u308B. ( \u87FB\u672C p.204-205 )\n\n[ constructor ]\n\t\u5F15\
    \u6570\n\t\tn : \u9802\u70B9\u6570 (source, sink \u3082\u542B\u3080)\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(V)\n\n[ add_directed_edge ]\n\t\u5236\u7D04\n\t\t0 <= u, v\
    \ < n\n\t\tcapa >= 0\n\t\u5099\u8003\n\t\t\u7121\u5411\u8FBA\u3092\u5F35\u308B\
    \u3068\u304D\u306F\u4EE3\u308F\u308A\u306B\u6709\u5411\u8FBA\u3092\u53CC\u65B9\
    \u5411\u306B\u5F35\u308B\n\n[ minimum_cost_flow ]\n\t\u8AAC\u660E\n\t\tlimit \u307E\
    \u3067\u6D41\u305B\u308B\u3068\u304D\u306E\u6700\u5C0F\u8CBB\u7528\u6700\u5927\
    \u6D41\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ts : \u30BD\u30FC\u30B9\n\t\
    \tt : \u30B7\u30F3\u30AF\n\t\tlimit : \u6700\u5927\u6D41\u91CF\n\t\u5236\u7D04\
    \n\t\t0 <= s, t < n\n\t\ts != t\n\t\u623B\u308A\u5024\n\t\t(\u6700\u5927\u6D41\
    \u91CF, \u305D\u306E\u3068\u304D\u306E\u6700\u5C0F\u30B3\u30B9\u30C8)\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(V E + F E log(V))\n*/\n\ntemplate<class capa_t,class cost_t>\n\
    class mcf_graph{\n\tstruct edge{\n\t\tint to,rev;\n\t\tcapa_t capa,flow;\n\t\t\
    cost_t cost;\n\t\tedge(int to,int rev,const capa_t& capa,const cost_t& cost,const\
    \ capa_t& flow):to(to),rev(rev),capa(capa),cost(cost),flow(flow){}\n\t};\n\n\t\
    vector<vector<edge>> G;\n\n\tstatic constexpr capa_t CAPA_INF=numeric_limits<capa_t>::max();\n\
    \tstatic constexpr cost_t COST_INF=numeric_limits<cost_t>::max();\n\npublic:\n\
    \tmcf_graph(){}\n\tmcf_graph(int n):G(n){}\n\n\tvoid add_directed_edge(int u,int\
    \ v,const capa_t& capa,const cost_t& cost){\n\t\tG[u].emplace_back(v,G[v].size()\
    \  ,capa, cost,0);\n\t\tG[v].emplace_back(u,G[u].size()-1,   0,-cost,0);\n\t}\n\
    \n\tpair<capa_t,cost_t> minimum_cost_flow(int s,int t,capa_t limit=CAPA_INF){\n\
    \t\tint n=G.size();\n\t\tvector<int> pre(n);\n\t\tvector<cost_t> d(n),pot(n);\n\
    \t\tpriority_queue<pair<cost_t,int>> Q;\n\n\t\tauto augment=[&](bool first)->pair<capa_t,cost_t>{\n\
    \t\t\trep(u,n) d[u]=(u==s?0:COST_INF);\n\n\t\t\tbool ok;\n\t\t\tif(first){\n\t\
    \t\t\t// Bellman-Ford\n\t\t\t\trep(_,n){\n\t\t\t\t\tbool upd=false;\n\t\t\t\t\t\
    rep(u,n) if(d[u]<COST_INF) {\n\t\t\t\t\t\tfor(const edge& e:G[u]) if(e.capa-e.flow>0)\
    \ {\n\t\t\t\t\t\t\tif(d[e.to]>d[u]+e.cost){\n\t\t\t\t\t\t\t\td[e.to]=d[u]+e.cost;\n\
    \t\t\t\t\t\t\t\tpre[e.to]=e.rev;\n\t\t\t\t\t\t\t\tupd=true;\n\t\t\t\t\t\t\t}\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif(!upd) break;\n\t\t\t\t}\n\t\t\t\tok=(d[t]<COST_INF);\n\
    \t\t\t}\n\t\t\telse{\n\t\t\t\t// Dijkstra\n\t\t\t\tok=false;\n\t\t\t\tQ.emplace(0,s);\n\
    \t\t\t\twhile(!Q.empty()){\n\t\t\t\t\tint u;\n\t\t\t\t\tcost_t tmp; tie(tmp,u)=Q.top();\
    \ Q.pop();\n\n\t\t\t\t\tif(-tmp<d[u]) continue;\n\t\t\t\t\tif(u==t) ok=true;\n\
    \n\t\t\t\t\tfor(const edge& e:G[u]) if(e.capa-e.flow>0) {\n\t\t\t\t\t\tcost_t\
    \ cost2=d[u]+e.cost+pot[u]-pot[e.to];\n\t\t\t\t\t\tif(d[e.to]>cost2){\n\t\t\t\t\
    \t\t\td[e.to]=cost2;\n\t\t\t\t\t\t\tpre[e.to]=e.rev;\n\t\t\t\t\t\t\tQ.emplace(-cost2,e.to);\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tif(!ok) return {0,0};\n\
    \n\t\t\tcapa_t water=limit;\n\t\t\tfor(int u=t;u!=s;){\n\t\t\t\tedge& e1=G[u][pre[u]];\n\
    \t\t\t\tedge& e2=G[e1.to][e1.rev];\n\t\t\t\twater=min(water,e2.capa-e2.flow);\n\
    \t\t\t\tu=e1.to;\n\t\t\t}\n\t\t\tlimit-=water;\n\n\t\t\tfor(int u=t;u!=s;){\n\t\
    \t\t\tedge& e1=G[u][pre[u]];\n\t\t\t\tedge& e2=G[e1.to][e1.rev];\n\t\t\t\te1.flow-=water;\n\
    \t\t\t\te2.flow+=water;\n\t\t\t\tu=e1.to;\n\t\t\t}\n\n\t\t\trep(u,n) pot[u]+=d[u];\n\
    \n\t\t\treturn {water,water*pot[t]};\n\t\t};\n\n\t\tcapa_t res1=0;\n\t\tcost_t\
    \ res2=0;\n\t\tfor(bool first=true;limit>0;first=false){\n\t\t\tauto tmp=augment(first);\n\
    \t\t\tif(tmp.first==0) break;\n\t\t\tres1+=tmp.first;\n\t\t\tres2+=tmp.second;\n\
    \t\t}\n\t\treturn {res1,res2};\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/primal_dual_neg.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/flow/primal_dual_neg.hpp
layout: document
redirect_from:
- /library/library/flow/primal_dual_neg.hpp
- /library/library/flow/primal_dual_neg.hpp.html
title: library/flow/primal_dual_neg.hpp
---
