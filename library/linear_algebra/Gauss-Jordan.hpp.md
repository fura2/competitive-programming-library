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
  bundledCode: "#line 1 \"library/linear_algebra/Gauss-Jordan.hpp\"\nvector<double>\
    \ Gauss_Jordan(const matrix<double>& A,const vector<double>& b){\n\tconst double\
    \ EPS=1e-8;\n\n\tassert(A.h()==A.w() && A.w()==b.size());\n\n\tint n=A.h();\n\t\
    matrix<double> B(n,n+1);\n\trep(i,n){\n\t\trep(j,n) B[i][j]=A[i][j];\n\t\tB[i][n]=b[i];\n\
    \t}\n\n\trep(i,n){\n\t\tint pivot=i;\n\t\tfor(int j=i;j<n;j++) if(abs(B[j][i])>abs(B[pivot][i]))\
    \ pivot=j;\n\t\trep(j,n+1) swap(B[i][j],B[pivot][j]);\n\t\tassert(abs(B[i][i])>EPS);\n\
    \t\tfor(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];\n\t\trep(j,n) if(i!=j) for(int k=i+1;k<=n;k++)\
    \ B[j][k]-=B[j][i]*B[i][k];\n\t}\n\n\tvector<double> x(n);\n\trep(i,n) x[i]=B[i][n];\n\
    \treturn x;\n}\n"
  code: "vector<double> Gauss_Jordan(const matrix<double>& A,const vector<double>&\
    \ b){\n\tconst double EPS=1e-8;\n\n\tassert(A.h()==A.w() && A.w()==b.size());\n\
    \n\tint n=A.h();\n\tmatrix<double> B(n,n+1);\n\trep(i,n){\n\t\trep(j,n) B[i][j]=A[i][j];\n\
    \t\tB[i][n]=b[i];\n\t}\n\n\trep(i,n){\n\t\tint pivot=i;\n\t\tfor(int j=i;j<n;j++)\
    \ if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;\n\t\trep(j,n+1) swap(B[i][j],B[pivot][j]);\n\
    \t\tassert(abs(B[i][i])>EPS);\n\t\tfor(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];\n\
    \t\trep(j,n) if(i!=j) for(int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];\n\t}\n\
    \n\tvector<double> x(n);\n\trep(i,n) x[i]=B[i][n];\n\treturn x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/linear_algebra/Gauss-Jordan.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linear_algebra/Gauss-Jordan.hpp
layout: document
redirect_from:
- /library/library/linear_algebra/Gauss-Jordan.hpp
- /library/library/linear_algebra/Gauss-Jordan.hpp.html
title: library/linear_algebra/Gauss-Jordan.hpp
---
