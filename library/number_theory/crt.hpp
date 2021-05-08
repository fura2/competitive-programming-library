/* 連立線形合同式 */
/*
	説明
		a_1 * x = b_1 (mod m_1)
		a_2 * x = b_2 (mod m_2)
				:
		a_n * x = b_n (mod m_n)
		を解く
	戻り値
		解は (存在するなら) ある整数 x, M (0 ≦ x < M, M > 0) を用いて x + k * M (k は任意の整数) と表される
		この x と M のペアを返す
		解が存在しない場合は (-1, -1) を返す
	制約
		m_i > 0
	備考
		アルゴリズムは次のとおり
			a_i の逆元を両辺にかけて a_i = 1 の問題に帰着させる
				逆元が存在しない場合は例外処理する
			あとは, 中国剰余定理のアルゴリズムにしたがって x と M を求める
				M は a_i = 1 に帰着したあとの系における LCM(m_1, m_2, ..., m_n) に等しい
		オーバーフローしやすいので注意すること
*/

pair<long long,long long> Chinese_remainder(vector<long long> a,vector<long long> b,vector<long long> m){
	int n=a.size();
	assert(n==b.size() && n==m.size());

	long long x=0,M=1;
	rep(i,n){
		a[i]%=m[i]; if(a[i]<0) a[i]+=m[i];
		b[i]%=m[i]; if(b[i]<0) b[i]+=m[i];
		if(a[i]==0){
			if(b[i]!=0) return {-1,-1};
			continue;
		}

		long long p,q,g;
		g=xgcd(a[i],m[i],p,q);
		if(b[i]%g!=0) return {-1,-1};
		m[i]/=g;
		b[i]=(b[i]/g)*p%m[i];

		g=xgcd(M,m[i],p,q);
		if((b[i]-x)%g!=0) return {-1,-1};
		x+=M*((b[i]-x)/g*p%(m[i]/g));
		M*=m[i]/g;
	}
	x%=M; if(x<0) x+=M;
	return {x,M};
}
