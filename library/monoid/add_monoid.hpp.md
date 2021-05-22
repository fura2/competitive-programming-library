---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/segment_tree.3.test.cpp
    title: verify/data_structure/segment_tree.3.test.cpp
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
    using namespace std;\nusing lint=long long;\n#line 3 \"library/monoid/add_monoid.hpp\"\
    \n\ntemplate<class T>\nclass add_monoid{\n\tT a;\npublic:\n\tadd_monoid(const\
    \ T& val=T()):a(val){}\n\tadd_monoid operator*(const add_monoid& x)const{\n\t\t\
    return a+x.a;\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{ return a;\
    \ }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass add_monoid{\n\
    \tT a;\npublic:\n\tadd_monoid(const T& val=T()):a(val){}\n\tadd_monoid operator*(const\
    \ add_monoid& x)const{\n\t\treturn a+x.a;\n\t}\n\tT& get(){ return a; }\n\tconst\
    \ T& get()const{ return a; }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/monoid/add_monoid.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/segment_tree.3.test.cpp
documentation_of: library/monoid/add_monoid.hpp
layout: document
title: Additive Monoid
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=a+b$ と定めることで得られるモノイド．\\
``T()`` が単位元となる．

### (constructor)
```
add_monoid<T>(const T& val = T())
```
- $\mathrm{val}$ で初期化する

#### Constraints
- $T$ 上の結合的な二項演算 $+$ が定義されている
- ``T()`` が加法単位元

#### Complexity
- $O(1)$

### operator*
```
add_monoid operator*(const add_monoid& x)
```
- モノイドの積

#### Constraints
- なし

#### Complexity
- $O(1)$ ($T$ の演算 $+$ が $O(1)$ でできることを仮定)

### get
```
(1) T& get()
(2) const T& get()
```
対応する $T$ の元を求める

#### Constraints
- なし

#### Complexity
- $O(1)$
