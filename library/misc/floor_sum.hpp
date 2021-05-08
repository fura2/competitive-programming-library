/*
	Σ_{x=0}^{n-1} floor((ax+b)/m) を求める
	制約
		0 <= n < 10^9
		1 <= m <= 10^9
		0 <= a,b < m
	計算量
		O(log min{a, m})
	備考
		a >= m や b >= m のときもオーバーフローさえしなければ正しく動く.
		a < 0 や b < 0 には対応していないが, floor((ax+b)/m) の符号で場合分けして
		適切に変数変換することで a, b >= 0 のケースに帰着できる.
*/

long long floor_sum(long long n,long long m,long long a,long long b){
	long long res=0;
	if(a>=m){
		res+=n*(n-1)/2*(a/m);
		a%=m;
	}
	if(b>=m){
		res+=n*(b/m);
		b%=m;
	}

	long long y_max=(a*(n-1)+b)/m;
	if(y_max==0) return res;
	return res+y_max+floor_sum(y_max,a,m,(a*(n-1)+b)-m*y_max);
}
