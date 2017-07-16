#include <iostream>
#include <memory>

using namespace std;

namespace {

struct Node {
  explicit Node(int v) : value(v) {}
  int value;
  std::unique_ptr<Node> next;
};

void Print(Node* head) {
  Node* cur = head;
  while (cur != nullptr) {
    cout << cur->value << endl;
    cur = cur->next.get();
  }
}

int FindNthToTheLast(Node* node, size_t n) {
  Node* output = node;
  Node* ahead = node;
  size_t i = 1;
  while (i < n && ahead->next) {
    ahead = ahead->next.get();
    i++;
  }
  while (ahead->next) {
    output = output->next.get();
    ahead = ahead->next.get();
  }
  return output->value;
}

}  // namespace

int main() {
  std::unique_ptr<Node> list(new Node(1));
  list->next.reset(new Node(2));
  list->next->next.reset(new Node(3));
  list->next->next->next.reset(new Node(4));
  list->next->next->next->next.reset(new Node(5));

  cout << FindNthToTheLast(list.get(), 3) << endl;
  cout << FindNthToTheLast(list.get(), 4) << endl;
  return 0;
}
