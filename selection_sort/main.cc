#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

void Sort(vector<double>* nums) {
  int nums_size = nums->size();
  for (int i = 0; i < nums_size - 1; i++) {
    double min = (*nums)[i];
    int min_index = i;
    for (int j = i + 1; j < nums_size; j++) {
      if ((*nums)[j] < min) {
        min = (*nums)[j];
        min_index = j;
      }
    }
    swap((*nums)[i], (*nums)[min_index]);
  }
}

void Print(const vector<double>& nums) {
  for (const double n : nums) {
    cout << n << endl;
  }
}

}

int main() {
  vector<double> nums({-0.3, -0.5, 1.0, 0.9, 100, 500, 250.6});
  Sort(&nums);
  Print(nums);
  return 0;
}
