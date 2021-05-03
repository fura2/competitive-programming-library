/* 二彩色 */
/*
	説明
		グラフを二彩色する
	引数
		G : 無向グラフ
	制約
		なし
	戻り値
		(G が二彩色可能かどうか, 彩色結果)
		彩色結果はサイズ V の vector で, 各要素は 0 または 1
	計算量
		O(V+E)
	備考
		G が二彩色できないとき, 彩色結果は空の vector が返る
*/

pair<bool,vector<int>> two_coloring(const graph& G){
	int n=G.size();
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		color[u]=0;
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			for(int w:G[v]){
				if(color[w]==-1){
					color[w]=1-color[v];
					Q.emplace(w);
				}
				else if(color[w]==color[v]) return {false,vector<int>()};
			}
		}
	}
	return {true,color};
}
