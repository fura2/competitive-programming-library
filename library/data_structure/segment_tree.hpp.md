---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/data_structure/segment_tree.hpp\"\n\n\
    template<class M>\nclass segment_tree{\n\tint n,sz;\n\tvector<M> seg;\npublic:\n\
    \tsegment_tree()=default;\n\tsegment_tree(int n){ build(n); }\n\ttemplate<class\
    \ T>\n\tsegment_tree(const vector<T>& a){ build(a); }\n\tvoid build(int n){\n\t\
    \tthis->n=n;\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,M());\n\t}\n\ttemplate<class\
    \ T>\n\tvoid build(const vector<T>& a){\n\t\tbuild(a.size());\n\t\trep(i,a.size())\
    \ seg[sz+i]=a[i];\n\t\tfor(int i=sz-1;i>0;i--){\n\t\t\tseg[i]=seg[2*i]*seg[2*i+1];\n\
    \t\t}\n\t}\n\tconst M& operator[](int i)const{\n\t\treturn seg[sz+i];\n\t}\n\t\
    void update(int i,const M& x){\n\t\ti+=sz;\n\t\tseg[i]=x;\n\t\tfor(i>>=1;i>0;i>>=1)\
    \ seg[i]=seg[2*i]*seg[2*i+1];\n\t}\n\tM product(int l,int r)const{\n\t\tM lcum,rcum;\n\
    \t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\tif(a&1) lcum=lcum*seg[a++];\n\
    \t\t\tif(b&1) rcum=seg[--b]*rcum;\n\t\t}\n\t\treturn lcum*rcum;\n\t}\n\ttemplate<class\
    \ N,class F>\n\tN operate(int l,int r,const F& f){\n\t\tN lcum,rcum;\n\t\tfor(int\
    \ a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\tif(a&1) lcum=lcum*f(seg[a++]);\n\t\t\t\
    if(b&1) rcum=f(seg[--b])*rcum;\n\t\t}\n\t\treturn lcum*rcum;\n\t}\n\ttemplate<class\
    \ F>\n\tint max_right(int l,const F& f)const{\n\t\tif(l==n) return n;\n\t\tM cum;\n\
    \t\tauto dfs=[&](auto&& dfs,int a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=cum*seg[u];\n\
    \t\t\t\treturn f(cum)?b:a;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(c<=l){\n\
    \t\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t\t}\n\t\t\tif(l<=a && f(cum*seg[u])){\n\
    \t\t\t\tcum=cum*seg[u];\n\t\t\t\treturn b;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,a,c,2*u);\n\
    \t\t\tif(idx<c) return idx;\n\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t};\n\t\treturn\
    \ min(dfs(dfs,0,sz,1),n);\n\t}\n\ttemplate<class F>\n\tint min_left(int r,const\
    \ F& f)const{\n\t\tif(r==0) return 0;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int\
    \ a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn\
    \ f(cum)?a:b;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(r<=c){\n\t\t\t\treturn\
    \ dfs(dfs,a,c,2*u);\n\t\t\t}\n\t\t\tif(b<=r && f(seg[u]*cum)){\n\t\t\t\tcum=seg[u]*cum;\n\
    \t\t\t\treturn a;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,c,b,2*u+1);\n\t\t\tif(idx>c)\
    \ return idx;\n\t\t\treturn dfs(dfs,a,c,2*u);\n\t\t};\n\t\treturn dfs(dfs,0,sz,1);\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class M>\nclass segment_tree{\n\
    \tint n,sz;\n\tvector<M> seg;\npublic:\n\tsegment_tree()=default;\n\tsegment_tree(int\
    \ n){ build(n); }\n\ttemplate<class T>\n\tsegment_tree(const vector<T>& a){ build(a);\
    \ }\n\tvoid build(int n){\n\t\tthis->n=n;\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,M());\n\
    \t}\n\ttemplate<class T>\n\tvoid build(const vector<T>& a){\n\t\tbuild(a.size());\n\
    \t\trep(i,a.size()) seg[sz+i]=a[i];\n\t\tfor(int i=sz-1;i>0;i--){\n\t\t\tseg[i]=seg[2*i]*seg[2*i+1];\n\
    \t\t}\n\t}\n\tconst M& operator[](int i)const{\n\t\treturn seg[sz+i];\n\t}\n\t\
    void update(int i,const M& x){\n\t\ti+=sz;\n\t\tseg[i]=x;\n\t\tfor(i>>=1;i>0;i>>=1)\
    \ seg[i]=seg[2*i]*seg[2*i+1];\n\t}\n\tM product(int l,int r)const{\n\t\tM lcum,rcum;\n\
    \t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\tif(a&1) lcum=lcum*seg[a++];\n\
    \t\t\tif(b&1) rcum=seg[--b]*rcum;\n\t\t}\n\t\treturn lcum*rcum;\n\t}\n\ttemplate<class\
    \ N,class F>\n\tN operate(int l,int r,const F& f){\n\t\tN lcum,rcum;\n\t\tfor(int\
    \ a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\tif(a&1) lcum=lcum*f(seg[a++]);\n\t\t\t\
    if(b&1) rcum=f(seg[--b])*rcum;\n\t\t}\n\t\treturn lcum*rcum;\n\t}\n\ttemplate<class\
    \ F>\n\tint max_right(int l,const F& f)const{\n\t\tif(l==n) return n;\n\t\tM cum;\n\
    \t\tauto dfs=[&](auto&& dfs,int a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=cum*seg[u];\n\
    \t\t\t\treturn f(cum)?b:a;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(c<=l){\n\
    \t\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t\t}\n\t\t\tif(l<=a && f(cum*seg[u])){\n\
    \t\t\t\tcum=cum*seg[u];\n\t\t\t\treturn b;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,a,c,2*u);\n\
    \t\t\tif(idx<c) return idx;\n\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t};\n\t\treturn\
    \ min(dfs(dfs,0,sz,1),n);\n\t}\n\ttemplate<class F>\n\tint min_left(int r,const\
    \ F& f)const{\n\t\tif(r==0) return 0;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int\
    \ a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn\
    \ f(cum)?a:b;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(r<=c){\n\t\t\t\treturn\
    \ dfs(dfs,a,c,2*u);\n\t\t\t}\n\t\t\tif(b<=r && f(seg[u]*cum)){\n\t\t\t\tcum=seg[u]*cum;\n\
    \t\t\t\treturn a;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,c,b,2*u+1);\n\t\t\tif(idx>c)\
    \ return idx;\n\t\t\treturn dfs(dfs,a,c,2*u);\n\t\t};\n\t\treturn dfs(dfs,0,sz,1);\n\
    \t}\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-05-10 18:53:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/segment_tree.hpp
