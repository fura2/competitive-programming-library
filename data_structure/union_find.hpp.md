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
  bundledCode: "#line 1 \"data_structure/union_find.hpp\"\n/* Union-Find */\n/*\n\t\
    \u8AAC\u660E\n\t\t\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\u3092\u7BA1\u7406\
    \u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n\t\t- find(u) : u \u304C\u542B\u307E\
    \u308C\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B\n\t\t\
    - unite(u,v) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3068 v \u304C\u542B\
    \u307E\u308C\u308B\u96C6\u5408\u3092\u5408\u4F75\u3059\u308B\n\t\t- is_same(u,v)\
    \ : u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n\t\t- size() : \u96C6\u5408\u304C\
    \u5168\u90E8\u3067\u3044\u304F\u3064\u3042\u308B\u304B\u3092\u6C42\u3081\u308B\
    \n\t\t- size(u) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u306E\u8981\u7D20\
    \u6570\u3092\u6C42\u3081\u308B\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\
    \t\tn : \u96C6\u5408\u306E\u8981\u7D20\u6570\n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\
    \u7B97\u91CF\n\t\t\u3059\u3079\u3066\u307B\u307C O(1)\n*/\n\nclass union_find{\n\
    \tint n;\n\tvector<int> p;\npublic:\n\tunion_find(int n):n(n),p(n,-1){}\n\tint\
    \ find(int u){ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int v){\n\
    \t\tu=find(u); v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\t\t\
    \tp[u]+=p[v]; p[v]=u; n--;\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return find(u)==find(v);\
    \ }\n\tint size()const{ return n; }\n\tint size(int u){ return -p[find(u)]; }\n\
    };\n"
  code: "/* Union-Find */\n/*\n\t\u8AAC\u660E\n\t\t\u4E92\u3044\u306B\u7D20\u306A\u96C6\
    \u5408\u3092\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n\t\t- find(u)\
    \ : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\
    \u6C42\u3081\u308B\n\t\t- unite(u,v) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\
    \u3068 v \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3092\u5408\u4F75\u3059\u308B\
    \n\t\t- is_same(u,v) : u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\
    \u308C\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n\t\t- size()\
    \ : \u96C6\u5408\u304C\u5168\u90E8\u3067\u3044\u304F\u3064\u3042\u308B\u304B\u3092\
    \u6C42\u3081\u308B\n\t\t- size(u) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\
    \u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n\t\tn : \u96C6\u5408\u306E\u8981\u7D20\u6570\n\t\u5236\u7D04\n\t\
    \tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\t\u3059\u3079\u3066\u307B\u307C O(1)\n*/\n\n\
    class union_find{\n\tint n;\n\tvector<int> p;\npublic:\n\tunion_find(int n):n(n),p(n,-1){}\n\
    \tint find(int u){ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int\
    \ v){\n\t\tu=find(u); v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\
    \t\t\tp[u]+=p[v]; p[v]=u; n--;\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return\
    \ find(u)==find(v); }\n\tint size()const{ return n; }\n\tint size(int u){ return\
    \ -p[find(u)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/union_find.hpp
layout: document
redirect_from:
- /library/data_structure/union_find.hpp
- /library/data_structure/union_find.hpp.html
title: data_structure/union_find.hpp
---
