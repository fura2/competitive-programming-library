/*
	2^n 次の Hadamard 行列
		各要素が 1 か -1 の正方行列であって次をみたすもの
		- どの二つの行も直交する
		- どの二つの列も直交する
	計算量 : O(4^N)
*/

matrix<int> Hadamard(int n){
	matrix<int> H(1<<n);
	H[0][0]=1;
	rep(k,n){
		int d=1<<k;
		rep(i,d) rep(j,d) {
			H[i][j+d]=H[i][j];
			H[i+d][j]=H[i][j];
			H[i+d][j+d]=-H[i][j];
		}
	}
	return H;
}
