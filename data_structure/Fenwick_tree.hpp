/* Fenwick Tree */
/*
	説明
		累積和を効率的に計算するデータ構造
		Fenwick tree (Binary Indexed Tree)
	備考
		G は Abel 群
		扱う数列を a[0,n) と記す (コード中の a とは異なる)

[ constructor ]
	説明
		0 で初期化
	引数
		n : BIT のサイズ
	制約
		なし
	計算量
		O(n)

[ add ]
	説明
		a[i]+=val
	引数
		i : 配列の添え字
		val : 加える値
	制約
		0 <= x < n
	計算量
		O(log n)

[ sum ]
	説明
		a[l]+a[l+1]+...+a[r-1] を求める
	引数
		l : 左端
		r : 右端
	制約
		l <= r
	計算量
		O(log n)
	備考
		半開区間で指定することに注意

[lower_bound]
	説明
		a[0]+a[1]+...+a[x]>=val となる最小の x を求める
	引数
		val : 閾値
	制約
		G には順序が入っている
		すべての i で a[i]>=0
	計算量
		O(log n)
	備考
		a[0]+...+a[n-1]<val のときは n が返る

[upper_bound]
	説明
		a[0]+a[1]+...+a[x]>val となる最小の x を求める
	引数
		val : 閾値
	制約
		G には順序が入っている
		すべての i で a[i]>=0
	計算量
		O(log n)
	備考
		a[0]+...+a[n-1]<=val のときは n が返る
*/

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(){}
	Fenwick_tree(int n){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
	}
	void add(int i,const G& val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};
