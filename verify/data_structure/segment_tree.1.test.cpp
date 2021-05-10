#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../library/template.hpp"
#include "../../library/data_structure/segment_tree.hpp"
#include "../../library/monoid/min_monoid.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	segment_tree<min_monoid<int>> S(n);
	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y);
		if(type==0){
			S.update(x,y);
		}
		else{
			y++;
			printf("%d\n",S.product(x,y).get());
		}
	}

	return 0;
}