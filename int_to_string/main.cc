#include <bits/stdc++.h>

using namespace std;

string IntToString(int n) {
  if (n == 0) return "0";
  bool is_negative = false;
  if (n < 0) {
    is_negative = true;
    n = -n;
  }
  string result;
  while (n != 0) {
    result += ('0' + (n % 10));
    n /= 10;
  }
  if (is_negative) result += "-";
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  cout << IntToString(-1234) << endl;
  cout << IntToString(1234) << endl;
  cout << IntToString(0) << endl;
  cout << IntToString(1) << endl;
  return 0;
}
