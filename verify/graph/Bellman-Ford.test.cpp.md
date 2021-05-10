---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Bellman-Ford.hpp
    title: Bellman-Ford Algorithm
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/graph/Bellman-Ford.hpp: line 10: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../library/template.hpp\"\n#include \"../../library/graph/Bellman-Ford.hpp\"\
    \n\nint main(){\n\tint n,m,s; scanf(\"%d%d%d\",&n,&m,&s);\n\tweighted_graph<int>\
    \ G(n);\n\trep(i,m){\n\t\tint u,v,c; scanf(\"%d%d%d\",&u,&v,&c);\n\t\tadd_directed_edge(G,u,v,c);\n\
    \t}\n\n\tauto d=Bellman_Ford(G,s);\n\tif(count(d.begin(),d.end(),INT_MIN)>0){\n\
    \t\tputs(\"NEGATIVE CYCLE\");\n\t}\n\telse{\n\t\trep(u,n){\n\t\t\tif(d[u]<INT_MAX)\
    \ printf(\"%d\\n\",d[u]);\n\t\t\telse             puts(\"INF\");\n\t\t}\n\t}\n\
    \n\treturn 0;\n}\n"
  dependsOn:
  - library/template.hpp
  - library/graph/Bellman-Ford.hpp
  - library/graph/wgraph.hpp
  isVerificationFile: true
  path: verify/graph/Bellman-Ford.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 17:14:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/Bellman-Ford.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/Bellman-Ford.test.cpp
- /verify/verify/graph/Bellman-Ford.test.cpp.html
title: verify/graph/Bellman-Ford.test.cpp
---
