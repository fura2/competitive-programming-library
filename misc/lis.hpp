/* 最長(増加|非減少)部分列 */
/*
	説明
		数列 a の最長(増加|非減少)部分列を求める
	備考
		最長(減少|非増加)部分列を求めたいときは -a を考えればよい
	引数
		a : 数列
	戻り値
		a の最長(増加|非減少)部分列(の一つ)
	制約
		なし
	計算量
		O(|a| log |a|)
*/

template<class T>
vector<T> longest_increasing_subsequence(const vector<T> &a){
	vector<T> lis;
	for(const auto& x:a){
		auto it=lower_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}

template<class T>
vector<T> longest_nondecreasing_subsequence(const vector<T> &a){
	vector<T> lis;
	for(const auto& x:a){
		auto it=upper_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}
