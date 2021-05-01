/*
	セグメント木
		(M, *) : モノイド
		x_1, ..., x_n : M の元の列

		update(i,x) : x_i の値を x に書き換える.
		product(l,r) : x_l * x_{l+1} * ... * x_{r-1} を求める.

		operate(l,r,f) : f(x_l * x_{l+1} * ... * x_{r-1}) を求める.
			ここで, (N, *) はモノイド, f M → N は準同型.
			operate<N>(l,r,[&](M& x)->N{
				return ...;
			});
			のように使う.
			x_l * x_{l+1} * ... * x_{r-1} を陽に求めると計算量がかかりすぎるが
			N における積と f の作用の計算量がどちらも小さいときに有効.

	max_right(l,f) :
		仮定
			0 <= l <= n
			f : M -> bool は f(e) = true をみたす
		次の二つの条件をみたす r (l <= r <= n) を一つ求める.
		- r = l または f(x_l * x_{l+1} * ... * x_{r-1}) = true
		- r = n または f(x_l * x_{l+1} * ... * x_r) = false
		f の計算にかかる時間を O(1) として, 計算量は O(log n).
	min_left(r,f) :
		仮定
			0 <= r <= n
			f : M -> bool は f(e) = true をみたす
		次の二つの条件をみたす l (0 <= l <= r) を一つ求める.
		- l = r または f(x_l * x_{l+1} * ... * x_{r-1}) = true
		- l = 0 または f(x_{l-1} * x_l * ... * x_{r-1}) = false
		f の計算にかかる時間を O(1) として, 計算量は O(log n).
*/

template<class M>
class segment_tree{
	int n,sz;
	vector<M> seg;
public:
	segment_tree(){}
	segment_tree(int n){ build(n); }
	template<class T>
	segment_tree(const vector<T>& a){ build(a); }
	void build(int n){
		this->n=n;
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,M());
	}
	template<class T>
	void build(const vector<T>& a){
		build(a.size());
		rep(i,a.size()) seg[sz+i]=a[i];
		for(int i=sz-1;i>0;i--){
			seg[i]=seg[2*i]*seg[2*i+1];
		}
	}
	const M& operator[](int i)const{
		return seg[sz+i];
	}
	void update(int i,const M& x){
		i+=sz;
		seg[i]=x;
		for(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];
	}
	M product(int l,int r)const{
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}
	template<class N,class F>
	N operate(int l,int r,const F& f){
		N lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*f(seg[a++]);
			if(b&1) rcum=f(seg[--b])*rcum;
		}
		return lcum*rcum;
	}
	template<class F>
	int max_right(int l,const F& f)const{
		if(l==n) return n;
		M cum;
		auto dfs=[&](auto&& dfs,int a,int b,int u){
			if(a==b-1){
				cum=cum*seg[u];
				return f(cum)?b:a;
			}

			int c=(a+b)/2;
			if(c<=l){
				return dfs(dfs,c,b,2*u+1);
			}
			if(l<=a && f(cum*seg[u])){
				cum=cum*seg[u];
				return b;
			}

			int idx=dfs(dfs,a,c,2*u);
			if(idx<c) return idx;
			return dfs(dfs,c,b,2*u+1);
		};
		return min(dfs(dfs,0,sz,1),n);
	}
	template<class F>
	int min_left(int r,const F& f)const{
		if(r==0) return 0;
		M cum;
		auto dfs=[&](auto&& dfs,int a,int b,int u){
			if(a==b-1){
				cum=seg[u]*cum;
				return f(cum)?a:b;
			}

			int c=(a+b)/2;
			if(r<=c){
				return dfs(dfs,a,c,2*u);
			}
			if(b<=r && f(seg[u]*cum)){
				cum=seg[u]*cum;
				return a;
			}

			int idx=dfs(dfs,c,b,2*u+1);
			if(idx>c) return idx;
			return dfs(dfs,a,c,2*u);
		};
		return dfs(dfs,0,sz,1);
	}
};
