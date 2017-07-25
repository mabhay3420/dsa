#include <bits/stdc++.h>

using namespace std;

struct Node {
  explicit Node(int v) : value(v) {}

  int value;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};

class BinaryTree {
 public:
  explicit BinaryTree(std::vector<int>* inorder)
    : inorder_(inorder) {}
  
  void Insert(int value) {
    if (!head_) {
      head_.reset(new Node(value));
    } else {
      InsertHelper(head_.get(), value);
    }
  }
  
  void Inorder() {
    InorderHelper(head_.get());
  }
  
  void Preorder() {
    PreorderHelper(head_.get());
  }
  
 private:
  int Compare(int a, int b) {
    const std::vector<int>& order = *inorder_;
    auto a_it = std::find(order.begin(), order.end(), a);
    auto b_it = std::find(order.begin(), order.end(), b);
    int a_index = std::distance(order.begin(), a_it);
    int b_index = std::distance(order.begin(), b_it);
    return a_index - b_index;
  }
  
  void InsertHelper(Node* node, int value) {
    if (Compare(node->value, value) < 0) {
      if (node->right) {
        InsertHelper(node->right.get(), value);
      } else {
        node->right.reset(new Node(value));
      }
    } else if (Compare(node->value, value) > 0) {
      if (node->left) {
        InsertHelper(node->left.get(), value);
      } else {
        node->left.reset(new Node(value));
      }
    }
  }
  
  void InorderHelper(Node* node) {
    if (node == nullptr) return;
    InorderHelper(node->left.get());
    cout << node->value << endl;
    InorderHelper(node->right.get());
  }
  
  void PreorderHelper(Node* node) {
    if (node == nullptr) return;
    cout << node->value << endl;
    PreorderHelper(node->left.get());
    PreorderHelper(node->right.get());
  }

  std::vector<int>* const inorder_;
  std::unique_ptr<Node> head_;
};

int main() {
  /*
           59
          /  \
        300  677
        /  \   \
       2   41   72
      /          \
     11           8
  */
  std::vector<int> inorder{11, 2, 300, 41, 59, 677, 72, 8};
  std::vector<int> preorder{59, 300, 2, 11, 41, 677, 72, 8};
  BinaryTree tree(&inorder);
  for (int p : preorder) tree.Insert(p);
  
  cout << "Inorder: " << endl;
  tree.Inorder();
  cout << "Preorder: " << endl;
  tree.Preorder();
  return 0;
}
