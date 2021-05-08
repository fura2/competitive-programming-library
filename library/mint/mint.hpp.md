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
  bundledCode: "#line 1 \"library/mint/mint.hpp\"\n// MOD \u306E\u5024\u3092 2 * MOD\
    \ > INT_MAX \u3068\u306A\u308B\u3088\u3046\u306B\u8A2D\u5B9A\u3059\u308B\u3068\
    \u30D0\u30B0\u308B\u306E\u3067\u6CE8\u610F\n// \u305D\u306E\u3068\u304D\u306F\
    \ 6 \u884C\u76EE\u3092 long long x; \u306B\u66F8\u304D\u63DB\u3048\u308C\u3070\
    \u3088\u3044\n\nclass mint{\n\tstatic const int MOD=1e9+7;\n//\tstatic const int\
    \ MOD=998244353;\n\tint x;\npublic:\n\tmint():x(0){}\n\tmint(long long y){ x=y%MOD;\
    \ if(x<0) x+=MOD; }\n\n\tmint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD;\
    \ return *this; }\n\tmint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD;\
    \ return *this; }\n\tmint& operator*=(const mint& m){ x=(long long)x*m.x%MOD;\
    \ return *this; }\n\tmint& operator/=(const mint& m){ return *this*=inverse(m);\
    \ }\n\tmint operator+(const mint& m)const{ return mint(*this)+=m; }\n\tmint operator-(const\
    \ mint& m)const{ return mint(*this)-=m; }\n\tmint operator*(const mint& m)const{\
    \ return mint(*this)*=m; }\n\tmint operator/(const mint& m)const{ return mint(*this)/=m;\
    \ }\n\tmint operator-()const{ return -x; }\n\n\tfriend mint inverse(const mint&\
    \ m){\n\t\tint a=m.x,b=MOD,u=1,v=0;\n\t\twhile(b>0){ int t=a/b; a-=t*b; swap(a,b);\
    \ u-=t*v; swap(u,v); }\n\t\treturn u;\n\t}\n\n\tfriend istream& operator>>(istream&\
    \ is,mint& m){ long long t; is>>t; m=t; return is; }\n\tfriend ostream& operator<<(ostream&\
    \ os,const mint& m){ return os<<m.x; }\n\tint to_int()const{ return x; }\n};\n\
    \nmint operator+(long long x,const mint& m){ return mint(x)+m; }\nmint operator-(long\
    \ long x,const mint& m){ return mint(x)-m; }\nmint operator*(long long x,const\
    \ mint& m){ return mint(x)*m; }\nmint operator/(long long x,const mint& m){ return\
    \ mint(x)/m; }\n"
  code: "// MOD \u306E\u5024\u3092 2 * MOD > INT_MAX \u3068\u306A\u308B\u3088\u3046\
    \u306B\u8A2D\u5B9A\u3059\u308B\u3068\u30D0\u30B0\u308B\u306E\u3067\u6CE8\u610F\
    \n// \u305D\u306E\u3068\u304D\u306F 6 \u884C\u76EE\u3092 long long x; \u306B\u66F8\
    \u304D\u63DB\u3048\u308C\u3070\u3088\u3044\n\nclass mint{\n\tstatic const int\
    \ MOD=1e9+7;\n//\tstatic const int MOD=998244353;\n\tint x;\npublic:\n\tmint():x(0){}\n\
    \tmint(long long y){ x=y%MOD; if(x<0) x+=MOD; }\n\n\tmint& operator+=(const mint&\
    \ m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }\n\tmint& operator-=(const mint&\
    \ m){ x-=m.x; if(x<   0) x+=MOD; return *this; }\n\tmint& operator*=(const mint&\
    \ m){ x=(long long)x*m.x%MOD; return *this; }\n\tmint& operator/=(const mint&\
    \ m){ return *this*=inverse(m); }\n\tmint operator+(const mint& m)const{ return\
    \ mint(*this)+=m; }\n\tmint operator-(const mint& m)const{ return mint(*this)-=m;\
    \ }\n\tmint operator*(const mint& m)const{ return mint(*this)*=m; }\n\tmint operator/(const\
    \ mint& m)const{ return mint(*this)/=m; }\n\tmint operator-()const{ return -x;\
    \ }\n\n\tfriend mint inverse(const mint& m){\n\t\tint a=m.x,b=MOD,u=1,v=0;\n\t\
    \twhile(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }\n\t\treturn u;\n\
    \t}\n\n\tfriend istream& operator>>(istream& is,mint& m){ long long t; is>>t;\
    \ m=t; return is; }\n\tfriend ostream& operator<<(ostream& os,const mint& m){\
    \ return os<<m.x; }\n\tint to_int()const{ return x; }\n};\n\nmint operator+(long\
    \ long x,const mint& m){ return mint(x)+m; }\nmint operator-(long long x,const\
    \ mint& m){ return mint(x)-m; }\nmint operator*(long long x,const mint& m){ return\
    \ mint(x)*m; }\nmint operator/(long long x,const mint& m){ return mint(x)/m; }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/mint/mint.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mint/mint.hpp
layout: document
redirect_from:
- /library/library/mint/mint.hpp
- /library/library/mint/mint.hpp.html
title: library/mint/mint.hpp
---
