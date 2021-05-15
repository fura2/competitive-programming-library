#pragma once
#include "../template.hpp"
#include "../graph/graph.hpp"
#include "../graph/wgraph.hpp"

template<class M,class F,class G>
vector<M> rerooting(const graph& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(int v:T[u]) if(v!=p) {
			dfs1(dfs1,v,u);
			dp1[u]=dp1[u]*f(dp1[v],v);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			int v=T[u][i];
			lcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			int v=T[u][i];
			if(v!=p){
				dfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));
			}
		}
	};

	dfs1(dfs1,0,-1);
	dfs2(dfs2,0,-1,M());

	return dp2;
}

template<class M,class W,class F,class G>
vector<M> rerooting(const weighted_graph<W>& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(const auto& e:T[u]) if(e.to!=p) {
			dfs1(dfs1,e.to,u);
			dp1[u]=dp1[u]*f(dp1[e.to],e);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			const auto& e=T[u][i];
			lcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			const auto& [v,wt]=T[u][i];
			if(v!=p){
				dfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));
			}
		}
	};

	dfs1(dfs1,0,-1);
	dfs2(dfs2,0,-1,M());

	return dp2;
}
