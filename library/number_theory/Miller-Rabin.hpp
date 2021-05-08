/* 素数判定 (Miller-Rabin) */
/*
	説明
		n が素数かどうかを判定する Miller-Rabin アルゴリズム (deterministic variant)
		https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants
	引数
		n : 整数
	戻り値
		n が素数かどうか
	制約
		0 <= n < 2^63
	計算量
		O(log n)
*/

bool Miller_Rabin(lint n){
	if(n<=1)   return false;
	if(n%2==0) return n==2;

	auto modpow=[](lint a,lint k,lint m){
		lint r=1;
		for(lint x=a;k>0;k>>=1){
			if(k&1) r=__int128(r)*x%m;
			x=__int128(x)*x%m;
		}
		return r;
	};

	int r=0;
	lint d=n-1;
	while(d%2==0) r++, d>>=1;

	for(lint a:{2,3,5,7,11,13,17,19,23,29,31,37}){
		if(a>=n-2) break;
		lint x=modpow(a,d,n);
		if(x==1 || x==n-1) continue;
		bool b=false;
		rep(_,r-1){
			x=__int128(x)*x%n;
			if(x==n-1){
				b=true;
				break;
			}
		}
		if(!b) return false;
	}
	return true;
}
