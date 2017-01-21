#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

class MinHeap {
 public:
  explicit MinHeap(size_t size)
      : v_(size), cur_size_(0) {}

  void Insert(const string& str) {
    size_t index = cur_size_;
    v_[index] = str;
    cur_size_++;
    // Bubble up.
    size_t parent_index = index >> 1;
    while (v_[index] < v_[parent_index]) {
      swap(v_[index], v_[parent_index]);
      index = parent_index;
      parent_index = index >> 1;
    }
  }

  string Pop() {
    string result = v_.front();
    v_[0] = v_[--cur_size_];
    size_t index = 0;
    // Bubble down.
    size_t left_child = 2 * index + 1;
    size_t right_child = left_child + 1;
    while (true) {
      if (left_child >= cur_size_) {
        break;
      } else if (right_child >= cur_size_) {
        if (v_[index] < v_[left_child]) {
          swap(v_[index], v_[left_child]);
          index = left_child;
        }
      } else {
        if (v_[left_child] < v_[right_child]) {
          swap(v_[index], v_[left_child]);
          index = left_child;
        } else {
          swap(v_[index], v_[right_child]);
          index = right_child;
        }
      }
      left_child = 2 * index + 1;
      right_child = left_child + 1;
    }
    return result;
  }

  bool empty() {
    return cur_size_ == 0;
  }

 private:
  vector<string> v_;
  size_t cur_size_;
};

}  // namespace

int main() {
  MinHeap min_heap(5);
  min_heap.Insert("d");
  min_heap.Insert("a");
  min_heap.Insert("c");
  min_heap.Insert("e");
  min_heap.Insert("b");
  while (!min_heap.empty()) {
    cout << min_heap.Pop() << endl;
  }
  return 0;
}
