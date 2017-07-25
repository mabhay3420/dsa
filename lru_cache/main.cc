#include <bits/stdc++.h>

using namespace std;

template <typename K, typename V>
class LRUCache {
 public:
  explicit LRUCache(int max_size)
    : max_size_(max_size) {}
  
  void Insert(const K& key, const V& value) {
    if (IsFull()) {
      RemoveOldest();
    }
    list_.push_front(make_pair(key, value));
    map_[key] = list_.begin();
  }
  
  void Get(const K& key, V* value) {
    auto map_it = map_.find(key);
    if (map_it == map_.end()) return;
    *value = map_it->second->second;
    list_.erase(map_it->second);
    map_.erase(map_it);
    Insert(key, *value);
  }
  
 private:
  bool IsFull() { return list_.size() >= max_size_; }
  
  void RemoveOldest() {
    auto last_it = list_.end();
    last_it--;
    map_.erase(last_it->first);
    list_.erase(last_it);
  }
  
  size_t max_size_;
  std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> map_;
  std::list<std::pair<K, V>> list_;
};

int main() {
  LRUCache<int, string> lru(2);
  lru.Insert(0, "a");
  lru.Insert(1, "b");
  lru.Insert(2, "c");
  
  string a;
  lru.Get(0, &a);
  cout << "a: " << a << endl;
  
  string b;
  lru.Get(1, &b);
  cout << "b: " << b << endl;
  
  string c;
  lru.Get(2, &c);
  cout << "c: " << c << endl;
  return 0;
}
