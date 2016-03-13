#include <inttypes.h>
#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

size_t partition(vector<int64_t>& v, size_t start, size_t end) {
  int64_t pivot = v[start];
  size_t cur_idx = start;  // The index of the last element < pivot.

  for (size_t i = start + 1; i <= end; i++) {
    if (v[i] < pivot) {
      cur_idx++;
      swap(v[i], v[cur_idx]);
    }
  }
  swap(v[start], v[cur_idx]);
  return cur_idx;
}

void QuickSortHelper(vector<int64_t>& v, size_t start, size_t end) {
  if (start >= end) {
    return;
  }
  size_t p = partition(v, start, end);
  QuickSortHelper(v, start, p);
  QuickSortHelper(v, p + 1, end);
}


void QuickSort(vector<int64_t>& v) {
  QuickSortHelper(v, 0, v.size() - 1);
}

}  // namespace

int main() {
  vector<int64_t> v({-14, 200, 0, 1234, 4235, -1235, -1, 523, -123});
  QuickSort(v);
  for (auto v_i : v) {
    cout << v_i << endl;
  }
  return 0;
}
