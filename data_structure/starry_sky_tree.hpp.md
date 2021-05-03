---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html
    - https://rsk0315.hatenablog.com/entry/2019/06/21/174953
  bundledCode: "#line 1 \"data_structure/starry_sky_tree.hpp\"\n/*\n\tStarry Sky tree\n\
    \t\t\u533A\u9593 add \u3068\u533A\u9593 max \u53D6\u5F97\u304C\u3067\u304D\u308B\
    \ segment tree\n\t\tT \u306F int, lint, double \u306E\u3044\u305A\u308C\u304B\u3092\
    \u60F3\u5B9A\u3057\u3066\u3044\u308B\n\t\u53C2\u8003\n\t\thttps://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html\n\
    \t\thttps://rsk0315.hatenablog.com/entry/2019/06/21/174953\n*/\n\ntemplate<class\
    \ T>\nclass starry_sky_tree{\n\tint sz;\n\tvector<T> seg;\n\n\tvoid maintain(int\
    \ u){\n\t\tif(1<=u && u<sz){\n\t\t\tT mx=std::max(seg[2*u],seg[2*u+1]);\n\t\t\t\
    seg[u]+=mx;\n\t\t\tseg[2*u  ]-=mx;\n\t\t\tseg[2*u+1]-=mx;\n\t\t}\n\t}\n\tT max(int\
    \ l,int r,int a,int b,int u,T cum)const{\n\t\tif(b<=l || r<=a) return numeric_limits<T>::min();\n\
    \t\tif(l<=a && b<=r) return cum+seg[u];\n\t\tT lmax=max(l,r,a,(a+b)/2,2*u  ,cum+seg[u]);\n\
    \t\tT rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);\n\t\treturn std::max(lmax,rmax);\n\
    \t}\npublic:\n\tstarry_sky_tree(int n){\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,T());\n\
    \t}\n\tvoid add(int l,int r,const T& val){\n\t\tint a,b;\n\t\tfor(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1){ seg[a]+=val; a++; }\n\t\t\tif(b&1){ b--; seg[b]+=val; }\n\t\t\t\
    maintain((a-1)>>1);\n\t\t\tmaintain(b>>1);\n\t\t}\n\t\tfor(int u=a-1;u>=1;u>>=1)\
    \ maintain(u);\n\t\tfor(int u= b ;u>=1;u>>=1) maintain(u);\n\t}\n\tT max(int l,int\
    \ r)const{ return max(l,r,0,sz,1,0); }\n};\n"
  code: "/*\n\tStarry Sky tree\n\t\t\u533A\u9593 add \u3068\u533A\u9593 max \u53D6\
    \u5F97\u304C\u3067\u304D\u308B segment tree\n\t\tT \u306F int, lint, double \u306E\
    \u3044\u305A\u308C\u304B\u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\n\t\u53C2\u8003\
    \n\t\thttps://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html\n\
    \t\thttps://rsk0315.hatenablog.com/entry/2019/06/21/174953\n*/\n\ntemplate<class\
    \ T>\nclass starry_sky_tree{\n\tint sz;\n\tvector<T> seg;\n\n\tvoid maintain(int\
    \ u){\n\t\tif(1<=u && u<sz){\n\t\t\tT mx=std::max(seg[2*u],seg[2*u+1]);\n\t\t\t\
    seg[u]+=mx;\n\t\t\tseg[2*u  ]-=mx;\n\t\t\tseg[2*u+1]-=mx;\n\t\t}\n\t}\n\tT max(int\
    \ l,int r,int a,int b,int u,T cum)const{\n\t\tif(b<=l || r<=a) return numeric_limits<T>::min();\n\
    \t\tif(l<=a && b<=r) return cum+seg[u];\n\t\tT lmax=max(l,r,a,(a+b)/2,2*u  ,cum+seg[u]);\n\
    \t\tT rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);\n\t\treturn std::max(lmax,rmax);\n\
    \t}\npublic:\n\tstarry_sky_tree(int n){\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,T());\n\
    \t}\n\tvoid add(int l,int r,const T& val){\n\t\tint a,b;\n\t\tfor(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1){ seg[a]+=val; a++; }\n\t\t\tif(b&1){ b--; seg[b]+=val; }\n\t\t\t\
    maintain((a-1)>>1);\n\t\t\tmaintain(b>>1);\n\t\t}\n\t\tfor(int u=a-1;u>=1;u>>=1)\
    \ maintain(u);\n\t\tfor(int u= b ;u>=1;u>>=1) maintain(u);\n\t}\n\tT max(int l,int\
    \ r)const{ return max(l,r,0,sz,1,0); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/starry_sky_tree.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/starry_sky_tree.hpp
layout: document
redirect_from:
- /library/data_structure/starry_sky_tree.hpp
- /library/data_structure/starry_sky_tree.hpp.html
title: data_structure/starry_sky_tree.hpp
---
