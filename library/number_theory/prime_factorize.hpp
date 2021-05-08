/* 素因数分解 (試し割り) */
/*
	説明
		a を素因数分解する
	引数
		a : 整数
	戻り値
		a の素因数分解
	制約
		a > 0
	計算量
		O(sqrt(a)*log(log a))
	備考
		a = 1 のときは空の map が返る
*/

map<long long,int> prime_factorize(long long a){
	map<long long,int> res;
	if(a%2==0){
		int cnt=0;
		do{ cnt++; a/=2; }while(a%2==0);
		res.emplace(2,cnt);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		int cnt=0;
		do{ cnt++; a/=p; }while(a%p==0);
		res.emplace(p,cnt);
	}
	if(a>1) res.emplace(a,1);
	return res;
}
