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
    path: library/data_structure/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: library/data_structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: library/data_structure/union-find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: library/graph/Bellman-Ford.hpp
    title: Bellman-Ford Algorithm
  - icon: ':heavy_check_mark:'
    path: library/graph/Dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: Graph
  - icon: ':warning:'
    path: library/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: library/graph/tree_diameter.hpp
    title: Diameter of a Tree
  - icon: ':heavy_check_mark:'
    path: library/graph/wgraph.hpp
    title: Weighted Graph
  - icon: ':heavy_check_mark:'
    path: library/monoid/add_monoid.hpp
    title: Additive Monoid
  - icon: ':heavy_check_mark:'
    path: library/monoid/max_monoid.hpp
    title: Maximum Monoid
  - icon: ':heavy_check_mark:'
    path: library/monoid/min_monoid.hpp
    title: Minimum Monoid
  - icon: ':heavy_check_mark:'
    path: library/string/z.hpp
    title: Z Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree.1.test.cpp
    title: verify/data_structure/Fenwick_tree.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree.2.test.cpp
    title: verify/data_structure/Fenwick_tree.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Fenwick_tree_dual.test.cpp
    title: verify/data_structure/Fenwick_tree_dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/segment_tree.1.test.cpp
    title: verify/data_structure/segment_tree.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/segment_tree.2.test.cpp
    title: verify/data_structure/segment_tree.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/segment_tree.3.test.cpp
    title: verify/data_structure/segment_tree.3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/sparse_table.test.cpp
    title: verify/data_structure/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/starry_sky_tree.test.cpp
    title: verify/data_structure/starry_sky_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/union-find.test.1.cpp
    title: verify/data_structure/union-find.test.1.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/union-find.test.2.cpp
    title: verify/data_structure/union-find.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Bellman-Ford.test.cpp
    title: verify/graph/Bellman-Ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Dijkstra.1.test.cpp
    title: verify/graph/Dijkstra.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/Dijkstra.2.test.cpp
    title: verify/graph/Dijkstra.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.1.test.cpp
    title: verify/graph/tree_diameter.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.2.test.cpp
    title: verify/graph/tree_diameter.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z.1.test.cpp
    title: verify/string/z.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z.2.test.cpp
    title: verify/string/z.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - library/graph/tree_diameter.hpp
  - library/graph/wgraph.hpp
  - library/graph/Bellman-Ford.hpp
  - library/graph/Dijkstra.hpp
  - library/graph/graph.hpp
  - library/graph/topological_sort.hpp
  - library/monoid/max_monoid.hpp
  - library/monoid/min_monoid.hpp
  - library/monoid/add_monoid.hpp
  - library/data_structure/Fenwick_tree_dual.hpp
  - library/data_structure/Fenwick_tree.hpp
  - library/data_structure/union-find.hpp
  - library/data_structure/sparse_table.hpp
  - library/data_structure/segment_tree.hpp
  timestamp: '2021-05-09 03:26:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/z.2.test.cpp
  - verify/string/z.1.test.cpp
  - verify/graph/tree_diameter.1.test.cpp
  - verify/graph/Dijkstra.1.test.cpp
  - verify/graph/Dijkstra.2.test.cpp
  - verify/graph/Bellman-Ford.test.cpp
  - verify/graph/tree_diameter.2.test.cpp
  - verify/data_structure/sparse_table.test.cpp
  - verify/data_structure/Fenwick_tree.1.test.cpp
  - verify/data_structure/starry_sky_tree.test.cpp
  - verify/data_structure/Fenwick_tree.2.test.cpp
  - verify/data_structure/segment_tree.3.test.cpp
  - verify/data_structure/segment_tree.2.test.cpp
  - verify/data_structure/union-find.test.1.cpp
  - verify/data_structure/segment_tree.1.test.cpp
  - verify/data_structure/Fenwick_tree_dual.test.cpp
  - verify/data_structure/union-find.test.2.cpp
documentation_of: library/template.hpp
layout: document
redirect_from:
- /library/library/template.hpp
- /library/library/template.hpp.html
title: library/template.hpp
---
