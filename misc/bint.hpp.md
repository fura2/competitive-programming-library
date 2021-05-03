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
  bundledCode: "#line 1 \"misc/bint.hpp\"\nclass bint{\n\tstatic const int BASE=1000000000;\n\
    \tint sign;\n\tvector<int> a;\n\n\tbint& normalize(){\n\t\twhile(!a.empty() &&\
    \ a.back()==0) a.pop_back();\n\t\tif(a.empty()) sign=1;\n\t\treturn *this;\n\t\
    }\npublic:\n\tbint(long long v=0){ *this=v; }\n\tbint(const string& s){ *this=s;\
    \ }\n\tbint& operator=(long long v){\n\t\tif(v>=0) sign=1;\n\t\telse sign=-1,\
    \ v*=-1;\n\t\ta.clear();\n\t\tfor(;v>0;v/=BASE) a.emplace_back(v%BASE);\n\t\t\
    return *this;\n\t}\n\tbint& operator=(const string& s){\n\t\tint n=s.length(),t=0;\n\
    \t\tsign=1;\n\t\tif     (s[0]=='+') t++;\n\t\telse if(s[0]=='-') t++, sign=-1;\n\
    \t\ta.clear();\n\t\tfor(int i=n;i>t;i-=9) a.emplace_back(stoi(s.substr(max(i-9,t),i-max(i-9,t))));\n\
    \t\treturn normalize();\n\t}\n\tbint& operator+=(const bint& b){\n\t\tint m=a.size(),n=b.a.size(),carry=0;\n\
    \t\tif(sign==b.sign){\n\t\t\tif(m<n) a.resize(n), m=n;\n\t\t\trep(i,n){\n\t\t\t\
    \ta[i]+=b.a[i]+carry;\n\t\t\t\tif(a[i]>=BASE) a[i]-=BASE, carry=1;\n\t\t\t\telse\
    \ carry=0;\n\t\t\t}\n\t\t\tfor(int i=n;carry>0;i++){\n\t\t\t\tif(a.size()==i)\
    \ a.resize(i+1);\n\t\t\t\ta[i]+=carry;\n\t\t\t\tif(a[i]>=BASE) a[i]-=BASE, carry=1;\n\
    \t\t\t\telse carry=0;\n\t\t\t}\n\t\t}\n\t\telse if(abs(*this)>=abs(b)){\n\t\t\t\
    rep(i,n){\n\t\t\t\ta[i]-=b.a[i]+carry;\n\t\t\t\tif(a[i]<0) a[i]+=BASE, carry=1;\n\
    \t\t\t\telse carry=0;\n\t\t\t}\n\t\t\tfor(int i=n;carry>0;i++){\n\t\t\t\ta[i]-=carry;\n\
    \t\t\t\tif(a[i]<0) a[i]+=BASE, carry=1;\n\t\t\t\telse carry=0;\n\t\t\t}\n\t\t\
    }\n\t\telse{\n\t\t\ta.resize(n);\n\t\t\trep(i,n){\n\t\t\t\ta[i]=b.a[i]-(a[i]+carry);\n\
    \t\t\t\tif(a[i]<0) a[i]+=BASE, carry=1;\n\t\t\t\telse carry=0;\n\t\t\t}\n\t\t\t\
    sign*=-1;\n\t\t}\n\t\treturn normalize();\n\t}\n\tbint& operator-=(const bint&\
    \ b){\n\t\tsign*=-1;\n\t\t*this+=b;\n\t\tsign*=-1;\n\t\treturn normalize();\n\t\
    }\n\tbint& operator*=(int v){\n\t\tif(v<0) sign*=-1, v=-v;\n\t\tint n=a.size(),carry=0;\n\
    \t\trep(i,n){\n\t\t\tauto tmp=(long long)a[i]*v+carry;\n\t\t\ta[i]=tmp%BASE;\n\
    \t\t\tcarry=tmp/BASE;\n\t\t}\n\t\tif(carry>0) a.emplace_back(carry);\n\t\treturn\
    \ normalize();\n\t}\n\tbint& operator/=(int v){\n\t\tif(v<0) sign*=-1, v*=-1;\n\
    \t\tfor(int i=a.size()-1,rem=0;i>=0;i--){\n\t\t\tauto tmp=a[i]+(long long)rem*BASE;\n\
    \t\t\ta[i]=tmp/v;\n\t\t\trem=tmp%v;\n\t\t}\n\t\treturn normalize();\n\t}\n\tbint&\
    \ operator*=(const long long& v){ return *this=(*this)*bint(v); }\n\tbint& operator/=(const\
    \ long long& v){ return *this=(*this)/bint(v); }\n\tbint& operator*=(const bint&\
    \ b){ return *this=(*this)*b; }\n\tbint& operator/=(const bint& b){ return *this=(*this)/b;\
    \ }\n\tbint& operator%=(const bint& b){ return *this=(*this)%b; }\n\tbint operator+(const\
    \ bint& b)const{ return bint(*this)+=b; }\n\tbint operator-(const bint& b)const{\
    \ return bint(*this)-=b; }\n\tbint operator*(int v)const{ return bint(*this)*=v;\
    \ }\n\tbint operator/(int v)const{ return bint(*this)/=v; }\n\tbint operator*(const\
    \ long long& v)const{ return bint(*this)*=bint(v); }\n\tbint operator/(const long\
    \ long& v)const{ return bint(*this)/=bint(v); }\n\tbint operator*(const bint&\
    \ b)const{\n\t\tint m=a.size(),n=b.a.size();\n\t\tif(m==0 || n==0) return 0;\n\
    \t\tbint res;\n\t\tres.a.resize(m+n);\n\t\trep(i,m) rep(j,n) {\n\t\t\tauto tmp=(long\
    \ long)a[i]*b.a[j];\n\t\t\tres.a[i+j]+=tmp%BASE;\n\t\t\tif(tmp>=BASE) res.a[i+j+1]+=tmp/BASE;\n\
    \t\t\tfor(int k=0;;k++){\n\t\t\t\tif(k>0 && res.a[i+j+k]<BASE) break;\n\t\t\t\t\
    if(res.a[i+j+k]>=BASE){\n\t\t\t\t\tres.a[i+j+k]-=BASE;\n\t\t\t\t\tres.a[i+j+k+1]++;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tres.sign=sign*b.sign;\n\t\treturn res.normalize();\n\
    \t}\n\tbint operator/(const bint& b)const{ return divmod(*this,b).first; }\n\t\
    bint operator%(const bint& b)const{ return divmod(*this,b).second; }\n\tbint operator-()const{\
    \ bint res=*this; if(res!=0) res.sign*=-1; return res; }\n\tbool operator< (const\
    \ bint& b)const{\n\t\tif(sign!=b.sign) return sign<b.sign;\n\t\tint m=a.size(),n=b.a.size();\n\
    \t\tif(m!=n) return sign==1?m<n:m>n;\n\t\tfor(int i=m-1;i>=0;i--) if(a[i]!=b.a[i])\
    \ return sign==1?a[i]<b.a[i]:a[i]>b.a[i];\n\t\treturn false;\n\t}\n\tbool operator>\
    \ (const bint& b)const{ return b<(*this); }\n\tbool operator<=(const bint& b)const{\
    \ return !(b<(*this)); }\n\tbool operator>=(const bint& b)const{ return !((*this)<b);\
    \ }\n\tbool operator==(const bint& b)const{ return !((*this)<b) && !(b<(*this));\
    \ }\n\tbool operator!=(const bint& b)const{ return (*this)<b || b<(*this); }\n\
    \tfriend istream& operator>>(istream& is,bint& b){\n\t\tstring s;\n\t\tis>>s;\n\
    \t\tb=bint(s);\n\t\treturn is;\n\t}\n\tfriend ostream& operator<<(ostream& os,const\
    \ bint& b){\n\t\tif(b.sign==-1) os<<'-';\n\t\tos<<(b.a.empty()?0:b.a.back());\n\
    \t\tfor(int i=b.a.size()-2;i>=0;i--) os<<setw(9)<<setfill('0')<<b.a[i];\n\t\t\
    return os;\n\t}\n\n\tfriend bint abs(const bint& b){ return b.sign==1?b:-b; }\n\
    \n\tfriend pair<bint,bint> divmod(const bint& a1,const bint& b1){\n\t\tint norm=BASE/(b1.a.back()+1);\n\
    \t\tbint a=abs(a1)*norm,b=abs(b1)*norm,q,r;\n\t\tq.a.resize(a.a.size());\n\t\t\
    for(int i=a.a.size()-1;i>=0;i--){\n\t\t\tr*=BASE;\n\t\t\tr+=a.a[i];\n\t\t\tint\
    \ s1=(r.a.size()<=b.a.size()?0:r.a[b.a.size()]);\n\t\t\tint s2=(r.a.size()<=b.a.size()-1?0:r.a[b.a.size()-1]);\n\
    \t\t\tint d=((long long)BASE*s1+s2)/b.a.back();\n\t\t\tr-=b*d;\n\t\t\twhile(r<0)\
    \ r+=b, d--;\n\t\t\tq.a[i]=d;\n\t\t}\n\t\tq.sign=a1.sign*b1.sign;\n\t\tr.sign=a1.sign;\n\
    \t\treturn make_pair(q.normalize(),r.normalize()/norm);\n\t}\n};\n\nstring to_string(const\
    \ bint& b){\n\tstringstream ss;\n\tss<<b;\n\treturn ss.str();\n}\n"
  code: "class bint{\n\tstatic const int BASE=1000000000;\n\tint sign;\n\tvector<int>\
    \ a;\n\n\tbint& normalize(){\n\t\twhile(!a.empty() && a.back()==0) a.pop_back();\n\
    \t\tif(a.empty()) sign=1;\n\t\treturn *this;\n\t}\npublic:\n\tbint(long long v=0){\
    \ *this=v; }\n\tbint(const string& s){ *this=s; }\n\tbint& operator=(long long\
    \ v){\n\t\tif(v>=0) sign=1;\n\t\telse sign=-1, v*=-1;\n\t\ta.clear();\n\t\tfor(;v>0;v/=BASE)\
    \ a.emplace_back(v%BASE);\n\t\treturn *this;\n\t}\n\tbint& operator=(const string&\
    \ s){\n\t\tint n=s.length(),t=0;\n\t\tsign=1;\n\t\tif     (s[0]=='+') t++;\n\t\
    \telse if(s[0]=='-') t++, sign=-1;\n\t\ta.clear();\n\t\tfor(int i=n;i>t;i-=9)\
    \ a.emplace_back(stoi(s.substr(max(i-9,t),i-max(i-9,t))));\n\t\treturn normalize();\n\
    \t}\n\tbint& operator+=(const bint& b){\n\t\tint m=a.size(),n=b.a.size(),carry=0;\n\
    \t\tif(sign==b.sign){\n\t\t\tif(m<n) a.resize(n), m=n;\n\t\t\trep(i,n){\n\t\t\t\
    \ta[i]+=b.a[i]+carry;\n\t\t\t\tif(a[i]>=BASE) a[i]-=BASE, carry=1;\n\t\t\t\telse\
    \ carry=0;\n\t\t\t}\n\t\t\tfor(int i=n;carry>0;i++){\n\t\t\t\tif(a.size()==i)\
    \ a.resize(i+1);\n\t\t\t\ta[i]+=carry;\n\t\t\t\tif(a[i]>=BASE) a[i]-=BASE, carry=1;\n\
    \t\t\t\telse carry=0;\n\t\t\t}\n\t\t}\n\t\telse if(abs(*this)>=abs(b)){\n\t\t\t\
    rep(i,n){\n\t\t\t\ta[i]-=b.a[i]+carry;\n\t\t\t\tif(a[i]<0) a[i]+=BASE, carry=1;\n\
    \t\t\t\telse carry=0;\n\t\t\t}\n\t\t\tfor(int i=n;carry>0;i++){\n\t\t\t\ta[i]-=carry;\n\
    \t\t\t\tif(a[i]<0) a[i]+=BASE, carry=1;\n\t\t\t\telse carry=0;\n\t\t\t}\n\t\t\
    }\n\t\telse{\n\t\t\ta.resize(n);\n\t\t\trep(i,n){\n\t\t\t\ta[i]=b.a[i]-(a[i]+carry);\n\
    \t\t\t\tif(a[i]<0) a[i]+=BASE, carry=1;\n\t\t\t\telse carry=0;\n\t\t\t}\n\t\t\t\
    sign*=-1;\n\t\t}\n\t\treturn normalize();\n\t}\n\tbint& operator-=(const bint&\
    \ b){\n\t\tsign*=-1;\n\t\t*this+=b;\n\t\tsign*=-1;\n\t\treturn normalize();\n\t\
    }\n\tbint& operator*=(int v){\n\t\tif(v<0) sign*=-1, v=-v;\n\t\tint n=a.size(),carry=0;\n\
    \t\trep(i,n){\n\t\t\tauto tmp=(long long)a[i]*v+carry;\n\t\t\ta[i]=tmp%BASE;\n\
    \t\t\tcarry=tmp/BASE;\n\t\t}\n\t\tif(carry>0) a.emplace_back(carry);\n\t\treturn\
    \ normalize();\n\t}\n\tbint& operator/=(int v){\n\t\tif(v<0) sign*=-1, v*=-1;\n\
    \t\tfor(int i=a.size()-1,rem=0;i>=0;i--){\n\t\t\tauto tmp=a[i]+(long long)rem*BASE;\n\
    \t\t\ta[i]=tmp/v;\n\t\t\trem=tmp%v;\n\t\t}\n\t\treturn normalize();\n\t}\n\tbint&\
    \ operator*=(const long long& v){ return *this=(*this)*bint(v); }\n\tbint& operator/=(const\
    \ long long& v){ return *this=(*this)/bint(v); }\n\tbint& operator*=(const bint&\
    \ b){ return *this=(*this)*b; }\n\tbint& operator/=(const bint& b){ return *this=(*this)/b;\
    \ }\n\tbint& operator%=(const bint& b){ return *this=(*this)%b; }\n\tbint operator+(const\
    \ bint& b)const{ return bint(*this)+=b; }\n\tbint operator-(const bint& b)const{\
    \ return bint(*this)-=b; }\n\tbint operator*(int v)const{ return bint(*this)*=v;\
    \ }\n\tbint operator/(int v)const{ return bint(*this)/=v; }\n\tbint operator*(const\
    \ long long& v)const{ return bint(*this)*=bint(v); }\n\tbint operator/(const long\
    \ long& v)const{ return bint(*this)/=bint(v); }\n\tbint operator*(const bint&\
    \ b)const{\n\t\tint m=a.size(),n=b.a.size();\n\t\tif(m==0 || n==0) return 0;\n\
    \t\tbint res;\n\t\tres.a.resize(m+n);\n\t\trep(i,m) rep(j,n) {\n\t\t\tauto tmp=(long\
    \ long)a[i]*b.a[j];\n\t\t\tres.a[i+j]+=tmp%BASE;\n\t\t\tif(tmp>=BASE) res.a[i+j+1]+=tmp/BASE;\n\
    \t\t\tfor(int k=0;;k++){\n\t\t\t\tif(k>0 && res.a[i+j+k]<BASE) break;\n\t\t\t\t\
    if(res.a[i+j+k]>=BASE){\n\t\t\t\t\tres.a[i+j+k]-=BASE;\n\t\t\t\t\tres.a[i+j+k+1]++;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tres.sign=sign*b.sign;\n\t\treturn res.normalize();\n\
    \t}\n\tbint operator/(const bint& b)const{ return divmod(*this,b).first; }\n\t\
    bint operator%(const bint& b)const{ return divmod(*this,b).second; }\n\tbint operator-()const{\
    \ bint res=*this; if(res!=0) res.sign*=-1; return res; }\n\tbool operator< (const\
    \ bint& b)const{\n\t\tif(sign!=b.sign) return sign<b.sign;\n\t\tint m=a.size(),n=b.a.size();\n\
    \t\tif(m!=n) return sign==1?m<n:m>n;\n\t\tfor(int i=m-1;i>=0;i--) if(a[i]!=b.a[i])\
    \ return sign==1?a[i]<b.a[i]:a[i]>b.a[i];\n\t\treturn false;\n\t}\n\tbool operator>\
    \ (const bint& b)const{ return b<(*this); }\n\tbool operator<=(const bint& b)const{\
    \ return !(b<(*this)); }\n\tbool operator>=(const bint& b)const{ return !((*this)<b);\
    \ }\n\tbool operator==(const bint& b)const{ return !((*this)<b) && !(b<(*this));\
    \ }\n\tbool operator!=(const bint& b)const{ return (*this)<b || b<(*this); }\n\
    \tfriend istream& operator>>(istream& is,bint& b){\n\t\tstring s;\n\t\tis>>s;\n\
    \t\tb=bint(s);\n\t\treturn is;\n\t}\n\tfriend ostream& operator<<(ostream& os,const\
    \ bint& b){\n\t\tif(b.sign==-1) os<<'-';\n\t\tos<<(b.a.empty()?0:b.a.back());\n\
    \t\tfor(int i=b.a.size()-2;i>=0;i--) os<<setw(9)<<setfill('0')<<b.a[i];\n\t\t\
    return os;\n\t}\n\n\tfriend bint abs(const bint& b){ return b.sign==1?b:-b; }\n\
    \n\tfriend pair<bint,bint> divmod(const bint& a1,const bint& b1){\n\t\tint norm=BASE/(b1.a.back()+1);\n\
    \t\tbint a=abs(a1)*norm,b=abs(b1)*norm,q,r;\n\t\tq.a.resize(a.a.size());\n\t\t\
    for(int i=a.a.size()-1;i>=0;i--){\n\t\t\tr*=BASE;\n\t\t\tr+=a.a[i];\n\t\t\tint\
    \ s1=(r.a.size()<=b.a.size()?0:r.a[b.a.size()]);\n\t\t\tint s2=(r.a.size()<=b.a.size()-1?0:r.a[b.a.size()-1]);\n\
    \t\t\tint d=((long long)BASE*s1+s2)/b.a.back();\n\t\t\tr-=b*d;\n\t\t\twhile(r<0)\
    \ r+=b, d--;\n\t\t\tq.a[i]=d;\n\t\t}\n\t\tq.sign=a1.sign*b1.sign;\n\t\tr.sign=a1.sign;\n\
    \t\treturn make_pair(q.normalize(),r.normalize()/norm);\n\t}\n};\n\nstring to_string(const\
    \ bint& b){\n\tstringstream ss;\n\tss<<b;\n\treturn ss.str();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/bint.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/bint.hpp
layout: document
redirect_from:
- /library/misc/bint.hpp
- /library/misc/bint.hpp.html
title: misc/bint.hpp
---
