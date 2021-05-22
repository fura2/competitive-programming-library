---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: library/monoid/min_monoid.hpp
    title: Minimum Monoid
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/data_structure/sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"library/template.hpp\"\
    \n#include <cassert>\n#include <cctype>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n#include <algorithm>\n#include <deque>\n#include <functional>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\nusing lint=long\
    \ long;\n#line 3 \"library/monoid/min_monoid.hpp\"\n\ntemplate<class T>\nclass\
    \ min_monoid{\n\tT a;\npublic:\n\tmin_monoid(const T& val=numeric_limits<T>::max()):a(val){}\n\
    \tmin_monoid operator*(const min_monoid& x)const{\n\t\treturn min(a,x.a);\n\t\
    }\n\tT& get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n#line 3 \"\
    library/data_structure/sparse_table.hpp\"\n\ntemplate<class B>\nclass sparse_table{\n\
    \tvector<vector<B>> st;\n\tvector<int> h;\npublic:\n\tsparse_table()=default;\n\
    \ttemplate<class T>\n\tsparse_table(const vector<T>& a){ build(a); }\n\n\ttemplate<class\
    \ T>\n\tvoid build(const vector<T>& a){\n\t\tint n=a.size();\n\t\th.assign(n+1,0);\n\
    \t\tfor(int i=2;i<=n;i++) h[i]=h[i>>1]+1;\n\t\tst.resize(h[n]+1);\n\t\tst[0].resize(n);\n\
    \t\trep(i,n) st[0][i]=a[i];\n\t\tfor(int i=1;i<h[n]+1;i++){\n\t\t\tst[i].resize(n-(1<<i)+1);\n\
    \t\t\trep(j,n-(1<<i)+1) st[i][j]=st[i-1][j]*st[i-1][j+(1<<(i-1))];\n\t\t}\n\t\
    }\n\n\tB product(int l,int r)const{\n\t\tint i=h[r-l];\n\t\treturn st[i][l]*st[i][r-(1<<i)];\n\
    \t}\n};\n#line 6 \"verify/data_structure/sparse_table.test.cpp\"\n\nint main(){\n\
    \tint n,q; scanf(\"%d%d\",&n,&q);\n\tvector<int> a(n);\n\trep(i,n) scanf(\"%d\"\
    ,&a[i]);\n\n\tsparse_table<min_monoid<int>> ST(a);\n\trep(_,q){\n\t\tint l,r;\
    \ scanf(\"%d%d\",&l,&r);\n\t\tprintf(\"%d\\n\",ST.product(l,r).get());\n\t}\n\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../library/template.hpp\"\n#include \"../../library/monoid/min_monoid.hpp\"\
    \n#include \"../../library/data_structure/sparse_table.hpp\"\n\nint main(){\n\t\
    int n,q; scanf(\"%d%d\",&n,&q);\n\tvector<int> a(n);\n\trep(i,n) scanf(\"%d\"\
    ,&a[i]);\n\n\tsparse_table<min_monoid<int>> ST(a);\n\trep(_,q){\n\t\tint l,r;\
    \ scanf(\"%d%d\",&l,&r);\n\t\tprintf(\"%d\\n\",ST.product(l,r).get());\n\t}\n\n\
    \treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/monoid/min_monoid.hpp
  - library/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: verify/data_structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/sparse_table.test.cpp
- /verify/verify/data_structure/sparse_table.test.cpp.html
title: verify/data_structure/sparse_table.test.cpp
---
