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
  bundledCode: "#line 1 \"library/misc/permutation.hpp\"\nclass permutation{\n\tvector<int>\
    \ f;\npublic:\n\tpermutation(){}\n\tpermutation(int n){\n\t\tf.resize(n);\n\t\t\
    iota(f.begin(),f.end(),0);\n\t}\n\tpermutation(const vector<int>& p):f(p){}\n\n\
    \tpermutation operator*(const permutation& p)const{\n\t\tint n=f.size();\n\t\t\
    permutation res(n);\n\t\trep(i,n) res.f[i]=f[p[i]];\n\t\treturn res;\n\t}\n\t\
    int operator[](int i)const{ return f[i]; }\n\n\tint size()const{ return f.size();\
    \ }\n\n\tvoid swap(int i,int j){ std::swap(f[i],f[j]); }\n\n\tfriend permutation\
    \ inverse(const permutation& p){\n\t\tint n=p.f.size();\n\t\tpermutation res(n);\n\
    \t\trep(i,n) res.f[p.f[i]]=i;\n\t\treturn res;\n\t}\n};\n\npermutation pow(permutation\
    \ p,long long k){\n\tpermutation res(p.size());\n\tfor(;k>0;k>>=1,p=p*p) if(k&1)\
    \ res=res*p;\n\treturn res;\n}\n\nlong long inversion_number(const permutation&\
    \ p){\n\tint n=p.size();\n\tlong long res=0;\n\tFenwick_tree<int> F(n);\n\trep(i,n){\
    \ res+=F.sum(p[i]+1,n); F.add(p[i],1); }\n\treturn res;\n}\n"
  code: "class permutation{\n\tvector<int> f;\npublic:\n\tpermutation(){}\n\tpermutation(int\
    \ n){\n\t\tf.resize(n);\n\t\tiota(f.begin(),f.end(),0);\n\t}\n\tpermutation(const\
    \ vector<int>& p):f(p){}\n\n\tpermutation operator*(const permutation& p)const{\n\
    \t\tint n=f.size();\n\t\tpermutation res(n);\n\t\trep(i,n) res.f[i]=f[p[i]];\n\
    \t\treturn res;\n\t}\n\tint operator[](int i)const{ return f[i]; }\n\n\tint size()const{\
    \ return f.size(); }\n\n\tvoid swap(int i,int j){ std::swap(f[i],f[j]); }\n\n\t\
    friend permutation inverse(const permutation& p){\n\t\tint n=p.f.size();\n\t\t\
    permutation res(n);\n\t\trep(i,n) res.f[p.f[i]]=i;\n\t\treturn res;\n\t}\n};\n\
    \npermutation pow(permutation p,long long k){\n\tpermutation res(p.size());\n\t\
    for(;k>0;k>>=1,p=p*p) if(k&1) res=res*p;\n\treturn res;\n}\n\nlong long inversion_number(const\
    \ permutation& p){\n\tint n=p.size();\n\tlong long res=0;\n\tFenwick_tree<int>\
    \ F(n);\n\trep(i,n){ res+=F.sum(p[i]+1,n); F.add(p[i],1); }\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/permutation.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/permutation.hpp
layout: document
redirect_from:
- /library/library/misc/permutation.hpp
- /library/library/misc/permutation.hpp.html
title: library/misc/permutation.hpp
---
