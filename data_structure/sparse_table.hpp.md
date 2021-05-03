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
  bundledCode: "#line 1 \"data_structure/sparse_table.hpp\"\n/* Range Minimum Query\
    \ (Sparse Table) */\n/*\n\t\u5099\u8003\n\t\tRange Maximum Query \u3092\u3084\u308A\
    \u305F\u3044\u3068\u304D\u306F, -a \u306B\u3064\u3044\u3066 Range Minimum Query\
    \ \u3092\u3084\u308B\u304B\n\t\t\u30B3\u30FC\u30C9\u4E2D\u306E\u3059\u3079\u3066\
    \u306E min \u3092 max \u306B\u66F8\u304D\u5909\u3048\u308C\u3070\u3044\u3044.\n\
    \n[ constructor ]\n\t\u8AAC\u660E\n\t\t\u521D\u671F\u5316\n\t\u5F15\u6570\n\t\t\
    a : \u914D\u5217\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\t\
    O(n log n)\n\n[ query ]\n\t\u8AAC\u660E\n\t\tmin{ a[i] | i=l,l+1,...,r-1 } \u3092\
    \u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tl : \u5DE6\u7AEF\n\t\tr : \u53F3\u7AEF\
    \n\t\u5236\u7D04\n\t\t0 <= l < r <= n\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\u5099\
    \u8003\n\t\t\u534A\u958B\u533A\u9593\u3067\u6307\u5B9A\u3059\u308B\u3053\u3068\
    \u306B\u6CE8\u610F.\n\t\tsegment tree \u306E RMQ \u3088\u308A\u5B9A\u6570\u500D\
    \u901F\u3044.\n*/\n\ntemplate<class T>\nclass sparse_table{\n\tvector<vector<T>>\
    \ st;\n\tvector<int> h;\npublic:\n\tsparse_table(const vector<T>& a){\n\t\tint\
    \ n=a.size();\n\t\th.assign(n+1,0);\n\t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\
    \t\tst.resize(h[n]+1);\n\t\tst[0]=a;\n\t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\
    \t\t\trep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);\n\t\t\
    }\n\t}\n\tT query(int l,int r)const{\n\t\tint i=h[r-l];\n\t\treturn min(st[i][l],st[i][r-(1<<i)]);\n\
    \t}\n};\n"
  code: "/* Range Minimum Query (Sparse Table) */\n/*\n\t\u5099\u8003\n\t\tRange Maximum\
    \ Query \u3092\u3084\u308A\u305F\u3044\u3068\u304D\u306F, -a \u306B\u3064\u3044\
    \u3066 Range Minimum Query \u3092\u3084\u308B\u304B\n\t\t\u30B3\u30FC\u30C9\u4E2D\
    \u306E\u3059\u3079\u3066\u306E min \u3092 max \u306B\u66F8\u304D\u5909\u3048\u308C\
    \u3070\u3044\u3044.\n\n[ constructor ]\n\t\u8AAC\u660E\n\t\t\u521D\u671F\u5316\
    \n\t\u5F15\u6570\n\t\ta : \u914D\u5217\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(n log n)\n\n[ query ]\n\t\u8AAC\u660E\n\t\tmin{ a[i] | i=l,l+1,...,r-1\
    \ } \u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tl : \u5DE6\u7AEF\n\t\tr : \u53F3\
    \u7AEF\n\t\u5236\u7D04\n\t\t0 <= l < r <= n\n\t\u8A08\u7B97\u91CF\n\t\tO(1)\n\t\
    \u5099\u8003\n\t\t\u534A\u958B\u533A\u9593\u3067\u6307\u5B9A\u3059\u308B\u3053\
    \u3068\u306B\u6CE8\u610F.\n\t\tsegment tree \u306E RMQ \u3088\u308A\u5B9A\u6570\
    \u500D\u901F\u3044.\n*/\n\ntemplate<class T>\nclass sparse_table{\n\tvector<vector<T>>\
    \ st;\n\tvector<int> h;\npublic:\n\tsparse_table(const vector<T>& a){\n\t\tint\
    \ n=a.size();\n\t\th.assign(n+1,0);\n\t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\
    \t\tst.resize(h[n]+1);\n\t\tst[0]=a;\n\t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\
    \t\t\trep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);\n\t\t\
    }\n\t}\n\tT query(int l,int r)const{\n\t\tint i=h[r-l];\n\t\treturn min(st[i][l],st[i][r-(1<<i)]);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
