/* 回転方向 */
/*
	説明
		三点の位置関係を求める
	引数
		a, b, c : 点
	戻り値
		a-b-c の順に反時計回りに回転しているとき CCW
		a-b-c の順に時計回りに回転しているとき CW
		a-b-c が同一直線上にあるとき ON
	制約
		なし
	計算量
		O(1)
	備考
		二点以上が同一の点であればつねに ON を返すことに注意
*/

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	int d=sgn(cross(b-a,c-a));
	return d>0?CCW:d<0?CW:ON;
}
