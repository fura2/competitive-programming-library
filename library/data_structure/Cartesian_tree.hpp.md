---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structure/Cartesian_tree.hpp\"\n/*\n\tCartesian\
    \ tree\n\t\t\u6700\u5C0F\u306E\u8981\u7D20\u304C\u6839\u306B\u306A\u308B\n\t\t\
    \u9802\u70B9\u306E\u756A\u53F7\u3067 tie break\n\t\tparent, left, right \u306F\
    \u305D\u308C\u305E\u308C\u89AA, \u5DE6\u306E\u5B50, \u53F3\u306E\u5B50\u306E\u9802\
    \u70B9\u756A\u53F7 (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n\t\t\
    \u9802\u70B9 u \u306B\u683C\u7D0D\u3055\u308C\u305F\u30C7\u30FC\u30BF\u306F [u]\
    \ \u3067\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u308B\n\n\t\u8A08\u7B97\u91CF O(n)\n\
    */\n\ntemplate<class T>\nclass Cartesian_tree{\n\tvector<T> a;\n\tint rt;\n\t\
    vector<int> p,l,r;\npublic:\n\tCartesian_tree(const vector<T>& a):a(a){\n\t\t\
    int n=a.size();\n\t\trt=0;\n\t\tp.assign(n,-1);\n\t\tl.assign(n,-1);\n\t\tr.assign(n,-1);\n\
    \n\t\tfor(int u=1;u<n;u++){\n\t\t\tint v=u-1;\n\t\t\tbool top=false;\n\t\t\twhile(a[v]>a[u]){\n\
    \t\t\t\tif(p[v]==-1){\n\t\t\t\t\ttop=true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\
    \tv=p[v];\n\t\t\t}\n\t\t\tif(top){\n\t\t\t\tp[v]=u;\n\t\t\t\tl[u]=v;\n\t\t\t\t\
    rt=u;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tp[u]=v;\n\t\t\t\tif(r[v]!=-1) p[r[v]]=u;\n\
    \t\t\t\tl[u]=r[v];\n\t\t\t\tr[v]=u;\n\t\t\t}\n\t\t}\n\t}\n\tconst T& operator[](int\
    \ u)const{ return a[u]; }\n\tint root()const{ return rt; }\n\tint parent(int u)const{\
    \ return p[u]; }\n\tint left(int u)const{ return l[u]; }\n\tint right(int u)const{\
    \ return r[u]; }\n};\n"
  code: "/*\n\tCartesian tree\n\t\t\u6700\u5C0F\u306E\u8981\u7D20\u304C\u6839\u306B\
    \u306A\u308B\n\t\t\u9802\u70B9\u306E\u756A\u53F7\u3067 tie break\n\t\tparent,\
    \ left, right \u306F\u305D\u308C\u305E\u308C\u89AA, \u5DE6\u306E\u5B50, \u53F3\
    \u306E\u5B50\u306E\u9802\u70B9\u756A\u53F7 (\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F -1)\n\t\t\u9802\u70B9 u \u306B\u683C\u7D0D\u3055\u308C\u305F\u30C7\
    \u30FC\u30BF\u306F [u] \u3067\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u308B\n\n\t\u8A08\
    \u7B97\u91CF O(n)\n*/\n\ntemplate<class T>\nclass Cartesian_tree{\n\tvector<T>\
    \ a;\n\tint rt;\n\tvector<int> p,l,r;\npublic:\n\tCartesian_tree(const vector<T>&\
    \ a):a(a){\n\t\tint n=a.size();\n\t\trt=0;\n\t\tp.assign(n,-1);\n\t\tl.assign(n,-1);\n\
    \t\tr.assign(n,-1);\n\n\t\tfor(int u=1;u<n;u++){\n\t\t\tint v=u-1;\n\t\t\tbool\
    \ top=false;\n\t\t\twhile(a[v]>a[u]){\n\t\t\t\tif(p[v]==-1){\n\t\t\t\t\ttop=true;\n\
    \t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tv=p[v];\n\t\t\t}\n\t\t\tif(top){\n\t\t\t\t\
    p[v]=u;\n\t\t\t\tl[u]=v;\n\t\t\t\trt=u;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tp[u]=v;\n\
    \t\t\t\tif(r[v]!=-1) p[r[v]]=u;\n\t\t\t\tl[u]=r[v];\n\t\t\t\tr[v]=u;\n\t\t\t}\n\
    \t\t}\n\t}\n\tconst T& operator[](int u)const{ return a[u]; }\n\tint root()const{\
    \ return rt; }\n\tint parent(int u)const{ return p[u]; }\n\tint left(int u)const{\
    \ return l[u]; }\n\tint right(int u)const{ return r[u]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/Cartesian_tree.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/Cartesian_tree.hpp
layout: document
redirect_from:
- /library/library/data_structure/Cartesian_tree.hpp
- /library/library/data_structure/Cartesian_tree.hpp.html
title: library/data_structure/Cartesian_tree.hpp
---
