#include <iostream>
#include <vector>

using namespace std;

namespace {

void CountingSort(std::vector<int>& v) {
  if (v.empty()) return;
  int min = v[0];
  int max = v[0];
  for (size_t i = 1; i < v.size(); i++) {
    if (v[i] < min) min = v[i];
    if (v[i] > max) max = v[i];
  }
  int offset = -min;
  std::vector<size_t> count(max - min + 1, 0);
  for (int v_i : v) {
    count[v_i + offset]++;
  }
  size_t i = 0;
  for (size_t j = 0; j < count.size(); j++) {
    for (size_t k = 0; k < count[j]; k++) {
      v[i++] = j - offset;
    }
  }
}

}  // namespace

int main() {
  std::vector<int> v{2, 100, 3, 0, 1, 100, -1, 2};
  CountingSort(v);
  for (int v_i : v) cout << v_i << endl;
  return 0;
}
