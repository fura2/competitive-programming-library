/* 三角形の面積 */

Real area(const point &a,const point &b,const point &c){
	return abs(cross(b-a,c-a)/2);
}

/* 多角形の面積 */
/*
	引数
		F : 多角形
	戻り値
		多角形の面積 (縮退しているときは 0)
	制約
		F は単純
	計算量
		O(n)
	備考
		F は CCW でも CW でもいい
*/

Real area(const polygon& F){
	int n=F.size();
	Real res=0;
	rep(i,n) res+=cross(F[i],F[(i+1)%n]);
	return abs(res)/2;
}
