/* 約数列挙 */
/*
	説明
		a の約数をすべて求める
	引数
		a : 整数
	制約
		a >= 0
	戻り値
		a の(正の)約数のリスト
	計算量
		O(sqrt(a))
	備考
		a = 0 のときは空のリストが返る
*/

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

/* 約数列挙 */
/*
	説明
		a の約数をすべて求める
	引数
		pf : a の素因数分解
	制約
		a >= 0
	戻り値
		a の(正の)約数のリスト
	計算量
		O(a の約数の個数) (= O(exp((log a)/loglog a)))
	備考
		a = 0 のときは空のリストが返る
*/

template<class T>
vector<T> divisors(const map<T,int>& pf){
	vector<T> res={T(1)};
	for(const auto& q:pf){
		int m=res.size();
		T pp=1;
		rep(i,q.second){
			pp*=q.first;
			rep(i,m) res.emplace_back(res[i]*pp);
		}
	}
	sort(res.begin(),res.end());
	return res;
}
