#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../library/template.hpp"
#include "../../library/data_structure/union-find.hpp"

int main(){
	int n,q; scanf("%d%d",&n,&q);

	union_find U(n);
	rep(_,q){
		int type,u,v; scanf("%d%d%d",&type,&u,&v);
		if(type==0){
			U.unite(u,v);
		}
		else{
			printf("%d\n",U.is_same(u,v)?1:0);
		}
	}

	return 0;
}
