---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/monoid/max_monoid.hpp
    title: Maximum Monoid
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/rerooting.hpp
    title: Rerooting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"verify/tree/rerooting.2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/graph/graph.hpp\"\n\nusing graph=vector<vector<int>>;\n\
    \nvoid add_undirected_edge(graph& G,int u,int v){\n\tG[u].emplace_back(v);\n\t\
    G[v].emplace_back(u);\n}\n\nvoid add_directed_edge(graph& G,int u,int v){\n\t\
    G[u].emplace_back(v);\n}\n#line 3 \"library/graph/wgraph.hpp\"\n\ntemplate<class\
    \ T> struct edge{\n\tint to;\n\tT wt;\n\tedge(int to,const T& wt):to(to),wt(wt){}\n\
    };\ntemplate<class T> using weighted_graph=vector<vector<edge<T>>>;\n\ntemplate<class\
    \ T>\nvoid add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\
    \tG[u].emplace_back(v,wt);\n\tG[v].emplace_back(u,wt);\n}\n\ntemplate<class T>\n\
    void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){\n\tG[u].emplace_back(v,wt);\n\
    }\n#line 5 \"library/tree/rerooting.hpp\"\n\ntemplate<class M,class F,class G>\n\
    vector<M> rerooting(const graph& T,const F& f,const G& g){\n\tint n=T.size();\n\
    \tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&& dfs1,int u,int p)->void{\n\
    \t\tfor(int v:T[u]) if(v!=p) {\n\t\t\tdfs1(dfs1,v,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[v],v);\n\
    \t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int\
    \ p,const M& dp_par)->void{\n\t\tint k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\
    \t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tint v=T[u][i];\n\t\t\t\
    if(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t}\n\t\
    };\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n\ntemplate<class\
    \ M,class W,class F,class G>\nvector<M> rerooting(const weighted_graph<W>& T,const\
    \ F& f,const G& g){\n\tint n=T.size();\n\tvector<M> dp1(n),dp2(n);\n\n\tauto dfs1=[&](auto&&\
    \ dfs1,int u,int p)->void{\n\t\tfor(const auto& [v,wt]:T[u]) if(v!=p) {\n\t\t\t\
    dfs1(dfs1,v,u);\n\t\t\tdp1[u]=dp1[u]*f(dp1[v],wt,v);\n\t\t}\n\t\tdp1[u]=g(dp1[u],u);\n\
    \t};\n\n\tauto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{\n\t\t\
    int k=T[u].size();\n\n\t\tvector<M> lcum(k+1),rcum(k+1);\n\t\trep(i,k){\n\t\t\t\
    const auto& [v,wt]=T[u][i];\n\t\t\tlcum[i+1]=rcum[i]=f(v==p?dp_par:dp1[v],wt,v);\n\
    \t\t}\n\t\trep(i,k){\n\t\t\tlcum[i+1]=lcum[i+1]*lcum[i];\n\t\t\trcum[k-i-1]=rcum[k-i-1]*rcum[k-i];\n\
    \t\t}\n\n\t\tdp2[u]=g(lcum[k],u);\n\t\trep(i,k){\n\t\t\tconst auto& [v,wt]=T[u][i];\n\
    \t\t\tif(v!=p){\n\t\t\t\tdfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));\n\t\t\t}\n\t\t\
    }\n\t};\n\n\tdfs1(dfs1,0,-1);\n\tdfs2(dfs2,0,-1,M());\n\n\treturn dp2;\n}\n#line\
    \ 3 \"library/monoid/max_monoid.hpp\"\n\ntemplate<class T>\nclass max_monoid{\n\
    \tT a;\npublic:\n\tmax_monoid(const T& val=numeric_limits<T>::min()):a(val){}\n\
    \tmax_monoid operator*(const max_monoid& x)const{\n\t\treturn max(a,x.a);\n\t\
    }\n\tT& get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n#line 6 \"\
    verify/tree/rerooting.2.test.cpp\"\n\nint main(){\n\tint n; scanf(\"%d\",&n);\n\
    \tweighted_graph<int> T(n);\n\trep(i,n-1){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\
    \t\tadd_undirected_edge(T,u,v,c);\n\t}\n\n\tusing monoid=max_monoid<int>;\n\t\
    auto f=[](monoid m,int wt,int v)->monoid{\n\t\treturn m.get()+wt;\n\t};\n\tauto\
    \ g=[](monoid m,int u)->monoid{\n\t\treturn m*0;\n\t};\n\tfor(auto m:rerooting<monoid>(T,f,g)){\n\
    \t\tprintf(\"%d\\n\",m.get());\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/tree/rerooting.hpp\"\
    \n#include \"../../library/monoid/max_monoid.hpp\"\n\nint main(){\n\tint n; scanf(\"\
    %d\",&n);\n\tweighted_graph<int> T(n);\n\trep(i,n-1){\n\t\tint u,v,c; scanf(\"\
    %d%d%d\",&u,&v,&c);\n\t\tadd_undirected_edge(T,u,v,c);\n\t}\n\n\tusing monoid=max_monoid<int>;\n\
    \tauto f=[](monoid m,int wt,int v)->monoid{\n\t\treturn m.get()+wt;\n\t};\n\t\
    auto g=[](monoid m,int u)->monoid{\n\t\treturn m*0;\n\t};\n\tfor(auto m:rerooting<monoid>(T,f,g)){\n\
    \t\tprintf(\"%d\\n\",m.get());\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/tree/rerooting.hpp
  - library/graph/graph.hpp
  - library/graph/wgraph.hpp
  - library/monoid/max_monoid.hpp
  isVerificationFile: true
  path: verify/tree/rerooting.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-15 16:57:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/rerooting.2.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/rerooting.2.test.cpp
- /verify/verify/tree/rerooting.2.test.cpp.html
title: verify/tree/rerooting.2.test.cpp
---
