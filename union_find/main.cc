#include <assert.h>
#include <iostream>

#include "union_find.h"

using namespace std;

int main() {
  UnionFind uf(10);
  uf.unite(0, 1);
  uf.unite(0, 2);
  uf.unite(2, 3);
  uf.unite(2, 4);
  uf.unite(4, 1);
  uf.unite(8, 9);

  assert(uf.find(0) == 0);
  assert(uf.find(1) == 0);
  assert(uf.find(2) == 0);
  assert(uf.find(3) == 0);
  assert(uf.find(4) == 0);
  assert(uf.find(5) == 5);
  assert(uf.find(6) == 6);
  assert(uf.find(7) == 7);
  assert(uf.find(8) == 8);
  assert(uf.find(9) == 8);
  return 0;
}
