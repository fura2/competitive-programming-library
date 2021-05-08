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
  bundledCode: "#line 1 \"library/data_structure/segment_tree.hpp\"\n/*\n\t\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n\t\t(M, *) : \u30E2\u30CE\u30A4\u30C9\n\t\tx_1, ...,\
    \ x_n : M \u306E\u5143\u306E\u5217\n\n\t\tupdate(i,x) : x_i \u306E\u5024\u3092\
    \ x \u306B\u66F8\u304D\u63DB\u3048\u308B.\n\t\tproduct(l,r) : x_l * x_{l+1} *\
    \ ... * x_{r-1} \u3092\u6C42\u3081\u308B.\n\n\t\toperate(l,r,f) : f(x_l * x_{l+1}\
    \ * ... * x_{r-1}) \u3092\u6C42\u3081\u308B.\n\t\t\t\u3053\u3053\u3067, (N, *)\
    \ \u306F\u30E2\u30CE\u30A4\u30C9, f M \u2192 N \u306F\u6E96\u540C\u578B.\n\t\t\
    \toperate<N>(l,r,[&](M& x)->N{\n\t\t\t\treturn ...;\n\t\t\t});\n\t\t\t\u306E\u3088\
    \u3046\u306B\u4F7F\u3046.\n\t\t\tx_l * x_{l+1} * ... * x_{r-1} \u3092\u967D\u306B\
    \u6C42\u3081\u308B\u3068\u8A08\u7B97\u91CF\u304C\u304B\u304B\u308A\u3059\u304E\
    \u308B\u304C\n\t\t\tN \u306B\u304A\u3051\u308B\u7A4D\u3068 f \u306E\u4F5C\u7528\
    \u306E\u8A08\u7B97\u91CF\u304C\u3069\u3061\u3089\u3082\u5C0F\u3055\u3044\u3068\
    \u304D\u306B\u6709\u52B9.\n\n\tmax_right(l,f) :\n\t\t\u4EEE\u5B9A\n\t\t\t0 <=\
    \ l <= n\n\t\t\tf : M -> bool \u306F f(e) = true \u3092\u307F\u305F\u3059\n\t\t\
    \u6B21\u306E\u4E8C\u3064\u306E\u6761\u4EF6\u3092\u307F\u305F\u3059 r (l <= r <=\
    \ n) \u3092\u4E00\u3064\u6C42\u3081\u308B.\n\t\t- r = l \u307E\u305F\u306F f(x_l\
    \ * x_{l+1} * ... * x_{r-1}) = true\n\t\t- r = n \u307E\u305F\u306F f(x_l * x_{l+1}\
    \ * ... * x_r) = false\n\t\tf \u306E\u8A08\u7B97\u306B\u304B\u304B\u308B\u6642\
    \u9593\u3092 O(1) \u3068\u3057\u3066, \u8A08\u7B97\u91CF\u306F O(log n).\n\tmin_left(r,f)\
    \ :\n\t\t\u4EEE\u5B9A\n\t\t\t0 <= r <= n\n\t\t\tf : M -> bool \u306F f(e) = true\
    \ \u3092\u307F\u305F\u3059\n\t\t\u6B21\u306E\u4E8C\u3064\u306E\u6761\u4EF6\u3092\
    \u307F\u305F\u3059 l (0 <= l <= r) \u3092\u4E00\u3064\u6C42\u3081\u308B.\n\t\t\
    - l = r \u307E\u305F\u306F f(x_l * x_{l+1} * ... * x_{r-1}) = true\n\t\t- l =\
    \ 0 \u307E\u305F\u306F f(x_{l-1} * x_l * ... * x_{r-1}) = false\n\t\tf \u306E\u8A08\
    \u7B97\u306B\u304B\u304B\u308B\u6642\u9593\u3092 O(1) \u3068\u3057\u3066, \u8A08\
    \u7B97\u91CF\u306F O(log n).\n*/\n\ntemplate<class M>\nclass segment_tree{\n\t\
    int n,sz;\n\tvector<M> seg;\npublic:\n\tsegment_tree(){}\n\tsegment_tree(int n){\
    \ build(n); }\n\ttemplate<class T>\n\tsegment_tree(const vector<T>& a){ build(a);\
    \ }\n\tvoid build(int n){\n\t\tthis->n=n;\n\t\tfor(sz=1;sz<n;sz<<=1);\n\t\tseg.assign(2*sz,M());\n\
    \t}\n\ttemplate<class T>\n\tvoid build(const vector<T>& a){\n\t\tbuild(a.size());\n\
    \t\trep(i,a.size()) seg[sz+i]=a[i];\n\t\tfor(int i=sz-1;i>0;i--){\n\t\t\tseg[i]=seg[2*i]*seg[2*i+1];\n\
    \t\t}\n\t}\n\tconst M& operator[](int i)const{\n\t\treturn seg[sz+i];\n\t}\n\t\
    void update(int i,const M& x){\n\t\ti+=sz;\n\t\tseg[i]=x;\n\t\tfor(i>>=1;i>0;i>>=1)\
    \ seg[i]=seg[2*i]*seg[2*i+1];\n\t}\n\tM product(int l,int r)const{\n\t\tM lcum,rcum;\n\
    \t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\tif(a&1) lcum=lcum*seg[a++];\n\
    \t\t\tif(b&1) rcum=seg[--b]*rcum;\n\t\t}\n\t\treturn lcum*rcum;\n\t}\n\ttemplate<class\
    \ N,class F>\n\tN operate(int l,int r,const F& f){\n\t\tN lcum,rcum;\n\t\tfor(int\
    \ a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\tif(a&1) lcum=lcum*f(seg[a++]);\n\t\t\t\
    if(b&1) rcum=f(seg[--b])*rcum;\n\t\t}\n\t\treturn lcum*rcum;\n\t}\n\ttemplate<class\
    \ F>\n\tint max_right(int l,const F& f)const{\n\t\tif(l==n) return n;\n\t\tM cum;\n\
    \t\tauto dfs=[&](auto&& dfs,int a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=cum*seg[u];\n\
    \t\t\t\treturn f(cum)?b:a;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(c<=l){\n\
    \t\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t\t}\n\t\t\tif(l<=a && f(cum*seg[u])){\n\
    \t\t\t\tcum=cum*seg[u];\n\t\t\t\treturn b;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,a,c,2*u);\n\
    \t\t\tif(idx<c) return idx;\n\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t};\n\t\treturn\
    \ min(dfs(dfs,0,sz,1),n);\n\t}\n\ttemplate<class F>\n\tint min_left(int r,const\
    \ F& f)const{\n\t\tif(r==0) return 0;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int\
    \ a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn\
    \ f(cum)?a:b;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(r<=c){\n\t\t\t\treturn\
    \ dfs(dfs,a,c,2*u);\n\t\t\t}\n\t\t\tif(b<=r && f(seg[u]*cum)){\n\t\t\t\tcum=seg[u]*cum;\n\
    \t\t\t\treturn a;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,c,b,2*u+1);\n\t\t\tif(idx>c)\
    \ return idx;\n\t\t\treturn dfs(dfs,a,c,2*u);\n\t\t};\n\t\treturn dfs(dfs,0,sz,1);\n\
    \t}\n};\n"
  code: "/*\n\t\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\t\t(M, *) : \u30E2\u30CE\u30A4\
    \u30C9\n\t\tx_1, ..., x_n : M \u306E\u5143\u306E\u5217\n\n\t\tupdate(i,x) : x_i\
    \ \u306E\u5024\u3092 x \u306B\u66F8\u304D\u63DB\u3048\u308B.\n\t\tproduct(l,r)\
    \ : x_l * x_{l+1} * ... * x_{r-1} \u3092\u6C42\u3081\u308B.\n\n\t\toperate(l,r,f)\
    \ : f(x_l * x_{l+1} * ... * x_{r-1}) \u3092\u6C42\u3081\u308B.\n\t\t\t\u3053\u3053\
    \u3067, (N, *) \u306F\u30E2\u30CE\u30A4\u30C9, f M \u2192 N \u306F\u6E96\u540C\
    \u578B.\n\t\t\toperate<N>(l,r,[&](M& x)->N{\n\t\t\t\treturn ...;\n\t\t\t});\n\t\
    \t\t\u306E\u3088\u3046\u306B\u4F7F\u3046.\n\t\t\tx_l * x_{l+1} * ... * x_{r-1}\
    \ \u3092\u967D\u306B\u6C42\u3081\u308B\u3068\u8A08\u7B97\u91CF\u304C\u304B\u304B\
    \u308A\u3059\u304E\u308B\u304C\n\t\t\tN \u306B\u304A\u3051\u308B\u7A4D\u3068 f\
    \ \u306E\u4F5C\u7528\u306E\u8A08\u7B97\u91CF\u304C\u3069\u3061\u3089\u3082\u5C0F\
    \u3055\u3044\u3068\u304D\u306B\u6709\u52B9.\n\n\tmax_right(l,f) :\n\t\t\u4EEE\u5B9A\
    \n\t\t\t0 <= l <= n\n\t\t\tf : M -> bool \u306F f(e) = true \u3092\u307F\u305F\
    \u3059\n\t\t\u6B21\u306E\u4E8C\u3064\u306E\u6761\u4EF6\u3092\u307F\u305F\u3059\
    \ r (l <= r <= n) \u3092\u4E00\u3064\u6C42\u3081\u308B.\n\t\t- r = l \u307E\u305F\
    \u306F f(x_l * x_{l+1} * ... * x_{r-1}) = true\n\t\t- r = n \u307E\u305F\u306F\
    \ f(x_l * x_{l+1} * ... * x_r) = false\n\t\tf \u306E\u8A08\u7B97\u306B\u304B\u304B\
    \u308B\u6642\u9593\u3092 O(1) \u3068\u3057\u3066, \u8A08\u7B97\u91CF\u306F O(log\
    \ n).\n\tmin_left(r,f) :\n\t\t\u4EEE\u5B9A\n\t\t\t0 <= r <= n\n\t\t\tf : M ->\
    \ bool \u306F f(e) = true \u3092\u307F\u305F\u3059\n\t\t\u6B21\u306E\u4E8C\u3064\
    \u306E\u6761\u4EF6\u3092\u307F\u305F\u3059 l (0 <= l <= r) \u3092\u4E00\u3064\u6C42\
    \u3081\u308B.\n\t\t- l = r \u307E\u305F\u306F f(x_l * x_{l+1} * ... * x_{r-1})\
    \ = true\n\t\t- l = 0 \u307E\u305F\u306F f(x_{l-1} * x_l * ... * x_{r-1}) = false\n\
    \t\tf \u306E\u8A08\u7B97\u306B\u304B\u304B\u308B\u6642\u9593\u3092 O(1) \u3068\
    \u3057\u3066, \u8A08\u7B97\u91CF\u306F O(log n).\n*/\n\ntemplate<class M>\nclass\
    \ segment_tree{\n\tint n,sz;\n\tvector<M> seg;\npublic:\n\tsegment_tree(){}\n\t\
    segment_tree(int n){ build(n); }\n\ttemplate<class T>\n\tsegment_tree(const vector<T>&\
    \ a){ build(a); }\n\tvoid build(int n){\n\t\tthis->n=n;\n\t\tfor(sz=1;sz<n;sz<<=1);\n\
    \t\tseg.assign(2*sz,M());\n\t}\n\ttemplate<class T>\n\tvoid build(const vector<T>&\
    \ a){\n\t\tbuild(a.size());\n\t\trep(i,a.size()) seg[sz+i]=a[i];\n\t\tfor(int\
    \ i=sz-1;i>0;i--){\n\t\t\tseg[i]=seg[2*i]*seg[2*i+1];\n\t\t}\n\t}\n\tconst M&\
    \ operator[](int i)const{\n\t\treturn seg[sz+i];\n\t}\n\tvoid update(int i,const\
    \ M& x){\n\t\ti+=sz;\n\t\tseg[i]=x;\n\t\tfor(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];\n\
    \t}\n\tM product(int l,int r)const{\n\t\tM lcum,rcum;\n\t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\
    \t\t\tif(a&1) lcum=lcum*seg[a++];\n\t\t\tif(b&1) rcum=seg[--b]*rcum;\n\t\t}\n\t\
    \treturn lcum*rcum;\n\t}\n\ttemplate<class N,class F>\n\tN operate(int l,int r,const\
    \ F& f){\n\t\tN lcum,rcum;\n\t\tfor(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){\n\t\t\t\
    if(a&1) lcum=lcum*f(seg[a++]);\n\t\t\tif(b&1) rcum=f(seg[--b])*rcum;\n\t\t}\n\t\
    \treturn lcum*rcum;\n\t}\n\ttemplate<class F>\n\tint max_right(int l,const F&\
    \ f)const{\n\t\tif(l==n) return n;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int\
    \ a,int b,int u){\n\t\t\tif(a==b-1){\n\t\t\t\tcum=cum*seg[u];\n\t\t\t\treturn\
    \ f(cum)?b:a;\n\t\t\t}\n\n\t\t\tint c=(a+b)/2;\n\t\t\tif(c<=l){\n\t\t\t\treturn\
    \ dfs(dfs,c,b,2*u+1);\n\t\t\t}\n\t\t\tif(l<=a && f(cum*seg[u])){\n\t\t\t\tcum=cum*seg[u];\n\
    \t\t\t\treturn b;\n\t\t\t}\n\n\t\t\tint idx=dfs(dfs,a,c,2*u);\n\t\t\tif(idx<c)\
    \ return idx;\n\t\t\treturn dfs(dfs,c,b,2*u+1);\n\t\t};\n\t\treturn min(dfs(dfs,0,sz,1),n);\n\
    \t}\n\ttemplate<class F>\n\tint min_left(int r,const F& f)const{\n\t\tif(r==0)\
    \ return 0;\n\t\tM cum;\n\t\tauto dfs=[&](auto&& dfs,int a,int b,int u){\n\t\t\
    \tif(a==b-1){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn f(cum)?a:b;\n\t\t\t}\n\n\
    \t\t\tint c=(a+b)/2;\n\t\t\tif(r<=c){\n\t\t\t\treturn dfs(dfs,a,c,2*u);\n\t\t\t\
    }\n\t\t\tif(b<=r && f(seg[u]*cum)){\n\t\t\t\tcum=seg[u]*cum;\n\t\t\t\treturn a;\n\
    \t\t\t}\n\n\t\t\tint idx=dfs(dfs,c,b,2*u+1);\n\t\t\tif(idx>c) return idx;\n\t\t\
    \treturn dfs(dfs,a,c,2*u);\n\t\t};\n\t\treturn dfs(dfs,0,sz,1);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/library/data_structure/segment_tree.hpp
- /library/library/data_structure/segment_tree.hpp.html
title: library/data_structure/segment_tree.hpp
---
