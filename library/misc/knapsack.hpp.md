---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://twitter.com/noshi91/status/1271857111903825920
  bundledCode: "#line 1 \"library/misc/knapsack.hpp\"\n/* 0-1 \u30CA\u30C3\u30D7\u30B5\
    \u30C3\u30AF\u554F\u984C */\n/*\n\t\u8AAC\u660E\n\t\tv_1, ..., v_n, w_1, ...,\
    \ w_n, W : given\n\t\tminimize \u03A3_{i in S} v_i s.t. \u03A3_{i in S} w_i \u2266\
    \ W\n\t\u5F15\u6570\n\t\tI : \u30A2\u30A4\u30C6\u30E0\u306E\u30EA\u30B9\u30C8\n\
    \t\tW : \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u306E\u5BB9\u91CF\n\t\u5236\u7D04\
    \n\t\tv_i >= 0\n\t\tw_i >= 0\n\t\tW >= 0\n\t\u623B\u308A\u5024\n\t\t\u4FA1\u5024\
    \u306E\u5408\u8A08\u306E\u6700\u5927\u5024\n\t\u8A08\u7B97\u91CF\n\t\tO(2^(n/2))\n\
    \t\u5099\u8003\n\t\thttps://twitter.com/noshi91/status/1271857111903825920\n*/\n\
    \ntemplate<class value_t,class weight_t>\nclass item{\npublic:\n\tvalue_t v;\n\
    \tweight_t w;\n\titem(){}\n\titem(const value_t& v,const weight_t& w):v(v),w(w){}\n\
    };\n\ntemplate<class value_t,class weight_t>\nvalue_t zero_one_knapsack(vector<item<value_t,weight_t>>\
    \ I,const weight_t& W){\n\tauto enumerate=[](decltype(I) J){\n\t\tdecltype(I)\
    \ res={{0,0}};\n\t\tfor(const auto& x:J){\n\t\t\tdecltype(I) tmp1=res,tmp2=res,tmp3;\n\
    \t\t\tfor(auto& y:tmp2) y.v+=x.v, y.w+=x.w;\n\n\t\t\tmerge(tmp1.begin(),tmp1.end(),tmp2.begin(),tmp2.end(),back_inserter(tmp3),\n\
    \t\t\t\t[](const auto& y1,const auto& y2){\n\t\t\t\t\treturn make_pair(y1.w,-y1.v)<make_pair(y2.w,-y2.v);\n\
    \t\t\t\t});\n\n\t\t\tres.clear();\n\t\t\tfor(const auto& y:tmp3) if(res.empty()\
    \ || res.back().v<y.v) res.emplace_back(y);\n\t\t}\n\t\treturn res;\n\t};\n\n\t\
    int n=I.size();\n\tauto I1=enumerate({I.begin(),I.begin()+n/2});\n\tauto I2=enumerate({I.begin()+n/2,I.end()});\n\
    \n\tvalue_t res=0;\n\tfor(int i1=0,i2=int(I2.size())-1;i1<I1.size();i1++){\n\t\
    \twhile(i2>0 && I1[i1].w+I2[i2].w>W) i2--;\n\t\tif(I1[i1].w>W) break;\n\t\tres=max(res,I1[i1].v+I2[i2].v);\n\
    \t}\n\treturn res;\n}\n"
  code: "/* 0-1 \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C */\n/*\n\t\u8AAC\u660E\
    \n\t\tv_1, ..., v_n, w_1, ..., w_n, W : given\n\t\tminimize \u03A3_{i in S} v_i\
    \ s.t. \u03A3_{i in S} w_i \u2266 W\n\t\u5F15\u6570\n\t\tI : \u30A2\u30A4\u30C6\
    \u30E0\u306E\u30EA\u30B9\u30C8\n\t\tW : \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u306E\
    \u5BB9\u91CF\n\t\u5236\u7D04\n\t\tv_i >= 0\n\t\tw_i >= 0\n\t\tW >= 0\n\t\u623B\
    \u308A\u5024\n\t\t\u4FA1\u5024\u306E\u5408\u8A08\u306E\u6700\u5927\u5024\n\t\u8A08\
    \u7B97\u91CF\n\t\tO(2^(n/2))\n\t\u5099\u8003\n\t\thttps://twitter.com/noshi91/status/1271857111903825920\n\
    */\n\ntemplate<class value_t,class weight_t>\nclass item{\npublic:\n\tvalue_t\
    \ v;\n\tweight_t w;\n\titem(){}\n\titem(const value_t& v,const weight_t& w):v(v),w(w){}\n\
    };\n\ntemplate<class value_t,class weight_t>\nvalue_t zero_one_knapsack(vector<item<value_t,weight_t>>\
    \ I,const weight_t& W){\n\tauto enumerate=[](decltype(I) J){\n\t\tdecltype(I)\
    \ res={{0,0}};\n\t\tfor(const auto& x:J){\n\t\t\tdecltype(I) tmp1=res,tmp2=res,tmp3;\n\
    \t\t\tfor(auto& y:tmp2) y.v+=x.v, y.w+=x.w;\n\n\t\t\tmerge(tmp1.begin(),tmp1.end(),tmp2.begin(),tmp2.end(),back_inserter(tmp3),\n\
    \t\t\t\t[](const auto& y1,const auto& y2){\n\t\t\t\t\treturn make_pair(y1.w,-y1.v)<make_pair(y2.w,-y2.v);\n\
    \t\t\t\t});\n\n\t\t\tres.clear();\n\t\t\tfor(const auto& y:tmp3) if(res.empty()\
    \ || res.back().v<y.v) res.emplace_back(y);\n\t\t}\n\t\treturn res;\n\t};\n\n\t\
    int n=I.size();\n\tauto I1=enumerate({I.begin(),I.begin()+n/2});\n\tauto I2=enumerate({I.begin()+n/2,I.end()});\n\
    \n\tvalue_t res=0;\n\tfor(int i1=0,i2=int(I2.size())-1;i1<I1.size();i1++){\n\t\
    \twhile(i2>0 && I1[i1].w+I2[i2].w>W) i2--;\n\t\tif(I1[i1].w>W) break;\n\t\tres=max(res,I1[i1].v+I2[i2].v);\n\
    \t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/knapsack.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/knapsack.hpp
layout: document
redirect_from:
- /library/library/misc/knapsack.hpp
- /library/library/misc/knapsack.hpp.html
title: library/misc/knapsack.hpp
---
