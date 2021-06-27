---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.1.test.cpp
    title: verify/data_structure/sparse_table.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.2.test.cpp
    title: verify/data_structure/sparse_table.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/data_structure/sparse_table.hpp\"\
    \n\ntemplate<class B>\nclass sparse_table{\n\tvector<vector<B>> st;\n\tvector<int>\
    \ h;\npublic:\n\tsparse_table()=default;\n\ttemplate<class T>\n\tsparse_table(const\
    \ vector<T>& a){ build(a); }\n\n\ttemplate<class T>\n\tvoid build(const vector<T>&\
    \ a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\
    \t\tst.resize(h[n]+1);\n\t\tst[0].resize(n);\n\t\trep(i,n) st[0][i]=a[i];\n\t\t\
    for(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\t\t\trep(j,n-(1<<i)+1)\
    \ st[i][j]=st[i-1][j]*st[i-1][j+(1<<(i-1))];\n\t\t}\n\t}\n\n\tB product(int l,int\
    \ r)const{\n\t\tint i=h[r-l];\n\t\treturn st[i][l]*st[i][r-(1<<i)];\n\t}\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class B>\nclass sparse_table{\n\
    \tvector<vector<B>> st;\n\tvector<int> h;\npublic:\n\tsparse_table()=default;\n\
    \ttemplate<class T>\n\tsparse_table(const vector<T>& a){ build(a); }\n\n\ttemplate<class\
    \ T>\n\tvoid build(const vector<T>& a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\
    \t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\t\tst.resize(h[n]+1);\n\t\tst[0].resize(n);\n\
    \t\trep(i,n) st[0][i]=a[i];\n\t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\
    \t\t\trep(j,n-(1<<i)+1) st[i][j]=st[i-1][j]*st[i-1][j+(1<<(i-1))];\n\t\t}\n\t\
    }\n\n\tB product(int l,int r)const{\n\t\tint i=h[r-l];\n\t\treturn st[i][l]*st[i][r-(1<<i)];\n\
    \t}\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/sparse_table.2.test.cpp
  - verify/data_structure/sparse_table.1.test.cpp
documentation_of: library/data_structure/sparse_table.hpp
layout: document
title: Sparse Table
---

## Description
[冪等半群](https://en.wikipedia.org/wiki/Band_(algebra)) $(B,\ast)$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，前処理を $O(n\log n)$ で，区間積を $O(1)$ で処理するデータ構造．\\
$B$ の演算の可換性は要求しない．
以下では，$B$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．
```
sparse_table<B>
```

### (constructor)
```
(1) sparse_table<B>()
(2) sparse_table<B>(const vector<T>& a)
```
- (1) 空の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $(B,\ast)$ は冪等半群 ($\ast$ は結合的で，すべての $a\in B$ に対して $a\ast a=a$)
- (2) $T$ は $B$ にキャストできる ($T$ と $B$ が一致していなくてもよい)

#### Complexity
- $O(n\log n)$

### build
```
void build(const vector<T>& a)
```
$a$ で初期化する

#### Constraints
- $T$ は $B$ にキャストできる ($T$ と $B$ が一致していなくてもよい)

#### Complexity
- $O(n\log n)$

### product
```
B product(int l, int r)
```
$a_l\ast a_{l+1}\ast\ldots\ast a_{r-1}$ を求める

#### Constraints
- $0\le l\lt r\le n$

#### Complexity
- $O(1)$

## References
- [Sparse Table - scrapbox.io/data-structures](https://scrapbox.io/data-structures/Sparse_Table)
