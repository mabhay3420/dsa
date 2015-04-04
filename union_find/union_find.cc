#include "union_find.h"

#include <unordered_map>

UnionFind::UnionFind(int size) {
  for (int i = 0; i < size; i++) {
    root[i] = i;
  }
}

void UnionFind::unite(int a, int b) {
  int a_root = find(a);
  int b_root = find(b);
  if (a_root != b_root) {
    for (auto& iter : root) {
      if (iter.second == b_root) {
        iter.second = a_root;
      }
    }
  }
}

int UnionFind::find(int node) {
  std::unordered_map<int, int>::iterator root_iter = root.find(node);
  return root_iter != root.end() ? (*root_iter).second : -1;
}

void UnionFind::clear() {
  root.clear();
}
