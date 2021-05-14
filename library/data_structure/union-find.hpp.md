---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/Kruskal.hpp
    title: Minimum Spanning Forest (Kruskal's Algorithm)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/union-find.test.1.cpp
    title: verify/data_structure/union-find.test.1.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/union-find.test.2.cpp
    title: verify/data_structure/union-find.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Kruskal.1.test.cpp
    title: verify/graph/Kruskal.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Kruskal.2.test.cpp
    title: verify/graph/Kruskal.2.test.cpp
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
    using lint=long long;\n#line 3 \"library/data_structure/union-find.hpp\"\n\nclass\
    \ union_find{\n\tint n;\n\tvector<int> p;\npublic:\n\tunion_find(int n=0){ build(n);\
    \ }\n\tvoid build(int n){\n\t\tthis->n=n;\n\t\tp.assign(n,-1);\n\t}\n\tint find(int\
    \ u){ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int v){\n\t\tu=find(u);\
    \ v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\t\t\tp[u]+=p[v];\
    \ p[v]=u; n--;\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return find(u)==find(v);\
    \ }\n\tint size()const{ return n; }\n\tint size(int u){ return -p[find(u)]; }\n\
    };\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nclass union_find{\n\tint n;\n\
    \tvector<int> p;\npublic:\n\tunion_find(int n=0){ build(n); }\n\tvoid build(int\
    \ n){\n\t\tthis->n=n;\n\t\tp.assign(n,-1);\n\t}\n\tint find(int u){ return p[u]<0?u:p[u]=find(p[u]);\
    \ }\n\tvoid unite(int u,int v){\n\t\tu=find(u); v=find(v);\n\t\tif(u!=v){\n\t\t\
    \tif(p[v]<p[u]) swap(u,v);\n\t\t\tp[u]+=p[v]; p[v]=u; n--;\n\t\t}\n\t}\n\tbool\
    \ is_same(int u,int v){ return find(u)==find(v); }\n\tint size()const{ return\
    \ n; }\n\tint size(int u){ return -p[find(u)]; }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/data_structure/union-find.hpp
  requiredBy:
  - library/graph/Kruskal.hpp
  timestamp: '2021-05-11 00:34:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/Kruskal.2.test.cpp
  - verify/graph/Kruskal.1.test.cpp
  - verify/data_structure/union-find.test.1.cpp
  - verify/data_structure/union-find.test.2.cpp
documentation_of: library/data_structure/union-find.hpp
layout: document
title: Union-Find
---

## Description
互いに素な $n$ 個の一点集合 $\lbrace0\rbrace,\ldots,\lbrace n-1\rbrace$ がある状態から始めて，次の操作を amortized $O(\alpha(n))$ で処理するデータ構造 ([素集合データ構造](https://en.wikipedia.org/wiki/Disjoint-set_data_structure))．
- 要素がどの集合に属するかを求める
- 二つの集合をマージする

union by size と path compression を実装している．

### (constructor)
```
union_find(int n = 0)
```
- 互いに素な $n$ 個の一点集合 $\lbrace0\rbrace,\ldots,\lbrace n-1\rbrace$ で初期化する

#### Constraints
- $n\ge0$

#### Complexity
- $O(n)$

### build
```
void build(int n)
```
- 互いに素な $n$ 個の一点集合 $\lbrace0\rbrace,\ldots,\lbrace n-1\rbrace$ で初期化する

#### Constraints
- $n\ge0$

#### Complexity
- $O(n)$

### find
```
int find(int u)
```
$u$ が含まれる集合の代表元を求める

#### Constraints
- $0\le u\lt n$

#### Complexity
- amortized $O(\alpha(n))$

### unite
```
void unite(int u, int v)
```
$u$ が含まれる集合と $v$ が含まれる集合をマージする

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- amortized $O(\alpha(n))$

### is_same
```
bool is_same(int u, int v)
```
$u$ と $v$ が同じ集合に含まれるかどうかを判定する

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- amortized $O(\alpha(n))$

### size
```
(1) int size()
(2) int size(int u)
```
- (1) 集合の個数を求める
- (2) $u$ が含まれる集合の要素数を求める

#### Constraints
- $0\le u,v\lt n$

#### Complexity
- (1) $O(1)$
- (2) amortized $O(\alpha(n))$
