/*
	trie

	N : アルファベットの種類数
	OFFSET : アルファベットの番号のオフセット (OFFSET, OFFSET+1, ..., OFFSET+N-1 が使用されるアルファベット)

	add(s,id) : trie にパターン s を追加し, その ID を id とする
	find_prefixes(s) :  s の prefix に一致するパターン全体 (の ID) を求める
*/

template<int N,int OFFSET>
class trie{
	struct node{
		vector<int> accept;
		int nxt[N];
		node():accept(){
			fill(nxt,nxt+N,-1);
		}
	};
	vector<node> V;
public:
	trie():V(1){}
	void add(const string& s,int id){
		int len=s.length(),pos=0;
		rep(i,len){
			if(V[pos].nxt[s[i]-OFFSET]==-1){
				V[pos].nxt[s[i]-OFFSET]=V.size();
				V.emplace_back();
			}
			pos=V[pos].nxt[s[i]-OFFSET];
		}
		V[pos].accept.emplace_back(id);
	}
	vector<int> find_prefixes(const char* s)const{
		auto res=V[0].accept;
		int pos=0;
		for(int i=0;s[i];i++){
			if(V[pos].nxt[s[i]-OFFSET]==-1){
				break;
			}
			pos=V[pos].nxt[s[i]-OFFSET];
			res.insert(res.end(),V[pos].accept.begin(),V[pos].accept.end());
		}
		return res;
	}
};
