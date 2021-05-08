class F2{
	bool x;
public:
	F2():x(false){}
	F2(long long n){ assert(n==0||n==1); x=(n==1); }
	F2& operator+=(const F2& a){ x=(x!=a.x); return *this; }
	F2& operator-=(const F2& a){ return (*this)+=a; }
	F2& operator*=(const F2& a){ x=(x&&a.x); return *this; }
	F2& operator/=(const F2& a){ assert(a.x); return *this; }
	F2 operator+(const F2& a)const{ return F2(*this)+=a; }
	F2 operator-(const F2& a)const{ return F2(*this)-=a; }
	F2 operator*(const F2& a)const{ return F2(*this)*=a; }
	F2 operator/(const F2& a)const{ return F2(*this)/=a; }
	F2 operator-()const{ return x; }
	bool operator==(const F2& a)const{ return x==a.x; }
	bool operator!=(const F2& a)const{ return !((*this)==a); }
	int to_int()const{ return x; }
};

// det(A) : 計算量 O(n^3)

F2 det(matrix<F2> A){
	assert(A.h()==A.w());
	int n=A.h();
	rep(i,n){
		int piv;
		for(piv=i;piv<n;piv++) if(A[piv][i]==1) break;
		if(piv==n) return 0;
		if(piv!=i){
			rep(j,n) swap(A[i][j],A[piv][j]);
		}
		for(int k=i+1;k<n;k++) if(A[k][i]==1) {
			for(int j=i;j<n;j++) A[k][j]-=A[i][j];
		}
	}
	return 1;
}

// rank(A) : 計算量 O(m*n^2)

int matrix_rank(matrix<F2> A){
	int m=A.h(),n=A.w(),r=0;
	rep(j,n){
		int piv;
		for(piv=r;piv<m;piv++) if(A[piv][j]==1) break;
		if(piv==m) continue;
		if(piv!=r){
			rep(k,n) swap(A[piv][k],A[r][k]);
		}
		for(int i=r+1;i<m;i++) if(A[i][j]==1) {
			for(int k=j;k<n;k++) A[i][k]-=A[r][k];
		}
		r++;
	}
	return r;
}

// A x = b が解をもつかどうか
// A は正方行列でなくてもよい
// 計算量 : O(m*n^2)

bool is_solvable(matrix<F2> A,vector<F2> b){
	int h=A.h(),w=A.w();
	assert(h==b.size());
	matrix<F2> A2(h,w+1);
	rep(i,h){
		rep(j,w) A2[i][j]=A[i][j];
		A2[i][w]=b[i];
	}
	return matrix_rank(A)==matrix_rank(A2);
}
