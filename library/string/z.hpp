#pragma once
#include "../template.hpp"

vector<int> Z_algorithm(const string& s){
	int n=s.length();
	vector<int> z(n);
	for(int i=1,pre=0;i<n;i++){
		if(z[pre]>(i-pre)+z[i-pre]){
			z[i]=z[i-pre];
		}
		else{
			int j=max(pre+z[pre]-i,0);
			while(i+j<n && s[j]==s[i+j]) j++;
			z[i]=j;
			pre=i;
		}
	}
	z[0]=n;
	return z;
}

template<class T>
vector<int> Z_algorithm(const vector<T>& a){
	int n=a.size();
	vector<int> z(n);
	for(int i=1,pre=0;i<n;i++){
		if(z[pre]>(i-pre)+z[i-pre]){
			z[i]=z[i-pre];
		}
		else{
			int j=max(pre+z[pre]-i,0);
			while(i+j<n && a[j]==a[i+j]) j++;
			z[i]=j;
			pre=i;
		}
	}
	z[0]=n;
	return z;
}
