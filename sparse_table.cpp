/* Range Minimum Query (Sparse Table) */
/*
	備考
		Range Maximum Query をやりたいときは, -a について Range Minimum Query をやるか
		コード中のすべての min を max に書き変えればいい.

[ constructor ]
	説明
		初期化
	引数
		a : 配列
	制約
		なし
	計算量
		O(n log n)

[ query ]
	説明
		min{ a[i] | i=l,l+1,...,r-1 } を求める
	引数
		l : 左端
		r : 右端
	制約
		0 <= l < r <= n
	計算量
		O(1)
	備考
		半開区間で指定することに注意.
		segment tree の RMQ より定数倍速い.
*/

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return min(st[i][l],st[i][r-(1<<i)]);
	}
};
