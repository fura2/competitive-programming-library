/* 二元連立一次方程式 */
/*
	説明
		体 F 上の二元連立一次方程式
			a x + b y = e
			c x + d y = f
		を解く
	引数
		a, b, c, d, e, f : パラメータ
	戻り値
		(x, y)
	制約
		解が一意に存在する (ad-bc != 0)
	計算量
		O(1)
	備考
		なし
*/

template<class F>
pair<F,F> solve_eq(const F& a,const F& b,const F& c,const F& d,const F& e,const F& f){
	F det=a*d-b*c;
	assert(det!=F{});
	return {(d*e-b*f)/det,(-c*e+a*f)/det};
}
