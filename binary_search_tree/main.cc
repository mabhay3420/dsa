#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

namespace {

struct Node {
  explicit Node(int v) : value(v) {}

  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  int value;
};

class BST {
 public:
  void Insert(int value) {
    if (!root_) {
      root_.reset(new Node(value));
    } else {
      InsertHelper(root_.get(), value);
    }
  }
  
  std::vector<int> bfs() {
    std::vector<int> values;
    std::queue<Node*> q;
    q.push(root_.get());
    while (!q.empty()) {
      Node* top = q.front();
      q.pop();
      values.push_back(top->value);
      if (top->left) {
        q.push(top->left.get());
      }
      if (top->right) {
        q.push(top->right.get());
      }
    }
    return values;
  }

 private:
  void InsertHelper(Node* root, int value) {
    if (value < root->value) {
      if (root->left) {
        InsertHelper(root->left.get(), value);
      } else {
        root->left.reset(new Node(value));
      }
    } else if (root->value < value) {
      if (root->right) {
        InsertHelper(root->right.get(), value);
      } else {
        root->right.reset(new Node(value));
      }
    }
  }
  
  std::unique_ptr<Node> root_;
};

void Print(const std::vector<int>& v) {
  for (int v_i : v) { cout << v_i << endl; }
}

}  // namespace

int main() {
  BST bst;
  bst.Insert(1);
  bst.Insert(3);
  bst.Insert(0);
  bst.Insert(-1);
  Print(bst.bfs());
  return 0;
}
