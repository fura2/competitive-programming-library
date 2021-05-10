#pragma once
#include "../template.hpp"

template<class T>
class add_monoid{
	T a;
public:
	add_monoid(const T& val=T()):a(val){}
	add_monoid operator*(const add_monoid& x)const{
		return a+x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};
