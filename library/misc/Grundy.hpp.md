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
  bundledCode: "#line 1 \"library/misc/Grundy.hpp\"\n/*\n\tD \u3092 N \u9802\u70B9\
    \ M \u8FBA\u306E DAG \u3068\u3059\u308B\n\n\t\u6B21\u306E\u3088\u3046\u306A D\
    \ \u4E0A\u306E\u4E8C\u4EBA\u30B2\u30FC\u30E0\u3092\u8003\u3048\u308B\n\t\tD \u306E\
    \u4E00\u3064\u306E\u9802\u70B9\u306B\u99D2\u3092\u7F6E\u3044\u305F\u72B6\u614B\
    \u304B\u3089\u30B2\u30FC\u30E0\u3092\u59CB\u3081\u308B\n\t\t\u30D7\u30EC\u30A4\
    \u30E4\u30FC\u306F, \u81EA\u5206\u306E\u756A\u3067\u99D2\u3092\u6709\u5411\u8FBA\
    \u306B\u6CBF\u3063\u3066\u4E00\u56DE\u52D5\u304B\u3059\n\t\t\u99D2\u3092\u52D5\
    \u304B\u305B\u306A\u304F\u306A\u3063\u305F\u30D7\u30EC\u30A4\u30E4\u30FC\u306E\
    \u8CA0\u3051\n\t\u3059\u3079\u3066\u306E\u9802\u70B9 u \u306B\u3064\u3044\u3066\
    , \u99D2\u304C u \u306B\u3042\u308B\u72B6\u614B\u306E Grundy \u6570\u3092\u8A08\
    \u7B97\u3059\u308B\n\n\t\u8A08\u7B97\u91CF\u306F O(N+M) \u3068\u306A\u308B\n*/\n\
    \nvector<int> Grundy(const graph& D){\n\tauto ord=topological_sort(D);\n\n\tint\
    \ n=D.size(),m=0;\n\trep(u,n) m=max(m,int(D[u].size()));\n\n\tvector<int> g(n),last(m+1,-1);\n\
    \trep(i,n){\n\t\tint u=ord[n-i-1];\n\t\tfor(int v:D[u]) last[g[v]]=u;\n\t\twhile(last[g[u]]==u)\
    \ g[u]++;\n\t}\n\treturn g;\n}\n"
  code: "/*\n\tD \u3092 N \u9802\u70B9 M \u8FBA\u306E DAG \u3068\u3059\u308B\n\n\t\
    \u6B21\u306E\u3088\u3046\u306A D \u4E0A\u306E\u4E8C\u4EBA\u30B2\u30FC\u30E0\u3092\
    \u8003\u3048\u308B\n\t\tD \u306E\u4E00\u3064\u306E\u9802\u70B9\u306B\u99D2\u3092\
    \u7F6E\u3044\u305F\u72B6\u614B\u304B\u3089\u30B2\u30FC\u30E0\u3092\u59CB\u3081\
    \u308B\n\t\t\u30D7\u30EC\u30A4\u30E4\u30FC\u306F, \u81EA\u5206\u306E\u756A\u3067\
    \u99D2\u3092\u6709\u5411\u8FBA\u306B\u6CBF\u3063\u3066\u4E00\u56DE\u52D5\u304B\
    \u3059\n\t\t\u99D2\u3092\u52D5\u304B\u305B\u306A\u304F\u306A\u3063\u305F\u30D7\
    \u30EC\u30A4\u30E4\u30FC\u306E\u8CA0\u3051\n\t\u3059\u3079\u3066\u306E\u9802\u70B9\
    \ u \u306B\u3064\u3044\u3066, \u99D2\u304C u \u306B\u3042\u308B\u72B6\u614B\u306E\
    \ Grundy \u6570\u3092\u8A08\u7B97\u3059\u308B\n\n\t\u8A08\u7B97\u91CF\u306F O(N+M)\
    \ \u3068\u306A\u308B\n*/\n\nvector<int> Grundy(const graph& D){\n\tauto ord=topological_sort(D);\n\
    \n\tint n=D.size(),m=0;\n\trep(u,n) m=max(m,int(D[u].size()));\n\n\tvector<int>\
    \ g(n),last(m+1,-1);\n\trep(i,n){\n\t\tint u=ord[n-i-1];\n\t\tfor(int v:D[u])\
    \ last[g[v]]=u;\n\t\twhile(last[g[u]]==u) g[u]++;\n\t}\n\treturn g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/Grundy.hpp
  requiredBy: []
  timestamp: '2021-06-27 17:33:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/Grundy.hpp
layout: document
redirect_from:
- /library/library/misc/Grundy.hpp
- /library/library/misc/Grundy.hpp.html
title: library/misc/Grundy.hpp
---
