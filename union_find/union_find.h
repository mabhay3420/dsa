#ifndef DSA_UNION_FIND_H_
#define DSA_UNION_FIND_H_

#include <unordered_map>

class UnionFind {
 public:
  explicit UnionFind(int size);
  void unite(int a, int b);
  int find(int node);
  void clear();
 private:
  std::unordered_map<int, int> root;
};

#endif
