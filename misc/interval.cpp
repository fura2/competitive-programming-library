template<class T> struct interval{
	T l,r;
	interval(){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

template<class T>
int interval_scheduling(vector<interval<T>> I){
	if(I.empty()) return 0;
	sort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){
		return make_pair(a.r,a.l)<make_pair(b.r,b.l);
	});
	int res=1;
	T cur=I[0].l;
	for(const auto& J:I) if(cur<=J.l) cur=J.r, res++;
	return res;
}

/*
	区間をマージする
		半開区間 [a, b), 整数座標を想定
*/
template<class T>
vector<interval<T>> interval_union(vector<interval<T>> I){
	sort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){ return a.l<b.l; });

	int n=I.size();
	if(n==0) return {};

	vector<interval<T>> res;
	T l=I[0].l,r=I[0].r;
	for(int i=1;i<=n;i++){
		if(i==n || r<I[i].l){
			res.emplace_back(l,r);
			if(i<n){
				l=I[i].l;
				r=I[i].r;
			}
		}
		else if(r<I[i].r){
			r=I[i].r;
		}
	}
	return res;
}
