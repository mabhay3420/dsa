#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename Iterator, typename Item>
Iterator LinearSearch(
    const Iterator& begin, const Iterator& end, const Item& item) {
  for (auto i = begin; i != end; ++i) {
    if (*i == item) {
      return i;
    }
  }
  return end;
}

int main() {
  vector<string> items = {"john", "paul", "george", "ringo"};
  assert(LinearSearch(items.begin(), items.end(), "paul") != items.end());
  assert(LinearSearch(items.begin(), items.end(), "george") != items.end());
  assert(LinearSearch(items.begin(), items.end(), "") == items.end());
  return 0;
}
