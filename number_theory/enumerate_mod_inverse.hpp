/* mod m での逆元列挙 */
/*
	説明
		1, 2, ..., n の mod m での逆元を求める
	引数
		n, m : 整数
	戻り値
		長さ n+1 の配列 inv が返る
		i>0 に対して, inv[i] = i^{-1} である
	制約
		0 <= n < m
		m >= 1 : 素数
	計算量
		O(n)
	備考
		なし
*/

vector<long long> enumerate_mod_inverse(int n,int m){
	vector<long long> inv(n+1);
	if(n>0) inv[1]=1;
	for(int i=2;i<=n;i++){
		long long x=(m+i-1)/i;
		inv[i]=x*inv[i*x%m]%m;
	}
	return inv;
}
