#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../library/template.hpp"
#include "../../library/data_structure/segment_tree.hpp"
#include "../../library/monoid/add_monoid.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	segment_tree<add_monoid<int>> S(n);
	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y); x--;
		if(type==0){
			S.update(x,S[x].get()+y);
		}
		else{
			printf("%d\n",S.product(x,y).get());
		}
	}

	return 0;
}
