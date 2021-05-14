---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/Fenwick_tree_dual.hpp
    title: Dual Fenwick Tree
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"verify/data_structure/Fenwick_tree_dual.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
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
    \t\treturn res;\n\t}\n};\n#line 5 \"verify/data_structure/Fenwick_tree_dual.test.cpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tFenwick_tree_dual<int>\
    \ F(n);\n\trep(_,q){\n\t\tint type; scanf(\"%d\",&type);\n\t\tif(type==0){\n\t\
    \t\tint l,r,x; scanf(\"%d%d%d\",&l,&r,&x); l--;\n\t\t\tF.add(l,r,x);\n\t\t}\n\t\
    \telse{\n\t\t\tint i; scanf(\"%d\",&i); i--;\n\t\t\tprintf(\"%d\\n\",F.get(i));\n\
    \t\t}\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/data_structure/Fenwick_tree_dual.hpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tFenwick_tree_dual<int>\
    \ F(n);\n\trep(_,q){\n\t\tint type; scanf(\"%d\",&type);\n\t\tif(type==0){\n\t\
    \t\tint l,r,x; scanf(\"%d%d%d\",&l,&r,&x); l--;\n\t\t\tF.add(l,r,x);\n\t\t}\n\t\
    \telse{\n\t\t\tint i; scanf(\"%d\",&i); i--;\n\t\t\tprintf(\"%d\\n\",F.get(i));\n\
    \t\t}\n\t}\n\n\treturn 0;\n}"
  dependsOn:
  - library/template.hpp
  - library/data_structure/Fenwick_tree_dual.hpp
  isVerificationFile: true
  path: verify/data_structure/Fenwick_tree_dual.test.cpp
  requiredBy: []
  timestamp: '2021-05-11 00:34:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/Fenwick_tree_dual.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/Fenwick_tree_dual.test.cpp
- /verify/verify/data_structure/Fenwick_tree_dual.test.cpp.html
title: verify/data_structure/Fenwick_tree_dual.test.cpp
---
