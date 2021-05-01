/* Eratosthenes の篩 */
/*
	説明
		n 以下の素数をすべて求める

[ constructor ]
	説明
		なし
	引数
		n : 整数
	制約
		n >= 0
	計算量
		O(n log log n)

[ primes ]
	説明
		n 以下の素数のリストを求める
	引数
		なし
	戻り値
		n 以下の素数のリスト
	制約
		なし
	計算量
		O(1)
		ただし, 長さ |p| の vector のコピーが発生する

[ is_prime ]
	説明
		整数 a が素数かどうかを判定する
	引数
		a : 整数
	戻り値
		a が素数かどうか
	制約
		a <= n
	計算量
		O(1)
*/

class Eratosthenes_sieve{
	vector<bool> er;
	vector<int> p;
public:
	Eratosthenes_sieve(int n):er(n+1,true){
		if(n>=0) er[0]=false;
		if(n>=1) er[1]=false;
		for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
		rep(i,n+1) if(er[i]) p.emplace_back(i);
	}

	vector<int> primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)er.size()-1);
		return a>=0 && er[a];
	}
};
