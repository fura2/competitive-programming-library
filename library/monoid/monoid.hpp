// どのモノイドについても, 引数を持たないコンストラクタが単位元を生成するものとする

// 台集合 : T1 の元と T2 の元のペア全体
// 積 : min (辞書順)
// 仮定 : i = 1, 2 に対して, Ti 上の全順序が定義されていて numeric_limits<Ti>::max() が最大元

template<class T> class min_monoid;
template<class T1,class T2>
class min_monoid<pair<T1,T2>>{
	pair<T1,T2> a;
public:
	min_monoid():a(numeric_limits<T1>::max(),numeric_limits<T2>::max()){}
	min_monoid(const pair<T1,T2>& val):a(val){}
	min_monoid operator*(const min_monoid& x)const{
		return min(a,x.a);
	}
	pair<T1,T2>& get(){ return a; }
	const pair<T1,T2>& get()const{ return a; }
};

// 台集合 : T の元全体
// 積 : max
// 仮定 : T 上の全順序が定義されていて numeric_limits<T>::min() が最小元

template<class T>
class max_monoid{
	T a;
public:
	max_monoid():a(numeric_limits<T>::min()){}
	max_monoid(const T& val):a(val){}
	max_monoid operator*(const max_monoid& x)const{
		return max(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

// 台集合 : T の元全体
// 積 : +
// 仮定 : T 上の結合的な二項演算 + が定義されていて T() が加法単位元

template<class T>
class add_monoid{
	T a;
public:
	add_monoid():a(){}
	add_monoid(const T& val):a(val){}
	add_monoid operator*(const add_monoid& x)const{
		return a+x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

// 台集合 : T の元全体
// 積 : bitwise OR
// 仮定 : T は int または lint を想定

template<class T>
class or_monoid{
	T a;
public:
	or_monoid():a(){}
	or_monoid(const T& val):a(val){}
	or_monoid operator*(const or_monoid& x)const{
		return a|x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

// 台集合 : T の元のソートされた列全体
// 積 : 列のマージ
// 仮定 : T 上の全順序が定義されている

template<class T>
class sequence_monoid{
	vector<T> a;
public:
	sequence_monoid(){}
	sequence_monoid(const T& val):a(1,val){}
	sequence_monoid(const vector<T>& x):a(x){
		sort(a.begin(),a.end());
	}
	sequence_monoid operator*(const sequence_monoid& x)const{
		vector<T> res;
		merge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));
		return res;
	}
};

// 台集合 : T の元のソートされた列とその累積和のペア全体
// 積 : 列のマージ
// 仮定 : T 上の全順序が定義されている
//       T 上の結合的な二項演算 + が定義されていて T() が加法単位元

template<class T>
class sequence_sum_monoid{
	vector<T> a,cum;
public:
	sequence_sum_monoid():cum(1){}
	sequence_sum_monoid(const T& val):a(1,val),cum{T(),val}{}
	sequence_sum_monoid(const vector<T>& x):a(x),cum(x.size()+1){
		sort(a.begin(),a.end());
		rep(i,x.size()) cum[i+1]=cum[i]+a[i];
	}
	sequence_sum_monoid operator*(const sequence_sum_monoid& x)const{
		vector<T> res;
		merge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));
		return res;
	}
};

// 台集合 : T の元を係数とする一次関数全体
// 積 : 一次関数の合成
//      f * g = g ○ f, 合成の向きに注意
//      (ax+b) * (cx+d) = c(ax+b)+d = cax + (cb+d)
// 仮定 : T は環 (非可換でもよい) であって T() が加法単位元, T(1) が乗法単位元

template<class T>
class affine_monoid{
	T a,b;
public:
	affine_monoid():a(1),b(){}
	affine_monoid(const T& a,const T& b):a(a),b(b){}
	affine_monoid(const pair<T,T>& val):a(val.first),b(val.second){}
	affine_monoid operator*(const affine_monoid& x)const{
		return {x.a*a,x.a*b+x.b};
	}
	pair<T&,T&> get(){ return {a,b}; }
	pair<const T&,const T&> get()const{ return {a,b}; }
	T eval(const T& x)const{ return a*x+b; }
};

// 台集合 : {0, 1, ..., N-1} の自己準同型全体 (N は明示的は指定しない)
// 積 : 写像の合成
//       f * g = f ○ g
// 仮定 : 特になし
// 備考 : N が異なる写像どうしの合成も計算できる
//       その場合には足りない部分は恒等写像になっていると見なす

class endomorphism_monoid{
	vector<int> f;
public:
	endomorphism_monoid(){}
	endomorphism_monoid(const vector<int>& f):f(f){}
	endomorphism_monoid operator*(const endomorphism_monoid& a)const{
		int n=f.size(),m=a.f.size();
		int k=max(n,m);
		vector<int> res(k);
		rep(i,k){
			int x=(i<m?a.f[i]:i);
			res[i]=(x<n?f[x]:x);
		}
		return res;
	}
	int operator[](int i)const{ return i<f.size()?f[i]:i; }
};
