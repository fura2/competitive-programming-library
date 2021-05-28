#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include "../../library/template.hpp"
#include "../../library/monoid/gcd_monoid.hpp"
#include "../../library/data_structure/sparse_table.hpp"

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sparse_table<gcd_monoid<lint>> ST(a);

	lint ans=0;
	for(int l=0,r=0;l<n;l++){
		r=max(r,l+1);
		while(r<n && ST.product(l,r).get()>1) r++;
		if(r==n && ST.product(l,r).get()>1) continue;
		ans+=n-r+1;
	}
	printf("%lld\n",ans);

	return 0;
}
