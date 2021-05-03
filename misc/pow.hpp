// 繰り返し二乗法で f^k を求める
// M はモノイド

template<class M>
M pow(M f,long long k){
	M res;
	for(;k>0;k>>=1){
		if(k&1) res=res*f;
		f=f*f;
	}
	return res;
}
