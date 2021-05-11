#pragma once
#include "../template.hpp"
#include "graph.hpp"

/*
[ constructor ]
	引数
		G : 有向グラフ
	制約
		なし
	計算量
		O(V+E)
	備考
		G には多重辺, 自己ループがあってもよい
		G は連結でなくてもよい

[ operator[] ]
	説明
		u が含まれる強連結成分の番号
	引数
		u : G の頂点
	制約
		0 <= u < |V(G)|
	計算量
		O(1)
	備考
		強連結成分の個数を K とすると, 強連結成分は DAG のトポロジカル順序にしたがって 0, 1, ..., K-1 で番号づけられている

component
	説明
		i 番目の強連結成分を返す
	引数
		i : 強連結成分の番号
	制約
		0 <= i < 強連結成分の個数
	計算量
		O(1)

DAG
	説明
		G 強連結成分を縮約して得られる DAG を返す
		G に多重辺がなくても DAG には多重辺が含まれうる
	計算量
		O(1)
	備考
		強連結成分の個数を K とすると, 0, 1, ..., K-1 はこの DAG のトポロジカル順序になっている
*/

class strongly_connected_components{
	vector<int> id;
	vector<vector<int>> Comp;
	graph D;

public:
	strongly_connected_components(const graph& G=graph()){ build(G); }

	void build(const graph& G){
		int n=G.size();
		graph G_rev(n);
		rep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);

		int k;
		vector<int> top(n);

		auto dfs1=[&](auto&& dfs1,int u)->void{
			id[u]=0;
			for(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);
			top[k++]=u;
		};
		auto dfs2=[&](auto&& dfs2,int u)->void{
			id[u]=k;
			for(int v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);
		};

		k=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs1(dfs1,u);

		reverse(top.begin(),top.end());

		k=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(dfs2,u), k++;

		Comp.resize(k);
		D.resize(k);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);
		}
	}

	int operator[](int u)const{ return id[u]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const graph& DAG()const{ return D; }
};
