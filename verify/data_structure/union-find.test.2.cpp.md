---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/union-find.hpp
    title: Union-Find
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"verify/data_structure/union-find.test.2.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\n\n#line\
    \ 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n#include\
    \ <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\nusing namespace std;\n\
    using lint=long long;\n#line 3 \"library/data_structure/union-find.hpp\"\n\nclass\
    \ union_find{\n\tint n;\n\tvector<int> p;\npublic:\n\tunion_find(int n=0){ build(n);\
    \ }\n\tvoid build(int n){\n\t\tthis->n=n;\n\t\tp.assign(n,-1);\n\t}\n\tint find(int\
    \ u){ return p[u]<0?u:p[u]=find(p[u]); }\n\tvoid unite(int u,int v){\n\t\tu=find(u);\
    \ v=find(v);\n\t\tif(u!=v){\n\t\t\tif(p[v]<p[u]) swap(u,v);\n\t\t\tp[u]+=p[v];\
    \ p[v]=u; n--;\n\t\t}\n\t}\n\tbool is_same(int u,int v){ return find(u)==find(v);\
    \ }\n\tint size()const{ return n; }\n\tint size(int u){ return -p[find(u)]; }\n\
    };\n#line 5 \"verify/data_structure/union-find.test.2.cpp\"\n\nint main(){\n\t\
    int n,q; scanf(\"%d%d\",&n,&q);\n\n\tunion_find U(n);\n\trep(_,q){\n\t\tint type,u,v;\
    \ scanf(\"%d%d%d\",&type,&u,&v);\n\t\tif(type==0){\n\t\t\tU.unite(u,v);\n\t\t\
    }\n\t\telse{\n\t\t\tprintf(\"%d\\n\",U.is_same(u,v)?1:0);\n\t\t}\n\t}\n\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/data_structure/union-find.hpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tunion_find U(n);\n\trep(_,q){\n\
    \t\tint type,u,v; scanf(\"%d%d%d\",&type,&u,&v);\n\t\tif(type==0){\n\t\t\tU.unite(u,v);\n\
    \t\t}\n\t\telse{\n\t\t\tprintf(\"%d\\n\",U.is_same(u,v)?1:0);\n\t\t}\n\t}\n\n\t\
    return 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/data_structure/union-find.hpp
  isVerificationFile: true
  path: verify/data_structure/union-find.test.2.cpp
  requiredBy: []
  timestamp: '2021-05-11 00:34:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/union-find.test.2.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/union-find.test.2.cpp
- /verify/verify/data_structure/union-find.test.2.cpp.html
title: verify/data_structure/union-find.test.2.cpp
---
