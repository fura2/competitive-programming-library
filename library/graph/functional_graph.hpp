// functional graph のサイクルを列挙する
//   V = {0, 1, ..., n-1}
//   E = { (u, f(u)) | u = 0, 1, ..., n-1 }

vector<vector<int>> cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			res.emplace_back(C);
		}
	}
	return res;
}
