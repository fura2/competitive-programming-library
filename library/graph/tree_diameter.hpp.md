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
  bundledCode: "#line 1 \"library/graph/tree_diameter.hpp\"\n/*\n\tn>0 \u3092\u4EEE\
    \u5B9A\n*/\n\npair<int,vector<int>> tree_diameter(const graph& T){\n\tint n=T.size();\n\
    \tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int u,int p)->pair<int,int>{\n\
    \t\tint g=u,d_max=0;\n\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\tauto [d,w]=dfs(dfs,v,u);\n\
    \t\t\tif(d+1>d_max){\n\t\t\t\td_max=d+1;\n\t\t\t\tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\
    \t\t}\n\t\treturn {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\tauto [diam,u1]=dfs(dfs,u0,-1);\n\
    \n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\t\tP.emplace_back(pre[u]);\n\
    \t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n}\n\n/*\n\t\u91CD\u307F\
    \u3064\u304D\u30D0\u30FC\u30B8\u30E7\u30F3\n\t\u8FBA\u306E\u91CD\u307F\u306E\u578B\
    \ W \u306F\u6574\u6570\u307E\u305F\u306F\u5B9F\u6570\u3092\u60F3\u5B9A\n\tn>0\
    \ \u3068\u8FBA\u306E\u91CD\u307F\u304C\u975E\u8CA0\u3092\u4EEE\u5B9A\n*/\n\ntemplate<class\
    \ W>\npair<W,vector<int>> tree_diameter(const weighted_graph<W>& T){\n\tint n=T.size();\n\
    \tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int u,int p)->pair<W,int>{\n\
    \t\tint g=u;\n\t\tW d_max=0;\n\t\tfor(auto e:T[u]) if(e.to!=p) {\n\t\t\tauto [d,v]=dfs(dfs,e.to,u);\n\
    \t\t\tif(d+e.wt>d_max){\n\t\t\t\td_max=d+e.wt;\n\t\t\t\tg=v;\n\t\t\t}\n\t\t\t\
    pre[e.to]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\
    \tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\
    \t\tP.emplace_back(pre[u]);\n\t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n\
    }\n"
  code: "/*\n\tn>0 \u3092\u4EEE\u5B9A\n*/\n\npair<int,vector<int>> tree_diameter(const\
    \ graph& T){\n\tint n=T.size();\n\tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&&\
    \ dfs,int u,int p)->pair<int,int>{\n\t\tint g=u,d_max=0;\n\t\tfor(int v:T[u])\
    \ if(v!=p) {\n\t\t\tauto [d,w]=dfs(dfs,v,u);\n\t\t\tif(d+1>d_max){\n\t\t\t\td_max=d+1;\n\
    \t\t\t\tg=w;\n\t\t\t}\n\t\t\tpre[v]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\t\
    int u0=dfs(dfs,0,-1).second;\n\tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int>\
    \ P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\t\tP.emplace_back(pre[u]);\n\t}\n\
    \treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n}\n\n/*\n\t\u91CD\u307F\u3064\
    \u304D\u30D0\u30FC\u30B8\u30E7\u30F3\n\t\u8FBA\u306E\u91CD\u307F\u306E\u578B W\
    \ \u306F\u6574\u6570\u307E\u305F\u306F\u5B9F\u6570\u3092\u60F3\u5B9A\n\tn>0 \u3068\
    \u8FBA\u306E\u91CD\u307F\u304C\u975E\u8CA0\u3092\u4EEE\u5B9A\n*/\n\ntemplate<class\
    \ W>\npair<W,vector<int>> tree_diameter(const weighted_graph<W>& T){\n\tint n=T.size();\n\
    \tvector<int> pre(n,-1);\n\n\tauto dfs=[&](auto&& dfs,int u,int p)->pair<W,int>{\n\
    \t\tint g=u;\n\t\tW d_max=0;\n\t\tfor(auto e:T[u]) if(e.to!=p) {\n\t\t\tauto [d,v]=dfs(dfs,e.to,u);\n\
    \t\t\tif(d+e.wt>d_max){\n\t\t\t\td_max=d+e.wt;\n\t\t\t\tg=v;\n\t\t\t}\n\t\t\t\
    pre[e.to]=u;\n\t\t}\n\t\treturn {d_max,g};\n\t};\n\tint u0=dfs(dfs,0,-1).second;\n\
    \tauto [diam,u1]=dfs(dfs,u0,-1);\n\n\tvector<int> P={u1};\n\tfor(int u=u1;u!=u0;u=pre[u]){\n\
    \t\tP.emplace_back(pre[u]);\n\t}\n\treverse(P.begin(),P.end());\n\n\treturn {diam,P};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/library/graph/tree_diameter.hpp
- /library/library/graph/tree_diameter.hpp.html
title: library/graph/tree_diameter.hpp
---
