// Euler tour (パスクエリ)
/*
	頂点に重みがついた N 頂点の根つき木 T を考える.
	根から DFS して各頂点を最初と最後に訪れたときにその頂点の番号を記録する.
	こうして得られる長さ 2*N の数列を I = (I[0], ..., I[2*N-1]) とする.
		I には 0, 1, ..., N-1 がそれぞれちょうど 2 回ずつ現れる.
	長さ N の数列 L, R を次のように定める.
		L[u] は頂点 u に最初に訪れたときの番号 (I の添え字),
		R[u] は頂点 u に最後に訪れたときの番号 (I の添え字).
	長さ 2*N の数列 W を次のように定める.
		W[L[u]] = +(頂点 u の重み),
		W[R[u]] = -(頂点 u の重み).
	u が v の親であるような頂点 u, v に対して, パス u - v に含まれる頂点の重みの総和は
		W[L[u]] + W[L[u]+1] + ... + W[R[v]-1]
	と表される.
	一般のパスの重みも LCA と組み合わせることで求められる.
*/

class Euler_tour_for_paths{
	vector<int> L,R;
	const graph& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(int v:Tr[u]) if(v!=p) dfs(v,u);
		R[u]=idx++;
	}
public:
	Euler_tour_for_paths(const graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	pair<int,int> get_indices(int u)const{ return {L[u],R[u]}; }
	pair<int,int> get_path(int u,int v)const{ return {L[u],R[v]}; }
};
