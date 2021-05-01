/* Montmort 数 */
/*
	引数
		n : 整数
	戻り値
		!n
	制約
		n >= 0
	計算量
		O(n)
	備考
		!n = (長さ n の攪乱順列 (不動点を持たない順列) の個数)
		   = (n-1)*(!(n-1) + !(n-2))
		   = n!*(1/(0!) - 1/(1!) + 1/(2!) - 1/(3!) + ... + (-1)^n/(n!)).
*/

mint Montmort(int n){
	static vector<mint> memo{1,0};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=(memo[k-1]+memo[k-2])*(k-1);
	}
	return memo[n];
}
