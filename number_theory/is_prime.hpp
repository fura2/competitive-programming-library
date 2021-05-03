/* 素数判定 */
/*
	説明
		a が素数かどうかを判定
	引数
		a : 整数
	戻り値
		a が素数かどうか
	制約
		a >= 0
	計算量
		O(sqrt(a))
	備考
		なし
*/

bool is_prime(long long a){
	if(a%2==0) return a==2;
	for(long long i=3;i*i<=a;i+=2) if(a%i==0) return false;
	return a!=1;
}
