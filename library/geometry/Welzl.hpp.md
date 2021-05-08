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
  bundledCode: "#line 1 \"library/geometry/Welzl.hpp\"\n/*\n\t\u70B9\u96C6\u5408\u306E\
    \u6700\u5C0F\u5305\u542B\u5186\u3092\u6C42\u3081\u308B Welzl \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\n\t\t\u671F\u5F85\u8A08\u7B97\u91CF O(n)\n\t\t\u6700\u60AA\
    \u8A08\u7B97\u91CF O(n^3)\n*/\n\nclass smallest_enclosing_circle{\n\trandom_device\
    \ seed_gen;\n\tmt19937 rng;\n\n\tvector<point> P;\n\tvector<int> bdry;\n\n\tcircle\
    \ make_circle(){\n\t\tint m=bdry.size();\n\t\tif(m==0) return circle(point(0,0),-1);\n\
    \n\t\tpoint c=P[bdry[0]],v[2];\n\t\tReal r2=0,z[2];\n\t\trep(i,m-1){\n\t\t\tpoint\
    \ delta=P[bdry[i+1]]-c;\n\n\t\t\tv[i]=delta;\n\t\t\trep(j,i) v[i]-=dot(v[j],delta)/z[j]*v[j];\n\
    \t\t\tz[i]=abs2(v[i]);\n\n\t\t\tReal a=abs2(delta)-r2;\n\t\t\tc+=a/(2*z[i])*v[i];\n\
    \t\t\tr2+=a*a/(4*z[i]);\n\t\t}\n\n\t\treturn circle(c,sqrt(r2));\n\t}\n\n\tcircle\
    \ dfs(int i){\n\t\tif(i==P.size() || bdry.size()==3) return make_circle();\n\n\
    \t\tcircle C=dfs(i+1);\n\t\tif(C.r!=-1 && cover(C,P[i])) return C;\n\n\t\tbdry.emplace_back(i);\n\
    \t\tC=dfs(i+1);\n\t\tbdry.pop_back();\n\t\treturn C;\n\t}\n\npublic:\n\tsmallest_enclosing_circle(const\
    \ vector<point>& P):rng(seed_gen()),P(P){}\n\tcircle find(){\n\t\tbdry.clear();\n\
    \t\tshuffle(P.begin(),P.end(),rng);\n\t\treturn dfs(0);\n\t}\n};\n"
  code: "/*\n\t\u70B9\u96C6\u5408\u306E\u6700\u5C0F\u5305\u542B\u5186\u3092\u6C42\u3081\
    \u308B Welzl \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n\t\t\u671F\u5F85\u8A08\
    \u7B97\u91CF O(n)\n\t\t\u6700\u60AA\u8A08\u7B97\u91CF O(n^3)\n*/\n\nclass smallest_enclosing_circle{\n\
    \trandom_device seed_gen;\n\tmt19937 rng;\n\n\tvector<point> P;\n\tvector<int>\
    \ bdry;\n\n\tcircle make_circle(){\n\t\tint m=bdry.size();\n\t\tif(m==0) return\
    \ circle(point(0,0),-1);\n\n\t\tpoint c=P[bdry[0]],v[2];\n\t\tReal r2=0,z[2];\n\
    \t\trep(i,m-1){\n\t\t\tpoint delta=P[bdry[i+1]]-c;\n\n\t\t\tv[i]=delta;\n\t\t\t\
    rep(j,i) v[i]-=dot(v[j],delta)/z[j]*v[j];\n\t\t\tz[i]=abs2(v[i]);\n\n\t\t\tReal\
    \ a=abs2(delta)-r2;\n\t\t\tc+=a/(2*z[i])*v[i];\n\t\t\tr2+=a*a/(4*z[i]);\n\t\t\
    }\n\n\t\treturn circle(c,sqrt(r2));\n\t}\n\n\tcircle dfs(int i){\n\t\tif(i==P.size()\
    \ || bdry.size()==3) return make_circle();\n\n\t\tcircle C=dfs(i+1);\n\t\tif(C.r!=-1\
    \ && cover(C,P[i])) return C;\n\n\t\tbdry.emplace_back(i);\n\t\tC=dfs(i+1);\n\t\
    \tbdry.pop_back();\n\t\treturn C;\n\t}\n\npublic:\n\tsmallest_enclosing_circle(const\
    \ vector<point>& P):rng(seed_gen()),P(P){}\n\tcircle find(){\n\t\tbdry.clear();\n\
    \t\tshuffle(P.begin(),P.end(),rng);\n\t\treturn dfs(0);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/Welzl.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/Welzl.hpp
layout: document
redirect_from:
- /library/library/geometry/Welzl.hpp
- /library/library/geometry/Welzl.hpp.html
title: library/geometry/Welzl.hpp
---
