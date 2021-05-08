---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structure/bit_vector.hpp\"\n/*\n\t<<=, >>=,\
    \ <<, >>\n\t\t\u30B7\u30D5\u30C8\u3059\u308B bit \u9577 x \u306F\u975E\u8CA0 (size()\
    \ \u4EE5\u4E0A\u3067\u3082\u3088\u3044)\n\tupdate_and_shift(x)\n\t\tB &= B <<\
    \ x \u3092 inplace \u306B\u8A08\u7B97\n\t\tx \u304C\u8CA0\u306E\u3068\u304D\u306F\
    \ -x bit \u306E\u53F3\u30B7\u30D5\u30C8\u3068\u89E3\u91C8\u3055\u308C\u308B\n\t\
    update_or_shift(x)\n\t\tB |= B << x \u3092 inplace \u306B\u8A08\u7B97\n\t\tx \u304C\
    \u8CA0\u306E\u3068\u304D\u306F -x bit \u306E\u53F3\u30B7\u30D5\u30C8\u3068\u89E3\
    \u91C8\u3055\u308C\u308B\n\tupdate_xor_shift(x)\n\t\tB ^= B << x \u3092 inplace\
    \ \u306B\u8A08\u7B97\n\t\tx \u304C\u8CA0\u306E\u3068\u304D\u306F -x bit \u306E\
    \u53F3\u30B7\u30D5\u30C8\u3068\u89E3\u91C8\u3055\u308C\u308B\n\tto_string\n\t\t\
    bit \u5217\u3092 0, 1 \u304B\u3089\u306A\u308B\u6587\u5B57\u5217\u306B\u5909\u63DB\
    \n\t\t\u4E0B\u4F4D bit \u304B\u3089\u9806\u306B\u4E26\u3076\u306E\u3067\u6CE8\u610F\
    \n*/\n\nclass bit_vector{\n\tint n,m;\n\tvector<unsigned long long> a;\npublic:\n\
    \tbit_vector(int n):n(n){\n\t\tm=n/64+1;\n\t\ta.assign(m,0);\n\t}\n\tint size()const{\
    \ return n; }\n\tvoid set(int i,int val){\n\t\tassert(0<=i && i<n && (val==0 ||\
    \ val==1));\n\t\tif(val==0) a[i/64]&=~(1ULL<<i%64);\n\t\telse       a[i/64]|=1ULL<<i%64;\n\
    \t}\n\tint operator[](int i)const{\n\t\tassert(0<=i && i<n);\n\t\treturn a[i/64]>>i%64&1;\n\
    \t}\n\tbool operator==(const bit_vector& B)const{\n\t\tassert(n==B.size());\n\t\
    \trep(i,m) if(a[i]!=B.a[i]) return false;\n\t\treturn true;\n\t}\n\tbool operator!=(const\
    \ bit_vector& B)const{\n\t\treturn !((*this)==B);\n\t}\n\tbit_vector& operator&=(const\
    \ bit_vector& B){\n\t\tassert(n==B.size());\n\t\trep(i,m) a[i]&=B.a[i];\n\t\t\
    return *this;\n\t}\n\tbit_vector& operator|=(const bit_vector& B){\n\t\tassert(n==B.size());\n\
    \t\trep(i,m) a[i]|=B.a[i];\n\t\treturn *this;\n\t}\n\tbit_vector& operator^=(const\
    \ bit_vector& B){\n\t\tassert(n==B.size());\n\t\trep(i,m) a[i]^=B.a[i];\n\t\t\
    return *this;\n\t}\n\tbit_vector& operator<<=(int x){\n\t\tx=min(x,n);\n\t\tint\
    \ w=x/64,d=x%64;\n\t\tfor(int i=m-1;i>=w;i--){\n\t\t\ta[i]=a[i-w]<<d;\n\t\t\t\
    if(i-w-1>=0 && d>0) a[i]|=a[i-w-1]>>(64-d);\n\t\t}\n\t\tfor(int i=w-1;i>=0;i--)\
    \ a[i]=0;\n\t\treturn *this;\n\t}\n\tbit_vector& operator>>=(int x){\n\t\tx=min(x,n);\n\
    \t\tint w=x/64,d=x%64;\n\t\trep(i,m-w){\n\t\t\ta[i]=a[i+w]>>d;\n\t\t\tif(i+w+1<m\
    \ && d>0) a[i]|=a[i+w+1]<<(64-d);\n\t\t}\n\t\tfor(int i=m-w;i<m;i++) a[i]=0;\n\
    \t\treturn *this;\n\t}\n\tbit_vector operator&(const bit_vector& B)const{ return\
    \ bit_vector(*this)&=B; }\n\tbit_vector operator|(const bit_vector& B)const{ return\
    \ bit_vector(*this)|=B; }\n\tbit_vector operator^(const bit_vector& B)const{ return\
    \ bit_vector(*this)^=B; }\n\tbit_vector operator<<(int x)const{ return bit_vector(*this)<<=x;\
    \ }\n\tbit_vector operator>>(int x)const{ return bit_vector(*this)>>=x; }\n\t\
    void update_and_shift(int x){\n\t\tif(x>0){\n\t\t\tx=min(x,n);\n\t\t\tint w=x/64,d=x%64;\n\
    \t\t\tfor(int i=m-1;i>=w;i--){\n\t\t\t\tunsigned long long mask=a[i-w]<<d;\n\t\
    \t\t\tif(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);\n\t\t\t\ta[i]&=mask;\n\t\t\t\
    }\n\t\t\tfor(int i=w-1;i>=0;i--) a[i]=0;\n\t\t}\n\t\telse if(x<0){\n\t\t\tx=min(-x,n);\n\
    \t\t\tint w=x/64,d=x%64;\n\t\t\trep(i,m-w){\n\t\t\t\tunsigned long long mask=a[i+w]>>d;\n\
    \t\t\t\tif(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);\n\t\t\t\ta[i]&=mask;\n\t\t\t\
    }\n\t\t\tfor(int i=m-w;i<m;i++) a[i]=0;\n\t\t}\n\t}\n\tvoid update_or_shift(int\
    \ x){\n\t\tif(x>0){\n\t\t\tx=min(x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\t\tfor(int\
    \ i=m-1;i>=w;i--){\n\t\t\t\tunsigned long long mask=a[i-w]<<d;\n\t\t\t\tif(i-w-1>=0\
    \ && d>0) mask|=a[i-w-1]>>(64-d);\n\t\t\t\ta[i]|=mask;\n\t\t\t}\n\t\t}\n\t\telse\
    \ if(x<0){\n\t\t\tx=min(-x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\t\trep(i,m-w){\n\t\
    \t\t\tunsigned long long mask=a[i+w]>>d;\n\t\t\t\tif(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);\n\
    \t\t\t\ta[i]|=mask;\n\t\t\t}\n\t\t}\n\t}\n\tvoid update_xor_shift(int x){\n\t\t\
    if(x>0){\n\t\t\tx=min(x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\t\tfor(int i=m-1;i>=w;i--){\n\
    \t\t\t\tunsigned long long mask=a[i-w]<<d;\n\t\t\t\tif(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);\n\
    \t\t\t\ta[i]^=mask;\n\t\t\t}\n\t\t}\n\t\telse if(x<0){\n\t\t\tx=min(-x,n);\n\t\
    \t\tint w=x/64,d=x%64;\n\t\t\trep(i,m-w){\n\t\t\t\tunsigned long long mask=a[i+w]>>d;\n\
    \t\t\t\tif(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);\n\t\t\t\ta[i]^=mask;\n\t\t\t\
    }\n\t\t}\n\t}\n};\n\nstring to_string(const bit_vector& B){\n\tstring s(B.size(),'?');\n\
    \trep(i,B.size()) s[i]='0'+B[i];\n\treturn s;\n}\n"
  code: "/*\n\t<<=, >>=, <<, >>\n\t\t\u30B7\u30D5\u30C8\u3059\u308B bit \u9577 x \u306F\
    \u975E\u8CA0 (size() \u4EE5\u4E0A\u3067\u3082\u3088\u3044)\n\tupdate_and_shift(x)\n\
    \t\tB &= B << x \u3092 inplace \u306B\u8A08\u7B97\n\t\tx \u304C\u8CA0\u306E\u3068\
    \u304D\u306F -x bit \u306E\u53F3\u30B7\u30D5\u30C8\u3068\u89E3\u91C8\u3055\u308C\
    \u308B\n\tupdate_or_shift(x)\n\t\tB |= B << x \u3092 inplace \u306B\u8A08\u7B97\
    \n\t\tx \u304C\u8CA0\u306E\u3068\u304D\u306F -x bit \u306E\u53F3\u30B7\u30D5\u30C8\
    \u3068\u89E3\u91C8\u3055\u308C\u308B\n\tupdate_xor_shift(x)\n\t\tB ^= B << x \u3092\
    \ inplace \u306B\u8A08\u7B97\n\t\tx \u304C\u8CA0\u306E\u3068\u304D\u306F -x bit\
    \ \u306E\u53F3\u30B7\u30D5\u30C8\u3068\u89E3\u91C8\u3055\u308C\u308B\n\tto_string\n\
    \t\tbit \u5217\u3092 0, 1 \u304B\u3089\u306A\u308B\u6587\u5B57\u5217\u306B\u5909\
    \u63DB\n\t\t\u4E0B\u4F4D bit \u304B\u3089\u9806\u306B\u4E26\u3076\u306E\u3067\u6CE8\
    \u610F\n*/\n\nclass bit_vector{\n\tint n,m;\n\tvector<unsigned long long> a;\n\
    public:\n\tbit_vector(int n):n(n){\n\t\tm=n/64+1;\n\t\ta.assign(m,0);\n\t}\n\t\
    int size()const{ return n; }\n\tvoid set(int i,int val){\n\t\tassert(0<=i && i<n\
    \ && (val==0 || val==1));\n\t\tif(val==0) a[i/64]&=~(1ULL<<i%64);\n\t\telse  \
    \     a[i/64]|=1ULL<<i%64;\n\t}\n\tint operator[](int i)const{\n\t\tassert(0<=i\
    \ && i<n);\n\t\treturn a[i/64]>>i%64&1;\n\t}\n\tbool operator==(const bit_vector&\
    \ B)const{\n\t\tassert(n==B.size());\n\t\trep(i,m) if(a[i]!=B.a[i]) return false;\n\
    \t\treturn true;\n\t}\n\tbool operator!=(const bit_vector& B)const{\n\t\treturn\
    \ !((*this)==B);\n\t}\n\tbit_vector& operator&=(const bit_vector& B){\n\t\tassert(n==B.size());\n\
    \t\trep(i,m) a[i]&=B.a[i];\n\t\treturn *this;\n\t}\n\tbit_vector& operator|=(const\
    \ bit_vector& B){\n\t\tassert(n==B.size());\n\t\trep(i,m) a[i]|=B.a[i];\n\t\t\
    return *this;\n\t}\n\tbit_vector& operator^=(const bit_vector& B){\n\t\tassert(n==B.size());\n\
    \t\trep(i,m) a[i]^=B.a[i];\n\t\treturn *this;\n\t}\n\tbit_vector& operator<<=(int\
    \ x){\n\t\tx=min(x,n);\n\t\tint w=x/64,d=x%64;\n\t\tfor(int i=m-1;i>=w;i--){\n\
    \t\t\ta[i]=a[i-w]<<d;\n\t\t\tif(i-w-1>=0 && d>0) a[i]|=a[i-w-1]>>(64-d);\n\t\t\
    }\n\t\tfor(int i=w-1;i>=0;i--) a[i]=0;\n\t\treturn *this;\n\t}\n\tbit_vector&\
    \ operator>>=(int x){\n\t\tx=min(x,n);\n\t\tint w=x/64,d=x%64;\n\t\trep(i,m-w){\n\
    \t\t\ta[i]=a[i+w]>>d;\n\t\t\tif(i+w+1<m && d>0) a[i]|=a[i+w+1]<<(64-d);\n\t\t\
    }\n\t\tfor(int i=m-w;i<m;i++) a[i]=0;\n\t\treturn *this;\n\t}\n\tbit_vector operator&(const\
    \ bit_vector& B)const{ return bit_vector(*this)&=B; }\n\tbit_vector operator|(const\
    \ bit_vector& B)const{ return bit_vector(*this)|=B; }\n\tbit_vector operator^(const\
    \ bit_vector& B)const{ return bit_vector(*this)^=B; }\n\tbit_vector operator<<(int\
    \ x)const{ return bit_vector(*this)<<=x; }\n\tbit_vector operator>>(int x)const{\
    \ return bit_vector(*this)>>=x; }\n\tvoid update_and_shift(int x){\n\t\tif(x>0){\n\
    \t\t\tx=min(x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\t\tfor(int i=m-1;i>=w;i--){\n\t\
    \t\t\tunsigned long long mask=a[i-w]<<d;\n\t\t\t\tif(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);\n\
    \t\t\t\ta[i]&=mask;\n\t\t\t}\n\t\t\tfor(int i=w-1;i>=0;i--) a[i]=0;\n\t\t}\n\t\
    \telse if(x<0){\n\t\t\tx=min(-x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\t\trep(i,m-w){\n\
    \t\t\t\tunsigned long long mask=a[i+w]>>d;\n\t\t\t\tif(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);\n\
    \t\t\t\ta[i]&=mask;\n\t\t\t}\n\t\t\tfor(int i=m-w;i<m;i++) a[i]=0;\n\t\t}\n\t\
    }\n\tvoid update_or_shift(int x){\n\t\tif(x>0){\n\t\t\tx=min(x,n);\n\t\t\tint\
    \ w=x/64,d=x%64;\n\t\t\tfor(int i=m-1;i>=w;i--){\n\t\t\t\tunsigned long long mask=a[i-w]<<d;\n\
    \t\t\t\tif(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);\n\t\t\t\ta[i]|=mask;\n\t\t\
    \t}\n\t\t}\n\t\telse if(x<0){\n\t\t\tx=min(-x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\
    \t\trep(i,m-w){\n\t\t\t\tunsigned long long mask=a[i+w]>>d;\n\t\t\t\tif(i+w+1<m\
    \ && d>0) mask|=a[i+w+1]<<(64-d);\n\t\t\t\ta[i]|=mask;\n\t\t\t}\n\t\t}\n\t}\n\t\
    void update_xor_shift(int x){\n\t\tif(x>0){\n\t\t\tx=min(x,n);\n\t\t\tint w=x/64,d=x%64;\n\
    \t\t\tfor(int i=m-1;i>=w;i--){\n\t\t\t\tunsigned long long mask=a[i-w]<<d;\n\t\
    \t\t\tif(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);\n\t\t\t\ta[i]^=mask;\n\t\t\t\
    }\n\t\t}\n\t\telse if(x<0){\n\t\t\tx=min(-x,n);\n\t\t\tint w=x/64,d=x%64;\n\t\t\
    \trep(i,m-w){\n\t\t\t\tunsigned long long mask=a[i+w]>>d;\n\t\t\t\tif(i+w+1<m\
    \ && d>0) mask|=a[i+w+1]<<(64-d);\n\t\t\t\ta[i]^=mask;\n\t\t\t}\n\t\t}\n\t}\n\
    };\n\nstring to_string(const bit_vector& B){\n\tstring s(B.size(),'?');\n\trep(i,B.size())\
    \ s[i]='0'+B[i];\n\treturn s;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/bit_vector.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/bit_vector.hpp
layout: document
redirect_from:
- /library/library/data_structure/bit_vector.hpp
- /library/library/data_structure/bit_vector.hpp.html
title: library/data_structure/bit_vector.hpp
---
