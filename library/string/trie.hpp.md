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
  bundledCode: "#line 1 \"library/string/trie.hpp\"\n/*\n\ttrie\n\n\tN : \u30A2\u30EB\
    \u30D5\u30A1\u30D9\u30C3\u30C8\u306E\u7A2E\u985E\u6570\n\tOFFSET : \u30A2\u30EB\
    \u30D5\u30A1\u30D9\u30C3\u30C8\u306E\u756A\u53F7\u306E\u30AA\u30D5\u30BB\u30C3\
    \u30C8 (OFFSET, OFFSET+1, ..., OFFSET+N-1 \u304C\u4F7F\u7528\u3055\u308C\u308B\
    \u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8)\n\n\tadd(s,id) : trie \u306B\u30D1\
    \u30BF\u30FC\u30F3 s \u3092\u8FFD\u52A0\u3057, \u305D\u306E ID \u3092 id \u3068\
    \u3059\u308B\n\tfind_prefixes(s) :  s \u306E prefix \u306B\u4E00\u81F4\u3059\u308B\
    \u30D1\u30BF\u30FC\u30F3\u5168\u4F53 (\u306E ID) \u3092\u6C42\u3081\u308B\n*/\n\
    \ntemplate<int N,int OFFSET>\nclass trie{\n\tstruct node{\n\t\tvector<int> accept;\n\
    \t\tint nxt[N];\n\t\tnode():accept(){\n\t\t\tfill(nxt,nxt+N,-1);\n\t\t}\n\t};\n\
    \tvector<node> V;\npublic:\n\ttrie():V(1){}\n\tvoid add(const string& s,int id){\n\
    \t\tint len=s.length(),pos=0;\n\t\trep(i,len){\n\t\t\tif(V[pos].nxt[s[i]-OFFSET]==-1){\n\
    \t\t\t\tV[pos].nxt[s[i]-OFFSET]=V.size();\n\t\t\t\tV.emplace_back();\n\t\t\t}\n\
    \t\t\tpos=V[pos].nxt[s[i]-OFFSET];\n\t\t}\n\t\tV[pos].accept.emplace_back(id);\n\
    \t}\n\tvector<int> find_prefixes(const char* s)const{\n\t\tauto res=V[0].accept;\n\
    \t\tint pos=0;\n\t\tfor(int i=0;s[i];i++){\n\t\t\tif(V[pos].nxt[s[i]-OFFSET]==-1){\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\tpos=V[pos].nxt[s[i]-OFFSET];\n\t\t\tres.insert(res.end(),V[pos].accept.begin(),V[pos].accept.end());\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/*\n\ttrie\n\n\tN : \u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8\u306E\u7A2E\
    \u985E\u6570\n\tOFFSET : \u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8\u306E\u756A\
    \u53F7\u306E\u30AA\u30D5\u30BB\u30C3\u30C8 (OFFSET, OFFSET+1, ..., OFFSET+N-1\
    \ \u304C\u4F7F\u7528\u3055\u308C\u308B\u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8\
    )\n\n\tadd(s,id) : trie \u306B\u30D1\u30BF\u30FC\u30F3 s \u3092\u8FFD\u52A0\u3057\
    , \u305D\u306E ID \u3092 id \u3068\u3059\u308B\n\tfind_prefixes(s) :  s \u306E\
    \ prefix \u306B\u4E00\u81F4\u3059\u308B\u30D1\u30BF\u30FC\u30F3\u5168\u4F53 (\u306E\
    \ ID) \u3092\u6C42\u3081\u308B\n*/\n\ntemplate<int N,int OFFSET>\nclass trie{\n\
    \tstruct node{\n\t\tvector<int> accept;\n\t\tint nxt[N];\n\t\tnode():accept(){\n\
    \t\t\tfill(nxt,nxt+N,-1);\n\t\t}\n\t};\n\tvector<node> V;\npublic:\n\ttrie():V(1){}\n\
    \tvoid add(const string& s,int id){\n\t\tint len=s.length(),pos=0;\n\t\trep(i,len){\n\
    \t\t\tif(V[pos].nxt[s[i]-OFFSET]==-1){\n\t\t\t\tV[pos].nxt[s[i]-OFFSET]=V.size();\n\
    \t\t\t\tV.emplace_back();\n\t\t\t}\n\t\t\tpos=V[pos].nxt[s[i]-OFFSET];\n\t\t}\n\
    \t\tV[pos].accept.emplace_back(id);\n\t}\n\tvector<int> find_prefixes(const char*\
    \ s)const{\n\t\tauto res=V[0].accept;\n\t\tint pos=0;\n\t\tfor(int i=0;s[i];i++){\n\
    \t\t\tif(V[pos].nxt[s[i]-OFFSET]==-1){\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tpos=V[pos].nxt[s[i]-OFFSET];\n\
    \t\t\tres.insert(res.end(),V[pos].accept.begin(),V[pos].accept.end());\n\t\t}\n\
    \t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/trie.hpp
  requiredBy: []
  timestamp: '2021-05-08 15:01:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/trie.hpp
layout: document
redirect_from:
- /library/library/string/trie.hpp
- /library/library/string/trie.hpp.html
title: library/string/trie.hpp
---
