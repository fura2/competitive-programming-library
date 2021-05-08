#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../library/template.hpp"
#include "../../library/string/z.hpp"

int main(){
	string s; cin>>s;
	int n=s.length();
	vector<char> t(s.begin(),s.end());

	auto z=Z_algorithm(t);
	rep(i,n) printf("%d%c",z[i],i<n-1?' ':'\n');

	return 0;
}
