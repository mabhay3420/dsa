#include <bits/stdc++.h>

using namespace std;

void Permute(const string& cur, const string& str,
             std::vector<string>* perms) {
  if (str.empty()) {
    perms->push_back(cur);
    return;
  }
  for (size_t i = 0; i < str.size(); i++) {
    Permute(cur + str[i],
            str.substr(0, i) + str.substr(i + 1), perms);
  }
}

int main() {
  std::vector<string> perms;
  Permute("", "abcde", &perms);
  for (const string& p : perms) cout << p << endl;
  return 0;
}
