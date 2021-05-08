/* 二部マッチング */
/*
[ constructor ]
	引数
		L : 左の頂点集合のサイズ
		R : 右の頂点集合のサイズ
	制約
		L, R >= 0
	計算量
		O(L)

[ add_edge ]
	制約
		0 <= u < L
		0 <= v < R

[ bipartite_matching ]
	説明
		最大マッチングを求める
	引数
		なし
	制約
		なし
	戻り値
		(最大マッチングのサイズ, 最大マッチング match)
		ここで,
			match[0][u] := 左の頂点 u とマッチしている右の頂点の番号 (存在しなければ -1)
			match[1][v] := 右の頂点 v とマッチしている左の頂点の番号 (存在しなければ -1)
	計算量
		O(V(V+E))
*/

class bipartite_graph{
	int L,R;
	vector<vector<int>> G,match;
	vector<bool> vis;

	bool augment(int u){
		if(u==-1) return true;
		for(int v:G[u]) if(!vis[v]) {
			vis[v]=true;
			if(augment(match[1][v])){
				match[0][u]=v;
				match[1][v]=u;
				return true;
			}
		}
		return false;
	}

public:
	bipartite_graph(int L,int R):L(L),R(R),G(L){}

	void add_edge(int u,int v){ G[u].emplace_back(v); }

	const vector<int>& operator[](int u)const{ return G[u]; }

	pair<int,vector<vector<int>>> bipartite_matching(){
		match.resize(2);
		match[0].assign(L,-1);
		match[1].assign(R,-1);

		int res=0;
		vis.resize(R);
		rep(u,L){
			fill(vis.begin(),vis.end(),false);
			if(augment(u)) res++;
		}

		return {res,match};
	}
};
