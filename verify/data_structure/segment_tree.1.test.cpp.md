---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/segment_tree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/data_structure/segment_tree.1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/data_structure/segment_tree.hpp\"\
    \n\ntemplate<class M>\nclass segment_tree{\n\tint n,sz;\n\tvector<M> seg;\npublic:\n\
    \tsegment_tree(int n=0){ build(n); }\n\ttemplate<class T>\n\tsegment_tree(const\
    \ vector<T>& a){ build(a); }\n\n\tvoid build(int n){\n\t\tthis->n=n;\n\t\tfor(sz=1;sz<n;sz<<=1);\n\
    \t\tseg.assign(2*sz,M());\n\t}\n\n\ttemplate<class T>\n\tvoid build(const vector<T>&\
    \ a){\n\t\tbuild(a.size());\n\t\trep(i,a.size()) seg[sz+i]=a[i];\n\t\tfor(int\
    \ i=sz-1;i>0;i--){\n\t\t\tseg[i]=seg[2*i]*seg[2*i+1];\n\t\t}\n\t}\n\n\tconst M&\
    \ operator[](int i)const{\n\t\treturn seg[sz+i];\n\t}\n\n\tvoid update(int i,const\
    \ M& x){\n\t\ti+=sz;\n\t\tseg[i]=x;\n\t\tfor(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];\n\
    \t}\n\n\tM product(int l,int r)const{\n\t\tM lcum,rcum;\n\t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1) lcum=lcum*seg[a++];\n\t\t\tif(b&1) rcum=seg[--b]*rcum;\n\t\t}\n\t\
    \treturn lcum*rcum;\n\t}\n\n\ttemplate<class N,class F>\n\tN operate(int l,int\
    \ r,const F& f){\n\t\tN lcum,rcum;\n\t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1) lcum=lcum*f(seg[a++]);\n\t\t\tif(b&1) rcum=f(seg[--b])*rcum;\n\t\
    \t}\n\t\treturn lcum*rcum;\n\t}\n\n\ttemplate<class F>\n\tint max_right(int l,const\
    \ F& f)const{\n\t\tif(l==n) return n;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int\
    \ a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=cum*seg[u];\n\t\t\t\treturn\
    \ f(cum)?b:a;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(c<=l){\n\t\t\t\treturn\
    \ dfs(dfs,c,b,2*u+1);\n\t\t\t}\n\t\t\tif(l<=a && f(cum*seg[u])){\n\t\t\t\tcum=cum*seg[u];\n\
    \t\t\t\treturn b;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,a,c,2*u);\n\t\t\tif(idx<c)\
    \ return idx;\n\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t};\n\t\treturn min(dfs(dfs,0,sz,1),n);\n\
    \t}\n\n\ttemplate<class F>\n\tint min_left(int r,const F& f)const{\n\t\tif(r==0)\
    \ return 0;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int a,int b,int u){\n\t\t\
    \tif(a==b-1){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn f(cum)?a:b;\n\t\t\t}\n\n\
    \t\t\tint c=(a+b)/2;\n\t\t\tif(r<=c){\n\t\t\t\treturn dfs(dfs,a,c,2*u);\n\t\t\t\
    }\n\t\t\tif(b<=r && f(seg[u]*cum)){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn a;\n\
    \t\t\t}\n\n\t\t\tint idx=dfs(dfs,c,b,2*u+1);\n\t\t\tif(idx>c) return idx;\n\t\t\
    \treturn dfs(dfs,a,c,2*u);\n\t\t};\n\t\treturn dfs(dfs,0,sz,1);\n\t}\n};\n#line\
    \ 3 \"library/monoid/min_monoid.hpp\"\n\ntemplate<class T>\nclass min_monoid{\n\
    \tT a;\npublic:\n\tmin_monoid(const T& val=numeric_limits<T>::max()):a(val){}\n\
    \tmin_monoid operator*(const min_monoid& x)const{\n\t\treturn min(a,x.a);\n\t\
    }\n\tT& get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n#line 6 \"\
    verify/data_structure/segment_tree.1.test.cpp\"\n\nint main(){\n\tint n,q; scanf(\"\
    %d%d\",&n,&q);\n\n\tsegment_tree<min_monoid<int>> S(n);\n\trep(_,q){\n\t\tint\
    \ type,x,y; scanf(\"%d%d%d\",&type,&x,&y);\n\t\tif(type==0){\n\t\t\tS.update(x,y);\n\
    \t\t}\n\t\telse{\n\t\t\ty++;\n\t\t\tprintf(\"%d\\n\",S.product(x,y).get());\n\t\
    \t}\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/data_structure/segment_tree.hpp\"\
    \n#include \"../../library/monoid/min_monoid.hpp\"\n\nint main(){\n\tint n,q;\
    \ scanf(\"%d%d\",&n,&q);\n\n\tsegment_tree<min_monoid<int>> S(n);\n\trep(_,q){\n\
    \t\tint type,x,y; scanf(\"%d%d%d\",&type,&x,&y);\n\t\tif(type==0){\n\t\t\tS.update(x,y);\n\
    \t\t}\n\t\telse{\n\t\t\ty++;\n\t\t\tprintf(\"%d\\n\",S.product(x,y).get());\n\t\
    \t}\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/data_structure/segment_tree.hpp
  - library/monoid/min_monoid.hpp
  isVerificationFile: true
  path: verify/data_structure/segment_tree.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/segment_tree.1.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/segment_tree.1.test.cpp
- /verify/verify/data_structure/segment_tree.1.test.cpp.html
title: verify/data_structure/segment_tree.1.test.cpp
---
