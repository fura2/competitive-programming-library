---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/Fenwick_tree.hpp
    title: Fenwick Tree
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/data_structure/Fenwick_tree.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/data_structure/Fenwick_tree.hpp\"\
    \n\ntemplate<class G>\nclass Fenwick_tree{\n\tvector<G> a;\npublic:\n\tFenwick_tree(int\
    \ n=0){ build(n); }\n\tFenwick_tree(const vector<G>& a){ build(a); }\n\tvoid build(int\
    \ n){\n\t\ta.assign(n,G{});\n\t}\n\tvoid build(const vector<G>& a){\n\t\tthis->a=a;\n\
    \t\tfor(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];\n\
    \t}\n\tvoid add(int i,const G& val){\n\t\tfor(i++;i<=a.size();i+=i&-i) a[i-1]+=val;\n\
    \t}\n\tG sum(int l,int r)const{\n\t\tif(l==0){\n\t\t\tG res{};\n\t\t\tfor(;r>0;r-=r&-r)\
    \ res+=a[r-1];\n\t\t\treturn res;\n\t\t}\n\t\treturn sum(0,r)-sum(0,l);\n\t}\n\
    \tint lower_bound(G val)const{\n\t\tif(!(G{}<val)) return 0;\n\t\tint x=0,k;\n\
    \t\tfor(k=1;k<=a.size();k<<=1);\n\t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() &&\
    \ a[x+k-1]<val) val-=a[x+k-1], x+=k;\n\t\treturn x;\n\t}\n\tint upper_bound(G\
    \ val)const{\n\t\tif(val<G{}) return 0;\n\t\tint x=0,k;\n\t\tfor(k=1;k<=a.size();k<<=1);\n\
    \t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() && !(val<a[x+k-1])) val-=a[x+k-1], x+=k;\n\
    \t\treturn x;\n\t}\n};\n#line 5 \"verify/data_structure/Fenwick_tree.2.test.cpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tFenwick_tree<int> F(n);\n\
    \trep(_,q){\n\t\tint type,x,y; scanf(\"%d%d%d\",&type,&x,&y); x--;\n\t\tif(type==0){\n\
    \t\t\tF.add(x,y);\n\t\t}\n\t\telse{\n\t\t\tprintf(\"%d\\n\",F.sum(x,y));\n\t\t\
    }\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/data_structure/Fenwick_tree.hpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tFenwick_tree<int> F(n);\n\
    \trep(_,q){\n\t\tint type,x,y; scanf(\"%d%d%d\",&type,&x,&y); x--;\n\t\tif(type==0){\n\
    \t\t\tF.add(x,y);\n\t\t}\n\t\telse{\n\t\t\tprintf(\"%d\\n\",F.sum(x,y));\n\t\t\
    }\n\t}\n\n\treturn 0;\n}"
  dependsOn:
  - library/template.hpp
  - library/data_structure/Fenwick_tree.hpp
  isVerificationFile: true
  path: verify/data_structure/Fenwick_tree.2.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/Fenwick_tree.2.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/Fenwick_tree.2.test.cpp
- /verify/verify/data_structure/Fenwick_tree.2.test.cpp.html
title: verify/data_structure/Fenwick_tree.2.test.cpp
---
