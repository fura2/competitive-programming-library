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
  bundledCode: "#line 1 \"library/mint/det.hpp\"\nmint det(matrix<mint> A){\n\tassert(A.h()==A.w());\n\
    \tint n=A.h();\n\n\tint sgn=1;\n\trep(i,n){\n\t\tint piv;\n\t\tfor(piv=i;piv<n;piv++)\
    \ if(A[piv][i].to_int()!=0) break;\n\t\tif(piv==n) return 0;\n\t\tif(piv!=i){\n\
    \t\t\trep(j,n) swap(A[i][j],A[piv][j]);\n\t\t\tsgn*=-1;\n\t\t}\n\t\tfor(int k=i+1;k<n;k++)\
    \ if(A[k][i].to_int()!=0) {\n\t\t\tmint c=A[k][i]/A[i][i];\n\t\t\tfor(int j=i;j<n;j++)\
    \ A[k][j]-=c*A[i][j];\n\t\t}\n\t}\n\n\tmint res=sgn;\n\trep(i,n) res*=A[i][i];\n\
    \treturn res;\n}\n"
  code: "mint det(matrix<mint> A){\n\tassert(A.h()==A.w());\n\tint n=A.h();\n\n\t\
    int sgn=1;\n\trep(i,n){\n\t\tint piv;\n\t\tfor(piv=i;piv<n;piv++) if(A[piv][i].to_int()!=0)\
    \ break;\n\t\tif(piv==n) return 0;\n\t\tif(piv!=i){\n\t\t\trep(j,n) swap(A[i][j],A[piv][j]);\n\
    \t\t\tsgn*=-1;\n\t\t}\n\t\tfor(int k=i+1;k<n;k++) if(A[k][i].to_int()!=0) {\n\t\
    \t\tmint c=A[k][i]/A[i][i];\n\t\t\tfor(int j=i;j<n;j++) A[k][j]-=c*A[i][j];\n\t\
    \t}\n\t}\n\n\tmint res=sgn;\n\trep(i,n) res*=A[i][i];\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/mint/det.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mint/det.hpp
layout: document
redirect_from:
- /library/library/mint/det.hpp
- /library/library/mint/det.hpp.html
title: library/mint/det.hpp
---
