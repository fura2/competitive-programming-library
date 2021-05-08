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
  bundledCode: "#line 1 \"library/string/z.hpp\"\n/* Z-algorithm */\n/*\n\t\u8AAC\u660E\
    \n\t\t\u6587\u5B57\u5217 s \u306E\u5404 suffix \u306B\u5BFE\u3057\u3066, \u305D\
    \u308C\u3068 s \u3068\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u3092\u6C42\
    \u3081\u308B\n\t\u5F15\u6570\n\t\ts : \u6587\u5B57\u5217\n\t\u5236\u7D04\n\t\t\
    \u306A\u3057\n\t\u623B\u308A\u5024\n\t\t\u914D\u5217 z[0..|S|)\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(|s|)\n\t\u5099\u8003\n\t\tz[i] = (s \u3068 s[i..) \u306E\u6700\u9577\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055)\n*/\n\nvector<int> Z_algorithm(const\
    \ string& s){\n\tint n=s.length();\n\tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\
    \t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\
    \tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n && s[j]==s[i+j]) j++;\n\t\t\t\
    z[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\treturn z;\n}\n\nvector<int> Z_algorithm(const\
    \ vector<int>& a){\n\tint n=a.size();\n\tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\
    \t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\
    \tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n && a[j]==a[i+j]) j++;\n\t\t\t\
    z[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\treturn z;\n}\n"
  code: "/* Z-algorithm */\n/*\n\t\u8AAC\u660E\n\t\t\u6587\u5B57\u5217 s \u306E\u5404\
    \ suffix \u306B\u5BFE\u3057\u3066, \u305D\u308C\u3068 s \u3068\u306E\u6700\u9577\
    \u5171\u901A\u63A5\u982D\u8F9E\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\ts\
    \ : \u6587\u5B57\u5217\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\
    \n\t\t\u914D\u5217 z[0..|S|)\n\t\u8A08\u7B97\u91CF\n\t\tO(|s|)\n\t\u5099\u8003\
    \n\t\tz[i] = (s \u3068 s[i..) \u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
    \u306E\u9577\u3055)\n*/\n\nvector<int> Z_algorithm(const string& s){\n\tint n=s.length();\n\
    \tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\t\tif(z[pre]>(i-pre)+z[i-pre]){\n\
    \t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\tint j=max(pre+z[pre]-i,0);\n\t\t\
    \twhile(i+j<n && s[j]==s[i+j]) j++;\n\t\t\tz[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\
    \tz[0]=n;\n\treturn z;\n}\n\nvector<int> Z_algorithm(const vector<int>& a){\n\t\
    int n=a.size();\n\tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\t\tif(z[pre]>(i-pre)+z[i-pre]){\n\
    \t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\tint j=max(pre+z[pre]-i,0);\n\t\t\
    \twhile(i+j<n && a[j]==a[i+j]) j++;\n\t\t\tz[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\
    \tz[0]=n;\n\treturn z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/z.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/z.hpp
layout: document
redirect_from:
- /library/library/string/z.hpp
- /library/library/string/z.hpp.html
title: library/string/z.hpp
---
