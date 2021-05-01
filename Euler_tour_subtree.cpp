// Euler tour (部分木クエリ)
/*
	頂点に重みがついた N 頂点の根つき木 T を考える.
	長さ N の数列 L, R は次をみたす.
		L は {0, 1, ..., N-1} の permutation であって,
		L[u] は DFS の行きがけ順で頂点 u が何番目に現れるかを表す.
		また, 0 <= L[u] < R[u] <= V が成り立つ.
	W[L[u]] = (頂点 u の重み) として,
	頂点 u を根とする部分木に含まれる頂点の重みの総和は
		W[L[u]] + W[L[u]+1] + ... + W[R[u]-1]
	と表される.
*/

class Euler_tour_for_subtrees{
	vector<int> L,R;
	const graph& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(int v:Tr[u]) if(v!=p) dfs(v,u);
		R[u]=idx;
	}
public:
	Euler_tour_for_subtrees(const graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	int get_index(int u)const{ return L[u]; }
	pair<int,int> get_subtree(int u)const{ return {L[u],R[u]}; }
};


// 辺に重みがついたバージョン (機能は同じ)

template<class T>
class Euler_tour_for_subtrees{
	vector<int> L,R;
	const weighted_graph<T>& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(const auto& e:Tr[u]){
			int v=e.to;
			if(v!=p) dfs(v,u);
		}
		R[u]=idx;
	}
public:
	Euler_tour_for_subtrees(const weighted_graph<T>& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	int get_index(int u)const{ return L[u]; }
	pair<int,int> get_subtree(int u)const{ return {L[u],R[u]}; }
};
