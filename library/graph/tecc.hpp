/* 二重辺連結成分分解 */
/*
[ constructor ]
	引数
		G : 無向グラフ
	制約
		G は無向グラフ (辺 u->v と同じ本数だけ v->u がある)
	計算量
		O(V+E)
	備考
		G には多重辺, 自己ループがあってもよい
		G は連結でなくてもよい

operator[]
	説明
		u が含まれる二重辺連結成分の番号
	引数
		u : G の頂点
	制約
		0 <= u < |V(G)|
	計算量
		O(1)
	備考
		二重辺連結成分の個数を K とすると, 二重辺連結成分は 0, 1, ..., K-1 で番号づけられている

component
	説明
		i 番目の二重辺連結成分を返す
	引数
		i : 二重辺連結成分の番号
	制約
		0 <= i < 二重辺連結成分の個数
	計算量
		O(1)

bridges
	説明
		橋の集合を返す
	計算量
		O(1)

bridge_block_tree
	説明
		二重辺連結成分を縮約して得られる木を返す
	計算量
		O(1)
	備考
		G が連結でない場合は縮約して得られる森を返す
*/

class two_edge_connected_components{
	int idx;
	vector<int> ord,low,id;
	const graph& G;

	vector<vector<int>> Comp;
	vector<pair<int,int>> B;
	graph Tr;

	void dfs1(int u,int p){
		ord[u]=low[u]=idx++;
		bool f=true;
		for(int v:G[u]){
			if(v==p && f){ f=false; continue; }
			if(ord[v]==-1){
				dfs1(v,u);
				low[u]=min(low[u],low[v]);
			}
			else{
				low[u]=min(low[u],ord[v]);
			}
		}
	}

	void dfs2(int u,int p){
		if(p==-1 || ord[p]<low[u]){
			id[u]=idx++;
			if(p!=-1) B.emplace_back(minmax(p,u));
		}
		else{
			id[u]=id[p];
		}
		for(int v:G[u]) if(id[v]==-1) dfs2(v,u);
	}

public:
	two_edge_connected_components(const graph& G):G(G){
		int n=G.size();

		idx=0;
		ord.assign(n,-1);
		low.assign(n,-1);
		rep(u,n) if(ord[u]==-1) dfs1(u,-1);

		idx=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs2(u,-1);

		Comp.resize(idx);
		Tr.resize(idx);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) Tr[id[u]].emplace_back(id[v]);
		}
	}

	int operator[](int i)const{ return id[i]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const vector<pair<int,int>>& bridges()const{ return B; }
	const graph& bridge_block_tree()const{ return Tr; }
};
