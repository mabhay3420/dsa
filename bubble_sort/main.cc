#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {
  void Sort(vector<string>* v) {
    for (int i = v->size() - 1; i >= 1; i--) {
      for (int j = 0; j < i; j++) {
        if ((*v)[j] > (*v)[j + 1]) {
          swap((*v)[j], (*v)[j + 1]); 
        }
      }
    }
  }
}  // namespace

int main() {
  vector<string> v{"microsoft", "google", "apple", "amazon", "facebook"};
  Sort(&v);
  for (const string& v_i : v) {
    cout << v_i << endl;
  }
  return 0;
}
