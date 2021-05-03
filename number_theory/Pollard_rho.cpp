/* 素因数分解 (Pollard's ρ) */
/*
	説明
		n を素因数分解する
	引数
		n : 整数
	戻り値
		n の素因数分解
	制約
		0 <= n < 2^63
	計算量
		O(n^{1/4} log n) 程度
	備考
		n = 0, 1 のときは空の map が返る
*/

map<lint,int> Pollard_rho(lint n){
	map<lint,int> pf;
	if(n<=1) return pf;
	if(Miller_Rabin(n)){ ++pf[n]; return pf; }

	auto divisor=[](lint n,int c)->lint{
		if(n%2==0) return 2;

		lint x=2,y=2,d=1;
		while(d==1){
			x=__int128(x)*x%n+c; if(x<0) x+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			d=gcd(abs(x-y),n);
		}
		return d<n?d:-1;
	};

	lint d=-1;
	for(int c=1;d==-1;c++) d=divisor(n,c);

	for(auto [p,e]:Pollard_rho( d )) pf[p]+=e;
	for(auto [p,e]:Pollard_rho(n/d)) pf[p]+=e;
	return pf;
}
