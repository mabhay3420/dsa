#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

void Sort(vector<string>* v) {
  for (int i = 1; i < v->size(); i++) {
    int j = i;
    while (j >= 1 && (*v)[j] < (*v)[j - 1]) {
      swap((*v)[j], (*v)[j - 1]);
      j--;
    }
  }
}

}  // namespace

int main() {
  vector<string> v{"google", "facebook", "apple", "microsoft", "amazon"};
  Sort(&v);
  for (const string& v_i : v) {
    cout << v_i << endl;
  }
  return 0;
}
