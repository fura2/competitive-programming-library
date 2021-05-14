---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Cartesian_tree.hpp
    title: Cartesian Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"verify/tree/Cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 2 \"library/template.hpp\"\
    \n#include <cassert>\n#include <cctype>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n#include <algorithm>\n#include <deque>\n#include <functional>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n\nusing namespace std;\nusing lint=long long;\n#line 3 \"library/tree/Cartesian_tree.hpp\"\
    \n\n/*\n\tCartesian tree\n\t\t\u6700\u5C0F\u306E\u8981\u7D20\u304C\u6839\u306B\
    \u306A\u308B\n\t\t\u9802\u70B9\u306E\u756A\u53F7\u3067 tie break\n\t\tparent,\
    \ left, right \u306F\u305D\u308C\u305E\u308C\u89AA, \u5DE6\u306E\u5B50, \u53F3\
    \u306E\u5B50\u306E\u9802\u70B9\u756A\u53F7 (\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F -1)\n\t\t\u9802\u70B9 u \u306B\u683C\u7D0D\u3055\u308C\u305F\u30C7\
    \u30FC\u30BF\u306F [u] \u3067\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u308B\n\n\t\u8A08\
    \u7B97\u91CF O(n)\n*/\n\ntemplate<class T>\nclass Cartesian_tree{\n\tvector<T>\
    \ a;\n\tint rt;\n\tvector<int> p,l,r;\npublic:\n\tCartesian_tree(const vector<T>&\
    \ a={}){ build(a); }\n\n\tvoid build(const vector<T>& a){\n\t\tthis->a=a;\n\t\t\
    int n=a.size();\n\t\trt=0;\n\t\tp.assign(n,-1);\n\t\tl.assign(n,-1);\n\t\tr.assign(n,-1);\n\
    \n\t\tfor(int u=1;u<n;u++){\n\t\t\tint v=u-1;\n\t\t\tbool top=false;\n\t\t\twhile(a[v]>a[u]){\n\
    \t\t\t\tif(p[v]==-1){\n\t\t\t\t\ttop=true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\
    \tv=p[v];\n\t\t\t}\n\t\t\tif(top){\n\t\t\t\tp[v]=u;\n\t\t\t\tl[u]=v;\n\t\t\t\t\
    rt=u;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tp[u]=v;\n\t\t\t\tif(r[v]!=-1) p[r[v]]=u;\n\
    \t\t\t\tl[u]=r[v];\n\t\t\t\tr[v]=u;\n\t\t\t}\n\t\t}\n\t}\n\tconst T& operator[](int\
    \ u)const{ return a[u]; }\n\tint root()const{ return rt; }\n\tint parent(int u)const{\
    \ return p[u]; }\n\tint left(int u)const{ return l[u]; }\n\tint right(int u)const{\
    \ return r[u]; }\n};\n#line 5 \"verify/tree/Cartesian_tree.test.cpp\"\n\nint main(){\n\
    \tint n; scanf(\"%d\",&n);\n\tvector<int> a(n);\n\trep(i,n) scanf(\"%d\",&a[i]);\n\
    \n\tCartesian_tree CT(a);\n\trep(u,n) printf(\"%d%c\",CT.parent(u)!=-1?CT.parent(u):u,u<n-1?'\
    \ ':'\\n');\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../library/template.hpp\"\n#include \"../../library/tree/Cartesian_tree.hpp\"\
    \n\nint main(){\n\tint n; scanf(\"%d\",&n);\n\tvector<int> a(n);\n\trep(i,n) scanf(\"\
    %d\",&a[i]);\n\n\tCartesian_tree CT(a);\n\trep(u,n) printf(\"%d%c\",CT.parent(u)!=-1?CT.parent(u):u,u<n-1?'\
    \ ':'\\n');\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/tree/Cartesian_tree.hpp
  isVerificationFile: true
  path: verify/tree/Cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2021-05-14 23:31:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/Cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/Cartesian_tree.test.cpp
- /verify/verify/tree/Cartesian_tree.test.cpp.html
title: verify/tree/Cartesian_tree.test.cpp
---
