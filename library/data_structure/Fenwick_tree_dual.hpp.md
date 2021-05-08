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
  bundledCode: "#line 1 \"library/data_structure/Fenwick_tree_dual.hpp\"\n/* Fenwick\
    \ Tree Dual */\n/*\n\t\u8AAC\u660E\n\t\t\u7D2F\u7A4D\u548C\u3092\u52B9\u7387\u7684\
    \u306B\u8A08\u7B97\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n\t\tFenwick Tree\
    \ \u306E add, sum \u64CD\u4F5C\u306E\u5F79\u5272\u3092\u5165\u308C\u66FF\u3048\
    \u305F\u3082\u306E\n\t\u5099\u8003\n\t\tG \u306F Abel \u7FA4\n\t\t\u6271\u3046\
    \u6570\u5217\u3092 a[0..n) \u3068\u8A18\u3059 (\u30B3\u30FC\u30C9\u4E2D\u306E\
    \ a \u3068\u306F\u7570\u306A\u308B)\n\n[ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \ ]\n\t\u8AAC\u660E\n\t\t0 \u3067\u521D\u671F\u5316\n\t\u5F15\u6570\n\t\tn : \u914D\
    \u5217\u306E\u9577\u3055\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n\n[ add ]\n\t\u8AAC\u660E\n\t\t\
    a[l]+=v, a[l+1]+=val, ..., a[r-1]+=val\n\t\u5F15\u6570\n\t\tl : \u5DE6\u7AEF\n\
    \t\tr : \u53F3\u7AEF\n\t\tval : \u52A0\u3048\u308B\u5024\n\t\u5236\u7D04\n\t\t\
    l <= r\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\t\u534A\u958B\u533A\
    \u9593\u3067\u6307\u5B9A\u3059\u308B\u3053\u3068\u306B\u6CE8\u610F.\n\n[ get ]\n\
    \t\u8AAC\u660E\n\t\ta[i] \u306E\u5024\u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\
    \t\ti : \u914D\u5217\u306E\u6DFB\u3048\u5B57\n\t\u5236\u7D04\n\t\t0 <= x < n\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n*/\n\ntemplate<class\
    \ G>\nclass Fenwick_tree_dual{\n\tvector<G> a;\npublic:\n\tFenwick_tree_dual(int\
    \ n):a(n){}\n\tvoid add(int l,int r,const G& val){\n\t\tif(l==0){\n\t\t\tfor(;r>0;r-=r&-r)\
    \ a[r-1]+=val;\n\t\t\treturn;\n\t\t}\n\t\tadd(0,r,val);\n\t\tadd(0,l,-val);\n\t\
    }\n\tG get(int i)const{\n\t\tG res{};\n\t\tfor(i++;i<=a.size();i+=i&-i) res+=a[i-1];\n\
    \t\treturn res;\n\t}\n};\n"
  code: "/* Fenwick Tree Dual */\n/*\n\t\u8AAC\u660E\n\t\t\u7D2F\u7A4D\u548C\u3092\
    \u52B9\u7387\u7684\u306B\u8A08\u7B97\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\
    \n\t\tFenwick Tree \u306E add, sum \u64CD\u4F5C\u306E\u5F79\u5272\u3092\u5165\u308C\
    \u66FF\u3048\u305F\u3082\u306E\n\t\u5099\u8003\n\t\tG \u306F Abel \u7FA4\n\t\t\
    \u6271\u3046\u6570\u5217\u3092 a[0..n) \u3068\u8A18\u3059 (\u30B3\u30FC\u30C9\u4E2D\
    \u306E a \u3068\u306F\u7570\u306A\u308B)\n\n[ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF ]\n\t\u8AAC\u660E\n\t\t0 \u3067\u521D\u671F\u5316\n\t\u5F15\u6570\n\t\t\
    n : \u914D\u5217\u306E\u9577\u3055\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n\n[ add ]\n\t\u8AAC\u660E\
    \n\t\ta[l]+=v, a[l+1]+=val, ..., a[r-1]+=val\n\t\u5F15\u6570\n\t\tl : \u5DE6\u7AEF\
    \n\t\tr : \u53F3\u7AEF\n\t\tval : \u52A0\u3048\u308B\u5024\n\t\u5236\u7D04\n\t\
    \tl <= r\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\t\u534A\u958B\
    \u533A\u9593\u3067\u6307\u5B9A\u3059\u308B\u3053\u3068\u306B\u6CE8\u610F.\n\n\
    [ get ]\n\t\u8AAC\u660E\n\t\ta[i] \u306E\u5024\u3092\u6C42\u3081\u308B\n\t\u5F15\
    \u6570\n\t\ti : \u914D\u5217\u306E\u6DFB\u3048\u5B57\n\t\u5236\u7D04\n\t\t0 <=\
    \ x < n\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\t\u306A\u3057\n\
    */\n\ntemplate<class G>\nclass Fenwick_tree_dual{\n\tvector<G> a;\npublic:\n\t\
    Fenwick_tree_dual(int n):a(n){}\n\tvoid add(int l,int r,const G& val){\n\t\tif(l==0){\n\
    \t\t\tfor(;r>0;r-=r&-r) a[r-1]+=val;\n\t\t\treturn;\n\t\t}\n\t\tadd(0,r,val);\n\
    \t\tadd(0,l,-val);\n\t}\n\tG get(int i)const{\n\t\tG res{};\n\t\tfor(i++;i<=a.size();i+=i&-i)\
    \ res+=a[i-1];\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/Fenwick_tree_dual.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/Fenwick_tree_dual.hpp
layout: document
redirect_from:
- /library/library/data_structure/Fenwick_tree_dual.hpp
- /library/library/data_structure/Fenwick_tree_dual.hpp.html
title: library/data_structure/Fenwick_tree_dual.hpp
---
