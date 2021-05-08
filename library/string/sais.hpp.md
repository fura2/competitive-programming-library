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
  bundledCode: "#line 1 \"library/string/sais.hpp\"\n/* Suffix Array */\n/*\n[ constructor(string)\
    \ ]\n\t\u8AAC\u660E\n\t\t\u6587\u5B57\u5217 s \u306E suffix array \u3092\u69CB\
    \u7BC9\u3059\u308B\n\t\u5F15\u6570\n\t\ts : \u6587\u5B57\u5217\n\t\u5236\u7D04\
    \n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(|s|)\n\t\u5099\u8003\n\t\t\u914D\
    \u5217 sa \u306F\u8981\u7D20\u6570 |s|+1\n\t\ts \u306E |s|+1 \u500B\u306E suffix\
    \ (\u7A7A\u6587\u5B57\u5217\u3082\u542B\u3080) \u306E\u3046\u3061, \u8F9E\u66F8\
    \u9806\u3067 i \u756A\u76EE\u306B\u304F\u308B\u3082\u306E\u304C s[sa[i]..) \u3068\
    \u306A\u308B\n\n[ constructor(vector<int>) ]\n\t\u8AAC\u660E\n\t\t\u6570\u5217\
    \ s \u306E suffix array \u3092\u69CB\u7BC9\u3059\u308B\n\t\u5F15\u6570\n\t\ts\
    \ : \u6570\u5217\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\u91CF\n\t\t\
    O(|s|)\n\t\u5099\u8003\n\t\t\u914D\u5217 sa \u306F\u8981\u7D20\u6570 |s|+1\n\t\
    \ts \u306E |s|+1 \u500B\u306E suffix (\u7A7A\u6587\u5B57\u5217\u3082\u542B\u3080\
    ) \u306E\u3046\u3061, \u8F9E\u66F8\u9806\u3067 i \u756A\u76EE\u306B\u304F\u308B\
    \u3082\u306E\u304C s[sa[i]..) \u3068\u306A\u308B\n\n[ operator[] ]\n\t\u5F15\u6570\
    \n\t\ti : \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\t\u5236\u7D04\n\t\t0 <= i <=\
    \ |s|\n\t\u623B\u308A\u5024\n\t\t\u6587\u5B57\u5217 s \u306E suffix array \u306E\
    \ i \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\n\n[ longest_common_prefix\
    \ ]\n\t\u5F15\u6570\n\t\t\u306A\u3057\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u623B\
    \u308A\u5024\n\t\ts \u306E LCP \u914D\u5217\u3092\u8FD4\u3059\n\t\t\u8981\u7D20\
    \u6570\u306F |s| \u3067, LCP[i] = (s[sa[i]..) \u3068 s[sa[i+1]..) \u306E\u6700\
    \u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055)\n\t\u8A08\u7B97\u91CF\n\
    \t\tO(1)\n*/\n\nclass suffix_array{\n\tvector<int> sa,lcp;\n\n\tvector<int> cnt;\n\
    \n\tvoid SA_IS(vector<int>& s,int k){\n\t\tint n=s.size();\n\n\t\tfor(int& c:s)\
    \ c++;\n\t\ts.emplace_back(0);\n\t\tk++;\n\n\t\tvector<bool> isS(n+1);\n\t\tvector<int>\
    \ LMS,bin(k+1);\n\t\tisS[n]=true;\n\t\tbin[1]=1;\n\t\tfor(int i=n-1;i>=0;i--){\n\
    \t\t\tisS[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:isS[i+1]);\n\t\t\tif(!isS[i] && isS[i+1]){\n\
    \t\t\t\tLMS.emplace_back(i+1);\n\t\t\t}\n\t\t\tbin[s[i]+1]++;\n\t\t}\n\t\trep(i,k)\
    \ bin[i+1]+=bin[i];\n\n\t\tauto induced_sort=[&](const vector<int>& LMS){\n\t\t\
    \tsa.assign(n+1,-1);\n\t\t\tcnt.assign(k,0);\n\t\t\tfor(int x:LMS){\n\t\t\t\t\
    sa[bin[s[x]+1]-cnt[s[x]]-1]=x;\n\t\t\t\tcnt[s[x]]++;\n\t\t\t}\n\n\t\t\tcnt.assign(k,0);\n\
    \t\t\trep(i,n+1){\n\t\t\t\tint x=sa[i]-1;\n\t\t\t\tif(x>=0 && !isS[x]){\n\t\t\t\
    \t\tsa[bin[s[x]]+cnt[s[x]]]=x;\n\t\t\t\t\tcnt[s[x]]++;\n\t\t\t\t}\n\t\t\t}\n\n\
    \t\t\tcnt.assign(k,0);\n\t\t\tfor(int i=n;i>=0;i--){\n\t\t\t\tint x=sa[i]-1;\n\
    \t\t\t\tif(x>=0 && isS[x]){\n\t\t\t\t\tsa[bin[s[x]+1]-cnt[s[x]]-1]=x;\n\t\t\t\t\
    \tcnt[s[x]]++;\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\n\t\tinduced_sort(LMS);\n\n\t\tif(LMS.size()<=1)\
    \ return;\n\n\t\tint m=LMS.size();\n\t\tvector<int> inv(n+1,-1);\n\t\trep(i,m)\
    \ inv[LMS[i]]=i;\n\n\t\tint idx=0;\n\t\tvector<int> LMS2(m);\n\t\tfor(int x:sa)\
    \ if(inv[x]!=-1) LMS2[idx++]=x;\n\n\t\tint k2=1;\n\t\tvector<int> s2(m);\n\t\t\
    s2[m-1-inv[LMS2[1]]]=1;\n\t\tfor(int i=2;i<m;i++){\n\t\t\tint xl=LMS2[i],yl=LMS2[i-1];\n\
    \t\t\tint xr=LMS[inv[xl]-1],yr=LMS[inv[yl]-1];\n\t\t\tif(xr-xl!=yr-yl) k2++;\n\
    \t\t\telse{\n\t\t\t\twhile(xl<=xr){\n\t\t\t\t\tif(s[xl]!=s[yl]){ k2++; break;\
    \ }\n\t\t\t\t\txl++; yl++;\n\t\t\t\t}\n\t\t\t}\n\t\t\ts2[m-1-inv[LMS2[i]]]=k2;\n\
    \t\t}\n\n\t\tSA_IS(s2,k2+1);\n\n\t\tidx=m;\n\t\tfor(int i=1;i<=m;i++) LMS2[--idx]=LMS[m-sa[i]-1];\n\
    \t\tinduced_sort(LMS2);\n\t}\n\n\tvoid build_lcp(const vector<int>& s){\n\t\t\
    int n=s.size();\n\t\tlcp.resize(n);\n\t\tvector<int> f(n+1);\n\t\trep(i,n+1) f[sa[i]]=i;\n\
    \t\tint h=0;\n\t\trep(i,n+1){\n\t\t\tif(f[i]){\n\t\t\t\tfor(int j=sa[f[i]-1];i+h<n&&j+h<n;h++)\
    \ if(s[i+h]!=s[j+h]) break;\n\t\t\t\tlcp[f[i]-1]=h;\n\t\t\t}\n\t\t\tif(h>0) h--;\n\
    \t\t}\n\t}\n\npublic:\n\tsuffix_array(const string& s){\n\t\tint n=s.length();\n\
    \t\tif(n==0){ sa={0}; return; }\n\n\t\tauto p=minmax_element(s.begin(),s.end());\n\
    \t\tchar mn=*p.first,mx=*p.second;\n\n\t\tvector<int> t(n);\n\t\trep(i,n) t[i]=s[i]-mn;\n\
    \n\t\tSA_IS(t,mx-mn+1);\n\n\t\tt.resize(n);\n\t\trep(i,n) t[i]=s[i]-mn;\n\t\t\
    build_lcp(t);\n\t}\n\n\tsuffix_array(const vector<int>& a){\n\t\tint n=a.size();\n\
    \t\tif(n==0){ sa={0}; return; }\n\n\t\tvector<int> X=a,b(n);\n\t\tsort(X.begin(),X.end());\n\
    \t\tX.erase(unique(X.begin(),X.end()),X.end());\n\n\t\trep(i,n) b[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();\n\
    \n\t\tSA_IS(b,X.size());\n\n\t\tbuild_lcp(a);\n\t}\n\n\tint operator[](int i)const{\
    \ return sa[i]; }\n\n\tconst vector<int>& longest_common_prefix()const{ return\
    \ lcp; }\n};\n"
  code: "/* Suffix Array */\n/*\n[ constructor(string) ]\n\t\u8AAC\u660E\n\t\t\u6587\
    \u5B57\u5217 s \u306E suffix array \u3092\u69CB\u7BC9\u3059\u308B\n\t\u5F15\u6570\
    \n\t\ts : \u6587\u5B57\u5217\n\t\u5236\u7D04\n\t\t\u306A\u3057\n\t\u8A08\u7B97\
    \u91CF\n\t\tO(|s|)\n\t\u5099\u8003\n\t\t\u914D\u5217 sa \u306F\u8981\u7D20\u6570\
    \ |s|+1\n\t\ts \u306E |s|+1 \u500B\u306E suffix (\u7A7A\u6587\u5B57\u5217\u3082\
    \u542B\u3080) \u306E\u3046\u3061, \u8F9E\u66F8\u9806\u3067 i \u756A\u76EE\u306B\
    \u304F\u308B\u3082\u306E\u304C s[sa[i]..) \u3068\u306A\u308B\n\n[ constructor(vector<int>)\
    \ ]\n\t\u8AAC\u660E\n\t\t\u6570\u5217 s \u306E suffix array \u3092\u69CB\u7BC9\
    \u3059\u308B\n\t\u5F15\u6570\n\t\ts : \u6570\u5217\n\t\u5236\u7D04\n\t\t\u306A\
    \u3057\n\t\u8A08\u7B97\u91CF\n\t\tO(|s|)\n\t\u5099\u8003\n\t\t\u914D\u5217 sa\
    \ \u306F\u8981\u7D20\u6570 |s|+1\n\t\ts \u306E |s|+1 \u500B\u306E suffix (\u7A7A\
    \u6587\u5B57\u5217\u3082\u542B\u3080) \u306E\u3046\u3061, \u8F9E\u66F8\u9806\u3067\
    \ i \u756A\u76EE\u306B\u304F\u308B\u3082\u306E\u304C s[sa[i]..) \u3068\u306A\u308B\
    \n\n[ operator[] ]\n\t\u5F15\u6570\n\t\ti : \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n\t\u5236\u7D04\n\t\t0 <= i <= |s|\n\t\u623B\u308A\u5024\n\t\t\u6587\u5B57\u5217\
    \ s \u306E suffix array \u306E i \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \n\n[ longest_common_prefix ]\n\t\u5F15\u6570\n\t\t\u306A\u3057\n\t\u5236\u7D04\
    \n\t\t\u306A\u3057\n\t\u623B\u308A\u5024\n\t\ts \u306E LCP \u914D\u5217\u3092\u8FD4\
    \u3059\n\t\t\u8981\u7D20\u6570\u306F |s| \u3067, LCP[i] = (s[sa[i]..) \u3068 s[sa[i+1]..)\
    \ \u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055)\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(1)\n*/\n\nclass suffix_array{\n\tvector<int> sa,lcp;\n\n\t\
    vector<int> cnt;\n\n\tvoid SA_IS(vector<int>& s,int k){\n\t\tint n=s.size();\n\
    \n\t\tfor(int& c:s) c++;\n\t\ts.emplace_back(0);\n\t\tk++;\n\n\t\tvector<bool>\
    \ isS(n+1);\n\t\tvector<int> LMS,bin(k+1);\n\t\tisS[n]=true;\n\t\tbin[1]=1;\n\t\
    \tfor(int i=n-1;i>=0;i--){\n\t\t\tisS[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:isS[i+1]);\n\
    \t\t\tif(!isS[i] && isS[i+1]){\n\t\t\t\tLMS.emplace_back(i+1);\n\t\t\t}\n\t\t\t\
    bin[s[i]+1]++;\n\t\t}\n\t\trep(i,k) bin[i+1]+=bin[i];\n\n\t\tauto induced_sort=[&](const\
    \ vector<int>& LMS){\n\t\t\tsa.assign(n+1,-1);\n\t\t\tcnt.assign(k,0);\n\t\t\t\
    for(int x:LMS){\n\t\t\t\tsa[bin[s[x]+1]-cnt[s[x]]-1]=x;\n\t\t\t\tcnt[s[x]]++;\n\
    \t\t\t}\n\n\t\t\tcnt.assign(k,0);\n\t\t\trep(i,n+1){\n\t\t\t\tint x=sa[i]-1;\n\
    \t\t\t\tif(x>=0 && !isS[x]){\n\t\t\t\t\tsa[bin[s[x]]+cnt[s[x]]]=x;\n\t\t\t\t\t\
    cnt[s[x]]++;\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tcnt.assign(k,0);\n\t\t\tfor(int i=n;i>=0;i--){\n\
    \t\t\t\tint x=sa[i]-1;\n\t\t\t\tif(x>=0 && isS[x]){\n\t\t\t\t\tsa[bin[s[x]+1]-cnt[s[x]]-1]=x;\n\
    \t\t\t\t\tcnt[s[x]]++;\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\n\t\tinduced_sort(LMS);\n\
    \n\t\tif(LMS.size()<=1) return;\n\n\t\tint m=LMS.size();\n\t\tvector<int> inv(n+1,-1);\n\
    \t\trep(i,m) inv[LMS[i]]=i;\n\n\t\tint idx=0;\n\t\tvector<int> LMS2(m);\n\t\t\
    for(int x:sa) if(inv[x]!=-1) LMS2[idx++]=x;\n\n\t\tint k2=1;\n\t\tvector<int>\
    \ s2(m);\n\t\ts2[m-1-inv[LMS2[1]]]=1;\n\t\tfor(int i=2;i<m;i++){\n\t\t\tint xl=LMS2[i],yl=LMS2[i-1];\n\
    \t\t\tint xr=LMS[inv[xl]-1],yr=LMS[inv[yl]-1];\n\t\t\tif(xr-xl!=yr-yl) k2++;\n\
    \t\t\telse{\n\t\t\t\twhile(xl<=xr){\n\t\t\t\t\tif(s[xl]!=s[yl]){ k2++; break;\
    \ }\n\t\t\t\t\txl++; yl++;\n\t\t\t\t}\n\t\t\t}\n\t\t\ts2[m-1-inv[LMS2[i]]]=k2;\n\
    \t\t}\n\n\t\tSA_IS(s2,k2+1);\n\n\t\tidx=m;\n\t\tfor(int i=1;i<=m;i++) LMS2[--idx]=LMS[m-sa[i]-1];\n\
    \t\tinduced_sort(LMS2);\n\t}\n\n\tvoid build_lcp(const vector<int>& s){\n\t\t\
    int n=s.size();\n\t\tlcp.resize(n);\n\t\tvector<int> f(n+1);\n\t\trep(i,n+1) f[sa[i]]=i;\n\
    \t\tint h=0;\n\t\trep(i,n+1){\n\t\t\tif(f[i]){\n\t\t\t\tfor(int j=sa[f[i]-1];i+h<n&&j+h<n;h++)\
    \ if(s[i+h]!=s[j+h]) break;\n\t\t\t\tlcp[f[i]-1]=h;\n\t\t\t}\n\t\t\tif(h>0) h--;\n\
    \t\t}\n\t}\n\npublic:\n\tsuffix_array(const string& s){\n\t\tint n=s.length();\n\
    \t\tif(n==0){ sa={0}; return; }\n\n\t\tauto p=minmax_element(s.begin(),s.end());\n\
    \t\tchar mn=*p.first,mx=*p.second;\n\n\t\tvector<int> t(n);\n\t\trep(i,n) t[i]=s[i]-mn;\n\
    \n\t\tSA_IS(t,mx-mn+1);\n\n\t\tt.resize(n);\n\t\trep(i,n) t[i]=s[i]-mn;\n\t\t\
    build_lcp(t);\n\t}\n\n\tsuffix_array(const vector<int>& a){\n\t\tint n=a.size();\n\
    \t\tif(n==0){ sa={0}; return; }\n\n\t\tvector<int> X=a,b(n);\n\t\tsort(X.begin(),X.end());\n\
    \t\tX.erase(unique(X.begin(),X.end()),X.end());\n\n\t\trep(i,n) b[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();\n\
    \n\t\tSA_IS(b,X.size());\n\n\t\tbuild_lcp(a);\n\t}\n\n\tint operator[](int i)const{\
    \ return sa[i]; }\n\n\tconst vector<int>& longest_common_prefix()const{ return\
    \ lcp; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/sais.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/sais.hpp
layout: document
redirect_from:
- /library/library/string/sais.hpp
- /library/library/string/sais.hpp.html
title: library/string/sais.hpp
---
