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
  bundledCode: "#line 1 \"library/string/rolling_hash.hpp\"\nclass rolling_hash{\n\
    \tstatic const long long base=10007,mod1=1e9+7,mod2=1e9+9;\n\tinline static vector<long\
    \ long> pow1={1},pow2={1};\n\tint len;\n\tvector<long long> h1,h2;\n\n\tstatic\
    \ void allocate(int len){\n\t\tif(pow1.size()<=len){\n\t\t\tint k=pow1.size();\n\
    \t\t\tpow1.resize(len+1);\n\t\t\tpow2.resize(len+1);\n\t\t\tfor(;k<=len;k++){\n\
    \t\t\t\tpow1[k]=pow1[k-1]*base%mod1;\n\t\t\t\tpow2[k]=pow2[k-1]*base%mod2;\n\t\
    \t\t}\n\t\t}\n\t}\n\npublic:\n\tusing hash_type=tuple<long long,long long,int>;\n\
    \trolling_hash(){}\n\trolling_hash(const string& s):len(s.length()),h1(len+1),h2(len+1){\n\
    \t\trep(i,len){\n\t\t\th1[i+1]=(h1[i]*base+s[i])%mod1;\n\t\t\th2[i+1]=(h2[i]*base+s[i])%mod2;\n\
    \t\t}\n\t}\n\ttemplate<class T>\n\trolling_hash(const vector<T>& a):len(a.size()),h1(len+1),h2(len+1){\n\
    \t\trep(i,len){\n\t\t\th1[i+1]=(h1[i]*base+a[i])%mod1; if(h1[i+1]<0) h1[i+1]+=mod1;\n\
    \t\t\th2[i+1]=(h2[i]*base+a[i])%mod2; if(h2[i+1]<0) h2[i+1]+=mod2;\n\t\t}\n\t\
    }\n\thash_type get_hash(int l,int r)const{\n\t\tassert(0<=l && l<=r && r<=len);\n\
    \t\tallocate(r-l);\n\t\tauto res1=(h1[r]-h1[l]*pow1[r-l])%mod1; if(res1<0) res1+=mod1;\n\
    \t\tauto res2=(h2[r]-h2[l]*pow2[r-l])%mod2; if(res2<0) res2+=mod2;\n\t\treturn\
    \ {res1,res2,r-l};\n\t}\n\tstatic hash_type get_hash(const string& s){\n\t\tlong\
    \ long res1=0,res2=0;\n\t\trep(i,s.length()){\n\t\t\tres1=(res1*base+s[i])%mod1;\n\
    \t\t\tres2=(res2*base+s[i])%mod2;\n\t\t}\n\t\treturn {res1,res2,s.length()};\n\
    \t}\n\ttemplate<class T>\n\tstatic hash_type get_hash(const vector<T>& a){\n\t\
    \tlong long res1=0,res2=0;\n\t\trep(i,a.size()){\n\t\t\tres1=(res1*base+a[i])%mod1;\n\
    \t\t\tres2=(res2*base+a[i])%mod2;\n\t\t}\n\t\treturn {res1,res2,a.size()};\n\t\
    }\n\tfriend hash_type operator*(const hash_type&,const hash_type&);\n};\n\nrolling_hash::hash_type\
    \ operator*(const rolling_hash::hash_type& H1,const rolling_hash::hash_type& H2){\n\
    \tlong long h11,h12,h21,h22;\n\tint len1,len2;\n\ttie(h11,h12,len1)=H1;\n\ttie(h21,h22,len2)=H2;\n\
    \n\trolling_hash::allocate(len2);\n\tlong long res1=(h11*rolling_hash::pow1[len2]+h21)%rolling_hash::mod1;\n\
    \tlong long res2=(h12*rolling_hash::pow2[len2]+h22)%rolling_hash::mod2;\n\treturn\
    \ {res1,res2,len1+len2};\n}\n"
  code: "class rolling_hash{\n\tstatic const long long base=10007,mod1=1e9+7,mod2=1e9+9;\n\
    \tinline static vector<long long> pow1={1},pow2={1};\n\tint len;\n\tvector<long\
    \ long> h1,h2;\n\n\tstatic void allocate(int len){\n\t\tif(pow1.size()<=len){\n\
    \t\t\tint k=pow1.size();\n\t\t\tpow1.resize(len+1);\n\t\t\tpow2.resize(len+1);\n\
    \t\t\tfor(;k<=len;k++){\n\t\t\t\tpow1[k]=pow1[k-1]*base%mod1;\n\t\t\t\tpow2[k]=pow2[k-1]*base%mod2;\n\
    \t\t\t}\n\t\t}\n\t}\n\npublic:\n\tusing hash_type=tuple<long long,long long,int>;\n\
    \trolling_hash(){}\n\trolling_hash(const string& s):len(s.length()),h1(len+1),h2(len+1){\n\
    \t\trep(i,len){\n\t\t\th1[i+1]=(h1[i]*base+s[i])%mod1;\n\t\t\th2[i+1]=(h2[i]*base+s[i])%mod2;\n\
    \t\t}\n\t}\n\ttemplate<class T>\n\trolling_hash(const vector<T>& a):len(a.size()),h1(len+1),h2(len+1){\n\
    \t\trep(i,len){\n\t\t\th1[i+1]=(h1[i]*base+a[i])%mod1; if(h1[i+1]<0) h1[i+1]+=mod1;\n\
    \t\t\th2[i+1]=(h2[i]*base+a[i])%mod2; if(h2[i+1]<0) h2[i+1]+=mod2;\n\t\t}\n\t\
    }\n\thash_type get_hash(int l,int r)const{\n\t\tassert(0<=l && l<=r && r<=len);\n\
    \t\tallocate(r-l);\n\t\tauto res1=(h1[r]-h1[l]*pow1[r-l])%mod1; if(res1<0) res1+=mod1;\n\
    \t\tauto res2=(h2[r]-h2[l]*pow2[r-l])%mod2; if(res2<0) res2+=mod2;\n\t\treturn\
    \ {res1,res2,r-l};\n\t}\n\tstatic hash_type get_hash(const string& s){\n\t\tlong\
    \ long res1=0,res2=0;\n\t\trep(i,s.length()){\n\t\t\tres1=(res1*base+s[i])%mod1;\n\
    \t\t\tres2=(res2*base+s[i])%mod2;\n\t\t}\n\t\treturn {res1,res2,s.length()};\n\
    \t}\n\ttemplate<class T>\n\tstatic hash_type get_hash(const vector<T>& a){\n\t\
    \tlong long res1=0,res2=0;\n\t\trep(i,a.size()){\n\t\t\tres1=(res1*base+a[i])%mod1;\n\
    \t\t\tres2=(res2*base+a[i])%mod2;\n\t\t}\n\t\treturn {res1,res2,a.size()};\n\t\
    }\n\tfriend hash_type operator*(const hash_type&,const hash_type&);\n};\n\nrolling_hash::hash_type\
    \ operator*(const rolling_hash::hash_type& H1,const rolling_hash::hash_type& H2){\n\
    \tlong long h11,h12,h21,h22;\n\tint len1,len2;\n\ttie(h11,h12,len1)=H1;\n\ttie(h21,h22,len2)=H2;\n\
    \n\trolling_hash::allocate(len2);\n\tlong long res1=(h11*rolling_hash::pow1[len2]+h21)%rolling_hash::mod1;\n\
    \tlong long res2=(h12*rolling_hash::pow2[len2]+h22)%rolling_hash::mod2;\n\treturn\
    \ {res1,res2,len1+len2};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/library/string/rolling_hash.hpp
- /library/library/string/rolling_hash.hpp.html
title: library/string/rolling_hash.hpp
---
