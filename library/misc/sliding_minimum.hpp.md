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
  bundledCode: "#line 1 \"library/misc/sliding_minimum.hpp\"\n/* \u30B9\u30E9\u30A4\
    \u30C9\u6700\u5C0F\u5024 */\n/*\n\t\u8AAC\u660E\n\t\t\u9577\u3055 n \u306E\u6570\
    \u5217 a \u3068\u6574\u6570 w \u306B\u5BFE\u3057\u3066, \u6B21\u306E\u3088\u3046\
    \u306B\u5B9A\u7FA9\u3055\u308C\u308B\u9577\u3055 n-w+1 \u306E\u5217 b \u3092\u6C42\
    \u3081\u308B\n\t\t\tb_i = argmin{a_i, a_{i+1}, ..., a_{i+w-1}}\n\t\t\u6700\u5C0F\
    \u5024\u3092\u9054\u6210\u3059\u308B a_i \u304C\u8907\u6570\u3042\u308B\u3068\u304D\
    \u306F\u6700\u3082\u5DE6\u306E\u3082\u306E\u304C\u63A1\u7528\u3055\u308C\u308B\
    \n\t\u5236\u7D04\n\t\tw > 0\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\
    \tw > n \u306E\u3068\u304D\u306F\u7A7A\u306E\u5217\u304C\u8FD4\u308B\n*/\n\ntemplate<class\
    \ T>\nvector<int> sliding_window_minimum(const vector<T>& a,int w){\n\tint n=a.size();\n\
    \tif(w>n) return {};\n\n\tvector<int> res(n-w+1);\n\tdeque<int> D;\n\trep(i,n){\n\
    \t\twhile(!D.empty() && a[D.back()]>a[i]) D.pop_back();\n\t\tD.emplace_back(i);\n\
    \t\tif(i>=w-1){\n\t\t\tif(i-D.front()>=w) D.pop_front();\n\t\t\tres[i-w+1]=D.front();\n\
    \t\t}\n\t}\n\treturn res;\n}\n"
  code: "/* \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024 */\n/*\n\t\u8AAC\u660E\n\t\t\
    \u9577\u3055 n \u306E\u6570\u5217 a \u3068\u6574\u6570 w \u306B\u5BFE\u3057\u3066\
    , \u6B21\u306E\u3088\u3046\u306B\u5B9A\u7FA9\u3055\u308C\u308B\u9577\u3055 n-w+1\
    \ \u306E\u5217 b \u3092\u6C42\u3081\u308B\n\t\t\tb_i = argmin{a_i, a_{i+1}, ...,\
    \ a_{i+w-1}}\n\t\t\u6700\u5C0F\u5024\u3092\u9054\u6210\u3059\u308B a_i \u304C\u8907\
    \u6570\u3042\u308B\u3068\u304D\u306F\u6700\u3082\u5DE6\u306E\u3082\u306E\u304C\
    \u63A1\u7528\u3055\u308C\u308B\n\t\u5236\u7D04\n\t\tw > 0\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(n)\n\t\u5099\u8003\n\t\tw > n \u306E\u3068\u304D\u306F\u7A7A\u306E\u5217\
    \u304C\u8FD4\u308B\n*/\n\ntemplate<class T>\nvector<int> sliding_window_minimum(const\
    \ vector<T>& a,int w){\n\tint n=a.size();\n\tif(w>n) return {};\n\n\tvector<int>\
    \ res(n-w+1);\n\tdeque<int> D;\n\trep(i,n){\n\t\twhile(!D.empty() && a[D.back()]>a[i])\
    \ D.pop_back();\n\t\tD.emplace_back(i);\n\t\tif(i>=w-1){\n\t\t\tif(i-D.front()>=w)\
    \ D.pop_front();\n\t\t\tres[i-w+1]=D.front();\n\t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/sliding_minimum.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/sliding_minimum.hpp
layout: document
redirect_from:
- /library/library/misc/sliding_minimum.hpp
- /library/library/misc/sliding_minimum.hpp.html
title: library/misc/sliding_minimum.hpp
---
