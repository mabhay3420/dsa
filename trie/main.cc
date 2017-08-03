#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value = -1;
  std::unordered_map<char, std::unique_ptr<Node>> next;
};

class Trie {
 public:
  void Insert(const string& key, int value) {
    if (key.empty()) {
      root.value = value;
      return;
    }
    Insert(key, value, &root);
  }
  
  int Get(const string& key) {
    if (key.empty()) return root.value;
    return Get(key, root);
  }
  
 private:
  void Insert(const string& key, int value, Node* node) {
    if (key.empty()) {
      node->value = value;
      return;
    }
    Node* next = new Node;
    node->next[key.front()].reset(next);
    Insert(key.substr(1), value, next);
  }
  
  int Get(const string& key, const Node& node) {
    if (key.empty()) return node.value;
    auto it = node.next.find(key.front());
    if (it == node.next.end()) return -1;
    return Get(key.substr(1), *(it->second));
  }
  
  Node root;
};

int main() {
  Trie t;
  t.Insert("dog", 1);
  cout << t.Get("do") << endl;  // -1
  cout << t.Get("dog") << endl;  // 1
  cout << t.Get("dogx") << endl;  // -1
  cout << t.Get("abc") << endl;  // -1
  return 0;
}
