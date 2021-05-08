/* スライド最小値 */
/*
	説明
		長さ n の数列 a と整数 w に対して, 次のように定義される長さ n-w+1 の列 b を求める
			b_i = argmin{a_i, a_{i+1}, ..., a_{i+w-1}}
		最小値を達成する a_i が複数あるときは最も左のものが採用される
	制約
		w > 0
	計算量
		O(n)
	備考
		w > n のときは空の列が返る
*/

template<class T>
vector<int> sliding_window_minimum(const vector<T>& a,int w){
	int n=a.size();
	if(w>n) return {};

	vector<int> res(n-w+1);
	deque<int> D;
	rep(i,n){
		while(!D.empty() && a[D.back()]>a[i]) D.pop_back();
		D.emplace_back(i);
		if(i>=w-1){
			if(i-D.front()>=w) D.pop_front();
			res[i-w+1]=D.front();
		}
	}
	return res;
}
