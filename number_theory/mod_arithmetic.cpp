/* mod m での逆元 */
/*
	説明
		mod m での逆元を求める
	引数
		a : 整数
	戻り値
		a^{-1} mod m
	制約
		a >= 0
		m >= 1
		a^{-1} mod m が存在する (<=> gcd(a,m) = 1)
	計算量
		O(log max(a,m))
	備考
		なし
*/

lint modinv(lint a,lint m){
	lint b=m,u=1,v=0;
	while(b>0){ lint t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
	return (u+m)%m;
}

/* mod m でのべき乗 */
/*
	説明
		mod m での逆元を求める
	引数
		a : 整数
		k : 整数
		m : 整数
	戻り値
		a^{-1} mod m
	制約
		a >= 0
		k >= 0
		1 <= m < INT_MAX
	計算量
		O(log k)
	備考
		なし
*/

lint modpow(lint a,lint k,int m){
	lint r=1%m;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

/* 離散対数問題 */
/*
	説明
		離散対数 a^k = b (mod p) を解く
	引数
		a : 整数
		b : 整数
		p : 整数
	戻り値
		a^k = b (mod p) の解 k (0 <= k < p)
		解がない場合は -1
	制約
		1 <= p < INT_MAX
		p は素数
	計算量
		O(sqrt(p) log p)
	備考
		(p が素数なので) 解は存在すれば一意
*/

int modlog(lint a,lint b,int p){
	a%=p; if(a<0) a+=p;
	b%=p; if(b<0) b+=p;

	int k=sqrt(p)+1,c=1;
	vector<pair<int,int>> H(k);
	rep(j,k) H[j]={c,j}, c=c*a%p;
	sort(H.begin(),H.end());

	c=modinv(c,p);
	rep(i,k){
		auto it=lower_bound(H.begin(),H.end(),make_pair(int(b),0));
		if(it!=H.end() && it->first==b) return i*k+(it->second);
		b=b*c%p;
	}
	return -1;
}
