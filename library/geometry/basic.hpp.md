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
  bundledCode: "#line 1 \"library/geometry/basic.hpp\"\nusing Real=double;\n\nconstexpr\
    \ Real EPS=1e-8;\nconstexpr Real PI=acos(Real(-1));\n\nint sgn(const Real& x){\
    \ return x>EPS?1:x<-EPS?-1:0; }\n\nclass point{\npublic:\n\tReal x,y;\n\tpoint(){}\n\
    \tpoint(const Real& x,const Real& y):x(x),y(y){}\n\tpoint& operator+=(const point&\
    \ p){ x+=p.x; y+=p.y; return *this; }\n\tpoint& operator-=(const point& p){ x-=p.x;\
    \ y-=p.y; return *this; }\n\tpoint& operator*=(const Real& c){ x*=c; y*=c; return\
    \ *this; }\n\tpoint& operator/=(const Real& c){ x/=c; y/=c; return *this; }\n\t\
    point operator+(const point& p)const{ return point(*this)+=p; }\n\tpoint operator-(const\
    \ point& p)const{ return point(*this)-=p; }\n\tpoint operator*(const Real& c)const{\
    \ return point(*this)*=c; }\n\tpoint operator/(const Real& c)const{ return point(*this)/=c;\
    \ }\n\tpoint operator-()const{ return point(-x,-y); }\n\tbool operator==(const\
    \ point& p)const{ return sgn(x-p.x)==0 && sgn(y-p.y)==0; }\n\tbool operator!=(const\
    \ point& p)const{ return !((*this)==p); }\n\n\tfriend point operator*(const Real&\
    \ c,const point& p){ return p*c; }\n};\n\nReal dot  (const point& p,const point&\
    \ q){ return p.x*q.x+p.y*q.y; }\nReal cross(const point& p,const point& q){ return\
    \ p.x*q.y-p.y*q.x; }\n\nReal abs (const point& p){ return sqrt(p.x*p.x+p.y*p.y);\
    \ }\nReal abs2(const point& p){ return p.x*p.x+p.y*p.y; }\n\npoint rot(const point&\
    \ p,const Real& theta){\n\treturn {p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta)};\n\
    }\n\nReal arg(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }\n\
    \nclass line{\npublic:\n\tpoint a,b;\n\tline(){}\n\tline(const point& a,const\
    \ point& b):a(a),b(b){}\n\tbool operator==(const line& L)const{\n\t\treturn sgn(cross(b-a,L.b-L.a))==0\
    \ && sgn(cross(L.a-a,L.b-a))==0;\n\t}\n\tbool operator!=(const line& L)const{\
    \ return !((*this)==L); }\n};\n\nclass segment{\npublic:\n\tpoint a,b;\n\tsegment(){}\n\
    \tsegment(const point& a,const point& b):a(a),b(b){}\n\toperator line()const{\
    \ return line(a,b); }\n};\n\nusing polygon=vector<point>;\n\nclass circle{\npublic:\n\
    \tpoint c;\n\tReal r;\n\tcircle(){}\n\tcircle(const point& c,const Real& r):c(c),r(r){}\n\
    };\n\npoint proj(const point& p,const line& L){ return L.a+dot(p-L.a,L.b-L.a)/abs2(L.b-L.a)*(L.b-L.a);\
    \ }\n"
  code: "using Real=double;\n\nconstexpr Real EPS=1e-8;\nconstexpr Real PI=acos(Real(-1));\n\
    \nint sgn(const Real& x){ return x>EPS?1:x<-EPS?-1:0; }\n\nclass point{\npublic:\n\
    \tReal x,y;\n\tpoint(){}\n\tpoint(const Real& x,const Real& y):x(x),y(y){}\n\t\
    point& operator+=(const point& p){ x+=p.x; y+=p.y; return *this; }\n\tpoint& operator-=(const\
    \ point& p){ x-=p.x; y-=p.y; return *this; }\n\tpoint& operator*=(const Real&\
    \ c){ x*=c; y*=c; return *this; }\n\tpoint& operator/=(const Real& c){ x/=c; y/=c;\
    \ return *this; }\n\tpoint operator+(const point& p)const{ return point(*this)+=p;\
    \ }\n\tpoint operator-(const point& p)const{ return point(*this)-=p; }\n\tpoint\
    \ operator*(const Real& c)const{ return point(*this)*=c; }\n\tpoint operator/(const\
    \ Real& c)const{ return point(*this)/=c; }\n\tpoint operator-()const{ return point(-x,-y);\
    \ }\n\tbool operator==(const point& p)const{ return sgn(x-p.x)==0 && sgn(y-p.y)==0;\
    \ }\n\tbool operator!=(const point& p)const{ return !((*this)==p); }\n\n\tfriend\
    \ point operator*(const Real& c,const point& p){ return p*c; }\n};\n\nReal dot\
    \  (const point& p,const point& q){ return p.x*q.x+p.y*q.y; }\nReal cross(const\
    \ point& p,const point& q){ return p.x*q.y-p.y*q.x; }\n\nReal abs (const point&\
    \ p){ return sqrt(p.x*p.x+p.y*p.y); }\nReal abs2(const point& p){ return p.x*p.x+p.y*p.y;\
    \ }\n\npoint rot(const point& p,const Real& theta){\n\treturn {p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta)};\n\
    }\n\nReal arg(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }\n\
    \nclass line{\npublic:\n\tpoint a,b;\n\tline(){}\n\tline(const point& a,const\
    \ point& b):a(a),b(b){}\n\tbool operator==(const line& L)const{\n\t\treturn sgn(cross(b-a,L.b-L.a))==0\
    \ && sgn(cross(L.a-a,L.b-a))==0;\n\t}\n\tbool operator!=(const line& L)const{\
    \ return !((*this)==L); }\n};\n\nclass segment{\npublic:\n\tpoint a,b;\n\tsegment(){}\n\
    \tsegment(const point& a,const point& b):a(a),b(b){}\n\toperator line()const{\
    \ return line(a,b); }\n};\n\nusing polygon=vector<point>;\n\nclass circle{\npublic:\n\
    \tpoint c;\n\tReal r;\n\tcircle(){}\n\tcircle(const point& c,const Real& r):c(c),r(r){}\n\
    };\n\npoint proj(const point& p,const line& L){ return L.a+dot(p-L.a,L.b-L.a)/abs2(L.b-L.a)*(L.b-L.a);\
    \ }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/basic.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/basic.hpp
layout: document
redirect_from:
- /library/library/geometry/basic.hpp
- /library/library/geometry/basic.hpp.html
title: library/geometry/basic.hpp
---
