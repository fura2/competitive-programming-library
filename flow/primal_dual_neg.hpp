/* 最小費用流 (primal-dual) */
/*
	capa_t, cost_t は整数型を想定している
	最初の 1 回だけ Bellman-Ford 法を使ってポテンシャルを求めて,
	2 回目以降は Dijkstra 法を使っている
	負のコストの辺があってもよいが, 負のコストの閉路がないことを仮定

	負辺の処理についての tips
	- DAG なら Bellman-Ford のかわりに O(V+E) の DP で最短経路が求まる (未実装).
	  元のグラフが DAG でも, augment の二回目以降では残余グラフは DAG とは限らないことに注意!!
	  0,1,..,n-1 がトポロジカル順序なら Bellman-Ford は 1 回で終わるので, このコードで O(F E log V) が達成できる.
	- 使う辺の本数 or 総流量が固定ならグラフを変形して負辺をなくせる. ( 蟻本 p.204-205 )

[ constructor ]
	引数
		n : 頂点数 (source, sink も含む)
	計算量
		O(V)

[ add_directed_edge ]
	制約
		0 <= u, v < n
		capa >= 0
	備考
		無向辺を張るときは代わりに有向辺を双方向に張る

[ minimum_cost_flow ]
	説明
		limit まで流せるときの最小費用最大流を求める
	引数
		s : ソース
		t : シンク
		limit : 最大流量
	制約
		0 <= s, t < n
		s != t
	戻り値
		(最大流量, そのときの最小コスト)
	計算量
		O(V E + F E log(V))
*/

template<class capa_t,class cost_t>
class mcf_graph{
	struct edge{
		int to,rev;
		capa_t capa,flow;
		cost_t cost;
		edge(int to,int rev,const capa_t& capa,const cost_t& cost,const capa_t& flow):to(to),rev(rev),capa(capa),cost(cost),flow(flow){}
	};

	vector<vector<edge>> G;

	static constexpr capa_t CAPA_INF=numeric_limits<capa_t>::max();
	static constexpr cost_t COST_INF=numeric_limits<cost_t>::max();

public:
	mcf_graph(){}
	mcf_graph(int n):G(n){}

	void add_directed_edge(int u,int v,const capa_t& capa,const cost_t& cost){
		G[u].emplace_back(v,G[v].size()  ,capa, cost,0);
		G[v].emplace_back(u,G[u].size()-1,   0,-cost,0);
	}

	pair<capa_t,cost_t> minimum_cost_flow(int s,int t,capa_t limit=CAPA_INF){
		int n=G.size();
		vector<int> pre(n);
		vector<cost_t> d(n),pot(n);
		priority_queue<pair<cost_t,int>> Q;

		auto augment=[&](bool first)->pair<capa_t,cost_t>{
			rep(u,n) d[u]=(u==s?0:COST_INF);

			bool ok;
			if(first){
				// Bellman-Ford
				rep(_,n){
					bool upd=false;
					rep(u,n) if(d[u]<COST_INF) {
						for(const edge& e:G[u]) if(e.capa-e.flow>0) {
							if(d[e.to]>d[u]+e.cost){
								d[e.to]=d[u]+e.cost;
								pre[e.to]=e.rev;
								upd=true;
							}
						}
					}
					if(!upd) break;
				}
				ok=(d[t]<COST_INF);
			}
			else{
				// Dijkstra
				ok=false;
				Q.emplace(0,s);
				while(!Q.empty()){
					int u;
					cost_t tmp; tie(tmp,u)=Q.top(); Q.pop();

					if(-tmp<d[u]) continue;
					if(u==t) ok=true;

					for(const edge& e:G[u]) if(e.capa-e.flow>0) {
						cost_t cost2=d[u]+e.cost+pot[u]-pot[e.to];
						if(d[e.to]>cost2){
							d[e.to]=cost2;
							pre[e.to]=e.rev;
							Q.emplace(-cost2,e.to);
						}
					}
				}
			}

			if(!ok) return {0,0};

			capa_t water=limit;
			for(int u=t;u!=s;){
				edge& e1=G[u][pre[u]];
				edge& e2=G[e1.to][e1.rev];
				water=min(water,e2.capa-e2.flow);
				u=e1.to;
			}
			limit-=water;

			for(int u=t;u!=s;){
				edge& e1=G[u][pre[u]];
				edge& e2=G[e1.to][e1.rev];
				e1.flow-=water;
				e2.flow+=water;
				u=e1.to;
			}

			rep(u,n) pot[u]+=d[u];

			return {water,water*pot[t]};
		};

		capa_t res1=0;
		cost_t res2=0;
		for(bool first=true;limit>0;first=false){
			auto tmp=augment(first);
			if(tmp.first==0) break;
			res1+=tmp.first;
			res2+=tmp.second;
		}
		return {res1,res2};
	}
};
