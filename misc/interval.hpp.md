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
  bundledCode: "#line 1 \"misc/interval.hpp\"\ntemplate<class T> struct interval{\n\
    \tT l,r;\n\tinterval(){}\n\tinterval(const T& l,const T& r):l(l),r(r){}\n\tbool\
    \ operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r);\
    \ }\n};\n\ntemplate<class T>\nint interval_scheduling(vector<interval<T>> I){\n\
    \tif(I.empty()) return 0;\n\tsort(I.begin(),I.end(),[](const interval<T>& a,const\
    \ interval<T>& b){\n\t\treturn make_pair(a.r,a.l)<make_pair(b.r,b.l);\n\t});\n\
    \tint res=1;\n\tT cur=I[0].l;\n\tfor(const auto& J:I) if(cur<=J.l) cur=J.r, res++;\n\
    \treturn res;\n}\n\n/*\n\t\u533A\u9593\u3092\u30DE\u30FC\u30B8\u3059\u308B\n\t\
    \t\u534A\u958B\u533A\u9593 [a, b), \u6574\u6570\u5EA7\u6A19\u3092\u60F3\u5B9A\n\
    */\ntemplate<class T>\nvector<interval<T>> interval_union(vector<interval<T>>\
    \ I){\n\tsort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){\
    \ return a.l<b.l; });\n\n\tint n=I.size();\n\tif(n==0) return {};\n\n\tvector<interval<T>>\
    \ res;\n\tT l=I[0].l,r=I[0].r;\n\tfor(int i=1;i<=n;i++){\n\t\tif(i==n || r<I[i].l){\n\
    \t\t\tres.emplace_back(l,r);\n\t\t\tif(i<n){\n\t\t\t\tl=I[i].l;\n\t\t\t\tr=I[i].r;\n\
    \t\t\t}\n\t\t}\n\t\telse if(r<I[i].r){\n\t\t\tr=I[i].r;\n\t\t}\n\t}\n\treturn\
    \ res;\n}\n"
  code: "template<class T> struct interval{\n\tT l,r;\n\tinterval(){}\n\tinterval(const\
    \ T& l,const T& r):l(l),r(r){}\n\tbool operator<(const interval& I)const{ return\
    \ make_tuple(l,r)<make_tuple(I.l,I.r); }\n};\n\ntemplate<class T>\nint interval_scheduling(vector<interval<T>>\
    \ I){\n\tif(I.empty()) return 0;\n\tsort(I.begin(),I.end(),[](const interval<T>&\
    \ a,const interval<T>& b){\n\t\treturn make_pair(a.r,a.l)<make_pair(b.r,b.l);\n\
    \t});\n\tint res=1;\n\tT cur=I[0].l;\n\tfor(const auto& J:I) if(cur<=J.l) cur=J.r,\
    \ res++;\n\treturn res;\n}\n\n/*\n\t\u533A\u9593\u3092\u30DE\u30FC\u30B8\u3059\
    \u308B\n\t\t\u534A\u958B\u533A\u9593 [a, b), \u6574\u6570\u5EA7\u6A19\u3092\u60F3\
    \u5B9A\n*/\ntemplate<class T>\nvector<interval<T>> interval_union(vector<interval<T>>\
    \ I){\n\tsort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){\
    \ return a.l<b.l; });\n\n\tint n=I.size();\n\tif(n==0) return {};\n\n\tvector<interval<T>>\
    \ res;\n\tT l=I[0].l,r=I[0].r;\n\tfor(int i=1;i<=n;i++){\n\t\tif(i==n || r<I[i].l){\n\
    \t\t\tres.emplace_back(l,r);\n\t\t\tif(i<n){\n\t\t\t\tl=I[i].l;\n\t\t\t\tr=I[i].r;\n\
    \t\t\t}\n\t\t}\n\t\telse if(r<I[i].r){\n\t\t\tr=I[i].r;\n\t\t}\n\t}\n\treturn\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/interval.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/interval.hpp
layout: document
redirect_from:
- /library/misc/interval.hpp
- /library/misc/interval.hpp.html
title: misc/interval.hpp
---
