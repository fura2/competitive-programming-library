bool is_DAG(const graph& G){
	int n=G.size();
	vector<int> deg(n);
	rep(u,n) for(int v:G[u]) deg[v]++;

	int cnt=0;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		cnt++;
		for(int v:G[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return cnt==n;
}
