#include <iostream>
#include <vector>

using namespace std;

namespace {

typedef std::vector<std::vector<int>> Matrix;

Matrix Multiply(const Matrix& A, const Matrix& B) {
  Matrix output(A.size());
  for (size_t i = 0; i < A.size(); i++) {
    output[i] = std::vector<int>(B[0].size());
    for (size_t j = 0; j < B[0].size(); j++) {
      long total = 0L;
      for (size_t k = 0; k < B.size(); k++) {
        total += A[i][k] * B[k][j];
      }
      output[i][j] = total;
    }
  }
  return output;
}

ostream& operator<<(ostream& os, const Matrix& m) {
  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m[i].size(); j++) {
      os << m[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

}  // namespace

int main() {
  Matrix A{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  Matrix B{
    {1, 2},
    {3, 4},
    {5, 6},
  };
  cout << Multiply(A, B);
  return 0;
}
