---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.2.test.cpp
    title: verify/data_structure/sparse_table.2.test.cpp
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
    using namespace std;\nusing lint=long long;\n#line 3 \"library/monoid/gcd_monoid.hpp\"\
    \n\ntemplate<class T>\nclass gcd_monoid{\n\tT a;\npublic:\n\tgcd_monoid(const\
    \ T& val=T()):a(val){}\n\tgcd_monoid operator*(const gcd_monoid& x)const{\n\t\t\
    return gcd(a,x.a);\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{ return\
    \ a; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass gcd_monoid{\n\
    \tT a;\npublic:\n\tgcd_monoid(const T& val=T()):a(val){}\n\tgcd_monoid operator*(const\
    \ gcd_monoid& x)const{\n\t\treturn gcd(a,x.a);\n\t}\n\tT& get(){ return a; }\n\
    \tconst T& get()const{ return a; }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/monoid/gcd_monoid.hpp
  requiredBy: []
  timestamp: '2021-05-28 17:41:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/sparse_table.2.test.cpp
documentation_of: library/monoid/gcd_monoid.hpp
layout: document
title: GCD Monoid
---

## Description
$T$ の元全体を台集合とし，積を $a\ast b=\mathrm{gcd}$ と定めることで得られるモノイド．\\
``T()`` が単位元となる．
```
gcd_monoid<T>
```

### (constructor)
```
gcd_monoid<T>(const T& val = T())
```
$\mathrm{val}$ で初期化する

#### Constraints
- $T$ は $\mathrm{gcd}:T\times T\to T$ が定義された環 ([参考](https://en.wikipedia.org/wiki/GCD_domain)) で，デフォルトコンストラクタが $T$ の零元を生成する．

#### Complexity
- $O(1)$

### operator*
```
gcd_monoid operator*(const gcd_monoid& x)
```
モノイドの積

#### Constraints
- なし

#### Complexity
- GCD の計算を $O(1)$ 回おこなう

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
