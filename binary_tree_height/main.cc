#include <bits/stdc++.h>

using namespace std;

struct Node {
  explicit Node(int v) : value(v) {}
  char value;
  Node* left = nullptr;
  Node* right = nullptr;
};

int GetHeight(Node* node) {
  if (node == nullptr) return -1;
  return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
}

int main() {
  std::unique_ptr<Node> a(new Node('a'));
  std::unique_ptr<Node> b(new Node('b'));
  std::unique_ptr<Node> c(new Node('c'));
  std::unique_ptr<Node> d(new Node('d'));
  std::unique_ptr<Node> e(new Node('e'));
  std::unique_ptr<Node> f(new Node('f'));
  std::unique_ptr<Node> g(new Node('g'));
  a->left = b.get();
  a->right = c.get();
  b->left = d.get();
  b->right = e.get();
  d->left = f.get();
  c->right = g.get();
  
  cout << "Height of the tree is " << GetHeight(a.get()) << endl;
  return 0;
}
