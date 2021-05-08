/*
	<<=, >>=, <<, >>
		シフトする bit 長 x は非負 (size() 以上でもよい)
	update_and_shift(x)
		B &= B << x を inplace に計算
		x が負のときは -x bit の右シフトと解釈される
	update_or_shift(x)
		B |= B << x を inplace に計算
		x が負のときは -x bit の右シフトと解釈される
	update_xor_shift(x)
		B ^= B << x を inplace に計算
		x が負のときは -x bit の右シフトと解釈される
	to_string
		bit 列を 0, 1 からなる文字列に変換
		下位 bit から順に並ぶので注意
*/

class bit_vector{
	int n,m;
	vector<unsigned long long> a;
public:
	bit_vector(int n):n(n){
		m=n/64+1;
		a.assign(m,0);
	}
	int size()const{ return n; }
	void set(int i,int val){
		assert(0<=i && i<n && (val==0 || val==1));
		if(val==0) a[i/64]&=~(1ULL<<i%64);
		else       a[i/64]|=1ULL<<i%64;
	}
	int operator[](int i)const{
		assert(0<=i && i<n);
		return a[i/64]>>i%64&1;
	}
	bool operator==(const bit_vector& B)const{
		assert(n==B.size());
		rep(i,m) if(a[i]!=B.a[i]) return false;
		return true;
	}
	bool operator!=(const bit_vector& B)const{
		return !((*this)==B);
	}
	bit_vector& operator&=(const bit_vector& B){
		assert(n==B.size());
		rep(i,m) a[i]&=B.a[i];
		return *this;
	}
	bit_vector& operator|=(const bit_vector& B){
		assert(n==B.size());
		rep(i,m) a[i]|=B.a[i];
		return *this;
	}
	bit_vector& operator^=(const bit_vector& B){
		assert(n==B.size());
		rep(i,m) a[i]^=B.a[i];
		return *this;
	}
	bit_vector& operator<<=(int x){
		x=min(x,n);
		int w=x/64,d=x%64;
		for(int i=m-1;i>=w;i--){
			a[i]=a[i-w]<<d;
			if(i-w-1>=0 && d>0) a[i]|=a[i-w-1]>>(64-d);
		}
		for(int i=w-1;i>=0;i--) a[i]=0;
		return *this;
	}
	bit_vector& operator>>=(int x){
		x=min(x,n);
		int w=x/64,d=x%64;
		rep(i,m-w){
			a[i]=a[i+w]>>d;
			if(i+w+1<m && d>0) a[i]|=a[i+w+1]<<(64-d);
		}
		for(int i=m-w;i<m;i++) a[i]=0;
		return *this;
	}
	bit_vector operator&(const bit_vector& B)const{ return bit_vector(*this)&=B; }
	bit_vector operator|(const bit_vector& B)const{ return bit_vector(*this)|=B; }
	bit_vector operator^(const bit_vector& B)const{ return bit_vector(*this)^=B; }
	bit_vector operator<<(int x)const{ return bit_vector(*this)<<=x; }
	bit_vector operator>>(int x)const{ return bit_vector(*this)>>=x; }
	void update_and_shift(int x){
		if(x>0){
			x=min(x,n);
			int w=x/64,d=x%64;
			for(int i=m-1;i>=w;i--){
				unsigned long long mask=a[i-w]<<d;
				if(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);
				a[i]&=mask;
			}
			for(int i=w-1;i>=0;i--) a[i]=0;
		}
		else if(x<0){
			x=min(-x,n);
			int w=x/64,d=x%64;
			rep(i,m-w){
				unsigned long long mask=a[i+w]>>d;
				if(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);
				a[i]&=mask;
			}
			for(int i=m-w;i<m;i++) a[i]=0;
		}
	}
	void update_or_shift(int x){
		if(x>0){
			x=min(x,n);
			int w=x/64,d=x%64;
			for(int i=m-1;i>=w;i--){
				unsigned long long mask=a[i-w]<<d;
				if(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);
				a[i]|=mask;
			}
		}
		else if(x<0){
			x=min(-x,n);
			int w=x/64,d=x%64;
			rep(i,m-w){
				unsigned long long mask=a[i+w]>>d;
				if(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);
				a[i]|=mask;
			}
		}
	}
	void update_xor_shift(int x){
		if(x>0){
			x=min(x,n);
			int w=x/64,d=x%64;
			for(int i=m-1;i>=w;i--){
				unsigned long long mask=a[i-w]<<d;
				if(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);
				a[i]^=mask;
			}
		}
		else if(x<0){
			x=min(-x,n);
			int w=x/64,d=x%64;
			rep(i,m-w){
				unsigned long long mask=a[i+w]>>d;
				if(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);
				a[i]^=mask;
			}
		}
	}
};

string to_string(const bit_vector& B){
	string s(B.size(),'?');
	rep(i,B.size()) s[i]='0'+B[i];
	return s;
}
