#pragma once
#include "../template.hpp"

template<class T>
class max_monoid{
	T a;
public:
	max_monoid(const T& val=numeric_limits<T>::min()):a(val){}
	max_monoid operator*(const max_monoid& x)const{
		return max(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};
