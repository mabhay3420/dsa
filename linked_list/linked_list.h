#ifndef DSA_LINKED_LIST_H_
#define DSA_LINKED_LIST_H_

#include <string>

using namespace std;

namespace dsa {

class Node {
 public:
  Node(const string& value);
  Node* next() const;
  void set_next(Node* node);
  const string value() const;
 private:
  Node* next_;
  string value_;
};

class LinkedList {
 public:
  LinkedList();
  ~LinkedList();
  void Add(const string& value);
  Node* Head() const;
  Node* Find(const string& value) const;
 private:
  Node* head_;
};

}  // dsa

#endif  // DSA_LINKED_LIST_H_
