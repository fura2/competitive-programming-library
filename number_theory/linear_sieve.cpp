/* 線形篩 */
/*
	説明
		n 以下のすべての正整数に対して, その最小の素因数を求める
	備考
		https://cp-algorithms.com/algebra/prime-sieve-linear.html

[ constructor ]
	説明
		なし
	引数
		n : 整数
	制約
		n >= 0
	計算量
		O(n)

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

[ is_prime ]
	説明
		a が素数かどうかを判定する
	引数
		a : 整数
	戻り値
		a が素数かどうか
	制約
		a <= n
	計算量
		O(1)

[ prime_factorize ]
	説明
		a を素因数分解する
	引数
		a : 整数
	戻り値
		a の素因数分解
	制約
		a <= n
	計算量
		O(log a)

[ number_of_divisors ]
	説明
		a の正の約数の個数を求める
	引数
		a : 整数
	戻り値
		a の正の約数の個数
	制約
		a <= n
	計算量
		O(log a)
*/

class linear_sieve{
	vector<int> lpf,p;
public:
	linear_sieve(int n):lpf(n+1){
		for(int i=2;i<=n;i++){
			if(lpf[i]==0){
				lpf[i]=i;
				p.emplace_back(i);
			}
			for(int j=0;j<p.size()&&p[j]<=lpf[i]&&i*p[j]<=n;j++) lpf[i*p[j]]=p[j];
		}
	}

	const vector<int>& primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)lpf.size()-1);
		return a>0 && lpf[a]==a;
	}

	map<int,int> prime_factorize(int a)const{
		assert(a<=(int)lpf.size()-1);
		map<int,int> pf;
		for(;a>1;a/=lpf[a]) ++pf[lpf[a]];
		return pf;
	}

	int number_of_divisors(int a)const{
		assert(a<=(int)lpf.size()-1);
		int res=1,cnt=0,pre=-1;
		for(;a>1;a/=lpf[a]){
			if(pre==-1 || pre==lpf[a]){
				cnt++;
			}
			else{
				res*=cnt+1;
				cnt=1;
			}
			pre=lpf[a];
		}
		return res*(cnt+1);
	}
};
