---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/z.hpp
    title: Z Algorithm
  - icon: ':heavy_check_mark:'
    path: library/template.hpp
    title: library/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/string/z.1.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 2 \"library/template.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <algorithm>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#define rep(i,n) for(int i=0;i<(n);i++)\n\n\
    using namespace std;\nusing lint=long long;\n#line 3 \"library/string/z.hpp\"\n\
    \nvector<int> Z_algorithm(const string& s){\n\tint n=s.length();\n\tvector<int>\
    \ z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\t\tif(z[pre]>(i-pre)+z[i-pre]){\n\t\t\
    \tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\tint j=max(pre+z[pre]-i,0);\n\t\t\twhile(i+j<n\
    \ && s[j]==s[i+j]) j++;\n\t\t\tz[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\tz[0]=n;\n\t\
    return z;\n}\n\ntemplate<class T>\nvector<int> Z_algorithm(const vector<T>& a){\n\
    \tint n=a.size();\n\tvector<int> z(n);\n\tfor(int i=1,pre=0;i<n;i++){\n\t\tif(z[pre]>(i-pre)+z[i-pre]){\n\
    \t\t\tz[i]=z[i-pre];\n\t\t}\n\t\telse{\n\t\t\tint j=max(pre+z[pre]-i,0);\n\t\t\
    \twhile(i+j<n && a[j]==a[i+j]) j++;\n\t\t\tz[i]=j;\n\t\t\tpre=i;\n\t\t}\n\t}\n\
    \tz[0]=n;\n\treturn z;\n}\n#line 5 \"verify/string/z.1.test.cpp\"\n\nint main(){\n\
    \tstring s; cin>>s;\n\tint n=s.length();\n\n\tauto z=Z_algorithm(s);\n\trep(i,n)\
    \ printf(\"%d%c\",z[i],i<n-1?' ':'\\n');\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../library/template.hpp\"\n#include \"../../library/string/z.hpp\"\n\n\
    int main(){\n\tstring s; cin>>s;\n\tint n=s.length();\n\n\tauto z=Z_algorithm(s);\n\
    \trep(i,n) printf(\"%d%c\",z[i],i<n-1?' ':'\\n');\n\n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/string/z.hpp
  isVerificationFile: true
  path: verify/string/z.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-23 04:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/string/z.1.test.cpp
layout: document
redirect_from:
- /verify/verify/string/z.1.test.cpp
- /verify/verify/string/z.1.test.cpp.html
title: verify/string/z.1.test.cpp
---
