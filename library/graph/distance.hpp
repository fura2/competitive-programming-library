vector<int> distance(const graph& G,int s){
	constexpr int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

/*
	01-BFS
	辺の重みが 0 か 1 であることを仮定
*/

vector<int> distance(const weighted_graph<int>& G,int s){
	constexpr int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF); d[s]=0;
	deque<int> Q; Q.emplace_back(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop_front();
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				if(e.wt==0) Q.emplace_front(v);
				else        Q.emplace_back(v);
			}
		}
	}
	return d;
}
