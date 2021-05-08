#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../library/template.hpp"
#include "../../library/data_structure/sparse_table.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sparse_table ST(a);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d\n",ST.fold(l,r));
	}

	return 0;
}
