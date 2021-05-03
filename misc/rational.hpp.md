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
  bundledCode: "#line 1 \"misc/rational.hpp\"\ntemplate<class T>\nclass rational{\n\
    \tT num,den;\n\n\trational& reduce(){\n\t\tT g=gcd(num,den);\n\t\tif(g<-1) g*=-1;\n\
    \t\tif(g>1) num/=g, den/=g;\n\t\treturn *this;\n\t}\npublic:\n\trational(const\
    \ T& num=0){ *this=num; }\n\trational(const T& num,const T& den):num(num),den(den){\n\
    \t\tif(den<0){\n\t\t\tthis->num*=-1;\n\t\t\tthis->den*=-1;\n\t\t}\n\t\treduce();\n\
    \t}\n\tconst T& nume()const{ return num; }\n\tconst T& deno()const{ return den;\
    \ }\n\trational& operator+=(const T& v){ num+=den*v; return reduce(); }\n\trational&\
    \ operator-=(const T& v){ num-=den*v; return reduce(); }\n\trational& operator+=(const\
    \ rational& r){\n\t\tT g=gcd(den,r.den);\n\t\tden/=g;\n\t\tnum*=r.den/g;\n\t\t\
    num+=den*r.num;\n\t\tden*=r.den;\n\t\treturn reduce();\n\t}\n\trational& operator-=(const\
    \ rational& r){\n\t\tT g=gcd(den,r.den);\n\t\tden/=g;\n\t\tnum*=r.den/g;\n\t\t\
    num-=den*r.num;\n\t\tden*=r.den;\n\t\treturn reduce();\n\t}\n\trational& operator*=(const\
    \ rational& r){\n\t\tT g1=gcd(num,r.den),g2=gcd(den,r.num);\n\t\tnum/=g1; num*=r.num/g2;\n\
    \t\tden/=g2; den*=r.den/g1;\n\t\tif(den<0) num*=-1, den*=-1;\n\t\treturn reduce();\n\
    \t}\n\trational& operator/=(const rational& r){\n\t\tT g1=gcd(num,r.num),g2=gcd(den,r.den);\n\
    \t\tnum/=g1; num*=r.den/g2;\n\t\tden/=g2; den*=r.num/g1;\n\t\tif(den<0) num*=-1,\
    \ den*=-1;\n\t\treturn reduce();\n\t}\n\trational operator+(const T& v)const{\
    \ return rational(*this)+=v; }\n\trational operator-(const T& v)const{ return\
    \ rational(*this)-=v; }\n\trational operator+(const rational& r)const{ return\
    \ rational(*this)+=r; }\n\trational operator-(const rational& r)const{ return\
    \ rational(*this)-=r; }\n\trational operator*(const rational& r)const{ return\
    \ rational(*this)*=r; }\n\trational operator/(const rational& r)const{ return\
    \ rational(*this)/=r; }\n\tbool operator< (const rational& r)const{ return num*r.den<r.num*den;\
    \ }\n\tbool operator> (const rational& r)const{ return r<(*this); }\n\tbool operator<=(const\
    \ rational& r)const{ return !(r<(*this)); }\n\tbool operator>=(const rational&\
    \ r)const{ return !((*this)<r); }\n\tbool operator==(const rational& r)const{\
    \ return !((*this)<r) && !(r<(*this)); }\n\tbool operator!=(const rational& r)const{\
    \ return (*this)<r || r<(*this); }\n\trational& operator=(const T& v){ num=v;\
    \ den=1; return *this; }\n\tfriend ostream& operator<<(ostream& os,const rational&\
    \ r){ return os<<r.num<<'/'<<r.den; }\n\n\tfriend rational abs(const rational&\
    \ r){ return rational(abs(r.den),r.num); }\n};\n"
  code: "template<class T>\nclass rational{\n\tT num,den;\n\n\trational& reduce(){\n\
    \t\tT g=gcd(num,den);\n\t\tif(g<-1) g*=-1;\n\t\tif(g>1) num/=g, den/=g;\n\t\t\
    return *this;\n\t}\npublic:\n\trational(const T& num=0){ *this=num; }\n\trational(const\
    \ T& num,const T& den):num(num),den(den){\n\t\tif(den<0){\n\t\t\tthis->num*=-1;\n\
    \t\t\tthis->den*=-1;\n\t\t}\n\t\treduce();\n\t}\n\tconst T& nume()const{ return\
    \ num; }\n\tconst T& deno()const{ return den; }\n\trational& operator+=(const\
    \ T& v){ num+=den*v; return reduce(); }\n\trational& operator-=(const T& v){ num-=den*v;\
    \ return reduce(); }\n\trational& operator+=(const rational& r){\n\t\tT g=gcd(den,r.den);\n\
    \t\tden/=g;\n\t\tnum*=r.den/g;\n\t\tnum+=den*r.num;\n\t\tden*=r.den;\n\t\treturn\
    \ reduce();\n\t}\n\trational& operator-=(const rational& r){\n\t\tT g=gcd(den,r.den);\n\
    \t\tden/=g;\n\t\tnum*=r.den/g;\n\t\tnum-=den*r.num;\n\t\tden*=r.den;\n\t\treturn\
    \ reduce();\n\t}\n\trational& operator*=(const rational& r){\n\t\tT g1=gcd(num,r.den),g2=gcd(den,r.num);\n\
    \t\tnum/=g1; num*=r.num/g2;\n\t\tden/=g2; den*=r.den/g1;\n\t\tif(den<0) num*=-1,\
    \ den*=-1;\n\t\treturn reduce();\n\t}\n\trational& operator/=(const rational&\
    \ r){\n\t\tT g1=gcd(num,r.num),g2=gcd(den,r.den);\n\t\tnum/=g1; num*=r.den/g2;\n\
    \t\tden/=g2; den*=r.num/g1;\n\t\tif(den<0) num*=-1, den*=-1;\n\t\treturn reduce();\n\
    \t}\n\trational operator+(const T& v)const{ return rational(*this)+=v; }\n\trational\
    \ operator-(const T& v)const{ return rational(*this)-=v; }\n\trational operator+(const\
    \ rational& r)const{ return rational(*this)+=r; }\n\trational operator-(const\
    \ rational& r)const{ return rational(*this)-=r; }\n\trational operator*(const\
    \ rational& r)const{ return rational(*this)*=r; }\n\trational operator/(const\
    \ rational& r)const{ return rational(*this)/=r; }\n\tbool operator< (const rational&\
    \ r)const{ return num*r.den<r.num*den; }\n\tbool operator> (const rational& r)const{\
    \ return r<(*this); }\n\tbool operator<=(const rational& r)const{ return !(r<(*this));\
    \ }\n\tbool operator>=(const rational& r)const{ return !((*this)<r); }\n\tbool\
    \ operator==(const rational& r)const{ return !((*this)<r) && !(r<(*this)); }\n\
    \tbool operator!=(const rational& r)const{ return (*this)<r || r<(*this); }\n\t\
    rational& operator=(const T& v){ num=v; den=1; return *this; }\n\tfriend ostream&\
    \ operator<<(ostream& os,const rational& r){ return os<<r.num<<'/'<<r.den; }\n\
    \n\tfriend rational abs(const rational& r){ return rational(abs(r.den),r.num);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rational.hpp
  requiredBy: []
  timestamp: '2021-05-03 18:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/rational.hpp
layout: document
redirect_from:
- /library/misc/rational.hpp
- /library/misc/rational.hpp.html
title: misc/rational.hpp
---
