#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../library/template.hpp"
#include "../../library/data_structure/Fenwick_tree.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	Fenwick_tree F(a);
	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y);
		if(type==0){
			F.add(x,y);
		}
		else{
			printf("%lld\n",F.sum(x,y));
		}
	}

	return 0;
}