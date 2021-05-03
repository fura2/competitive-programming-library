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
  bundledCode: "#line 1 \"linear_algebra/matrix.hpp\"\ntemplate<class R>\nclass matrix{\n\
    \tvector<vector<R>> a;\npublic:\n\tmatrix(int n):a(n,vector<R>(n)){}\n\tmatrix(int\
    \ m,int n):a(m,vector<R>(n)){}\n\n\tmatrix& operator+=(const matrix& A){\n\t\t\
    assert(h()==A.h() && w()==A.w());\n\t\tint m=h(),n=w();\n\t\trep(i,m) rep(j,n)\
    \ (*this)[i][j]+=A[i][j];\n\t\treturn *this;\n\t}\n\tmatrix& operator-=(const\
    \ matrix& A){\n\t\tassert(h()==A.h() && w()==A.w());\n\t\tint m=h(),n=w();\n\t\
    \trep(i,m) rep(j,n) (*this)[i][j]-=A[i][j];\n\t\treturn *this;\n\t}\n\tmatrix&\
    \ operator*=(const matrix& A){\n\t\tassert(w()==A.h());\n\t\tint m=h(),n=w(),l=A.w();\n\
    \t\tmatrix B(m,l);\n\t\trep(i,m) rep(j,l) rep(k,n) B[i][j]+=(*this)[i][k]*A[k][j];\n\
    \t\tswap(*this,B);\n\t\treturn *this;\n\t}\n\tmatrix operator+(const matrix& A)const{\
    \ return matrix(*this)+=A; }\n\tmatrix operator-(const matrix& A)const{ return\
    \ matrix(*this)-=A; }\n\tmatrix operator*(const matrix& A)const{ return matrix(*this)*=A;\
    \ }\n\tconst vector<R>& operator[](int i)const{ return a[i]; }\n\tvector<R>& operator[](int\
    \ i){ return a[i]; }\n\n\tvector<R> operator*(const vector<R>& v)const{\n\t\t\
    assert(w()==v.size());\n\t\tint m=h(),n=w();\n\t\tvector<R> res(m);\n\t\trep(i,m)\
    \ rep(j,n) res[i]+=(*this)[i][j]*v[j];\n\t\treturn res;\n\t}\n\n\tint h()const{\
    \ return a.size(); }\n\tint w()const{ return a.empty()?0:a[0].size(); }\n\n\t\
    static matrix identity(int n){\n\t\tmatrix I(n);\n\t\trep(i,n) I[i][i]=R{1};\n\
    \t\treturn I;\n\t}\n};\n\ntemplate<class R>\nmatrix<R> pow(matrix<R> A,long long\
    \ k){\n\tassert(A.h()==A.w());\n\tmatrix<R> B=matrix<R>::identity(A.h());\n\t\
    for(;k>0;k>>=1){\n\t\tif(k&1) B*=A;\n\t\tA*=A;\n\t}\n\treturn B;\n}\n"
  code: "template<class R>\nclass matrix{\n\tvector<vector<R>> a;\npublic:\n\tmatrix(int\
    \ n):a(n,vector<R>(n)){}\n\tmatrix(int m,int n):a(m,vector<R>(n)){}\n\n\tmatrix&\
    \ operator+=(const matrix& A){\n\t\tassert(h()==A.h() && w()==A.w());\n\t\tint\
    \ m=h(),n=w();\n\t\trep(i,m) rep(j,n) (*this)[i][j]+=A[i][j];\n\t\treturn *this;\n\
    \t}\n\tmatrix& operator-=(const matrix& A){\n\t\tassert(h()==A.h() && w()==A.w());\n\
    \t\tint m=h(),n=w();\n\t\trep(i,m) rep(j,n) (*this)[i][j]-=A[i][j];\n\t\treturn\
    \ *this;\n\t}\n\tmatrix& operator*=(const matrix& A){\n\t\tassert(w()==A.h());\n\
    \t\tint m=h(),n=w(),l=A.w();\n\t\tmatrix B(m,l);\n\t\trep(i,m) rep(j,l) rep(k,n)\
    \ B[i][j]+=(*this)[i][k]*A[k][j];\n\t\tswap(*this,B);\n\t\treturn *this;\n\t}\n\
    \tmatrix operator+(const matrix& A)const{ return matrix(*this)+=A; }\n\tmatrix\
    \ operator-(const matrix& A)const{ return matrix(*this)-=A; }\n\tmatrix operator*(const\
    \ matrix& A)const{ return matrix(*this)*=A; }\n\tconst vector<R>& operator[](int\
    \ i)const{ return a[i]; }\n\tvector<R>& operator[](int i){ return a[i]; }\n\n\t\
    vector<R> operator*(const vector<R>& v)const{\n\t\tassert(w()==v.size());\n\t\t\
    int m=h(),n=w();\n\t\tvector<R> res(m);\n\t\trep(i,m) rep(j,n) res[i]+=(*this)[i][j]*v[j];\n\
    \t\treturn res;\n\t}\n\n\tint h()const{ return a.size(); }\n\tint w()const{ return\
    \ a.empty()?0:a[0].size(); }\n\n\tstatic matrix identity(int n){\n\t\tmatrix I(n);\n\
    \t\trep(i,n) I[i][i]=R{1};\n\t\treturn I;\n\t}\n};\n\ntemplate<class R>\nmatrix<R>\
    \ pow(matrix<R> A,long long k){\n\tassert(A.h()==A.w());\n\tmatrix<R> B=matrix<R>::identity(A.h());\n\
    \tfor(;k>0;k>>=1){\n\t\tif(k&1) B*=A;\n\t\tA*=A;\n\t}\n\treturn B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linear_algebra/matrix.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linear_algebra/matrix.hpp
layout: document
redirect_from:
- /library/linear_algebra/matrix.hpp
- /library/linear_algebra/matrix.hpp.html
title: linear_algebra/matrix.hpp
---
