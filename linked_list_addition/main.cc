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

std::unique_ptr<Node> Add(Node* a, Node* b) {
  std::unique_ptr<Node> output;
  Node* cur_node = nullptr;
  int a_val, b_val, total, cur_sum;
  int cur_carry = 0;
  while (a != nullptr || b != nullptr) {
  	a_val = (a == nullptr) ? 0 : a->value;
  	b_val = (b == nullptr) ? 0 : b->value;

    total = (a_val + b_val + cur_carry);
    cur_sum = total % 10;
    cur_carry = total / 10;
    if (!output) {
      output.reset(new Node(cur_sum));
      cur_node = output.get();
    } else {
      cur_node->next.reset(new Node(cur_sum));
      cur_node = cur_node->next.get();
    }

    if (a != nullptr) a = a->next.get();
    if (b != nullptr) b = b->next.get();
  }
  if (cur_carry > 0) {
  	cur_node->next.reset(new Node(cur_carry));
  }
  return std::move(output);
}

}  // namespace

int main() {
  std::unique_ptr<Node> a(new Node(9));
  a->next.reset(new Node(2));
  a->next->next.reset(new Node(3));
  
  std::unique_ptr<Node> b(new Node(1));
  b->next.reset(new Node(2));
  b->next->next.reset(new Node(3));
  b->next->next->next.reset(new Node(4));
  
  Print(Add(a.get(), b.get()).get());
  return 0;
}
