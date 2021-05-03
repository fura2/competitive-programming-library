/* Fenwick Tree Dual */
/*
	説明
		累積和を効率的に計算するデータ構造
		Fenwick Tree の add, sum 操作の役割を入れ替えたもの
	備考
		G は Abel 群
		扱う数列を a[0..n) と記す (コード中の a とは異なる)

[ コンストラクタ ]
	説明
		0 で初期化
	引数
		n : 配列の長さ
	制約
		なし
	計算量
		O(n)
	備考
		なし

[ add ]
	説明
		a[l]+=v, a[l+1]+=val, ..., a[r-1]+=val
	引数
		l : 左端
		r : 右端
		val : 加える値
	制約
		l <= r
	計算量
		O(log n)
	備考
		半開区間で指定することに注意.

[ get ]
	説明
		a[i] の値を求める
	引数
		i : 配列の添え字
	制約
		0 <= x < n
	計算量
		O(log n)
	備考
		なし
*/

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,const G& val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G get(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};
