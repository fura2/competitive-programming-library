inline int digital_root(long long n,long long base=10){
	if(n==0) return 0;
	else     return n%(base-1)!=0?n%(base-1):base-1;
}
