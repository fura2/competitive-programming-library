---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/segment_tree.2.test.cpp
    title: verify/data_structure/segment_tree.2.test.cpp
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
    using lint=long long;\n#line 3 \"library/monoid/max_monoid.hpp\"\n\ntemplate<class\
    \ T>\nclass max_monoid{\n\tT a;\npublic:\n\tmax_monoid():a(numeric_limits<T>::min()){}\n\
    \tmax_monoid(const T& val):a(val){}\n\tmax_monoid operator*(const max_monoid&\
    \ x)const{\n\t\treturn max(a,x.a);\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{\
    \ return a; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass max_monoid{\n\
    \tT a;\npublic:\n\tmax_monoid():a(numeric_limits<T>::min()){}\n\tmax_monoid(const\
    \ T& val):a(val){}\n\tmax_monoid operator*(const max_monoid& x)const{\n\t\treturn\
    \ max(a,x.a);\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{ return a;\
    \ }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/monoid/max_monoid.hpp
  requiredBy: []
  timestamp: '2021-05-10 21:01:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/segment_tree.2.test.cpp
documentation_of: library/monoid/max_monoid.hpp
layout: document
title: Maximum Monoid
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=\max\lbrace a,b\rbrace$ と定めることで得られるモノイド．\\
``numeric_limits<T>::min()`` が単位元となる．

### (constructor)
```
(1) max_monoid<T>()
(2) max_monoid<T>(const T& val)
```
- (1) 単位元で初期化する
- (2) $\mathrm{val}$ で初期化する

#### Constraints
- $T$ 上の比較演算子 $<$ が定義されていて，これについて $T$ は全順序集合
- ``numeric_limits<T>::min()`` が $T$ の最小元

#### Complexity
- $O(1)$

### operator*
```
max_monoid operator*(const max_monoid& x)
```
- モノイドの積

#### Constraints
- なし

#### Complexity
- $O(1)$ ($T$ の元の比較が $O(1)$ でできることを仮定)

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
