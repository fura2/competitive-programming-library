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
  bundledCode: "#line 1 \"library/misc/inversion_number.hpp\"\ntemplate<class T>\n\
    long long inversion_number(const vector<T>& a){\n\tauto X=a;\n\tsort(X.begin(),X.end());\n\
    \tX.erase(unique(X.begin(),X.end()),X.end());\n\n\tlong long res=0;\n\tFenwick_tree<int>\
    \ F(X.size());\n\trep(i,a.size()){\n\t\tint x=lower_bound(X.begin(),X.end(),a[i])-X.begin();\n\
    \t\tres+=F.sum(x+1,X.size());\n\t\tF.add(x,1);\n\t}\n\treturn res;\n}\n"
  code: "template<class T>\nlong long inversion_number(const vector<T>& a){\n\tauto\
    \ X=a;\n\tsort(X.begin(),X.end());\n\tX.erase(unique(X.begin(),X.end()),X.end());\n\
    \n\tlong long res=0;\n\tFenwick_tree<int> F(X.size());\n\trep(i,a.size()){\n\t\
    \tint x=lower_bound(X.begin(),X.end(),a[i])-X.begin();\n\t\tres+=F.sum(x+1,X.size());\n\
    \t\tF.add(x,1);\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/inversion_number.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/inversion_number.hpp
layout: document
redirect_from:
- /library/library/misc/inversion_number.hpp
- /library/library/misc/inversion_number.hpp.html
title: library/misc/inversion_number.hpp
---
