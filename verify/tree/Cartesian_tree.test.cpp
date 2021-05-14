#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../library/template.hpp"
#include "../../library/tree/Cartesian_tree.hpp"

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	Cartesian_tree CT(a);
	rep(u,n) printf("%d%c",CT.parent(u)!=-1?CT.parent(u):u,u<n-1?' ':'\n');

	return 0;
}
