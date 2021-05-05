#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../template.hpp"
#include "../../data_structure/Fenwick_tree.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	Fenwick_tree<int> F(n);
	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y); x--;
		if(type==0){
			F.add(x,y);
		}
		else{
			printf("%d\n",F.sum(x,y));
		}
	}

	return 0;
}