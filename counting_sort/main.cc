#include <iostream>
#include <vector>

using namespace std;

static const int kMaxValue = 10;

namespace {

void CountingSort(vector<int>* v) {
  if (v == nullptr) {
    return;
  }
  vector<int> count(kMaxValue + 1);
  for (int v_i : *v) {
    count[v_i + 1]++;
  }
  for (int i = 0; i < kMaxValue; i++) {
    count[i + 1] += count[i];
  }
  vector<int> aux(v->size());
  for (int v_i : *v) {
    aux[count[v_i]++] = v_i;
  }
  for (int i = 0; i < aux.size(); i++) {
    (*v)[i] = aux[i];
  }
}

}  // namespace

int main() {
  vector<int> v({2, 3, 1, 0, 9, 8, 4, 5, 7, 6});
  CountingSort(&v);
  for (int v_i : v) {
    cout << v_i << endl;
  }
  return 0;
}
