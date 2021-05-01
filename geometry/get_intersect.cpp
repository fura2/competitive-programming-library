/* 直線と直線の交点 */
/*
	引数
		L1, L2 : 直線
	戻り値
		L1 と L2 の交点
	制約
		二直線は交点を持つこと (平行でない or L1 == L2).
	計算量
		O(1)
	備考
		交点が無限個ある (L1 == L2) ときは L1.a を返す.
*/

point get_intersect(const line& L1,const line& L2){
	Real c1=cross(L1.b-L1.a,L2.b-L2.a);
	Real c2=cross(L1.b-L1.a,L1.b-L2.a);
	if(sgn(c1)==0) return L1.a;
	return L2.a+c2/c1*(L2.b-L2.a);
}

/* 線分と線分の交点 */
/*
	引数
		S1, S2 : 線分
	戻り値
		S1 と S2 の交点
	制約
		二線分は交点を持つこと (intersect(segment, segment) で判定できる).
	計算量
		O(1)
	備考
		交点が無限個あるときは, 4 つの端点のうちいずれかは二線分の共通部分に含まれるので,
		その交点 (のうちの一つ) を返す.
*/

point get_intersect(const segment& S1,const segment& S2){
	Real c1=cross(S1.b-S1.a,S2.b-S2.a);
	Real c2=cross(S1.b-S1.a,S1.b-S2.a);
	if(sgn(c1)==0){
		if(cover(S1,S2.a)) return S2.a;
		if(cover(S1,S2.b)) return S2.b;
		if(cover(S2,S1.a)) return S1.a;
		return S1.b;
	}
	return S2.a+c2/c1*(S2.b-S2.a);
}

/* 円周と直線の交点 */
/*
	引数
		C : 円周
		L : 直線
	戻り値
		交点の集合
	制約
		なし
	計算量
		O(1)
	備考
		C は円盤ではないことに注意!!
*/

vector<point> get_intersect(const circle& C,const line& L){
	point h=proj(C.c,L);
	Real d=abs(C.c-h);
	if(sgn(d-C.r)==1){
		return {};
	}
	if(sgn(d-C.r)==0){
		return {h};
	}
	else{
		point v=L.b-L.a;
		v*=sqrt(C.r*C.r-d*d)/abs(v);
		return {h+v,h-v};
	}
}

/* 円周と円周の交点 */
/*
	引数
		C1, C2 : 円周
	戻り値
		交点の集合
		ただし, 交点が無限個ある (C1==C2) ときは空集合
	制約
		なし
	計算量
		O(1)
	備考
		C1, C2 は円盤ではないことに注意!!
*/

vector<point> get_intersect(const circle& C1,const circle& C2){
	const point& p1=C1.c;
	const point& p2=C2.c;
	const Real& r1=C1.r;
	const Real& r2=C2.r;

	vector<point> res;
	if(p1==p2 && sgn(r1-r2)==0) return res;

	Real d=abs(p1-p2);
	if(sgn((r1+r2)-d)>=0 && sgn(d-abs(r1-r2))>=0){
		Real a=(r1*r1-r2*r2+d*d)/(2*d);
		Real h=sqrt(max(r1*r1-a*a,Real(0)));
		point tmp1=p1+a/d*(p2-p1);
		point tmp2=h/d*(p2-p1);
		if(sgn(abs(tmp2))==0){
			res.emplace_back(tmp1);
		}
		else{
			res.emplace_back(tmp1.x-tmp2.y,tmp1.y+tmp2.x);
			res.emplace_back(tmp1.x+tmp2.y,tmp1.y-tmp2.x);
		}
	}
	return res;
}
