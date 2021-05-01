Real dist(const point& a,const point& b){ return abs(a-b); }

Real dist(const line& L,const point& p){
	return abs(cross(L.b-L.a,p-L.a))/abs(L.a-L.b);
}

Real dist(const segment &S,const point &p){
	if(sgn(dot(S.b-S.a,p-S.a))<=0) return dist(p,S.a);
	if(sgn(dot(S.a-S.b,p-S.b))<=0) return dist(p,S.b);
	return abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);
}
