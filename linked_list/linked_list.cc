#include <iostream>
#include <string>

#include "linked_list.h"

namespace dsa {

Node::Node(const string& value)
    : next_(nullptr),
      value_(value) {}

Node* Node::next() const {
  return next_;
}

void Node::set_next(Node* node) {
  next_ = node;
}

const string Node::value() const {
  return value_;
}

LinkedList::LinkedList()
    : head_(nullptr) {}

LinkedList::~LinkedList() {
  Node* cur = head_;
  Node* temp = nullptr;
  while (cur != nullptr) {
    temp = cur->next();
    delete cur;
    if (temp == nullptr) {
      return;
    }
    cur = temp;
    temp = cur->next();
  }
}

void LinkedList::Add(const string& value) {
  Node* new_node = new Node(value);
  if (head_ == nullptr) {
    head_ = new_node;
    return;
  }

  Node* cur = head_;
  while (cur->next() != nullptr) {
    cur = cur->next();
  }
  cur->set_next(new_node);
}

Node* LinkedList::Head() const {
  return head_;
}

Node* LinkedList::Find(const string& value) const {
  Node* cur = head_;
  while (cur != nullptr) {
    if (value == cur->value()) {
      return cur;
    }
    cur = cur->next();
  }
  return nullptr;
}

}  // dsa
