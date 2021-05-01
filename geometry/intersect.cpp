/* 直線と直線の交差判定 */
/*
	説明
		直線と直線が交わるかどうかを判定する
	引数
		L1, L2 : 直線
	戻り値
		交わるなら true, 交わらないなら false
	制約
		なし
	計算量
		O(1)
	備考
		コードは
			L1 と L2 が平行でない or L1 == L2
		という意味.
		特に, L1 == L2 のときは交わると判定することに注意.
*/

bool intersect(const line& L1,const line& L2){
	return sgn(cross(L1.b-L1.a,L2.b-L2.a))!=0
		|| sgn(cross(L1.b-L1.a,L2.a-L1.a))==0;
}

/* 線分と線分の交差判定 */
/*
	説明
		線分と線分が交わるかどうかを判定する
	引数
		S1, S2 : 線分
	戻り値
		交わるなら true, 交わらないなら false
	制約
		なし
	計算量
		O(1)
	備考
		bounding box によるラフチェックは必要 (ccw による判定だけだと, 二線分が同一直線上にあるときに間違う).
*/

bool intersect(const segment& S1,const segment& S2){
	if(sgn(min(S2.a.x,S2.b.x)-max(S1.a.x,S1.b.x))==1
	|| sgn(min(S2.a.y,S2.b.y)-max(S1.a.y,S1.b.y))==1
	|| sgn(min(S1.a.x,S1.b.x)-max(S2.a.x,S2.b.x))==1
	|| sgn(min(S1.a.y,S1.b.y)-max(S2.a.y,S2.b.y))==1){
		return false;
	}
	return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
		&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

/* 円周の直線の交差判定 */
/*
	引数
		C : 円周
		L : 直線
	戻り値
		交点の個数
	制約
		なし
	計算量
		O(1)
	備考
		C は円盤ではないことに注意!!
*/

int intersect(const circle& C,const line& L){
	point h=proj(C.c,L);
	Real d=abs(C.c-h);
	if(sgn(d-C.r)==1) return 0;
	if(sgn(d-C.r)==0) return 1;
	return 2;
}
