---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree.1.test.cpp
    title: verify/data_structure/Fenwick_tree.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree.2.test.cpp
    title: verify/data_structure/Fenwick_tree.2.test.cpp
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
    using lint=long long;\n#line 3 \"library/data_structure/Fenwick_tree.hpp\"\n\n\
    template<class G>\nclass Fenwick_tree{\n\tvector<G> a;\npublic:\n\tFenwick_tree()=default;\n\
    \tFenwick_tree(int n){ build(n); }\n\tFenwick_tree(const vector<G>& a){ build(a);\
    \ }\n\tvoid build(int n){\n\t\ta.assign(n,G{});\n\t}\n\tvoid build(const vector<G>&\
    \ a){\n\t\tthis->a=a;\n\t\tfor(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size())\
    \ (this->a)[i+(i&-i)-1]+=(this->a)[i-1];\n\t}\n\tvoid add(int i,const G& val){\n\
    \t\tfor(i++;i<=a.size();i+=i&-i) a[i-1]+=val;\n\t}\n\tG sum(int l,int r)const{\n\
    \t\tif(l==0){\n\t\t\tG res{};\n\t\t\tfor(;r>0;r-=r&-r) res+=a[r-1];\n\t\t\treturn\
    \ res;\n\t\t}\n\t\treturn sum(0,r)-sum(0,l);\n\t}\n\tint lower_bound(G val)const{\n\
    \t\tif(!(G{}<val)) return 0;\n\t\tint x=0,k;\n\t\tfor(k=1;k<=a.size();k<<=1);\n\
    \t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;\n\
    \t\treturn x;\n\t}\n\tint upper_bound(G val)const{\n\t\tif(val<G{}) return 0;\n\
    \t\tint x=0,k;\n\t\tfor(k=1;k<=a.size();k<<=1);\n\t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size()\
    \ && !(val<a[x+k-1])) val-=a[x+k-1], x+=k;\n\t\treturn x;\n\t}\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class G>\nclass Fenwick_tree{\n\
    \tvector<G> a;\npublic:\n\tFenwick_tree()=default;\n\tFenwick_tree(int n){ build(n);\
    \ }\n\tFenwick_tree(const vector<G>& a){ build(a); }\n\tvoid build(int n){\n\t\
    \ta.assign(n,G{});\n\t}\n\tvoid build(const vector<G>& a){\n\t\tthis->a=a;\n\t\
    \tfor(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];\n\
    \t}\n\tvoid add(int i,const G& val){\n\t\tfor(i++;i<=a.size();i+=i&-i) a[i-1]+=val;\n\
    \t}\n\tG sum(int l,int r)const{\n\t\tif(l==0){\n\t\t\tG res{};\n\t\t\tfor(;r>0;r-=r&-r)\
    \ res+=a[r-1];\n\t\t\treturn res;\n\t\t}\n\t\treturn sum(0,r)-sum(0,l);\n\t}\n\
    \tint lower_bound(G val)const{\n\t\tif(!(G{}<val)) return 0;\n\t\tint x=0,k;\n\
    \t\tfor(k=1;k<=a.size();k<<=1);\n\t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() &&\
    \ a[x+k-1]<val) val-=a[x+k-1], x+=k;\n\t\treturn x;\n\t}\n\tint upper_bound(G\
    \ val)const{\n\t\tif(val<G{}) return 0;\n\t\tint x=0,k;\n\t\tfor(k=1;k<=a.size();k<<=1);\n\
    \t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() && !(val<a[x+k-1])) val-=a[x+k-1], x+=k;\n\
    \t\treturn x;\n\t}\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/data_structure/Fenwick_tree.hpp
  requiredBy: []
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/Fenwick_tree.1.test.cpp
  - verify/data_structure/Fenwick_tree.2.test.cpp
documentation_of: library/data_structure/Fenwick_tree.hpp
layout: document
title: Fenwick Tree
---

## Description
Abel 群 $G$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，一点加算と区間和を $O(\log n)$ で処理するデータ構造．  
以下では，$G$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) Fenwick_tree<G>()
(2) Fenwick_tree<G>(int n)
(3) Fenwick_tree<G>(const vector<G>& a)
```
- (1) 空の列で初期化する
- (2) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (3) $a$ で初期化する

#### Constraints
- $(G,+)$ は Abel 群 (デフォルトコンストラクタが $G$ の単位元を生成し，$-$ は $+$ の逆演算)
- (2) $n\ge0$

#### Complexity
- (1) $O(1)$
- (2), (3) $O(n)$

### build
```
(1) void build(int n)
(2) void build(const vector<G>& a)
```
- (1) $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- (1) $n\ge0$

#### Complexity
- $O(n)$

### add
```
void add(int i, const G& val)
```
$a_i$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(\log n)$

### sum
```
G sum(int l, int r)
```
$a_l+a_{l+1}+\cdots+a_{r-1}$ を求める

#### Constraints
- $0\le l\le r\lt n$

#### Complexity
- $O(\log n)$

### lower_bound
```
int lower_bound(G val)
```
$a_0+a_1+\cdots+a_i\ge\mathrm{val}$ をみたす最小の $i$ を求める．  
ただし，$a_0+\cdots+a_{n-1}\lt\mathrm{val}$ のときは $n$ を返す．

#### Constraints
- $G$ 上の比較演算子 $<$ が定義されていて，これについて $G$ は[全順序群](https://en.wikipedia.org/wiki/Linearly_ordered_group)．
- $a_i\ge e\quad(i=0,\ldots,n-1)$

#### Complexity
- $O(\log n)$ ($G$ の元の比較が $O(1)$ でできることを仮定)

### upper_bound
```
int upper_bound(G val)
```
$a_0+a_1+\cdots+a_i\gt\mathrm{val}$ をみたす最小の $i$ を求める．  
ただし，$a_0+\cdots+a_{n-1}\le\mathrm{val}$ のときは $n$ を返す．

#### Constraints
- $G$ 上の比較演算子 $<$ が定義されていて，これについて $G$ は[全順序群](https://en.wikipedia.org/wiki/Linearly_ordered_group)．
- $a_i\ge e\quad(i=0,\ldots,n-1)$

#### Complexity
- $O(\log n)$ ($G$ の元の比較が $O(1)$ でできることを仮定)

## References
- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)
