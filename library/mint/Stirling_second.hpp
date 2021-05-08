/*
	第 2 種 Stirling 数 S(n, k)
		n 個の区別できるボールを k 個のグループに分ける方法の数
*/

mint Stirling_second(int n,int k){
	mint res=0;
	rep(i,k+1) res+=(i%2==0?1:-1)*choose(k,i)*pow(mint(k-i),n);
	return res/fact(k);
}
