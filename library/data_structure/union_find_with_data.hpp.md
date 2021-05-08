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
  bundledCode: "#line 1 \"library/data_structure/union_find_with_data.hpp\"\n/* Union-Find\
    \ with data */\n/*\n\t\u8AAC\u660E\n\t\t\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\
    \u3092\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020 (\u9023\u7D50\u6210\
    \u5206\u306E\u60C5\u5831\u3092\u967D\u306B\u6301\u3064)\n\t\t- find(u) : u \u304C\
    \u542B\u307E\u308C\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\
    \u308B\n\t\t- unite(u,v) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3068\
    \ v \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3092\u5408\u4F75\u3059\u308B\n\
    \t\t- is_same(u,v) : u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\
    \u308C\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n\t\t- size()\
    \ : \u96C6\u5408\u304C\u5168\u90E8\u3067\u3044\u304F\u3064\u3042\u308B\u304B\u3092\
    \u6C42\u3081\u308B\n\t\t- size(u) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\
    \u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\n\t\t- connected_component(u)\
    \ : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3092\u6C42\u3081\u308B\n\t\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t\tn : \u96C6\u5408\u306E\u8981\u7D20\u6570\
    \n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tunite : \u306A\u3089\u3057\
    \ O(log n)\n\t\tconnected_component : O(|u \u304C\u542B\u307E\u308C\u308B\u96C6\
    \u5408|)\n\t\u5099\u8003\n\t\tweighted-union heuristic (\u3044\u308F\u3086\u308B\
    \u30DE\u30FC\u30B8\u30C6\u30AF) \u3092\u4F7F\u3063\u3066\u3044\u308B\n*/\n\nclass\
    \ union_find{\n\tint n;\n\tvector<int> p;\n\tvector<vector<int>> C;\npublic:\n\
    \tunion_find(int n):n(n),p(n,-1),C(n){\n\t\trep(u,n) C[u].emplace_back(u);\n\t\
    }\n\tint find(int u){ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int\
    \ v){\n\t\tu=find(u); v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\
    \t\t\tp[u]+=p[v]; p[v]=u; n--;\n\t\t\tC[u].insert(C[u].end(),C[v].begin(),C[v].end());\n\
    \t\t\tC[v].clear();\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return find(u)==find(v);\
    \ }\n\tint size()const{ return n; }\n\tint size(int u){ return -p[find(u)]; }\n\
    \tvector<int> connected_component(int u){ return C[find(u)]; }\n};\n"
  code: "/* Union-Find with data */\n/*\n\t\u8AAC\u660E\n\t\t\u4E92\u3044\u306B\u7D20\
    \u306A\u96C6\u5408\u3092\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\
    \ (\u9023\u7D50\u6210\u5206\u306E\u60C5\u5831\u3092\u967D\u306B\u6301\u3064)\n\
    \t\t- find(u) : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u306E\u4EE3\u8868\
    \u5143\u3092\u6C42\u3081\u308B\n\t\t- unite(u,v) : u \u304C\u542B\u307E\u308C\u308B\
    \u96C6\u5408\u3068 v \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3092\u5408\u4F75\
    \u3059\u308B\n\t\t- is_same(u,v) : u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\
    \u542B\u307E\u308C\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n\t\t- size() : \u96C6\u5408\u304C\u5168\u90E8\u3067\u3044\u304F\u3064\u3042\u308B\
    \u304B\u3092\u6C42\u3081\u308B\n\t\t- size(u) : u \u304C\u542B\u307E\u308C\u308B\
    \u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\n\t\t- connected_component(u)\
    \ : u \u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u3092\u6C42\u3081\u308B\n\t\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t\tn : \u96C6\u5408\u306E\u8981\u7D20\u6570\
    \n\t\u5236\u7D04\n\t\tn >= 0\n\t\u8A08\u7B97\u91CF\n\t\tunite : \u306A\u3089\u3057\
    \ O(log n)\n\t\tconnected_component : O(|u \u304C\u542B\u307E\u308C\u308B\u96C6\
    \u5408|)\n\t\u5099\u8003\n\t\tweighted-union heuristic (\u3044\u308F\u3086\u308B\
    \u30DE\u30FC\u30B8\u30C6\u30AF) \u3092\u4F7F\u3063\u3066\u3044\u308B\n*/\n\nclass\
    \ union_find{\n\tint n;\n\tvector<int> p;\n\tvector<vector<int>> C;\npublic:\n\
    \tunion_find(int n):n(n),p(n,-1),C(n){\n\t\trep(u,n) C[u].emplace_back(u);\n\t\
    }\n\tint find(int u){ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int\
    \ v){\n\t\tu=find(u); v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\
    \t\t\tp[u]+=p[v]; p[v]=u; n--;\n\t\t\tC[u].insert(C[u].end(),C[v].begin(),C[v].end());\n\
    \t\t\tC[v].clear();\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return find(u)==find(v);\
    \ }\n\tint size()const{ return n; }\n\tint size(int u){ return -p[find(u)]; }\n\
    \tvector<int> connected_component(int u){ return C[find(u)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/union_find_with_data.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/union_find_with_data.hpp
layout: document
redirect_from:
- /library/library/data_structure/union_find_with_data.hpp
- /library/library/data_structure/union_find_with_data.hpp.html
title: library/data_structure/union_find_with_data.hpp
---
