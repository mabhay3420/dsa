#include <assert.h>
#include "linked_list.h"

int main() {
  dsa::LinkedList linked_list;
  linked_list.Add("microsoft");
  linked_list.Add("apple");
  linked_list.Add("amazon");
  linked_list.Add("google");
  assert(linked_list.Find("microsoft") != nullptr);
  assert(linked_list.Find("google") != nullptr);
  assert(linked_list.Find("facebook") == nullptr);
  return 0;
}
