#include <assert.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename Iterator, typename Item>
Iterator BinarySearch(
    const Iterator& begin, const Iterator& end, const Item& item) {
  sort(begin, end);
  int i = 0, m = 0;
  int j = (end - begin) - 1;
  while (i <= j) {
    m = i + (j - i) / 2;
    const Iterator& cur = begin + m;
    if (*cur == item) {
      return cur;
    }

    if (item > *cur) {
      i = m + 1;
    } else {
      j = m - 1;
    }
  }
  return end;
}

int main() {
  vector<string> items = {"microsoft", "amazon", "google", "apple", "facebook"};
  assert(BinarySearch(items.begin(), items.end(), "amazon") != items.end());
  assert(BinarySearch(items.begin(), items.end(), "google") != items.end());
  assert(BinarySearch(items.begin(), items.end(), "facebook") != items.end());
  assert(BinarySearch(items.begin(), items.end(), "azeus") == items.end());
  assert(BinarySearch(items.begin(), items.end(), "") == items.end());
  return 0;
}
