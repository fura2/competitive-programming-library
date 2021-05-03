/* 素因数列挙 */
/*
	説明
		a の素因数をすべて求める
	引数
		a : 整数
	戻り値
		a の素因数のリスト
	制約
		a > 0
	計算量
		O(sqrt(a))
	備考
		a = 1 のときは空のリストが返る
*/

vector<long long> prime_factors(long long a){
	vector<long long> res;
	if(a%2==0){
		do a/=2; while(a%2==0);
		res.emplace_back(2);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		do a/=p; while(a%p==0);
		res.emplace_back(p);
	}
	if(a>1) res.emplace_back(a);
	sort(res.begin(),res.end());
	return res;
}
