#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "../../library/template.hpp"
#include "../../library/data_structure/starry_sky_tree.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	starry_sky_tree<int> S(n);
	rep(_,q){
		int type,l,r; scanf("%d%d%d",&type,&l,&r); r++;
		if(type==0){
			int x; scanf("%d",&x);
			S.add(l,r,-x);
		}
		else{
			printf("%d\n",-S.max(l,r));
		}
	}

	return 0;
}
