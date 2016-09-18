#include <iostream>
#include <vector>

using namespace std;

namespace {

int search(const vector<int>& v, int start, int end, int to_find) {
  if (start > end) {
    return -1;
  }
  int mid = start + ((end - start) >> 1);
  int mid_elem = v[mid];
  if (mid_elem == to_find) {
    return mid;
  }
  if (v[start] < mid_elem) {
    if (to_find < mid_elem) {
      return search(v, start, mid - 1, to_find);
    }
    return search(v, mid + 1, end, to_find);
  }
  if (mid_elem < v[end]) {
    if (mid_elem < to_find) {
      return search(v, mid + 1, end, to_find);
    }
    return search(v, start, mid - 1, to_find);
  }
  return -1;
}

}

int main() {
  vector<int> v({3, 4, 5, 6, 7, 8, 9, 0, 1, 2});
  cout << search(v, 0, v.size() - 1, 6) << endl;
  return 0;
}
