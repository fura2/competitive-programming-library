---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/string/z.1.test.cpp
    title: verify/string/z.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z.2.test.cpp
    title: verify/string/z.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/string/z.hpp\"\n\nvector<int> Z_algorithm(const\
    \ string& s){\n\tint n=s.length();\n\tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\
    \t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\
    \tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n && s[j]==s[i+j]) j++;\n\t\t\t\
    z[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\treturn z;\n}\n\ntemplate<class\
    \ T>\nvector<int> Z_algorithm(const vector<T>& a){\n\tint n=a.size();\n\tvector<int>\
    \ z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\
    \tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n\
    \ && a[j]==a[i+j]) j++;\n\t\t\tz[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\t\
    return z;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nvector<int> Z_algorithm(const\
    \ string& s){\n\tint n=s.length();\n\tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\
    \t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\
    \tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n && s[j]==s[i+j]) j++;\n\t\t\t\
    z[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\treturn z;\n}\n\ntemplate<class\
    \ T>\nvector<int> Z_algorithm(const vector<T>& a){\n\tint n=a.size();\n\tvector<int>\
    \ z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\
    \tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n\
    \ && a[j]==a[i+j]) j++;\n\t\t\tz[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\t\
    return z;\n}\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/string/z.hpp
  requiredBy: []
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/z.2.test.cpp
  - verify/string/z.1.test.cpp
documentation_of: library/string/z.hpp
layout: document
title: Z Algorithm
---

## Description
文字列 $s=s_0\cdots s_{n-1}$ に対して，$z_i=(s$ と $s_i\cdots s_{n-1}$ の最長共通接頭辞の長さ$)$ と定める．\\
Z algorithm は数列 $z=(z_0,\ldots,z_{n-1})$ を $O(n)$ で求めるアルゴリズムである．

```
(1) vector<int> Z_algorithm(const string& s)
(2) vector<int> Z_algorithm(const vector<T>& a)
```
- (1) 文字列 $s$ に対して数列 $z$ を求める
- (2) $T$ の元の列 $a$ に対して数列 $z$ を求める

#### Constraints
- なし

#### Complexity
- $O(n)$

## References
- [Z Algorithm - paladin8's blog](https://codeforces.com/blog/entry/3107)
