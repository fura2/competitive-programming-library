/* 凸包 */
/*
	説明
		点集合の凸包を求める
	引数
		P : 点集合
	戻り値
		P の凸包
	制約
		なし
	計算量
		O(n log n)
	備考
		point に (x, y) の辞書式順序を入れておく.
		辺上にある頂点は端のものだけ拾う.
		辺上にある頂点を全部拾うようにしたいときは !=CCW を ==CW と修正すればいい.
*/

polygon convex_hull(vector<point> P){
	int n=P.size();
	if(n<=1) return P;

	sort(P.begin(),P.end(),[](const point& p,const point& q){
		return make_pair(p.x,p.y)<make_pair(q.x,q.y);
	});

	polygon CH;
	rep(_,2){
		int m=0;
		vector<point> half(n);
		for(const point& p:P){
			half[m++]=p;
			while(m>=3 && ccw(half[m-3],half[m-2],half[m-1])!=CCW){
				half[m-2]=half[m-1];
				m--;
			}
		}
		CH.insert(CH.end(),half.begin(),half.begin()+m-1);
		reverse(P.begin(),P.end());
	}
	return CH;
}
