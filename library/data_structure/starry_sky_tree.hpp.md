---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/starry_sky_tree.test.cpp
    title: verify/data_structure/starry_sky_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structure/starry_sky_tree.hpp\"\ntemplate<class\
    \ T>\nclass starry_sky_tree{\n\tint sz;\n\tvector<T> seg;\n\n\tvoid maintain(int\
    \ u){\n\t\tif(1<=u && u<sz){\n\t\t\tT mx=std::max(seg[2*u],seg[2*u+1]);\n\t\t\t\
    seg[u]+=mx;\n\t\t\tseg[2*u  ]-=mx;\n\t\t\tseg[2*u+1]-=mx;\n\t\t}\n\t}\n\tT max(int\
    \ l,int r,int a,int b,int u,T cum)const{\n\t\tif(b<=l || r<=a) return numeric_limits<T>::min();\n\
    \t\tif(l<=a && b<=r) return cum+seg[u];\n\t\tT lmax=max(l,r,a,(a+b)/2,2*u  ,cum+seg[u]);\n\
    \t\tT rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);\n\t\treturn std::max(lmax,rmax);\n\
    \t}\npublic:\n\tstarry_sky_tree()=default;\n\tstarry_sky_tree(int n){ build(n);\
    \ }\n\tvoid build(int n){\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,T());\n\
    \t}\n\tvoid add(int l,int r,const T& val){\n\t\tint a,b;\n\t\tfor(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1){ seg[a]+=val; a++; }\n\t\t\tif(b&1){ b--; seg[b]+=val; }\n\t\t\t\
    maintain((a-1)>>1);\n\t\t\tmaintain(b>>1);\n\t\t}\n\t\tfor(int u=a-1;u>=1;u>>=1)\
    \ maintain(u);\n\t\tfor(int u= b ;u>=1;u>>=1) maintain(u);\n\t}\n\tT max(int l,int\
    \ r)const{ return max(l,r,0,sz,1,0); }\n};\n"
  code: "template<class T>\nclass starry_sky_tree{\n\tint sz;\n\tvector<T> seg;\n\n\
    \tvoid maintain(int u){\n\t\tif(1<=u && u<sz){\n\t\t\tT mx=std::max(seg[2*u],seg[2*u+1]);\n\
    \t\t\tseg[u]+=mx;\n\t\t\tseg[2*u  ]-=mx;\n\t\t\tseg[2*u+1]-=mx;\n\t\t}\n\t}\n\t\
    T max(int l,int r,int a,int b,int u,T cum)const{\n\t\tif(b<=l || r<=a) return\
    \ numeric_limits<T>::min();\n\t\tif(l<=a && b<=r) return cum+seg[u];\n\t\tT lmax=max(l,r,a,(a+b)/2,2*u\
    \  ,cum+seg[u]);\n\t\tT rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);\n\t\treturn\
    \ std::max(lmax,rmax);\n\t}\npublic:\n\tstarry_sky_tree()=default;\n\tstarry_sky_tree(int\
    \ n){ build(n); }\n\tvoid build(int n){\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,T());\n\
    \t}\n\tvoid add(int l,int r,const T& val){\n\t\tint a,b;\n\t\tfor(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1){ seg[a]+=val; a++; }\n\t\t\tif(b&1){ b--; seg[b]+=val; }\n\t\t\t\
    maintain((a-1)>>1);\n\t\t\tmaintain(b>>1);\n\t\t}\n\t\tfor(int u=a-1;u>=1;u>>=1)\
    \ maintain(u);\n\t\tfor(int u= b ;u>=1;u>>=1) maintain(u);\n\t}\n\tT max(int l,int\
    \ r)const{ return max(l,r,0,sz,1,0); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/starry_sky_tree.hpp
  requiredBy: []
  timestamp: '2021-05-10 22:05:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/starry_sky_tree.test.cpp
documentation_of: library/data_structure/starry_sky_tree.hpp
layout: document
title: Starry Sky Tree
---

## Description
数列 $a_0,\ldots,a_{n-1}$ に対して，区間加算と区間 max を $O(\log n)$ で処理するデータ構造

### (constructor)
```
(1) starry_sky_tree<T>()
(2) starry_sky_tree<T>(int n)
```
- (1) 空の列で初期化する
- (2) $0$ のみからなる長さ $n$ の列で初期化する

#### Constraints
- $T$ は整数型または実数型 (``int``, ``long long``, ``double``, ``long double`` など)
- (2) $n\ge0$

#### Complexity
- (1) $O(1)$
- (2) $O(n)$

### build
```
void build(int n)
```
- $0$ のみからなる長さ $n$ の列で初期化する

#### Constraints
- $n\ge0$

#### Complexity
- $O(n)$

### add
```
void add(int l, int r, const T& val)
```
$a_l,a_{l+1},\ldots,a_{r-1}$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

### max
```
T max(int l, int r)
```
$\max\lbrace a_l,a_{l+1},\cdots,a_{r-1}\rbrace$ を求める．
$l=r$ のときは ``numeric_limits<T>::min()`` が返る．

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

## References
- [Starry Sky(星空) - joi2009-day4 解説](https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html)
- [Starry sky 木 - えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2019/06/21/174953)
