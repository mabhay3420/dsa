#include <assert.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace {
  class UnionFind {
   public:
    explicit UnionFind(int size) {
      for (int i = 0; i < size; i++) {
        root[i] = i;
      }
    }

    void unite(int a, int b) {
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

    int find(int node) {
      std::unordered_map<int, int>::iterator root_iter = root.find(node);
      return root_iter != root.end() ? (*root_iter).second : -1;      
    }

    void clear() {
      root.clear();
    }
   private:
    std::unordered_map<int, int> root;
  };

  struct Edge {
    Edge(int a, int b, int c) : x(a), y(b), weight(c) {}
    int x, y, weight;
  };

  vector<Edge> Kruskals(vector<Edge>& edges) {
    vector<Edge> result;
    sort(edges.begin(), edges.end(),
        [](const Edge& e1, const Edge& e2) -> bool {
          return e1.weight < e2.weight;
        });
    UnionFind uf(7);
    for (const auto& e : edges) {
      if (uf.find(e.x) != uf.find(e.y)) {
        result.push_back(e);
        uf.unite(e.x, e.y);
      }
    }
    return result;
  }
} // namespace

int main() {
  vector<Edge> edges;
  edges.emplace_back(0, 1, 7);
  edges.emplace_back(0, 3, 5);
  edges.emplace_back(1, 2, 8);
  edges.emplace_back(1, 3, 9);
  edges.emplace_back(1, 4, 7);
  edges.emplace_back(2, 4, 5);
  edges.emplace_back(3, 4, 15);
  edges.emplace_back(3, 5, 6);
  edges.emplace_back(4, 5, 8);
  edges.emplace_back(4, 6, 9);
  edges.emplace_back(5, 6, 11);

  int total_weight = 0;
  for (const auto& e : Kruskals(edges)) {
    total_weight += e.weight;
  }
  assert(total_weight == 39);
  return 0;
}
