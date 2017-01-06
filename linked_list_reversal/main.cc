#include <iostream>

using namespace std;

namespace {

struct Node {
  Node(int val) : value(val), next(nullptr) {}
  ~Node() {
    if (next != nullptr) {
      delete next;
    }
  }

  int value;
  Node* next;
};

Node* Reverse(Node* head) {
  Node* new_head = head;
  Node* p1 = head->next;
  Node* p2 = p1;
  new_head->next = nullptr;
  while (p1 != nullptr) {
    p2 = p1->next;
    p1->next = new_head;
    new_head = p1;
    p1 = p2;
  }
  return new_head;
}

void Print(Node* head) {
  Node* cur = head;
  while (cur != nullptr) {
    cout << cur->value << endl;
    cur = cur->next;
  }
}

}  // namespace

int main() {
  Node* list = new Node(1);
  list->next = new Node(2);
  list->next->next = new Node(3);
  list->next->next->next = new Node(4);
  list->next->next->next->next = new Node(5);
  Node* reversed_list = Reverse(list);
  Print(reversed_list);
  delete reversed_list;
  return 0;
}
