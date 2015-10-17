#include <iostream>
#include <vector>

using namespace std;

class Matrix {
 public:
  explicit Matrix(const vector<vector<double>> matrix):matrix_(matrix) {}

  const vector<vector<double>>& get_matrix() const {
    return matrix_;
  }

  Matrix& operator*(const Matrix& other) {
    vector<vector<double>> result;
    const vector<vector<double>> a = get_matrix();
    const vector<vector<double>> b = other.get_matrix();
    for (int i = 0; i < a.size(); i++) {
      result.push_back(vector<double>(b[0].size()));
      for (int j = 0; j < b[0].size(); j++) {
        double total = 0.0;
        for (int k = 0; k < b.size(); k++) {
          total += a[i][k] * b[k][j];
        }
        result[i][j] = total;
      }
    }
    matrix_ = result;
    return *this;
  }
 private:
  vector<vector<double>> matrix_;
};

namespace {

ostream& operator<<(ostream& os, const Matrix& matrix) {
  const vector<vector<double>> m = matrix.get_matrix();
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      os << m[i][j] << " ";
    }
     os << endl;
  }
  return os;
}

}  // namespace

int main() {
  vector<vector<double>> m1;
  m1.push_back({1, 2});
  m1.push_back({3, 4});
  vector<vector<double>> m2;
  m2.push_back({5, 6, 7});
  m2.push_back({8, 9, 10});
  cout << Matrix(m1) * Matrix(m2) << endl;
  return 0;
}

