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
  bundledCode: "#line 1 \"misc/zeta.hpp\"\n/*\n\t\u4E0B\u4F4D\u96C6\u5408\u306B\u5BFE\
    \u3059\u308B\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\n\t\tM : \u53EF\u63DB\u30E2\
    \u30CE\u30A4\u30C9\n\t\tf : 2^{0, 1, ..., N-1} -> M\n\t\t\u306B\u5BFE\u3057\u3066\
    \n\t\tg(S) = \u03A3_{T \u2282 S} f(T)\n\t\t\u3067\u5B9A\u7FA9\u3055\u308C\u308B\
    \ g : 2^{0, 1, ..., N-1} -> M \u3092\u6C42\u3081\u308B\n*/\n\ntemplate<class M>\n\
    vector<M> zeta_subset(vector<M> f){\n\tint n=log2(f.size());\n\trep(i,n) rep(S,1<<n)\
    \ if(~S>>i&1) f[S|1<<i]=f[S|1<<i]*f[S];\n\treturn f;\n}\n"
  code: "/*\n\t\u4E0B\u4F4D\u96C6\u5408\u306B\u5BFE\u3059\u308B\u9AD8\u901F\u30BC\u30FC\
    \u30BF\u5909\u63DB\n\t\tM : \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n\t\tf : 2^{0,\
    \ 1, ..., N-1} -> M\n\t\t\u306B\u5BFE\u3057\u3066\n\t\tg(S) = \u03A3_{T \u2282\
    \ S} f(T)\n\t\t\u3067\u5B9A\u7FA9\u3055\u308C\u308B g : 2^{0, 1, ..., N-1} ->\
    \ M \u3092\u6C42\u3081\u308B\n*/\n\ntemplate<class M>\nvector<M> zeta_subset(vector<M>\
    \ f){\n\tint n=log2(f.size());\n\trep(i,n) rep(S,1<<n) if(~S>>i&1) f[S|1<<i]=f[S|1<<i]*f[S];\n\
    \treturn f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/zeta.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/zeta.hpp
layout: document
redirect_from:
- /library/misc/zeta.hpp
- /library/misc/zeta.hpp.html
title: misc/zeta.hpp
---
