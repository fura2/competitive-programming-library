---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree_dual.test.cpp
    title: verify/data_structure/Fenwick_tree_dual.test.cpp
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
    using lint=long long;\n#line 3 \"library/data_structure/Fenwick_tree_dual.hpp\"\
    \n\ntemplate<class G>\nclass Fenwick_tree_dual{\n\tvector<G> a;\npublic:\n\tFenwick_tree_dual(int\
    \ n=0){ build(n); }\n\tFenwick_tree_dual(const vector<G>& a){ build(a); }\n\t\
    void build(int n){\n\t\ta.assign(n,G{});\n\t}\n\tvoid build(const vector<G>& a){\n\
    \t\tthis->a=a;\n\t\tfor(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i-1]-=(this->a)[i+(i&-i)-1];\n\
    \t}\n\tvoid add(int l,int r,const G& val){\n\t\tif(l==0){\n\t\t\tfor(;r>0;r-=r&-r)\
    \ a[r-1]+=val;\n\t\t\treturn;\n\t\t}\n\t\tadd(0,r,val);\n\t\tadd(0,l,-val);\n\t\
    }\n\tG get(int i)const{\n\t\tG res{};\n\t\tfor(i++;i<=a.size();i+=i&-i) res+=a[i-1];\n\
    \t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class G>\nclass Fenwick_tree_dual{\n\
    \tvector<G> a;\npublic:\n\tFenwick_tree_dual(int n=0){ build(n); }\n\tFenwick_tree_dual(const\
    \ vector<G>& a){ build(a); }\n\tvoid build(int n){\n\t\ta.assign(n,G{});\n\t}\n\
    \tvoid build(const vector<G>& a){\n\t\tthis->a=a;\n\t\tfor(int i=1;i<=a.size();i++)\
    \ if(i+(i&-i)<=a.size()) (this->a)[i-1]-=(this->a)[i+(i&-i)-1];\n\t}\n\tvoid add(int\
    \ l,int r,const G& val){\n\t\tif(l==0){\n\t\t\tfor(;r>0;r-=r&-r) a[r-1]+=val;\n\
    \t\t\treturn;\n\t\t}\n\t\tadd(0,r,val);\n\t\tadd(0,l,-val);\n\t}\n\tG get(int\
    \ i)const{\n\t\tG res{};\n\t\tfor(i++;i<=a.size();i+=i&-i) res+=a[i-1];\n\t\t\
    return res;\n\t}\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/data_structure/Fenwick_tree_dual.hpp
  requiredBy: []
  timestamp: '2021-05-11 00:34:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/Fenwick_tree_dual.test.cpp
documentation_of: library/data_structure/Fenwick_tree_dual.hpp
layout: document
title: Dual Fenwick Tree
---

## Description
Abel 群 $G$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，区間加算と一点取得を $O(\log n)$ で処理するデータ構造．\\
以下では，$G$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) Fenwick_tree_dual<G>(int n = 0)
(2) Fenwick_tree_dual<G>(const vector<G>& a)
```
- (1) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- $(G,+)$ は Abel 群 (デフォルトコンストラクタが $G$ の単位元を生成し，$-$ は $+$ の逆演算)
- (1) $n\ge0$

#### Complexity
- $O(n)$

### build
```
(1) void build(int n)
(2) void build(const vector<G>& a)
```
- (1) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (2) $a$ で初期化する

#### Constraints
- (1) $n\ge0$

#### Complexity
- $O(n)$

### add
```
void add(int l, int r, const G& val)
```
$a_l,a_{l+1},\ldots,a_{r-1}$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le l\le r\le n$

#### Complexity
- $O(\log n)$

### get
```
G get(int i)
```
$a_i$ を求める

#### Constraints
- $0\le i\lt n$

#### Complexity
- $O(\log n)$