#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../../library/template.hpp"
#include "../../library/data_structure/Fenwick_tree_dual.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	Fenwick_tree_dual<int> F(n);
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==0){
			int l,r,x; scanf("%d%d%d",&l,&r,&x); l--;
			F.add(l,r,x);
		}
		else{
			int i; scanf("%d",&i); i--;
			printf("%d\n",F.get(i));
		}
	}

	return 0;
}