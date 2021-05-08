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
  bundledCode: "#line 1 \"library/data_structure/persistent_union_find.hpp\"\n/* Partially\
    \ Persistent Union-Find */\n/*\n\t\u8AAC\u660E\n\t\t\u4E92\u3044\u306B\u7D20\u306A\
    \u96C6\u5408\u3092\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n\t\t\
    - find(u,t) : t \u56DE\u76EE\u306E unite \u306E\u5F8C\u306E, u \u304C\u542B\u307E\
    \u308C\u3066\u3044\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\
    \u308B\n\t\t\t(t = 0 \u306F\u521D\u671F\u72B6\u614B)\n\t\t- unite(u,v) : u \u304C\
    \u542B\u307E\u308C\u3066\u3044\u308B\u96C6\u5408\u3068 v \u304C\u542B\u307E\u308C\
    \u3066\u3044\u308B\u96C6\u5408\u3092\u5408\u4F75\u3059\u308B\n\t\t- is_same(u,v,t)\
    \ : t \u56DE\u76EE\u306E unite \u306E\u5F8C\u3067, u \u3068 v \u304C\u540C\u3058\
    \u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\n\t\t- size() : \u96C6\u5408\u304C\u5168\u90E8\u3067\u3044\u304F\
    \u3064\u3042\u308B\u304B\u3092\u6C42\u3081\u308B\n\t\t- size(u,t) : t \u56DE\u76EE\
    \u306E unite \u306E\u5F8C\u306E, u \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u96C6\
    \u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\n\t\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n\t\tn : \u96C6\u5408\u306E\u8981\u7D20\u6570\n\t\u5236\u7D04\
    \n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tsize() : O(1)\n\t\t\u4ED6 : O(log\
    \ n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\nclass persistent_union_find{\n\t\
    int n,t;\n\tvector<int> p,t0;\n\tvector<vector<pair<int,int>>> Sz;\npublic:\n\t\
    persistent_union_find(int n):n(n),t(0),p(n,-1),t0(n,1e9),Sz(n,{make_pair(-1,1)}){}\n\
    \tint find(int u,int t){\n\t\twhile(t>t0[u]) u=find(p[u],t);\n\t\treturn u;\n\t\
    }\n\tvoid unite(int u,int v){\n\t\tu=find(u,t); v=find(v,t);\n\t\tif(u!=v){\n\t\
    \t\tif(p[v]<p[u]) swap(u,v);\n\t\t\tp[u]+=p[v]; p[v]=u;\n\t\t\tt0[v]=t;\n\t\t\t\
    Sz[u].emplace_back(t,-p[u]);\n\t\t\tn--;\n\t\t}\n\t\tt++;\n\t}\n\tbool is_same(int\
    \ u,int v,int t){ return find(u,t)==find(v,t); }\n\tint size()const{ return n;\
    \ }\n\tint size(int u,int t){\n\t\tu=find(u,t);\n\t\treturn (--lower_bound(Sz[u].begin(),Sz[u].end(),make_pair(t,0)))->second;\n\
    \t}\n};\n"
  code: "/* Partially Persistent Union-Find */\n/*\n\t\u8AAC\u660E\n\t\t\u4E92\u3044\
    \u306B\u7D20\u306A\u96C6\u5408\u3092\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\
    \u69CB\u9020\n\t\t- find(u,t) : t \u56DE\u76EE\u306E unite \u306E\u5F8C\u306E\
    , u \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\
    \u3092\u6C42\u3081\u308B\n\t\t\t(t = 0 \u306F\u521D\u671F\u72B6\u614B)\n\t\t-\
    \ unite(u,v) : u \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u96C6\u5408\u3068\
    \ v \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u96C6\u5408\u3092\u5408\u4F75\u3059\
    \u308B\n\t\t- is_same(u,v,t) : t \u56DE\u76EE\u306E unite \u306E\u5F8C\u3067,\
    \ u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n\t\t- size() : \u96C6\u5408\u304C\
    \u5168\u90E8\u3067\u3044\u304F\u3064\u3042\u308B\u304B\u3092\u6C42\u3081\u308B\
    \n\t\t- size(u,t) : t \u56DE\u76EE\u306E unite \u306E\u5F8C\u306E, u \u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\
    \u3081\u308B\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t\tn : \u96C6\u5408\
    \u306E\u8981\u7D20\u6570\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\
    \n\t\tsize() : O(1)\n\t\t\u4ED6 : O(log n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n\
    */\n\nclass persistent_union_find{\n\tint n,t;\n\tvector<int> p,t0;\n\tvector<vector<pair<int,int>>>\
    \ Sz;\npublic:\n\tpersistent_union_find(int n):n(n),t(0),p(n,-1),t0(n,1e9),Sz(n,{make_pair(-1,1)}){}\n\
    \tint find(int u,int t){\n\t\twhile(t>t0[u]) u=find(p[u],t);\n\t\treturn u;\n\t\
    }\n\tvoid unite(int u,int v){\n\t\tu=find(u,t); v=find(v,t);\n\t\tif(u!=v){\n\t\
    \t\tif(p[v]<p[u]) swap(u,v);\n\t\t\tp[u]+=p[v]; p[v]=u;\n\t\t\tt0[v]=t;\n\t\t\t\
    Sz[u].emplace_back(t,-p[u]);\n\t\t\tn--;\n\t\t}\n\t\tt++;\n\t}\n\tbool is_same(int\
    \ u,int v,int t){ return find(u,t)==find(v,t); }\n\tint size()const{ return n;\
    \ }\n\tint size(int u,int t){\n\t\tu=find(u,t);\n\t\treturn (--lower_bound(Sz[u].begin(),Sz[u].end(),make_pair(t,0)))->second;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/persistent_union_find.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/persistent_union_find.hpp
layout: document
redirect_from:
- /library/library/data_structure/persistent_union_find.hpp
- /library/library/data_structure/persistent_union_find.hpp.html
title: library/data_structure/persistent_union_find.hpp
---
