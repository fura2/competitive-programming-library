/* Z-algorithm */
/*
	説明
		文字列 s の各 suffix に対して, それと s との最長共通接頭辞を求める
	引数
		s : 文字列
	制約
		なし
	戻り値
		配列 z[0..|S|)
	計算量
		O(|s|)
	備考
		z[i] = (s と s[i..) の最長共通接頭辞の長さ)
*/

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

vector<int> Z_algorithm(const vector<int>& a){
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
