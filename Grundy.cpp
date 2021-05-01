/*
	D を N 頂点 M 辺の DAG とする

	次のような D 上の二人ゲームを考える
		D の一つの頂点に駒を置いた状態からゲームを始める
		プレイヤーは, 自分の番で駒を有向辺に沿って一回動かす
		駒を動かせなくなったプレイヤーの負け
	すべての頂点 u について, 駒が u にある状態の Grundy 数を計算する

	計算量は O(N+M) となる
*/

vector<int> Grundy(const graph& D){
	auto ord=topological_order(D);

	int n=D.size(),m=0;
	rep(u,n) m=max(m,int(D[u].size()));

	vector<int> g(n),last(m+1,-1);
	rep(i,n){
		int u=ord[n-i-1];
		for(int v:D[u]) last[g[v]]=u;
		while(last[g[u]]==u) g[u]++;
	}
	return g;
}
