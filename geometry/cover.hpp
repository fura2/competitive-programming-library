// 点 p が閉線分 S に含まれるか

bool cover(const segment& S,const point& p){
	return sgn(cross(S.a-p,S.b-p))==0 && sgn(dot(S.a-p,S.b-p))<=0;
}

// 点 p が閉円盤 C に含まれるか

bool cover(const circle& C,const point& p){
	return sgn(abs(C.c-p)-C.r)<=0;
}

/* 多角形と点の包含判定 */
/*
	引数
		F : 多角形
		p : 点
	戻り値
		含むなら true, 含まないなら false
	制約
		F は単純
	計算量
		O(n)
	備考
		F は凸でなくてもいい.
		点が多角形の境界にあるときは含むと判定する.
*/

bool cover(const polygon& F,const point& p){
	int n=F.size();
	bool res=false;
	rep(i,n){
		point v1=F[i]-p,v2=F[(i+1)%n]-p;
		if(v1.y>v2.y) swap(v1,v2);
		// y 座標が小さい方の端点は含め, 大きい方の端点は含めない
		if(sgn(v1.y)<=0 && sgn(v2.y)==1 && sgn(cross(v1,v2))==1) res=!res;
		// p が辺 (F[i], F[i+1]) 上にある
		if(sgn(cross(v1,v2))==0 && sgn(dot(v1,v2))<=0) return true;
	}
	return res;
}
