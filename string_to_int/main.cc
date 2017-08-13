#include <bits/stdc++.h>

using namespace std;

int StringToInt(const string& str) {
  if (str.empty()) return 0;
  size_t start_idx = (str.front() == '-') ? 1 : 0;
  int total = 0;
  for (size_t i = start_idx; i < str.size(); i++) {
    total = (total * 10 + (str[i] - '0'));
  }
  return (start_idx == 0) ? total : -total;
}

int main() {
  cout << StringToInt("-1234") << endl;
  cout << StringToInt("123454786") << endl;
  cout << StringToInt("-0") << endl;
  cout << StringToInt("0") << endl;
  return 0;
}
