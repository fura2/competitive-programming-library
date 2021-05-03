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
  bundledCode: "#line 1 \"misc/lis.hpp\"\n/* \u6700\u9577(\u5897\u52A0|\u975E\u6E1B\
    \u5C11)\u90E8\u5206\u5217 */\n/*\n\t\u8AAC\u660E\n\t\t\u6570\u5217 a \u306E\u6700\
    \u9577(\u5897\u52A0|\u975E\u6E1B\u5C11)\u90E8\u5206\u5217\u3092\u6C42\u3081\u308B\
    \n\t\u5099\u8003\n\t\t\u6700\u9577(\u6E1B\u5C11|\u975E\u5897\u52A0)\u90E8\u5206\
    \u5217\u3092\u6C42\u3081\u305F\u3044\u3068\u304D\u306F -a \u3092\u8003\u3048\u308C\
    \u3070\u3088\u3044\n\t\u5F15\u6570\n\t\ta : \u6570\u5217\n\t\u623B\u308A\u5024\
    \n\t\ta \u306E\u6700\u9577(\u5897\u52A0|\u975E\u6E1B\u5C11)\u90E8\u5206\u5217\
    (\u306E\u4E00\u3064)\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\
    \t\tO(|a| log |a|)\n*/\n\ntemplate<class T>\nvector<T> longest_increasing_subsequence(const\
    \ vector<T> &a){\n\tvector<T> lis;\n\tfor(const auto& x:a){\n\t\tauto it=lower_bound(lis.begin(),lis.end(),x);\n\
    \t\tif(it!=lis.end()) *it=x;\n\t\telse lis.emplace_back(x);\n\t}\n\treturn lis;\n\
    }\n\ntemplate<class T>\nvector<T> longest_nondecreasing_subsequence(const vector<T>\
    \ &a){\n\tvector<T> lis;\n\tfor(const auto& x:a){\n\t\tauto it=upper_bound(lis.begin(),lis.end(),x);\n\
    \t\tif(it!=lis.end()) *it=x;\n\t\telse lis.emplace_back(x);\n\t}\n\treturn lis;\n\
    }\n"
  code: "/* \u6700\u9577(\u5897\u52A0|\u975E\u6E1B\u5C11)\u90E8\u5206\u5217 */\n/*\n\
    \t\u8AAC\u660E\n\t\t\u6570\u5217 a \u306E\u6700\u9577(\u5897\u52A0|\u975E\u6E1B\
    \u5C11)\u90E8\u5206\u5217\u3092\u6C42\u3081\u308B\n\t\u5099\u8003\n\t\t\u6700\u9577\
    (\u6E1B\u5C11|\u975E\u5897\u52A0)\u90E8\u5206\u5217\u3092\u6C42\u3081\u305F\u3044\
    \u3068\u304D\u306F -a \u3092\u8003\u3048\u308C\u3070\u3088\u3044\n\t\u5F15\u6570\
    \n\t\ta : \u6570\u5217\n\t\u623B\u308A\u5024\n\t\ta \u306E\u6700\u9577(\u5897\u52A0\
    |\u975E\u6E1B\u5C11)\u90E8\u5206\u5217(\u306E\u4E00\u3064)\n\t\u5236\u7D04\n\t\
    \t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(|a| log |a|)\n*/\n\ntemplate<class\
    \ T>\nvector<T> longest_increasing_subsequence(const vector<T> &a){\n\tvector<T>\
    \ lis;\n\tfor(const auto& x:a){\n\t\tauto it=lower_bound(lis.begin(),lis.end(),x);\n\
    \t\tif(it!=lis.end()) *it=x;\n\t\telse lis.emplace_back(x);\n\t}\n\treturn lis;\n\
    }\n\ntemplate<class T>\nvector<T> longest_nondecreasing_subsequence(const vector<T>\
    \ &a){\n\tvector<T> lis;\n\tfor(const auto& x:a){\n\t\tauto it=upper_bound(lis.begin(),lis.end(),x);\n\
    \t\tif(it!=lis.end()) *it=x;\n\t\telse lis.emplace_back(x);\n\t}\n\treturn lis;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/lis.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/lis.hpp
layout: document
redirect_from:
- /library/misc/lis.hpp
- /library/misc/lis.hpp.html
title: misc/lis.hpp
---
