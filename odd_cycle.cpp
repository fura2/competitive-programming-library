/*
	無向グラフ G の奇数長の閉路 C を一つ求める
	C に含まれる頂点列と辺列のペアを返す
		頂点列を u_1, ..., u_K, 辺列を e_1, ... e_K とすると,
		e_i は u_i と u_{i+1} を結ぶ辺
	G が奇数長の閉路をもたないときは空の vector のペアを返す
*/

template<class T>
pair<vector<int>,vector<edge<T>>> odd_cycle(const weighted_graph<T>& G){
	int n=G.size();
	vector<int> color(n,-1);

	vector<int> res1;
	vector<edge<T>> res2;

	auto dfs=[&](auto&& dfs,int u,int c)->bool{
		color[u]=c;
		for(auto e:G[u]){
			if(color[e.to]==-1){
				if(dfs(dfs,e.to,1-c)){
					if(res2[0].to!=res1.back()){
						res1.emplace_back(u);
						res2.emplace_back(e);
					}
					return true;
				}
			}
			else if(color[e.to]==c){
				res1.emplace_back(u);
				res2.emplace_back(e);
				return true;
			}
		}
		return false;
	};

	rep(u,n) if(color[u]==-1 && dfs(dfs,u,0)) {
		reverse(res1.begin(),res1.end());
		reverse(res2.begin(),res2.end());
		break;
	}
	return {res1,res2};
}
