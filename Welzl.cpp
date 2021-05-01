/*
	点集合の最小包含円を求める Welzl のアルゴリズム
		期待計算量 O(n)
		最悪計算量 O(n^3)
*/

class smallest_enclosing_circle{
	random_device seed_gen;
	mt19937 rng;

	vector<point> P;
	vector<int> bdry;

	circle make_circle(){
		int m=bdry.size();
		if(m==0) return circle(point(0,0),-1);

		point c=P[bdry[0]],v[2];
		Real r2=0,z[2];
		rep(i,m-1){
			point delta=P[bdry[i+1]]-c;

			v[i]=delta;
			rep(j,i) v[i]-=dot(v[j],delta)/z[j]*v[j];
			z[i]=abs2(v[i]);

			Real a=abs2(delta)-r2;
			c+=a/(2*z[i])*v[i];
			r2+=a*a/(4*z[i]);
		}

		return circle(c,sqrt(r2));
	}

	circle dfs(int i){
		if(i==P.size() || bdry.size()==3) return make_circle();

		circle C=dfs(i+1);
		if(C.r!=-1 && cover(C,P[i])) return C;

		bdry.emplace_back(i);
		C=dfs(i+1);
		bdry.pop_back();
		return C;
	}

public:
	smallest_enclosing_circle(const vector<point>& P):rng(seed_gen()),P(P){}
	circle find(){
		bdry.clear();
		shuffle(P.begin(),P.end(),rng);
		return dfs(0);
	}
};
