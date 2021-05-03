template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

/* 拡張 Euclid 互除法 */
/*
	引数
		a, b : 整数
		x, y : 計算結果 ( 方程式 a*x + b*y = gcd(a, b) の解 )
	戻り値
		gcd(a, b)
	制約
		a >= 0
		b >= 0
		(a, b) != (0, 0)
	計算量
		O(log min{a, b})
	備考
		a > 0 かつ b > 0 のとき |x| <= b/gcd(a, b), |y| <= a/gcd(a, b) が保障される.
*/

template<class T>
T xgcd(T a,T b,T& x,T& y){
	if(b==0){ x=1; y=0; return a; }
	T g=xgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