layout: document
title: Segment Tree
---

## Description
モノイド $(M,\ast)$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，一点更新と区間積を $O(\log n)$ で処理するデータ構造．  
以下では，$M$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) segment_tree<M>()
(2) segment_tree<M>(int n)
(3) segment_tree<M>(const vector<T>& a)
```
- (1) 空の列で初期化する
- (2) $M$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (3) $a$ で初期化する

#### Constraints
- $(M,\ast)$ はモノイド (デフォルトコンストラクタが $M$ の単位元を生成する)
- (2) $n\ge0$
- (3) $T$ は $M$ にキャストできる ($T$ と $M$ が一致していなくてもよい)．

#### Complexity
- (1) $O(1)$
- (2), (3) $O(n)$

### build
```
(1) void build(int n)
(2) void build(const vector<T>& a)
```
- (1) $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- (1) $n\ge0$
- (2) $T$ は $M$ にキャストできる ($T$ と $M$ が一致していなくてもよい)．

#### Complexity
- $O(n)$

### operator[]
```
const M& operator[](int i)
```
$a_i$ を求める

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(1)$

### update
```
void update(int i, const M& x)
```
$a_i$ に $x$ を代入する

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(\log n)$

### product
```
M product(int l, int r)
```
$a_l\ast a_{l+1}\ast\cdots\ast a_{r-1}$ を求める

#### Constraints
- $0\le l\le r\lt n$

#### Complexity
- $O(\log n)$

### operate
```
N operate(int l, int r, const F& f)
```
モノイド $(N,\ast)$ と準同型 $f:M\to N$ に対して，$f(a_l\ast a_{l+1}\cdots\ast a_{r-1})$ を求める．  
$M$ における積の計算量が大きく，$N$ における積と $f$ を作用させる計算量がどちらも小さいときに有用．

#### Constraints
- $(N,\ast)$ はモノイド (デフォルトコンストラクタが $N$ の単位元を生成する)
- $f:M\to N$ はモノイドの準同型
- $0\le l\le r\lt n$

#### Complexity
- $O(\log n)$ ($N$ の演算とインスタンスの生成，および，$f$ を作用させる計算量が $O(1)$ であることを仮定)

### max_right
```
int max_right(int l, const F& f)
```
$f:M\to\mathrm{bool}$　に対して，次の二つの条件をみたす $r\ (l\le r\le n)$ を一つ求める．
- $r=l$ または $f(a_l\ast a_{l+1}\ast\cdots\ast a_{r-1})=\mathrm{true}$
- $r=n$ または $f(a_l\ast a_{l+1}\ast\cdots\ast a_r)=\mathrm{false}$

#### Constraints
- $0\le l\le n$
- $f:M\to\mathrm{bool}$ は $f(e)=\mathrm{true}$ をみたす

#### Complexity
- $O(\log n)$ ($f$ を作用させる計算量が $O(1)$ であることを仮定)

### min_left
```
int min_left(int r, const F& f)
```
$f:M\to\mathrm{bool}$　に対して，次の二つの条件をみたす $l\ (0\le l\le r)$ を一つ求める．
- $l=r$ または $f(a_l\ast a_{l+1}\ast\cdots\ast a_{r-1})=\mathrm{true}$
- $l=0$ または $f(a_{l-1}\ast a_l\ast\cdots\ast a_{r-1})=\mathrm{false}$

#### Constraints
- $0\le r\le n$
- $f:M\to\mathrm{bool}$ は $f(e)=\mathrm{true}$ をみたす

#### Complexity
- $O(\log n)$ ($f$ を作用させる計算量が $O(1)$ であることを仮定)
