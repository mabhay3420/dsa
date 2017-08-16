#include <bits/stdc++.h>

using namespace std;

double SqrtHelper(int n, double guess) {
  const double kDelta = 0.000001;
  double n_over_guess = n / guess;
  if (std::abs(n_over_guess - guess) < kDelta) return guess;
  return SqrtHelper(n, (n_over_guess + guess) / 2);
}

double Sqrt(int n) {
  if (n < 0) return -1.0;
  if (n == 0) return 0.0;
  return SqrtHelper(n, 1.0);
}

int main() {
  cout << Sqrt(0) << endl;
  cout << Sqrt(1) << endl;
  cout << Sqrt(4) << endl;
  cout << Sqrt(9) << endl;
  cout << Sqrt(16) << endl;
  cout << Sqrt(25) << endl;
  cout << Sqrt(2) << endl;
  cout << Sqrt(3) << endl;
  return 0;
}
