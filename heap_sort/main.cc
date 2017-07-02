#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

template <typename T>
void Sink(std::vector<T>& v, int i, int n) {
  int left_idx = 2 * i + 1;
  int right_idx = 2 * i + 2;
  while (left_idx <= n || right_idx <= n) {
    if (left_idx > n) return;
    if (right_idx > n) {
      if (v[i] < v[left_idx]) swap(v[i], v[left_idx]);
      return;
    }
    if (v[i] < v[left_idx] && v[right_idx] <= v[left_idx]) {
      swap(v[i], v[left_idx]);
      i = left_idx;
    } else if (v[i] < v[right_idx] && v[left_idx] <= v[right_idx]) {
      swap(v[i], v[right_idx]);
      i = right_idx;
    } else {
      return;
    }
    left_idx = 2 * i + 1;
    right_idx = 2 * i + 2;
  }
}
 
template <typename T>
void HeapSort(std::vector<T>& v) {
  int n = v.size() - 1;
  for (int i = n / 2; i >= 0; i--) {
    Sink(v, i, n);
  }
  while (n > 0) {
    swap(v[0], v[n--]);
    Sink(v, 0, n);
  }
}

}  // namespace

int main() {
	std::vector<int> v{2, 100, 3, 0, 1, 100, -1, 2};
	HeapSort(v);
	for (int v_i : v) cout << v_i << endl;
	return 0;
}
