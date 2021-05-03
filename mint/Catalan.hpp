mint Catalan(int n){
	return n==0?1:choose(2*n,n)-choose(2*n,n-1);
}
