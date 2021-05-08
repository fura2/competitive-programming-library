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
  bundledCode: "#line 1 \"library/graph/functional_graph.hpp\"\n// functional graph\
    \ \u306E\u30B5\u30A4\u30AF\u30EB\u3092\u5217\u6319\u3059\u308B\n//   V = {0, 1,\
    \ ..., n-1}\n//   E = { (u, f(u)) | u = 0, 1, ..., n-1 }\n\nvector<vector<int>>\
    \ cycles(const vector<int>& f){\n\tint n=f.size();\n\tvector<vector<int>> res;\n\
    \tvector<int> color(n,-1);\n\trep(u,n) if(color[u]==-1) {\n\t\tint v=u;\n\t\t\
    do{ color[v]=u; v=f[v]; }while(color[v]==-1);\n\t\tif(color[v]==u){\n\t\t\tvector<int>\
    \ C;\n\t\t\tint w=v;\n\t\t\tdo{ C.emplace_back(v); v=f[v]; }while(v!=w);\n\t\t\
    \tres.emplace_back(C);\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "// functional graph \u306E\u30B5\u30A4\u30AF\u30EB\u3092\u5217\u6319\u3059\
    \u308B\n//   V = {0, 1, ..., n-1}\n//   E = { (u, f(u)) | u = 0, 1, ..., n-1 }\n\
    \nvector<vector<int>> cycles(const vector<int>& f){\n\tint n=f.size();\n\tvector<vector<int>>\
    \ res;\n\tvector<int> color(n,-1);\n\trep(u,n) if(color[u]==-1) {\n\t\tint v=u;\n\
    \t\tdo{ color[v]=u; v=f[v]; }while(color[v]==-1);\n\t\tif(color[v]==u){\n\t\t\t\
    vector<int> C;\n\t\t\tint w=v;\n\t\t\tdo{ C.emplace_back(v); v=f[v]; }while(v!=w);\n\
    \t\t\tres.emplace_back(C);\n\t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/functional_graph.hpp
layout: document
redirect_from:
- /library/library/graph/functional_graph.hpp
- /library/library/graph/functional_graph.hpp.html
title: library/graph/functional_graph.hpp
---
