#include <iostream>
#include <vector>

using namespace std;

namespace {

void Merge(
    const vector<double>& left,
    const vector<double>& right,
    vector<double>* merged) {
  int i = 0;
  int j = 0;
  while (i < left.size() || j < right.size()) {
    if (i >= left.size()) {
      while (j < right.size()) {
        merged->push_back(right[j]);
        j++;
      }
      break;
    }
    if (j >= right.size()) {
      while (i < left.size()) {
        merged->push_back(left[i]);
        i++;
      }
      break;
    }
    if (left[i] <= right[j]) {
      merged->push_back(left[i]);
      i++;
    } else {
      merged->push_back(right[j]);
      j++;
    }
  }
}

void Sort(vector<double>* v) {
  if (v->size() <= 1) {
    return;
  }
  int half = v->size() >> 1;
  vector<double> left(v->begin(), v->begin() + half);
  vector<double> right(v->begin() + half, v->end());
  Sort(&left);
  Sort(&right);
  v->clear();
  Merge(left, right, v);
}

void Print(const vector<double>& nums) {
  for (auto num : nums) {
    cout << num << endl;
  }
}

}

int main() {
  vector<double> v({1, 0.2, -1, -100, 100.3});
  Sort(&v);
  Print(v);
  return 0;
}
