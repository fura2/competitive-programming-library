inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

inline int popcount(unsigned long long x){
	x-=(x>>1)&0x5555555555555555LL;
	x=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);
	x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;
	x=(x*0x0101010101010101LL)>>56;
	return x;
}
