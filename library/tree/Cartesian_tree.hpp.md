---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/Cartesian_tree.test.cpp
    title: verify/tree/Cartesian_tree.test.cpp
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
    using namespace std;\nusing lint=long long;\n#line 3 \"library/tree/Cartesian_tree.hpp\"\
    \n\ntemplate<class T>\nclass Cartesian_tree{\n\tvector<T> a;\n\tint rt;\n\tvector<int>\
    \ p,l,r;\npublic:\n\tCartesian_tree(const vector<T>& a={}){ build(a); }\n\n\t\
    void build(const vector<T>& a){\n\t\tthis->a=a;\n\t\tint n=a.size();\n\t\trt=0;\n\
    \t\tp.assign(n,-1);\n\t\tl.assign(n,-1);\n\t\tr.assign(n,-1);\n\n\t\tfor(int u=1;u<n;u++){\n\
    \t\t\tint v=u-1;\n\t\t\tbool top=false;\n\t\t\twhile(a[v]>a[u]){\n\t\t\t\tif(p[v]==-1){\n\
    \t\t\t\t\ttop=true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tv=p[v];\n\t\t\t}\n\t\
    \t\tif(top){\n\t\t\t\tp[v]=u;\n\t\t\t\tl[u]=v;\n\t\t\t\trt=u;\n\t\t\t}\n\t\t\t\
    else{\n\t\t\t\tp[u]=v;\n\t\t\t\tif(r[v]!=-1) p[r[v]]=u;\n\t\t\t\tl[u]=r[v];\n\t\
    \t\t\tr[v]=u;\n\t\t\t}\n\t\t}\n\t}\n\tconst T& operator[](int u)const{ return\
    \ a[u]; }\n\tint root()const{ return rt; }\n\tint parent(int u)const{ return p[u];\
    \ }\n\tint left(int u)const{ return l[u]; }\n\tint right(int u)const{ return r[u];\
    \ }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass Cartesian_tree{\n\
    \tvector<T> a;\n\tint rt;\n\tvector<int> p,l,r;\npublic:\n\tCartesian_tree(const\
    \ vector<T>& a={}){ build(a); }\n\n\tvoid build(const vector<T>& a){\n\t\tthis->a=a;\n\
    \t\tint n=a.size();\n\t\trt=0;\n\t\tp.assign(n,-1);\n\t\tl.assign(n,-1);\n\t\t\
    r.assign(n,-1);\n\n\t\tfor(int u=1;u<n;u++){\n\t\t\tint v=u-1;\n\t\t\tbool top=false;\n\
    \t\t\twhile(a[v]>a[u]){\n\t\t\t\tif(p[v]==-1){\n\t\t\t\t\ttop=true;\n\t\t\t\t\t\
    break;\n\t\t\t\t}\n\t\t\t\tv=p[v];\n\t\t\t}\n\t\t\tif(top){\n\t\t\t\tp[v]=u;\n\
    \t\t\t\tl[u]=v;\n\t\t\t\trt=u;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tp[u]=v;\n\t\t\t\t\
    if(r[v]!=-1) p[r[v]]=u;\n\t\t\t\tl[u]=r[v];\n\t\t\t\tr[v]=u;\n\t\t\t}\n\t\t}\n\
    \t}\n\tconst T& operator[](int u)const{ return a[u]; }\n\tint root()const{ return\
    \ rt; }\n\tint parent(int u)const{ return p[u]; }\n\tint left(int u)const{ return\
    \ l[u]; }\n\tint right(int u)const{ return r[u]; }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/tree/Cartesian_tree.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/Cartesian_tree.test.cpp
documentation_of: library/tree/Cartesian_tree.hpp
layout: document
title: Cartesian Tree
---

## Description
数列 $a=(a_0,\ldots,a_{n-1})$ に対して，次の手順で得られる $n$ 頂点の二分木を [Cartesian tree](https://en.wikipedia.org/wiki/Cartesian_tree) と呼ぶ．
- $i_\mathrm{min}$ を $\displaystyle a_{i_\mathrm{min}}=\min_{0\le i\lt n}a_i$ (複数ある場合は番号が最小のもの) となるように定め，頂点 $i_\mathrm{min}$ を根とする．
- 数列 $(a_0,\ldots,a_{i_\mathrm{min}-1})$ と $(a_{i_\mathrm{min}+1},\ldots,a_{n-1})$ についてそれぞれ再帰的に Cartesian tree を構築し，それらの根を頂点 $i_\mathrm{min}$ の左, 右の子とする．
```
Cartesian_tree<T>
```

### (constructor)
```
Cartesian_tree(const vector<T>& a = {})
```
数列 $a$ の Cartesian tree を構築する

#### Constraints
- $T$ は整数型 (``int``, ``long long`` など)

#### Complexity
- $O(n)$

### build
```
void build(const vector<T>& a)
```
数列 $a$ の Cartesian tree を構築する

#### Constraints
- なし

#### Complexity
- $O(n)$

### operator[]
```
const T& operator[](int u)
```
$a_u$ の値を求める

#### Constraints
- $0\le u\lt n$

#### Complexity
- $O(1)$

### root
```
int root()
```
Cartesian tree の根を求める

#### Constraints
- なし

#### Complexity
- $O(1)$

### parent
```
int parent(int u)
```
頂点 $u$ の親を求める．存在しない場合は $-1$ が返る．

#### Constraints
- なし

#### Complexity
- $O(1)$

### left
```
int left(int u)
```
頂点 $u$ の左の子を求める．存在しない場合は $-1$ が返る．

#### Constraints
- なし

#### Complexity
- $O(1)$

### right
```
int right(int u)
```
頂点 $u$ の右の子を求める．存在しない場合は $-1$ が返る．

#### Constraints
- なし

#### Complexity
- $O(1)$
