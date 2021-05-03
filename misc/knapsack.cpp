/* 0-1 ナップサック問題 */
/*
	説明
		v_1, ..., v_n, w_1, ..., w_n, W : given
		minimize Σ_{i in S} v_i s.t. Σ_{i in S} w_i ≦ W
	引数
		I : アイテムのリスト
		W : ナップサックの容量
	制約
		v_i >= 0
		w_i >= 0
		W >= 0
	戻り値
		価値の合計の最大値
	計算量
		O(2^(n/2))
	備考
		https://twitter.com/noshi91/status/1271857111903825920
*/

template<class value_t,class weight_t>
class item{
public:
	value_t v;
	weight_t w;
	item(){}
	item(const value_t& v,const weight_t& w):v(v),w(w){}
};

template<class value_t,class weight_t>
value_t zero_one_knapsack(vector<item<value_t,weight_t>> I,const weight_t& W){
	auto enumerate=[](decltype(I) J){
		decltype(I) res={{0,0}};
		for(const auto& x:J){
			decltype(I) tmp1=res,tmp2=res,tmp3;
			for(auto& y:tmp2) y.v+=x.v, y.w+=x.w;

			merge(tmp1.begin(),tmp1.end(),tmp2.begin(),tmp2.end(),back_inserter(tmp3),
				[](const auto& y1,const auto& y2){
					return make_pair(y1.w,-y1.v)<make_pair(y2.w,-y2.v);
				});

			res.clear();
			for(const auto& y:tmp3) if(res.empty() || res.back().v<y.v) res.emplace_back(y);
		}
		return res;
	};

	int n=I.size();
	auto I1=enumerate({I.begin(),I.begin()+n/2});
	auto I2=enumerate({I.begin()+n/2,I.end()});

	value_t res=0;
	for(int i1=0,i2=int(I2.size())-1;i1<I1.size();i1++){
		while(i2>0 && I1[i1].w+I2[i2].w>W) i2--;
		if(I1[i1].w>W) break;
		res=max(res,I1[i1].v+I2[i2].v);
	}
	return res;
}
