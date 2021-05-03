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
  bundledCode: "#line 1 \"misc/rle.hpp\"\n/* \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E */\n/*\n\t\u5F15\u6570\n\t\ts : \u6587\u5B57\u5217\n\t\u623B\u308A\u5024\
    \n\t\ts \u3092\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\u3057\u305F\u3082\
    \u306E\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(|s|)\n*/\n\
    \nvector<pair<char,int>> run_length_encoding(const string& s){\n\tvector<pair<char,int>>\
    \ res;\n\tint n=s.length(),pre=0;\n\trep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1),\
    \ pre=i+1;\n\treturn res;\n}\n\ntemplate<class T>\nvector<pair<T,int>> run_length_encoding(const\
    \ vector<T>& a){\n\tvector<pair<T,int>> res;\n\tint n=a.size(),pre=0;\n\trep(i,n)\
    \ if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;\n\treturn\
    \ res;\n}\n"
  code: "/* \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E */\n/*\n\t\u5F15\u6570\
    \n\t\ts : \u6587\u5B57\u5217\n\t\u623B\u308A\u5024\n\t\ts \u3092\u30E9\u30F3\u30EC\
    \u30F3\u30B0\u30B9\u5727\u7E2E\u3057\u305F\u3082\u306E\n\t\u5236\u7D04\n\t\t\u306A\
    \u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(|s|)\n*/\n\nvector<pair<char,int>> run_length_encoding(const\
    \ string& s){\n\tvector<pair<char,int>> res;\n\tint n=s.length(),pre=0;\n\trep(i,n)\
    \ if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;\n\treturn\
    \ res;\n}\n\ntemplate<class T>\nvector<pair<T,int>> run_length_encoding(const\
    \ vector<T>& a){\n\tvector<pair<T,int>> res;\n\tint n=a.size(),pre=0;\n\trep(i,n)\
    \ if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;\n\treturn\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rle.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/rle.hpp
layout: document
redirect_from:
- /library/misc/rle.hpp
- /library/misc/rle.hpp.html
title: misc/rle.hpp
---
