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
  bundledCode: "#line 1 \"library/monoid/monoid.hpp\"\n// \u3069\u306E\u30E2\u30CE\
    \u30A4\u30C9\u306B\u3064\u3044\u3066\u3082, \u5F15\u6570\u3092\u6301\u305F\u306A\
    \u3044\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u304C\u5358\u4F4D\u5143\u3092\
    \u751F\u6210\u3059\u308B\u3082\u306E\u3068\u3059\u308B\n\n// \u53F0\u96C6\u5408\
    \ : T1 \u306E\u5143\u3068 T2 \u306E\u5143\u306E\u30DA\u30A2\u5168\u4F53\n// \u7A4D\
    \ : min (\u8F9E\u66F8\u9806)\n// \u4EEE\u5B9A : i = 1, 2 \u306B\u5BFE\u3057\u3066\
    , Ti \u4E0A\u306E\u5168\u9806\u5E8F\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u3066\
    \ numeric_limits<Ti>::max() \u304C\u6700\u5927\u5143\n\ntemplate<class T> class\
    \ min_monoid;\ntemplate<class T1,class T2>\nclass min_monoid<pair<T1,T2>>{\n\t\
    pair<T1,T2> a;\npublic:\n\tmin_monoid():a(numeric_limits<T1>::max(),numeric_limits<T2>::max()){}\n\
    \tmin_monoid(const pair<T1,T2>& val):a(val){}\n\tmin_monoid operator*(const min_monoid&\
    \ x)const{\n\t\treturn min(a,x.a);\n\t}\n\tpair<T1,T2>& get(){ return a; }\n\t\
    const pair<T1,T2>& get()const{ return a; }\n};\n\n// \u53F0\u96C6\u5408 : T \u306E\
    \u5143\u5168\u4F53\n// \u7A4D : +\n// \u4EEE\u5B9A : T \u4E0A\u306E\u7D50\u5408\
    \u7684\u306A\u4E8C\u9805\u6F14\u7B97 + \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\
    \u3066 T() \u304C\u52A0\u6CD5\u5358\u4F4D\u5143\n\ntemplate<class T>\nclass add_monoid{\n\
    \tT a;\npublic:\n\tadd_monoid():a(){}\n\tadd_monoid(const T& val):a(val){}\n\t\
    add_monoid operator*(const add_monoid& x)const{\n\t\treturn a+x.a;\n\t}\n\tT&\
    \ get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n\n// \u53F0\u96C6\
    \u5408 : T \u306E\u5143\u5168\u4F53\n// \u7A4D : bitwise OR\n// \u4EEE\u5B9A :\
    \ T \u306F int \u307E\u305F\u306F lint \u3092\u60F3\u5B9A\n\ntemplate<class T>\n\
    class or_monoid{\n\tT a;\npublic:\n\tor_monoid():a(){}\n\tor_monoid(const T& val):a(val){}\n\
    \tor_monoid operator*(const or_monoid& x)const{\n\t\treturn a|x.a;\n\t}\n\tT&\
    \ get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n\n// \u53F0\u96C6\
    \u5408 : T \u306E\u5143\u306E\u30BD\u30FC\u30C8\u3055\u308C\u305F\u5217\u5168\u4F53\
    \n// \u7A4D : \u5217\u306E\u30DE\u30FC\u30B8\n// \u4EEE\u5B9A : T \u4E0A\u306E\
    \u5168\u9806\u5E8F\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\n\ntemplate<class\
    \ T>\nclass sequence_monoid{\n\tvector<T> a;\npublic:\n\tsequence_monoid(){}\n\
    \tsequence_monoid(const T& val):a(1,val){}\n\tsequence_monoid(const vector<T>&\
    \ x):a(x){\n\t\tsort(a.begin(),a.end());\n\t}\n\tsequence_monoid operator*(const\
    \ sequence_monoid& x)const{\n\t\tvector<T> res;\n\t\tmerge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));\n\
    \t\treturn res;\n\t}\n};\n\n// \u53F0\u96C6\u5408 : T \u306E\u5143\u306E\u30BD\
    \u30FC\u30C8\u3055\u308C\u305F\u5217\u3068\u305D\u306E\u7D2F\u7A4D\u548C\u306E\
    \u30DA\u30A2\u5168\u4F53\n// \u7A4D : \u5217\u306E\u30DE\u30FC\u30B8\n// \u4EEE\
    \u5B9A : T \u4E0A\u306E\u5168\u9806\u5E8F\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\
    \u308B\n//       T \u4E0A\u306E\u7D50\u5408\u7684\u306A\u4E8C\u9805\u6F14\u7B97\
    \ + \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u3066 T() \u304C\u52A0\u6CD5\u5358\
    \u4F4D\u5143\n\ntemplate<class T>\nclass sequence_sum_monoid{\n\tvector<T> a,cum;\n\
    public:\n\tsequence_sum_monoid():cum(1){}\n\tsequence_sum_monoid(const T& val):a(1,val),cum{T(),val}{}\n\
    \tsequence_sum_monoid(const vector<T>& x):a(x),cum(x.size()+1){\n\t\tsort(a.begin(),a.end());\n\
    \t\trep(i,x.size()) cum[i+1]=cum[i]+a[i];\n\t}\n\tsequence_sum_monoid operator*(const\
    \ sequence_sum_monoid& x)const{\n\t\tvector<T> res;\n\t\tmerge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));\n\
    \t\treturn res;\n\t}\n};\n\n// \u53F0\u96C6\u5408 : T \u306E\u5143\u3092\u4FC2\
    \u6570\u3068\u3059\u308B\u4E00\u6B21\u95A2\u6570\u5168\u4F53\n// \u7A4D : \u4E00\
    \u6B21\u95A2\u6570\u306E\u5408\u6210\n//      f * g = g \u25CB f, \u5408\u6210\
    \u306E\u5411\u304D\u306B\u6CE8\u610F\n//      (ax+b) * (cx+d) = c(ax+b)+d = cax\
    \ + (cb+d)\n// \u4EEE\u5B9A : T \u306F\u74B0 (\u975E\u53EF\u63DB\u3067\u3082\u3088\
    \u3044) \u3067\u3042\u3063\u3066 T() \u304C\u52A0\u6CD5\u5358\u4F4D\u5143, T(1)\
    \ \u304C\u4E57\u6CD5\u5358\u4F4D\u5143\n\ntemplate<class T>\nclass affine_monoid{\n\
    \tT a,b;\npublic:\n\taffine_monoid():a(1),b(){}\n\taffine_monoid(const T& a,const\
    \ T& b):a(a),b(b){}\n\taffine_monoid(const pair<T,T>& val):a(val.first),b(val.second){}\n\
    \taffine_monoid operator*(const affine_monoid& x)const{\n\t\treturn {x.a*a,x.a*b+x.b};\n\
    \t}\n\tpair<T&,T&> get(){ return {a,b}; }\n\tpair<const T&,const T&> get()const{\
    \ return {a,b}; }\n\tT eval(const T& x)const{ return a*x+b; }\n};\n\n// \u53F0\
    \u96C6\u5408 : {0, 1, ..., N-1} \u306E\u81EA\u5DF1\u6E96\u540C\u578B\u5168\u4F53\
    \ (N \u306F\u660E\u793A\u7684\u306F\u6307\u5B9A\u3057\u306A\u3044)\n// \u7A4D\
    \ : \u5199\u50CF\u306E\u5408\u6210\n//       f * g = f \u25CB g\n// \u4EEE\u5B9A\
    \ : \u7279\u306B\u306A\u3057\n// \u5099\u8003 : N \u304C\u7570\u306A\u308B\u5199\
    \u50CF\u3069\u3046\u3057\u306E\u5408\u6210\u3082\u8A08\u7B97\u3067\u304D\u308B\
    \n//       \u305D\u306E\u5834\u5408\u306B\u306F\u8DB3\u308A\u306A\u3044\u90E8\u5206\
    \u306F\u6052\u7B49\u5199\u50CF\u306B\u306A\u3063\u3066\u3044\u308B\u3068\u898B\
    \u306A\u3059\n\nclass endomorphism_monoid{\n\tvector<int> f;\npublic:\n\tendomorphism_monoid(){}\n\
    \tendomorphism_monoid(const vector<int>& f):f(f){}\n\tendomorphism_monoid operator*(const\
    \ endomorphism_monoid& a)const{\n\t\tint n=f.size(),m=a.f.size();\n\t\tint k=max(n,m);\n\
    \t\tvector<int> res(k);\n\t\trep(i,k){\n\t\t\tint x=(i<m?a.f[i]:i);\n\t\t\tres[i]=(x<n?f[x]:x);\n\
    \t\t}\n\t\treturn res;\n\t}\n\tint operator[](int i)const{ return i<f.size()?f[i]:i;\
    \ }\n};\n"
  code: "// \u3069\u306E\u30E2\u30CE\u30A4\u30C9\u306B\u3064\u3044\u3066\u3082, \u5F15\
    \u6570\u3092\u6301\u305F\u306A\u3044\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u304C\u5358\u4F4D\u5143\u3092\u751F\u6210\u3059\u308B\u3082\u306E\u3068\u3059\
    \u308B\n\n// \u53F0\u96C6\u5408 : T1 \u306E\u5143\u3068 T2 \u306E\u5143\u306E\u30DA\
    \u30A2\u5168\u4F53\n// \u7A4D : min (\u8F9E\u66F8\u9806)\n// \u4EEE\u5B9A : i\
    \ = 1, 2 \u306B\u5BFE\u3057\u3066, Ti \u4E0A\u306E\u5168\u9806\u5E8F\u304C\u5B9A\
    \u7FA9\u3055\u308C\u3066\u3044\u3066 numeric_limits<Ti>::max() \u304C\u6700\u5927\
    \u5143\n\ntemplate<class T> class min_monoid;\ntemplate<class T1,class T2>\nclass\
    \ min_monoid<pair<T1,T2>>{\n\tpair<T1,T2> a;\npublic:\n\tmin_monoid():a(numeric_limits<T1>::max(),numeric_limits<T2>::max()){}\n\
    \tmin_monoid(const pair<T1,T2>& val):a(val){}\n\tmin_monoid operator*(const min_monoid&\
    \ x)const{\n\t\treturn min(a,x.a);\n\t}\n\tpair<T1,T2>& get(){ return a; }\n\t\
    const pair<T1,T2>& get()const{ return a; }\n};\n\n// \u53F0\u96C6\u5408 : T \u306E\
    \u5143\u5168\u4F53\n// \u7A4D : +\n// \u4EEE\u5B9A : T \u4E0A\u306E\u7D50\u5408\
    \u7684\u306A\u4E8C\u9805\u6F14\u7B97 + \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\
    \u3066 T() \u304C\u52A0\u6CD5\u5358\u4F4D\u5143\n\ntemplate<class T>\nclass add_monoid{\n\
    \tT a;\npublic:\n\tadd_monoid():a(){}\n\tadd_monoid(const T& val):a(val){}\n\t\
    add_monoid operator*(const add_monoid& x)const{\n\t\treturn a+x.a;\n\t}\n\tT&\
    \ get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n\n// \u53F0\u96C6\
    \u5408 : T \u306E\u5143\u5168\u4F53\n// \u7A4D : bitwise OR\n// \u4EEE\u5B9A :\
    \ T \u306F int \u307E\u305F\u306F lint \u3092\u60F3\u5B9A\n\ntemplate<class T>\n\
    class or_monoid{\n\tT a;\npublic:\n\tor_monoid():a(){}\n\tor_monoid(const T& val):a(val){}\n\
    \tor_monoid operator*(const or_monoid& x)const{\n\t\treturn a|x.a;\n\t}\n\tT&\
    \ get(){ return a; }\n\tconst T& get()const{ return a; }\n};\n\n// \u53F0\u96C6\
    \u5408 : T \u306E\u5143\u306E\u30BD\u30FC\u30C8\u3055\u308C\u305F\u5217\u5168\u4F53\
    \n// \u7A4D : \u5217\u306E\u30DE\u30FC\u30B8\n// \u4EEE\u5B9A : T \u4E0A\u306E\
    \u5168\u9806\u5E8F\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\n\ntemplate<class\
    \ T>\nclass sequence_monoid{\n\tvector<T> a;\npublic:\n\tsequence_monoid(){}\n\
    \tsequence_monoid(const T& val):a(1,val){}\n\tsequence_monoid(const vector<T>&\
    \ x):a(x){\n\t\tsort(a.begin(),a.end());\n\t}\n\tsequence_monoid operator*(const\
    \ sequence_monoid& x)const{\n\t\tvector<T> res;\n\t\tmerge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));\n\
    \t\treturn res;\n\t}\n};\n\n// \u53F0\u96C6\u5408 : T \u306E\u5143\u306E\u30BD\
    \u30FC\u30C8\u3055\u308C\u305F\u5217\u3068\u305D\u306E\u7D2F\u7A4D\u548C\u306E\
    \u30DA\u30A2\u5168\u4F53\n// \u7A4D : \u5217\u306E\u30DE\u30FC\u30B8\n// \u4EEE\
    \u5B9A : T \u4E0A\u306E\u5168\u9806\u5E8F\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\
    \u308B\n//       T \u4E0A\u306E\u7D50\u5408\u7684\u306A\u4E8C\u9805\u6F14\u7B97\
    \ + \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u3066 T() \u304C\u52A0\u6CD5\u5358\
    \u4F4D\u5143\n\ntemplate<class T>\nclass sequence_sum_monoid{\n\tvector<T> a,cum;\n\
    public:\n\tsequence_sum_monoid():cum(1){}\n\tsequence_sum_monoid(const T& val):a(1,val),cum{T(),val}{}\n\
    \tsequence_sum_monoid(const vector<T>& x):a(x),cum(x.size()+1){\n\t\tsort(a.begin(),a.end());\n\
    \t\trep(i,x.size()) cum[i+1]=cum[i]+a[i];\n\t}\n\tsequence_sum_monoid operator*(const\
    \ sequence_sum_monoid& x)const{\n\t\tvector<T> res;\n\t\tmerge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));\n\
    \t\treturn res;\n\t}\n};\n\n// \u53F0\u96C6\u5408 : T \u306E\u5143\u3092\u4FC2\
    \u6570\u3068\u3059\u308B\u4E00\u6B21\u95A2\u6570\u5168\u4F53\n// \u7A4D : \u4E00\
    \u6B21\u95A2\u6570\u306E\u5408\u6210\n//      f * g = g \u25CB f, \u5408\u6210\
    \u306E\u5411\u304D\u306B\u6CE8\u610F\n//      (ax+b) * (cx+d) = c(ax+b)+d = cax\
    \ + (cb+d)\n// \u4EEE\u5B9A : T \u306F\u74B0 (\u975E\u53EF\u63DB\u3067\u3082\u3088\
    \u3044) \u3067\u3042\u3063\u3066 T() \u304C\u52A0\u6CD5\u5358\u4F4D\u5143, T(1)\
    \ \u304C\u4E57\u6CD5\u5358\u4F4D\u5143\n\ntemplate<class T>\nclass affine_monoid{\n\
    \tT a,b;\npublic:\n\taffine_monoid():a(1),b(){}\n\taffine_monoid(const T& a,const\
    \ T& b):a(a),b(b){}\n\taffine_monoid(const pair<T,T>& val):a(val.first),b(val.second){}\n\
    \taffine_monoid operator*(const affine_monoid& x)const{\n\t\treturn {x.a*a,x.a*b+x.b};\n\
    \t}\n\tpair<T&,T&> get(){ return {a,b}; }\n\tpair<const T&,const T&> get()const{\
    \ return {a,b}; }\n\tT eval(const T& x)const{ return a*x+b; }\n};\n\n// \u53F0\
    \u96C6\u5408 : {0, 1, ..., N-1} \u306E\u81EA\u5DF1\u6E96\u540C\u578B\u5168\u4F53\
    \ (N \u306F\u660E\u793A\u7684\u306F\u6307\u5B9A\u3057\u306A\u3044)\n// \u7A4D\
    \ : \u5199\u50CF\u306E\u5408\u6210\n//       f * g = f \u25CB g\n// \u4EEE\u5B9A\
    \ : \u7279\u306B\u306A\u3057\n// \u5099\u8003 : N \u304C\u7570\u306A\u308B\u5199\
    \u50CF\u3069\u3046\u3057\u306E\u5408\u6210\u3082\u8A08\u7B97\u3067\u304D\u308B\
    \n//       \u305D\u306E\u5834\u5408\u306B\u306F\u8DB3\u308A\u306A\u3044\u90E8\u5206\
    \u306F\u6052\u7B49\u5199\u50CF\u306B\u306A\u3063\u3066\u3044\u308B\u3068\u898B\
    \u306A\u3059\n\nclass endomorphism_monoid{\n\tvector<int> f;\npublic:\n\tendomorphism_monoid(){}\n\
    \tendomorphism_monoid(const vector<int>& f):f(f){}\n\tendomorphism_monoid operator*(const\
    \ endomorphism_monoid& a)const{\n\t\tint n=f.size(),m=a.f.size();\n\t\tint k=max(n,m);\n\
    \t\tvector<int> res(k);\n\t\trep(i,k){\n\t\t\tint x=(i<m?a.f[i]:i);\n\t\t\tres[i]=(x<n?f[x]:x);\n\
    \t\t}\n\t\treturn res;\n\t}\n\tint operator[](int i)const{ return i<f.size()?f[i]:i;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/monoid/monoid.hpp
  requiredBy: []
  timestamp: '2021-05-10 21:01:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/monoid/monoid.hpp
layout: document
redirect_from:
- /library/library/monoid/monoid.hpp
- /library/library/monoid/monoid.hpp.html
title: library/monoid/monoid.hpp
---
