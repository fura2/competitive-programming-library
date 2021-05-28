#pragma once
#include "../template.hpp"

template<class T>
class gcd_monoid{
	T a;
public:
	gcd_monoid(const T& val=T()):a(val){}
	gcd_monoid operator*(const gcd_monoid& x)const{
		return gcd(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};
