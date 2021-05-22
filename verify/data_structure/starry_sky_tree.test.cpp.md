---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/starry_sky_tree.hpp
    title: Starry Sky Tree
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"verify/data_structure/starry_sky_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 1 \"library/data_structure/starry_sky_tree.hpp\"\
    \ntemplate<class T>\nclass starry_sky_tree{\n\tint sz;\n\tvector<T> seg;\n\n\t\
    void maintain(int u){\n\t\tif(1<=u && u<sz){\n\t\t\tT mx=std::max(seg[2*u],seg[2*u+1]);\n\
    \t\t\tseg[u]+=mx;\n\t\t\tseg[2*u  ]-=mx;\n\t\t\tseg[2*u+1]-=mx;\n\t\t}\n\t}\n\t\
    T max(int l,int r,int a,int b,int u,T cum)const{\n\t\tif(b<=l || r<=a) return\
    \ numeric_limits<T>::min();\n\t\tif(l<=a && b<=r) return cum+seg[u];\n\t\tT lmax=max(l,r,a,(a+b)/2,2*u\
    \  ,cum+seg[u]);\n\t\tT rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);\n\t\treturn\
    \ std::max(lmax,rmax);\n\t}\npublic:\n\tstarry_sky_tree(int n=0){ build(n); }\n\
    \tvoid build(int n){\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,T());\n\t\
    }\n\tvoid add(int l,int r,const T& val){\n\t\tint a,b;\n\t\tfor(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1){ seg[a]+=val; a++; }\n\t\t\tif(b&1){ b--; seg[b]+=val; }\n\t\t\t\
    maintain((a-1)>>1);\n\t\t\tmaintain(b>>1);\n\t\t}\n\t\tfor(int u=a-1;u>=1;u>>=1)\
    \ maintain(u);\n\t\tfor(int u= b ;u>=1;u>>=1) maintain(u);\n\t}\n\tT max(int l,int\
    \ r)const{ return max(l,r,0,sz,1,0); }\n};\n#line 5 \"verify/data_structure/starry_sky_tree.test.cpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tstarry_sky_tree<int> S(n);\n\
    \trep(_,q){\n\t\tint type,l,r; scanf(\"%d%d%d\",&type,&l,&r); r++;\n\t\tif(type==0){\n\
    \t\t\tint x; scanf(\"%d\",&x);\n\t\t\tS.add(l,r,-x);\n\t\t}\n\t\telse{\n\t\t\t\
    printf(\"%d\\n\",-S.max(l,r));\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/data_structure/starry_sky_tree.hpp\"\
    \n\nint main(){\n\tint n,q; scanf(\"%d%d\",&n,&q);\n\n\tstarry_sky_tree<int> S(n);\n\
    \trep(_,q){\n\t\tint type,l,r; scanf(\"%d%d%d\",&type,&l,&r); r++;\n\t\tif(type==0){\n\
    \t\t\tint x; scanf(\"%d\",&x);\n\t\t\tS.add(l,r,-x);\n\t\t}\n\t\telse{\n\t\t\t\
    printf(\"%d\\n\",-S.max(l,r));\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/data_structure/starry_sky_tree.hpp
  isVerificationFile: true
  path: verify/data_structure/starry_sky_tree.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/starry_sky_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/starry_sky_tree.test.cpp
- /verify/verify/data_structure/starry_sky_tree.test.cpp.html
title: verify/data_structure/starry_sky_tree.test.cpp
---
