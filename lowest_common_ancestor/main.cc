#include <bits/stdc++.h>

using namespace std;

struct Node {
  explicit Node(char c) : value(c) {}
  char value;
  Node* left = nullptr;
  Node* right = nullptr;
};

Node* LCA(Node* root, char a, char b) {
  if (root == nullptr) return nullptr;
  if (root->value == a || root->value == b) return root;
  Node* left_lca = LCA(root->left, a, b);
  Node* right_lca = LCA(root->right, a, b);
  if (left_lca != nullptr && right_lca != nullptr) {
    return root;
  }
  return left_lca != nullptr ? left_lca : right_lca;
}

int main() {
  std::unique_ptr<Node> a(new Node('a'));
  std::unique_ptr<Node> b(new Node('b'));
  std::unique_ptr<Node> c(new Node('c'));
  std::unique_ptr<Node> d(new Node('d'));
  std::unique_ptr<Node> e(new Node('e'));
  a->left = b.get();
  a->right = e.get();
  b->left = c.get();
  b->right = d.get();

  cout << LCA(a.get(), 'c', 'd')->value << endl;  // b
  cout << LCA(a.get(), 'd', 'e')->value << endl;  // a
  return 0;
}
