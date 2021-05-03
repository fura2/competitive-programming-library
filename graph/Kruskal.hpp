/* 最小全域森 (Kruskal) */
/*
	引数
		G : 重みつき無向グラフ
	戻り値
		(MSF の辺の重みの和, MSF)
	制約
		なし
	計算量
		O(E log E)
	備考
		グラフが連結のときは最小全域木が求まる.
		辺の重みは負でもいい.
*/

template<class T>
pair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G){
	int n=G.size();
	vector<tuple<T,int,int>> E;
	rep(u,n) for(const auto& e:G[u]) {
		int v=e.to;
		if(u<v) E.emplace_back(e.wt,u,v);
	}

	sort(E.begin(),E.end());

	T ans{};
	weighted_graph<T> Res(n);
	union_find U(n);
	for(const auto& e:E){
		if(U.size()==1) break;
		T wt;
		int u,v; tie(wt,u,v)=e;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			ans+=wt;
			Res[u].emplace_back(v,wt);
			Res[v].emplace_back(u,wt);
		}
	}
	return {ans,Res};
}
