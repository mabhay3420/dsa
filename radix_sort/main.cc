#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace {

int GetDigit(int n, int place) {
  return (n / place) % 10;
}
 
void CountingSort(std::vector<int>& v, int place) {
  std::vector<int> out(v.size());
  std::vector<int> digits(10, 0);
  for (int v_i : v) {
    digits[GetDigit(v_i, place)]++;
  }
  for (size_t i = 1; i < digits.size(); i++) {
    digits[i] += digits[i - 1];
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    int digit = GetDigit(v[i], place);
    out[digits[digit] - 1] = v[i];
    digits[digit]--;
  }
  v.assign(out.begin(), out.end());
}
 
void RadixSort(std::vector<int>& v) {
  if (v.empty()) return;
  int max = *std::max_element(v.begin(), v.end());
  int num_zeroes = log10(max);
  for (int i = 0; i <= num_zeroes; i++) {
    CountingSort(v, pow(10, i));
  }
}

}  // namespace

int main() {
  std::vector<int> v{2, 100, 3, 0, 1, 100, 2, 7, 0, 1000};
  RadixSort(v);
  for (int v_i : v) cout << v_i << endl;
  return 0;
}
