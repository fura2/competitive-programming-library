#pragma once
#include "../template.hpp"

template<class T>
class min_monoid{
	T a;
public:
	min_monoid():a(numeric_limits<T>::max()){}
	min_monoid(const T& val):a(val){}
	min_monoid operator*(const min_monoid& x)const{
		return min(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};
