/* 原始根 */
/*
	説明
		p の原始根を一つ求める
	引数
		p : 整数
	戻り値
		p の一つの原始根
	制約
		p は素数
	計算量
		O(log^2(p))
	備考
		g が p の原始根であるとは
		  {g,g^2,...,g^(p-1)} = {1,2,...,p-1}
		となることをいう.
		素数 p の原始根は {1,2,...,p-1} の中に φ(p-1) 個存在することが知られている.

		アルゴリズムは
		  (1) 原始根の候補 g を {1,2,..,p-1} から一様ランダムに選ぶ.
		  (2) g が原始根かどうかをチェックし, 原始根なら終了. そうでなければ (1) に戻る.
		というもの.
		サンプリングの回数は実験すると平均 2.8 回程度で, p の大きさによらないように見える.
*/

lint primitive_root(lint p){
	vector<lint> pf;
	lint tmp=p-1;
	for(lint q=2;q*q<=tmp;q++) if(tmp%q==0) {
		pf.emplace_back(q);
		do tmp/=q; while(tmp%q==0);
	}
	if(tmp>1) pf.emplace_back(tmp);

	while(1){
		lint g=xor64()%(p-1)+1;
		bool ok=true;
		rep(i,pf.size()) if(modpow(g,(p-1)/pf[i],p)==1) { ok=false; break; }
		if(ok) return g;
	}
}
