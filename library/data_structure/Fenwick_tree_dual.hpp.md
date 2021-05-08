---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"library/data_structure/Fenwick_tree_dual.hpp\"\ntemplate<class\
    \ G>\nclass Fenwick_tree_dual{\n\tvector<G> a;\npublic:\n\tFenwick_tree_dual(){}\n\
    \tFenwick_tree_dual(int n){ build(n); }\n\tFenwick_tree_dual(const vector<G>&\
    \ a){ build(a); }\n\tvoid build(int n){\n\t\ta.assign(n,G{});\n\t}\n\tvoid build(const\
    \ vector<G>& a){\n\t\tthis->a=a;\n\t\tfor(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size())\
    \ (this->a)[i-1]-=(this->a)[i+(i&-i)-1];\n\t}\n\tvoid add(int l,int r,const G&\
    \ val){\n\t\tif(l==0){\n\t\t\tfor(;r>0;r-=r&-r) a[r-1]+=val;\n\t\t\treturn;\n\t\
    \t}\n\t\tadd(0,r,val);\n\t\tadd(0,l,-val);\n\t}\n\tG get(int i)const{\n\t\tG res{};\n\
    \t\tfor(i++;i<=a.size();i+=i&-i) res+=a[i-1];\n\t\treturn res;\n\t}\n\tvoid f(){\n\
    \t\trep(i,a.size()) printf(\"%d: %d\\n\",i+1,a[i]);\n\t}\n};\n"
  code: "template<class G>\nclass Fenwick_tree_dual{\n\tvector<G> a;\npublic:\n\t\
    Fenwick_tree_dual(){}\n\tFenwick_tree_dual(int n){ build(n); }\n\tFenwick_tree_dual(const\
    \ vector<G>& a){ build(a); }\n\tvoid build(int n){\n\t\ta.assign(n,G{});\n\t}\n\
    \tvoid build(const vector<G>& a){\n\t\tthis->a=a;\n\t\tfor(int i=1;i<=a.size();i++)\
    \ if(i+(i&-i)<=a.size()) (this->a)[i-1]-=(this->a)[i+(i&-i)-1];\n\t}\n\tvoid add(int\
    \ l,int r,const G& val){\n\t\tif(l==0){\n\t\t\tfor(;r>0;r-=r&-r) a[r-1]+=val;\n\
    \t\t\treturn;\n\t\t}\n\t\tadd(0,r,val);\n\t\tadd(0,l,-val);\n\t}\n\tG get(int\
    \ i)const{\n\t\tG res{};\n\t\tfor(i++;i<=a.size();i+=i&-i) res+=a[i-1];\n\t\t\
    return res;\n\t}\n\tvoid f(){\n\t\trep(i,a.size()) printf(\"%d: %d\\n\",i+1,a[i]);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/Fenwick_tree_dual.hpp
  requiredBy: []
  timestamp: '2021-05-08 16:32:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/Fenwick_tree_dual.test.cpp
documentation_of: library/data_structure/Fenwick_tree_dual.hpp
layout: document
title: Dual Fenwick Tree
---

## Description
Abel 群 $G$ の元の列 $a_0,\ldots,a_{n-1}$ に対して，区間加算と一点取得を $O(\log n)$ で処理できるデータ構造．  
以下では，$G$ の演算やインスタンスの生成が $O(1)$ でできることを仮定している．

### (constructor)
```
(1) Fenwick_tree_dual<G>()
(2) Fenwick_tree_dual<G>(int n)
(3) Fenwick_tree_dual<G>(const vector<G>& a)
```
- (1) 空の列で初期化する
- (2) $G$ の単位元 $e$ のみからなる長さ $n$ の列で初期化する
- (3) $a$ で初期化する

#### Constraints
- $(G,+)$ は Abel 群 (デフォルトコンストラクタが $G$ の単位元を生成し，$-$ は $+$ の逆演算)
- (2) $n\ge0$

#### Complexity
- (1) $O(1)$
- (2)(3) $O(n)$

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
void add(int l, int r, const G& val)
```
$a_l,\ldots,a_{r-1}$ に $\mathrm{val}$ を加える

#### Constraints
- $0\le l\le r\lt n$

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
