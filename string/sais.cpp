/* Suffix Array */
/*
[ constructor(string) ]
	説明
		文字列 s の suffix array を構築する
	引数
		s : 文字列
	制約
		なし
	計算量
		O(|s|)
	備考
		配列 sa は要素数 |s|+1
		s の |s|+1 個の suffix (空文字列も含む) のうち, 辞書順で i 番目にくるものが s[sa[i]..) となる

[ constructor(vector<int>) ]
	説明
		数列 s の suffix array を構築する
	引数
		s : 数列
	制約
		なし
	計算量
		O(|s|)
	備考
		配列 sa は要素数 |s|+1
		s の |s|+1 個の suffix (空文字列も含む) のうち, 辞書順で i 番目にくるものが s[sa[i]..) となる

[ operator[] ]
	引数
		i : インデックス
	制約
		0 <= i <= |s|
	戻り値
		文字列 s の suffix array の i 番目の要素を返す

[ longest_common_prefix ]
	引数
		なし
	制約
		なし
	戻り値
		s の LCP 配列を返す
		要素数は |s| で, LCP[i] = (s[sa[i]..) と s[sa[i+1]..) の最長共通接頭辞の長さ)
	計算量
		O(1)
*/

class suffix_array{
	vector<int> sa,lcp;

	vector<int> cnt;

	void SA_IS(vector<int>& s,int k){
		int n=s.size();

		for(int& c:s) c++;
		s.emplace_back(0);
		k++;

		vector<bool> isS(n+1);
		vector<int> LMS,bin(k+1);
		isS[n]=true;
		bin[1]=1;
		for(int i=n-1;i>=0;i--){
			isS[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:isS[i+1]);
			if(!isS[i] && isS[i+1]){
				LMS.emplace_back(i+1);
			}
			bin[s[i]+1]++;
		}
		rep(i,k) bin[i+1]+=bin[i];

		auto induced_sort=[&](const vector<int>& LMS){
			sa.assign(n+1,-1);
			cnt.assign(k,0);
			for(int x:LMS){
				sa[bin[s[x]+1]-cnt[s[x]]-1]=x;
				cnt[s[x]]++;
			}

			cnt.assign(k,0);
			rep(i,n+1){
				int x=sa[i]-1;
				if(x>=0 && !isS[x]){
					sa[bin[s[x]]+cnt[s[x]]]=x;
					cnt[s[x]]++;
				}
			}

			cnt.assign(k,0);
			for(int i=n;i>=0;i--){
				int x=sa[i]-1;
				if(x>=0 && isS[x]){
					sa[bin[s[x]+1]-cnt[s[x]]-1]=x;
					cnt[s[x]]++;
				}
			}
		};

		induced_sort(LMS);

		if(LMS.size()<=1) return;

		int m=LMS.size();
		vector<int> inv(n+1,-1);
		rep(i,m) inv[LMS[i]]=i;

		int idx=0;
		vector<int> LMS2(m);
		for(int x:sa) if(inv[x]!=-1) LMS2[idx++]=x;

		int k2=1;
		vector<int> s2(m);
		s2[m-1-inv[LMS2[1]]]=1;
		for(int i=2;i<m;i++){
			int xl=LMS2[i],yl=LMS2[i-1];
			int xr=LMS[inv[xl]-1],yr=LMS[inv[yl]-1];
			if(xr-xl!=yr-yl) k2++;
			else{
				while(xl<=xr){
					if(s[xl]!=s[yl]){ k2++; break; }
					xl++; yl++;
				}
			}
			s2[m-1-inv[LMS2[i]]]=k2;
		}

		SA_IS(s2,k2+1);

		idx=m;
		for(int i=1;i<=m;i++) LMS2[--idx]=LMS[m-sa[i]-1];
		induced_sort(LMS2);
	}

	void build_lcp(const vector<int>& s){
		int n=s.size();
		lcp.resize(n);
		vector<int> f(n+1);
		rep(i,n+1) f[sa[i]]=i;
		int h=0;
		rep(i,n+1){
			if(f[i]){
				for(int j=sa[f[i]-1];i+h<n&&j+h<n;h++) if(s[i+h]!=s[j+h]) break;
				lcp[f[i]-1]=h;
			}
			if(h>0) h--;
		}
	}

public:
	suffix_array(const string& s){
		int n=s.length();
		if(n==0){ sa={0}; return; }

		auto p=minmax_element(s.begin(),s.end());
		char mn=*p.first,mx=*p.second;

		vector<int> t(n);
		rep(i,n) t[i]=s[i]-mn;

		SA_IS(t,mx-mn+1);

		t.resize(n);
		rep(i,n) t[i]=s[i]-mn;
		build_lcp(t);
	}

	suffix_array(const vector<int>& a){
		int n=a.size();
		if(n==0){ sa={0}; return; }

		vector<int> X=a,b(n);
		sort(X.begin(),X.end());
		X.erase(unique(X.begin(),X.end()),X.end());

		rep(i,n) b[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();

		SA_IS(b,X.size());

		build_lcp(a);
	}

	int operator[](int i)const{ return sa[i]; }

	const vector<int>& longest_common_prefix()const{ return lcp; }
};
