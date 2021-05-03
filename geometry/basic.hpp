using Real=double;

constexpr Real EPS=1e-8;
constexpr Real PI=acos(Real(-1));

int sgn(const Real& x){ return x>EPS?1:x<-EPS?-1:0; }

class point{
public:
	Real x,y;
	point(){}
	point(const Real& x,const Real& y):x(x),y(y){}
	point& operator+=(const point& p){ x+=p.x; y+=p.y; return *this; }
	point& operator-=(const point& p){ x-=p.x; y-=p.y; return *this; }
	point& operator*=(const Real& c){ x*=c; y*=c; return *this; }
	point& operator/=(const Real& c){ x/=c; y/=c; return *this; }
	point operator+(const point& p)const{ return point(*this)+=p; }
	point operator-(const point& p)const{ return point(*this)-=p; }
	point operator*(const Real& c)const{ return point(*this)*=c; }
	point operator/(const Real& c)const{ return point(*this)/=c; }
	point operator-()const{ return point(-x,-y); }
	bool operator==(const point& p)const{ return sgn(x-p.x)==0 && sgn(y-p.y)==0; }
	bool operator!=(const point& p)const{ return !((*this)==p); }

	friend point operator*(const Real& c,const point& p){ return p*c; }
};

Real dot  (const point& p,const point& q){ return p.x*q.x+p.y*q.y; }
Real cross(const point& p,const point& q){ return p.x*q.y-p.y*q.x; }

Real abs (const point& p){ return sqrt(p.x*p.x+p.y*p.y); }
Real abs2(const point& p){ return p.x*p.x+p.y*p.y; }

point rot(const point& p,const Real& theta){
	return {p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta)};
}

Real arg(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }

class line{
public:
	point a,b;
	line(){}
	line(const point& a,const point& b):a(a),b(b){}
	bool operator==(const line& L)const{
		return sgn(cross(b-a,L.b-L.a))==0 && sgn(cross(L.a-a,L.b-a))==0;
	}
	bool operator!=(const line& L)const{ return !((*this)==L); }
};

class segment{
public:
	point a,b;
	segment(){}
	segment(const point& a,const point& b):a(a),b(b){}
	operator line()const{ return line(a,b); }
};

using polygon=vector<point>;

class circle{
public:
	point c;
	Real r;
	circle(){}
	circle(const point& c,const Real& r):c(c),r(r){}
};

point proj(const point& p,const line& L){ return L.a+dot(p-L.a,L.b-L.a)/abs2(L.b-L.a)*(L.b-L.a); }
