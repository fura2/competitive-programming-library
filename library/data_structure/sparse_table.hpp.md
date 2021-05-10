---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.test.cpp
    title: verify/data_structure/sparse_table.test.cpp
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
    using lint=long long;\n#line 3 \"library/data_structure/sparse_table.hpp\"\n\n\
    template<class T>\nclass sparse_table{\n\tvector<vector<T>> st;\n\tvector<int>\
    \ h;\npublic:\n\tsparse_table()=default;\n\tsparse_table(const vector<T>& a){\
    \ build(a); }\n\tvoid build(const vector<T>& a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\
    \t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\t\tst.resize(h[n]+1);\n\t\tst[0]=a;\n\
    \t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\t\t\trep(j,n-(1<<i)+1)\
    \ st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);\n\t\t}\n\t}\n\tT fold(int l,int\
    \ r)const{\n\t\tint i=h[r-l];\n\t\treturn min(st[i][l],st[i][r-(1<<i)]);\n\t}\n\
    };\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass sparse_table{\n\
    \tvector<vector<T>> st;\n\tvector<int> h;\npublic:\n\tsparse_table()=default;\n\
    \tsparse_table(const vector<T>& a){ build(a); }\n\tvoid build(const vector<T>&\
    \ a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\
    \t\tst.resize(h[n]+1);\n\t\tst[0]=a;\n\t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\
    \t\t\trep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);\n\t\t\
    }\n\t}\n\tT fold(int l,int r)const{\n\t\tint i=h[r-l];\n\t\treturn min(st[i][l],st[i][r-(1<<i)]);\n\
    \t}\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/sparse_table.test.cpp
documentation_of: library/data_structure/sparse_table.hpp
layout: document
title: Sparse Table
---

## Description
数列 $a_0,\ldots,a_{n-1}$ に対して，[RMQ](https://en.wikipedia.org/wiki/Range_minimum_query) を構築 $O(n\log n)$ / 区間最小値クエリ $O(1)$ で処理するデータ構造．  
素直に [band](https://en.wikipedia.org/wiki/Band_(algebra)) (冪等半群) の元の列に一般化できるが，ここでは RMQ に特化した形で実装した．

### (constructor)
```
(1) sparse_table<T>()
(2) sparse_table<T>(const vector<T>& a)
```
- (1) 空の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)

#### Complexity
- (1) $O(1)$
- (2) $O(n\log n)$

### build
```
void build(const vector<T>& a)
```
- $a$ で初期化する

#### Constraints
- なし

#### Complexity
- $O(n\log n)$

### fold
```
T fold(int l, int r)
```
$\min\lbrace a_l,a_{l+1},\ldots,a_{r-1}\rbrace$ を求める

#### Constraints
- $0\le l\lt r\le n$

#### Complexity
- $O(1)$

## References
- [Sparse Table - scrapbox.io/data-structures](https://scrapbox.io/data-structures/Sparse_Table)
