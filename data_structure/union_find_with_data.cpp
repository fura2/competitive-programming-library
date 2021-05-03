/* Union-Find with data */
/*
	説明
		互いに素な集合を管理するデータ構造 (連結成分の情報を陽に持つ)
		- find(u) : u が含まれる集合の代表元を求める
		- unite(u,v) : u が含まれる集合と v が含まれる集合を合併する
		- is_same(u,v) : u と v が同じ集合に含まれるかどうかを判定する
		- size() : 集合が全部でいくつあるかを求める
		- size(u) : u が含まれる集合の要素数を求める
		- connected_component(u) : u が含まれる集合を求める
	コンストラクタ
		n : 集合の要素数
	制約
		n >= 0
	計算量
		unite : ならし O(log n)
		connected_component : O(|u が含まれる集合|)
	備考
		weighted-union heuristic (いわゆるマージテク) を使っている
*/

class union_find{
	int n;
	vector<int> p;
	vector<vector<int>> C;
public:
	union_find(int n):n(n),p(n,-1),C(n){
		rep(u,n) C[u].emplace_back(u);
	}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
			C[u].insert(C[u].end(),C[v].begin(),C[v].end());
			C[v].clear();
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
	vector<int> connected_component(int u){ return C[find(u)]; }
};
