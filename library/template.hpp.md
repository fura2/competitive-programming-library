---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/data_structure/Fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: library/data_structure/Fenwick_tree_dual.hpp
    title: Dual Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: library/data_structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: library/data_structure/union-find.hpp
    title: Union-Find
  - icon: ':x:'
    path: library/graph/Dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':warning:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':x:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/string/z.hpp
    title: Z Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree.test.cpp
    title: verify/data_structure/Fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree_dual.test.cpp
    title: verify/data_structure/Fenwick_tree_dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.test.cpp
    title: verify/data_structure/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/union-find.test.cpp
    title: verify/data_structure/union-find.test.cpp
  - icon: ':x:'
    path: verify/graph/Dijkstra.test.cpp
    title: verify/graph/Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z.1.test.cpp
    title: verify/string/z.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z.2.test.cpp
    title: verify/string/z.2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "library/template.hpp"

    #include <cassert>

    #include <cctype>

    #include <chrono>

    #include <climits>

    #include <cmath>

    #include <cstdio>

    #include <cstdlib>

    #include <cstring>

    #include <ctime>

    #include <algorithm>

    #include <deque>

    #include <functional>

    #include <iostream>

    #include <limits>

    #include <map>

    #include <numeric>

    #include <queue>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <string>

    #include <tuple>

    #include <utility>

    #include <vector>


    #define rep(i,n) for(int i=0;i<(n);i++)


    using namespace std;

    using lint=long long;

    '
  code: '#pragma once

    #include <cassert>

    #include <cctype>

    #include <chrono>

    #include <climits>

    #include <cmath>

    #include <cstdio>

    #include <cstdlib>

    #include <cstring>

    #include <ctime>

    #include <algorithm>

    #include <deque>

    #include <functional>

    #include <iostream>

    #include <limits>

    #include <map>

    #include <numeric>

    #include <queue>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <string>

    #include <tuple>

    #include <utility>

    #include <vector>


    #define rep(i,n) for(int i=0;i<(n);i++)


    using namespace std;

    using lint=long long;

    '
  dependsOn: []
  isVerificationFile: false
  path: library/template.hpp
  requiredBy:
  - library/string/z.hpp
  - library/graph/wgraph.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/graph.hpp
  - library/data_structure/Fenwick_tree_dual.hpp
  - library/data_structure/Fenwick_tree.hpp
  - library/data_structure/union-find.hpp
  - library/data_structure/sparse_table.hpp
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/string/z.2.test.cpp
  - verify/string/z.1.test.cpp
  - verify/graph/Dijkstra.test.cpp
  - verify/data_structure/Fenwick_tree.test.cpp
  - verify/data_structure/sparse_table.test.cpp
  - verify/data_structure/union-find.test.cpp
  - verify/data_structure/Fenwick_tree_dual.test.cpp
documentation_of: library/template.hpp
layout: document
redirect_from:
- /library/library/template.hpp
- /library/library/template.hpp.html
title: library/template.hpp
---
