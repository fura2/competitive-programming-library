// a の xor についての基底を一組求める
// cf. https://twitter.com/noshi91/status/1200702280128856064
//     https://twitter.com/noshi91/status/1269660771086041088
//     https://twitter.com/tatyam_prime/status/1269653456454729728

auto basis(const vector<unsigned long long>& a){
	vector<unsigned long long> B;
	for(auto v:a){
		for(const auto& b:B) v=min(v,v^b);
		if(v!=0) B.emplace_back(v);
	}
	return B;
}

// B の元の線形結合で v が表されるかどうかを判定する
// B は上記の basis 関数で求めた基底でないといけない

bool is_linearly_independent(unsigned long long v,const vector<unsigned long long>& B){
	for(const auto& b:B) v=min(v,v^b);
	return v!=0;
}
