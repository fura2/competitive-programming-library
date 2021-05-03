/*
	P/Q mod M から P と Q を復元する
		P, Q が十分小さいとき (具体的には |P| < sqrt(M/2), 0 < Q < sqrt(M/2) 程度),
		P, Q が一意に定まるので, この P, Q を求める
		解なしの場合は P = Q = -1 が返る
		P, Q がある程度大きい場合は, 解なしと判定されるか意図していない解を捕まえてしまうので注意
	入力
		r : P/Q mod M
		m : M
	参考
		https://en.wikipedia.org/wiki/Rational_reconstruction_(mathematics)
*/

pair<lint,lint> rational_reconstruction(lint r,lint m=1000000007){
	lint D=sqrt(m/2);
	lint N=sqrt(m/2);

	lint v1=m,v2=0,w1=r,w2=1;
	while(w1>N){
		lint z1=v1-(v1/w1)*w1;
		lint z2=v2-(v1/w1)*w2;
		v1=w1; v2=w2;
		w1=z1; w2=z2;
	}
	if(w2<0) w1*=-1, w2*=-1;

	if(w2<D && gcd(w1,w2)==1) return {w1,w2};
	else                      return {-1,-1};
}
