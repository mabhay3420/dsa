#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

namespace {

void Shuffle(std::vector<double>* v) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::shuffle(v->begin(), v->end(), generator);
}

void RandomShuffle(std::vector<double>* v) {
  std::srand(time(0));
  std::random_shuffle(
      v->begin(), v->end(), [](int x){ return std::rand() % x; });
}

void Print(const std::vector<double> v) {
  for (double v_i : v) {
    std::cout << v_i << std::endl;
  }
}

}

int main() {
  std::vector<double> v{12.3, -0.0, 0.1, 0.04, 123.4, -1000, -40.421};
  std::cout << "Shuffle: " << std::endl;
  Shuffle(&v);
  Print(v);
  std::cout << "RandomShuffle: " << std::endl;
  RandomShuffle(&v);
  Print(v);
  return 0;
}
