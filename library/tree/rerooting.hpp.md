---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://null-mn.hatenablog.com/entry/2020/04/14/124151
  bundledCode: "#line 1 \"library/tree/rerooting.hpp\"\n/*\n\t\u5168\u65B9\u4F4D\u6728\
    \ DP\n\t\tT = (V, E) : \u6728\n\t\t(M, *) : \u30E2\u30CE\u30A4\u30C9\n\t\tf :\
    \ M \xD7 V \u2192 M\n\t\tg : M \xD7 V \u2192 M\n\n\t\t\u6839\u3092\u4EFB\u610F\
    \u306B\u56FA\u5B9A\u3057\u3066 T \u3092\u6839\u3064\u304D\u6728\u3068\u307F\u306A\
    \u3057, dp : V \u2192 M \u3092\n\t\t\tdp[u] = g(f(dp[v_1], v_1) * f(dp[v_2], v_2)\
    \ * ... * f(dp[v_k], v_k), u)\n\t\t\u3068\u5B9A\u3081\u308B. \u3053\u3053\u3067\
    , \u9802\u70B9 u \u306E\u5B50\u3092 v_1, ..., v_k \u3068\u3059\u308B.\n\t\tf,\
    \ g \u306E\u7B2C 2 \u5F15\u6570\u306F\u4F7F\u308F\u306A\u3044\u3053\u3068\u3082\
    \u591A\u3044 (\u9802\u70B9\u306B\u91CD\u307F\u304C\u3064\u3044\u3066\u3044\u308B\
    \u3068\u304D\u306A\u3069\u306B\u6709\u52B9).\n\n\t\t\u5404\u9802\u70B9 u \u306B\
    \u5BFE\u3057\u3066, u \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E dp[u] \u306E\
    \u5024\u3092\u6C42\u3081\u308B.\n\t\t\u8A08\u7B97\u91CF\u306F O(|V|) \u3068\u306A\
    \u308B.\n\n\t\t\u4F7F\u3046\u3068\u304D\u306F\u6B21\u306E\u3088\u3046\u306B\u66F8\
    \u304F (\u5FC5\u8981\u306B\u5FDC\u3058\u3066 [] \u306F [&] \u306B\u66F8\u304D\u63DB\
    \u3048\u308B).\n\n\t\tauto f=[](monoid m,int u)->monoid{\n\t\t\treturn ***;\n\t\
    \t};\n\t\tauto g=[](monoid m,int u)->monoid{\n\t\t\treturn ***;\n\t\t};\n\t\t\
    auto res=rerooting<monoid>(T,f,g);\n\n\t\t\u53C2\u8003 : https://null-mn.hatenablog.com/entry/2020/04/14/124151\n\
    */\n\ntemplate<class M,class F,class G>\nvector<M> rerooting(const graph& T,const\
    \ F& f,const G& g){\n\tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&&\
    \ dfs1,int u,int p)->void{\n\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\tdfs1(dfs1,v,u);\n\
    \t\t\tdp1[u]=dp1[u]*f(dp1[v],v);\n\t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\t};\n\n\tauto\
    \ dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{\n\t\tint k=T[u].size();\n\
    \n\t\tvector<M> lcum(k+1),rcum(k+1);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\
    \tlcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));\n\t\t}\n\t\trep(i,k){\n\t\t\
    \tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\t\t\
    }\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\tif(v!=p){\n\
    \t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t}\n\t};\n\n\tdfs1(dfs1,0,-1);\n\
    \tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n\n/*\n\t\u5168\u65B9\u4F4D\u6728 DP\n\
    \t\tT = (V, E) : \u8FBA\u306B\u91CD\u307F\u304C\u3064\u3044\u305F\u6728\n\t\t\
    W : \u8FBA\u306E\u91CD\u307F\u306E\u578B\n\t\t\t\u5B9F\u88C5\u4E0A, T \u306E\u8FBA\
    \u306F 2 \u672C\u306E\u6709\u5411\u8FBA\u3067\u8868\u3055\u308C\u308B\n\t\t\t\u3053\
    \u306E\u3068\u304D, \u3053\u308C\u3089 2 \u672C\u306E\u6709\u5411\u8FBA\u306E\u91CD\
    \u307F\u306F\u7570\u306A\u3063\u3066\u3044\u3066\u3082\u3088\u3044\n\t\t(M, *)\
    \ : \u30E2\u30CE\u30A4\u30C9\n\t\tf : M \xD7 E \u2192 M\n\t\tg : M \xD7 V \u2192\
    \ M\n\n\t\t\u6839\u3092\u4EFB\u610F\u306B\u56FA\u5B9A\u3057\u3066 T \u3092\u6839\
    \u3064\u304D\u6728\u3068\u307F\u306A\u3057, dp : V \u2192 M \u3092\n\t\t\tdp[u]\
    \ = g(f(dp[v_1], e_1) * f(dp[v_2], e_2) * ... * f(dp[v_k], e_k), u)\n\t\t\u3068\
    \u5B9A\u3081\u308B. \u3053\u3053\u3067, \u9802\u70B9 u \u306E\u5B50\u3092 v_1,\
    \ ..., v_k \u3068, u \u304B\u3089 v_i \u3078\u306E\u6709\u5411\u8FBA\u3092 e_i\
    \ \u3068\u304A\u304F.\n\t\tg \u306E\u7B2C 2 \u5F15\u6570\u306F\u4F7F\u308F\u306A\
    \u3044\u3053\u3068\u3082\u591A\u3044 (\u9802\u70B9\u306B\u91CD\u307F\u304C\u3064\
    \u3044\u3066\u3044\u308B\u3068\u304D\u306A\u3069\u306B\u6709\u52B9).\n\n\t\t\u5404\
    \u9802\u70B9 u \u306B\u5BFE\u3057\u3066, u \u3092\u6839\u3068\u3057\u305F\u3068\
    \u304D\u306E dp[u] \u306E\u5024\u3092\u6C42\u3081\u308B.\n\t\t\u8A08\u7B97\u91CF\
    \u306F O(|V|) \u3068\u306A\u308B.\n\n\t\t\u4F7F\u3046\u3068\u304D\u306F\u6B21\u306E\
    \u3088\u3046\u306B\u66F8\u304F (\u5FC5\u8981\u306B\u5FDC\u3058\u3066 [] \u306F\
    \ [&] \u306B\u66F8\u304D\u63DB\u3048\u308B).\n\n\t\tauto f=[](monoid m,edge<int>\
    \ e)->monoid{\n\t\t\treturn ***;\n\t\t};\n\t\tauto g=[](monoid m,int u)->monoid{\n\
    \t\t\treturn ***;\n\t\t};\n\t\tauto res=rerooting<monoid>(T,f,g);\n*/\n\ntemplate<class\
    \ M,class W,class F,class G>\nvector<M> rerooting(const weighted_graph<W>& T,const\
    \ F& f,const G& g){\n\tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&&\
    \ dfs1,int u,int p)->void{\n\t\tfor(const auto& e:T[u]) if(e.to!=p) {\n\t\t\t\
    dfs1(dfs1,e.to,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[e.to],e);\n\t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\
    \t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{\n\t\t\
    int k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\t\trep(i,k){\n\t\t\t\
    const auto& e=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tconst auto& e=T[u][i];\n\
    \t\t\tif(e.to!=p){\n\t\t\t\tdfs2(dfs2,e.to,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t\
    }\n\t\t}\n\t};\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n\
    }\n"
  code: "/*\n\t\u5168\u65B9\u4F4D\u6728 DP\n\t\tT = (V, E) : \u6728\n\t\t(M, *) :\
    \ \u30E2\u30CE\u30A4\u30C9\n\t\tf : M \xD7 V \u2192 M\n\t\tg : M \xD7 V \u2192\
    \ M\n\n\t\t\u6839\u3092\u4EFB\u610F\u306B\u56FA\u5B9A\u3057\u3066 T \u3092\u6839\
    \u3064\u304D\u6728\u3068\u307F\u306A\u3057, dp : V \u2192 M \u3092\n\t\t\tdp[u]\
    \ = g(f(dp[v_1], v_1) * f(dp[v_2], v_2) * ... * f(dp[v_k], v_k), u)\n\t\t\u3068\
    \u5B9A\u3081\u308B. \u3053\u3053\u3067, \u9802\u70B9 u \u306E\u5B50\u3092 v_1,\
    \ ..., v_k \u3068\u3059\u308B.\n\t\tf, g \u306E\u7B2C 2 \u5F15\u6570\u306F\u4F7F\
    \u308F\u306A\u3044\u3053\u3068\u3082\u591A\u3044 (\u9802\u70B9\u306B\u91CD\u307F\
    \u304C\u3064\u3044\u3066\u3044\u308B\u3068\u304D\u306A\u3069\u306B\u6709\u52B9\
    ).\n\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3066, u \u3092\u6839\u3068\u3057\
    \u305F\u3068\u304D\u306E dp[u] \u306E\u5024\u3092\u6C42\u3081\u308B.\n\t\t\u8A08\
    \u7B97\u91CF\u306F O(|V|) \u3068\u306A\u308B.\n\n\t\t\u4F7F\u3046\u3068\u304D\u306F\
    \u6B21\u306E\u3088\u3046\u306B\u66F8\u304F (\u5FC5\u8981\u306B\u5FDC\u3058\u3066\
    \ [] \u306F [&] \u306B\u66F8\u304D\u63DB\u3048\u308B).\n\n\t\tauto f=[](monoid\
    \ m,int u)->monoid{\n\t\t\treturn ***;\n\t\t};\n\t\tauto g=[](monoid m,int u)->monoid{\n\
    \t\t\treturn ***;\n\t\t};\n\t\tauto res=rerooting<monoid>(T,f,g);\n\n\t\t\u53C2\
    \u8003 : https://null-mn.hatenablog.com/entry/2020/04/14/124151\n*/\n\ntemplate<class\
    \ M,class F,class G>\nvector<M> rerooting(const graph& T,const F& f,const G& g){\n\
    \tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&& dfs1,int\
    \ u,int p)->void{\n\t\tfor(int v:T[u]) if(v!=p) {\n\t\t\tdfs1(dfs1,v,u);\n\t\t\
    \tdp1[u]=dp1[u]*f(dp1[v],v);\n\t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\t};\n\n\tauto dfs2=[&](auto&&\
    \ dfs2,int u,int p,const M& dp_par)->void{\n\t\tint k=T[u].size();\n\n\t\tvector<M>\
    \ lcum(k+1),rcum(k+1);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\t\
    if(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t}\n\t\
    };\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n\n/*\n\t\
    \u5168\u65B9\u4F4D\u6728 DP\n\t\tT = (V, E) : \u8FBA\u306B\u91CD\u307F\u304C\u3064\
    \u3044\u305F\u6728\n\t\tW : \u8FBA\u306E\u91CD\u307F\u306E\u578B\n\t\t\t\u5B9F\
    \u88C5\u4E0A, T \u306E\u8FBA\u306F 2 \u672C\u306E\u6709\u5411\u8FBA\u3067\u8868\
    \u3055\u308C\u308B\n\t\t\t\u3053\u306E\u3068\u304D, \u3053\u308C\u3089 2 \u672C\
    \u306E\u6709\u5411\u8FBA\u306E\u91CD\u307F\u306F\u7570\u306A\u3063\u3066\u3044\
    \u3066\u3082\u3088\u3044\n\t\t(M, *) : \u30E2\u30CE\u30A4\u30C9\n\t\tf : M \xD7\
    \ E \u2192 M\n\t\tg : M \xD7 V \u2192 M\n\n\t\t\u6839\u3092\u4EFB\u610F\u306B\u56FA\
    \u5B9A\u3057\u3066 T \u3092\u6839\u3064\u304D\u6728\u3068\u307F\u306A\u3057, dp\
    \ : V \u2192 M \u3092\n\t\t\tdp[u] = g(f(dp[v_1], e_1) * f(dp[v_2], e_2) * ...\
    \ * f(dp[v_k], e_k), u)\n\t\t\u3068\u5B9A\u3081\u308B. \u3053\u3053\u3067, \u9802\
    \u70B9 u \u306E\u5B50\u3092 v_1, ..., v_k \u3068, u \u304B\u3089 v_i \u3078\u306E\
    \u6709\u5411\u8FBA\u3092 e_i \u3068\u304A\u304F.\n\t\tg \u306E\u7B2C 2 \u5F15\u6570\
    \u306F\u4F7F\u308F\u306A\u3044\u3053\u3068\u3082\u591A\u3044 (\u9802\u70B9\u306B\
    \u91CD\u307F\u304C\u3064\u3044\u3066\u3044\u308B\u3068\u304D\u306A\u3069\u306B\
    \u6709\u52B9).\n\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3066, u \u3092\u6839\
    \u3068\u3057\u305F\u3068\u304D\u306E dp[u] \u306E\u5024\u3092\u6C42\u3081\u308B\
    .\n\t\t\u8A08\u7B97\u91CF\u306F O(|V|) \u3068\u306A\u308B.\n\n\t\t\u4F7F\u3046\
    \u3068\u304D\u306F\u6B21\u306E\u3088\u3046\u306B\u66F8\u304F (\u5FC5\u8981\u306B\
    \u5FDC\u3058\u3066 [] \u306F [&] \u306B\u66F8\u304D\u63DB\u3048\u308B).\n\n\t\t\
    auto f=[](monoid m,edge<int> e)->monoid{\n\t\t\treturn ***;\n\t\t};\n\t\tauto\
    \ g=[](monoid m,int u)->monoid{\n\t\t\treturn ***;\n\t\t};\n\t\tauto res=rerooting<monoid>(T,f,g);\n\
    */\n\ntemplate<class M,class W,class F,class G>\nvector<M> rerooting(const weighted_graph<W>&\
    \ T,const F& f,const G& g){\n\tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\
    \tauto dfs1=[&](auto&& dfs1,int u,int p)->void{\n\t\tfor(const auto& e:T[u]) if(e.to!=p)\
    \ {\n\t\t\tdfs1(dfs1,e.to,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[e.to],e);\n\t\t}\n\t\t\
    dp1[u]=g(dp1[u],u);\n\t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int p,const M&\
    \ dp_par)->void{\n\t\tint k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\
    \t\trep(i,k){\n\t\t\tconst auto& e=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tconst auto& e=T[u][i];\n\
    \t\t\tif(e.to!=p){\n\t\t\t\tdfs2(dfs2,e.to,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t\
    }\n\t\t}\n\t};\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2021-05-12 18:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/rerooting.hpp
layout: document
redirect_from:
- /library/library/tree/rerooting.hpp
- /library/library/tree/rerooting.hpp.html
title: library/tree/rerooting.hpp
---
