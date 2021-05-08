---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"library/data_structure/sparse_table.hpp\"\ntemplate<class\
    \ T>\nclass sparse_table{\n\tvector<vector<T>> st;\n\tvector<int> h;\npublic:\n\
    \tsparse_table()=default;\n\tsparse_table(const vector<T>& a){ build(a); }\n\t\
    void build(const vector<T>& a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\t\
    \tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\t\tst.resize(h[n]+1);\n\t\tst[0]=a;\n\
    \t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\t\t\trep(j,n-(1<<i)+1)\
    \ st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);\n\t\t}\n\t}\n\tT fold(int l,int\
    \ r)const{\n\t\tint i=h[r-l];\n\t\treturn min(st[i][l],st[i][r-(1<<i)]);\n\t}\n\
    };\n"
  code: "template<class T>\nclass sparse_table{\n\tvector<vector<T>> st;\n\tvector<int>\
    \ h;\npublic:\n\tsparse_table()=default;\n\tsparse_table(const vector<T>& a){\
    \ build(a); }\n\tvoid build(const vector<T>& a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\
    \t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\t\tst.resize(h[n]+1);\n\t\tst[0]=a;\n\
    \t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\t\t\trep(j,n-(1<<i)+1)\
    \ st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);\n\t\t}\n\t}\n\tT fold(int l,int\
    \ r)const{\n\t\tint i=h[r-l];\n\t\treturn min(st[i][l],st[i][r-(1<<i)]);\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2021-05-08 17:56:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/sparse_table.test.cpp
documentation_of: library/data_structure/sparse_table.hpp
layout: document
title: Sparse Table
---

## Description
数列 $a_0,\ldots,a_{n-1}$ に対して，[RMQ](https://en.wikipedia.org/wiki/Range_minimum_query) を構築 $O(n\log n)$ / 区間最小値クエリ $O(1)$ で処理するデータ構造．  
素直に [Band](https://en.wikipedia.org/wiki/Band_(algebra)) (冪等半群) の元の列に一般化できるが，ここでは RMQ に特化した形で実装した．

### (constructor)
```
(1) sparse_table<T>()
(2) sparse_table<T>(const vector<T>& a)
```
- (1) 空の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $T$ は整数型 (``int``, ``long long`` など) または実数型 (``double``, ``long double`` など)．

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
$\min\{a_l,\cdots,a_{r-1}\}$ を求める

#### Constraints
- $0\le l\lt r\le n$

#### Complexity
- $O(1)$

## References
- [Sparse Table - scrapbox.io/data-structures](https://scrapbox.io/data-structures/Sparse_Table)
