/* Partially Persistent Union-Find */
/*
	説明
		互いに素な集合を管理するデータ構造
		- find(u,t) : t 回目の unite の後の, u が含まれている集合の代表元を求める
			(t = 0 は初期状態)
		- unite(u,v) : u が含まれている集合と v が含まれている集合を合併する
		- is_same(u,v,t) : t 回目の unite の後で, u と v が同じ集合に含まれるかどうかを判定する
		- size() : 集合が全部でいくつあるかを求める
		- size(u,t) : t 回目の unite の後の, u が含まれている集合の要素数を求める
	コンストラクタ
		n : 集合の要素数
	制約
		なし
	計算量
		size() : O(1)
		他 : O(log n)
	備考
		なし
*/

class persistent_union_find{
	int n,t;
	vector<int> p,t0;
	vector<vector<pair<int,int>>> Sz;
public:
	persistent_union_find(int n):n(n),t(0),p(n,-1),t0(n,1e9),Sz(n,{make_pair(-1,1)}){}
	int find(int u,int t){
		while(t>t0[u]) u=find(p[u],t);
		return u;
	}
	void unite(int u,int v){
		u=find(u,t); v=find(v,t);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u;
			t0[v]=t;
			Sz[u].emplace_back(t,-p[u]);
			n--;
		}
		t++;
	}
	bool is_same(int u,int v,int t){ return find(u,t)==find(v,t); }
	int size()const{ return n; }
	int size(int u,int t){
		u=find(u,t);
		return (--lower_bound(Sz[u].begin(),Sz[u].end(),make_pair(t,0)))->second;
	}
};
