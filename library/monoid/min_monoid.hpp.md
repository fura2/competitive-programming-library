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
    using lint=long long;\n#line 3 \"library/monoid/min_monoid.hpp\"\n\ntemplate<class\
    \ T>\nclass min_monoid{\n\tT a;\npublic:\n\tmin_monoid():a(numeric_limits<T>::max()){}\n\
    \tmin_monoid(const T& val):a(val){}\n\tmin_monoid operator*(const min_monoid&\
    \ x)const{\n\t\treturn min(a,x.a);\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{\
    \ return a; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<class T>\nclass min_monoid{\n\
    \tT a;\npublic:\n\tmin_monoid():a(numeric_limits<T>::max()){}\n\tmin_monoid(const\
    \ T& val):a(val){}\n\tmin_monoid operator*(const min_monoid& x)const{\n\t\treturn\
    \ min(a,x.a);\n\t}\n\tT& get(){ return a; }\n\tconst T& get()const{ return a;\
    \ }\n};\n"
  dependsOn:
  - library/template.hpp
  isVerificationFile: false
  path: library/monoid/min_monoid.hpp
  requiredBy: []
  timestamp: '2021-05-10 19:36:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/segment_tree.1.test.cpp
documentation_of: library/monoid/min_monoid.hpp
layout: document
redirect_from:
- /library/library/monoid/min_monoid.hpp
- /library/library/monoid/min_monoid.hpp.html
title: library/monoid/min_monoid.hpp
---
