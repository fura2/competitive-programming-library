---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/segment_tree.1.test.cpp
    title: verify/data_structure/segment_tree.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.1.test.cpp
    title: verify/data_structure/sparse_table.1.test.cpp
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
    using namespace std;\nusing lint=long long;\n#line 3 \"library/monoid/min_monoid.hpp\"\
    \n\ntemplate<class T>\nclass min_monoid{\n\tT a;\npublic:\n\tmin_monoid(const\
    \ T& val=numeric_limits<T>::max()):a(val){}\n\tmin_monoid operator*(const min_monoid&\
    \ x)const{\n\t\treturn min(a,x.a);\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{\
    \ return a; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass min_monoid{\n\
    \tT a;\npublic:\n\tmin_monoid(const T& val=numeric_limits<T>::max()):a(val){}\n\
    \tmin_monoid operator*(const min_monoid& x)const{\n\t\treturn min(a,x.a);\n\t\
    }\n\tT& get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/monoid/min_monoid.hpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/sparse_table.1.test.cpp
  - verify/data_structure/segment_tree.1.test.cpp
documentation_of: library/monoid/min_monoid.hpp
layout: document
title: Minimum Monoid
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=\min\lbrace a,b\rbrace$ と定めることで得られるモノイド．\\
``numeric_limits<T>::max()`` が単位元となる．
```
min_monoid<T>
```

### (constructor)
```
min_monoid<T>(const T& val = numeric_limits<T>::max())
```
$\mathrm{val}$ で初期化する

#### Constraints
- $T$ 上の比較演算子 $<$ が定義されていて，これについて $T$ は全順序集合
- ``numeric_limits<T>::max()`` が $T$ の最大元

#### Complexity
- $O(1)$

### operator*
```
min_monoid operator*(const min_monoid& x)
```
モノイドの積

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
