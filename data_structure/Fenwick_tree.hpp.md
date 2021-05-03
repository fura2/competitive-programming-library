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
  bundledCode: "#line 1 \"data_structure/Fenwick_tree.hpp\"\n/* Fenwick Tree */\n\
    /*\n\t\u8AAC\u660E\n\t\t\u7D2F\u7A4D\u548C\u3092\u52B9\u7387\u7684\u306B\u8A08\
    \u7B97\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n\t\tFenwick tree (Binary Indexed\
    \ Tree)\n\t\u5099\u8003\n\t\tG \u306F Abel \u7FA4\n\t\t\u6271\u3046\u6570\u5217\
    \u3092 a[0,n) \u3068\u8A18\u3059 (\u30B3\u30FC\u30C9\u4E2D\u306E a \u3068\u306F\
    \u7570\u306A\u308B)\n\n[ constructor ]\n\t\u8AAC\u660E\n\t\t0 \u3067\u521D\u671F\
    \u5316\n\t\u5F15\u6570\n\t\tn : BIT \u306E\u30B5\u30A4\u30BA\n\t\u5236\u7D04\n\
    \t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\n[ add ]\n\t\u8AAC\u660E\n\t\
    \ta[i]+=val\n\t\u5F15\u6570\n\t\ti : \u914D\u5217\u306E\u6DFB\u3048\u5B57\n\t\t\
    val : \u52A0\u3048\u308B\u5024\n\t\u5236\u7D04\n\t\t0 <= x < n\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(log n)\n\n[ sum ]\n\t\u8AAC\u660E\n\t\ta[l]+a[l+1]+...+a[r-1] \u3092\
    \u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tl : \u5DE6\u7AEF\n\t\tr : \u53F3\u7AEF\
    \n\t\u5236\u7D04\n\t\tl <= r\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\
    \n\t\t\u534A\u958B\u533A\u9593\u3067\u6307\u5B9A\u3059\u308B\u3053\u3068\u306B\
    \u6CE8\u610F\n\n[lower_bound]\n\t\u8AAC\u660E\n\t\ta[0]+a[1]+...+a[x]>=val \u3068\
    \u306A\u308B\u6700\u5C0F\u306E x \u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\t\
    val : \u95BE\u5024\n\t\u5236\u7D04\n\t\tG \u306B\u306F\u9806\u5E8F\u304C\u5165\
    \u3063\u3066\u3044\u308B\n\t\t\u3059\u3079\u3066\u306E i \u3067 a[i]>=0\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\ta[0]+...+a[n-1]<val \u306E\u3068\
    \u304D\u306F n \u304C\u8FD4\u308B\n\n[upper_bound]\n\t\u8AAC\u660E\n\t\ta[0]+a[1]+...+a[x]>val\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306E x \u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\
    \n\t\tval : \u95BE\u5024\n\t\u5236\u7D04\n\t\tG \u306B\u306F\u9806\u5E8F\u304C\
    \u5165\u3063\u3066\u3044\u308B\n\t\t\u3059\u3079\u3066\u306E i \u3067 a[i]>=0\n\
    \t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\ta[0]+...+a[n-1]<=val \u306E\
    \u3068\u304D\u306F n \u304C\u8FD4\u308B\n*/\n\ntemplate<class G>\nclass Fenwick_tree{\n\
    \tvector<G> a;\npublic:\n\tFenwick_tree(){}\n\tFenwick_tree(int n){ build(n);\
    \ }\n\tFenwick_tree(const vector<G>& a){ build(a); }\n\tvoid build(int n){\n\t\
    \ta.assign(n,G{});\n\t}\n\tvoid build(const vector<G>& a){\n\t\tthis->a=a;\n\t\
    \tfor(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];\n\
    \t}\n\tvoid add(int i,const G& val){\n\t\tfor(i++;i<=a.size();i+=i&-i) a[i-1]+=val;\n\
    \t}\n\tG sum(int l,int r)const{\n\t\tif(l==0){\n\t\t\tG res{};\n\t\t\tfor(;r>0;r-=r&-r)\
    \ res+=a[r-1];\n\t\t\treturn res;\n\t\t}\n\t\treturn sum(0,r)-sum(0,l);\n\t}\n\
    \tint lower_bound(G val)const{\n\t\tif(val<=G{}) return 0;\n\t\tint x=0,k;\n\t\
    \tfor(k=1;k<=a.size();k<<=1);\n\t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val)\
    \ val-=a[x+k-1], x+=k;\n\t\treturn x;\n\t}\n\tint upper_bound(G val)const{\n\t\
    \tif(val<G{}) return 0;\n\t\tint x=0,k;\n\t\tfor(k=1;k<=a.size();k<<=1);\n\t\t\
    for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;\n\
    \t\treturn x;\n\t}\n};\n"
  code: "/* Fenwick Tree */\n/*\n\t\u8AAC\u660E\n\t\t\u7D2F\u7A4D\u548C\u3092\u52B9\
    \u7387\u7684\u306B\u8A08\u7B97\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n\t\t\
    Fenwick tree (Binary Indexed Tree)\n\t\u5099\u8003\n\t\tG \u306F Abel \u7FA4\n\
    \t\t\u6271\u3046\u6570\u5217\u3092 a[0,n) \u3068\u8A18\u3059 (\u30B3\u30FC\u30C9\
    \u4E2D\u306E a \u3068\u306F\u7570\u306A\u308B)\n\n[ constructor ]\n\t\u8AAC\u660E\
    \n\t\t0 \u3067\u521D\u671F\u5316\n\t\u5F15\u6570\n\t\tn : BIT \u306E\u30B5\u30A4\
    \u30BA\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(n)\n\n[\
    \ add ]\n\t\u8AAC\u660E\n\t\ta[i]+=val\n\t\u5F15\u6570\n\t\ti : \u914D\u5217\u306E\
    \u6DFB\u3048\u5B57\n\t\tval : \u52A0\u3048\u308B\u5024\n\t\u5236\u7D04\n\t\t0\
    \ <= x < n\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\n[ sum ]\n\t\u8AAC\u660E\n\t\t\
    a[l]+a[l+1]+...+a[r-1] \u3092\u6C42\u3081\u308B\n\t\u5F15\u6570\n\t\tl : \u5DE6\
    \u7AEF\n\t\tr : \u53F3\u7AEF\n\t\u5236\u7D04\n\t\tl <= r\n\t\u8A08\u7B97\u91CF\
    \n\t\tO(log n)\n\t\u5099\u8003\n\t\t\u534A\u958B\u533A\u9593\u3067\u6307\u5B9A\
    \u3059\u308B\u3053\u3068\u306B\u6CE8\u610F\n\n[lower_bound]\n\t\u8AAC\u660E\n\t\
    \ta[0]+a[1]+...+a[x]>=val \u3068\u306A\u308B\u6700\u5C0F\u306E x \u3092\u6C42\u3081\
    \u308B\n\t\u5F15\u6570\n\t\tval : \u95BE\u5024\n\t\u5236\u7D04\n\t\tG \u306B\u306F\
    \u9806\u5E8F\u304C\u5165\u3063\u3066\u3044\u308B\n\t\t\u3059\u3079\u3066\u306E\
    \ i \u3067 a[i]>=0\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\ta[0]+...+a[n-1]<val\
    \ \u306E\u3068\u304D\u306F n \u304C\u8FD4\u308B\n\n[upper_bound]\n\t\u8AAC\u660E\
    \n\t\ta[0]+a[1]+...+a[x]>val \u3068\u306A\u308B\u6700\u5C0F\u306E x \u3092\u6C42\
    \u3081\u308B\n\t\u5F15\u6570\n\t\tval : \u95BE\u5024\n\t\u5236\u7D04\n\t\tG \u306B\
    \u306F\u9806\u5E8F\u304C\u5165\u3063\u3066\u3044\u308B\n\t\t\u3059\u3079\u3066\
    \u306E i \u3067 a[i]>=0\n\t\u8A08\u7B97\u91CF\n\t\tO(log n)\n\t\u5099\u8003\n\t\
    \ta[0]+...+a[n-1]<=val \u306E\u3068\u304D\u306F n \u304C\u8FD4\u308B\n*/\n\ntemplate<class\
    \ G>\nclass Fenwick_tree{\n\tvector<G> a;\npublic:\n\tFenwick_tree(){}\n\tFenwick_tree(int\
    \ n){ build(n); }\n\tFenwick_tree(const vector<G>& a){ build(a); }\n\tvoid build(int\
    \ n){\n\t\ta.assign(n,G{});\n\t}\n\tvoid build(const vector<G>& a){\n\t\tthis->a=a;\n\
    \t\tfor(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];\n\
    \t}\n\tvoid add(int i,const G& val){\n\t\tfor(i++;i<=a.size();i+=i&-i) a[i-1]+=val;\n\
    \t}\n\tG sum(int l,int r)const{\n\t\tif(l==0){\n\t\t\tG res{};\n\t\t\tfor(;r>0;r-=r&-r)\
    \ res+=a[r-1];\n\t\t\treturn res;\n\t\t}\n\t\treturn sum(0,r)-sum(0,l);\n\t}\n\
    \tint lower_bound(G val)const{\n\t\tif(val<=G{}) return 0;\n\t\tint x=0,k;\n\t\
    \tfor(k=1;k<=a.size();k<<=1);\n\t\tfor(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val)\
    \ val-=a[x+k-1], x+=k;\n\t\treturn x;\n\t}\n\tint upper_bound(G val)const{\n\t\
    \tif(val<G{}) return 0;\n\t\tint x=0,k;\n\t\tfor(k=1;k<=a.size();k<<=1);\n\t\t\
    for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;\n\
    \t\treturn x;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Fenwick_tree.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Fenwick_tree.hpp
layout: document
redirect_from:
- /library/data_structure/Fenwick_tree.hpp
- /library/data_structure/Fenwick_tree.hpp.html
title: data_structure/Fenwick_tree.hpp
---
