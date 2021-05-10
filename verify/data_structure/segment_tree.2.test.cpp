#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../library/template.hpp"
#include "../../library/data_structure/segment_tree.hpp"
#include "../../library/monoid/max_monoid.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	segment_tree<max_monoid<int>> S(n);
	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y);
		if(type==0){
			S.update(x,-y);
		}
		else{
			y++;
			int res=S.product(x,y).get();
			printf("%d\n",res==INT_MIN?INT_MAX:-res);
		}
	}

	return 0;
}
