#include <bits/stdc++.h>

using namespace std;

bool IsOperator(const string& tok) {
  return tok == "+" || tok == "-" ||
         tok == "*" || tok == "/";
}

double DoOperation(double a, double b, const string& op) {
  if (op == "+") {
    return a + b;
  } else if (op == "-") {
    return a - b;
  } else if (op == "*") {
    return a * b;
  } else if (op == "/") {
    return a / b;
  }
  // Should not happen.
  return 0;
}

int main() {
  string expr = "34 34 + 23 3 - *";
  istringstream iss(expr);
  std::queue<string> tokens;
  string token;
  while (iss >> token) {
    tokens.push(token);
  }
  
  std::stack<double> stk;
  while (!tokens.empty()) {
    string cur_tok = tokens.front();
    tokens.pop();
    if (IsOperator(cur_tok)) {
      double op2 = stk.top();
      stk.pop();
      double op1 = stk.top();
      stk.pop();
      stk.push(DoOperation(op1, op2, cur_tok));
    } else {
      stk.push(std::stod(cur_tok));
    }
  }
  cout << stk.top() << endl;
  return 0;
}
