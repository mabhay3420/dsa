#include <iomanip>
#include <iostream>
#include <map>
#include <random>

namespace {

int Generate() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> uniform_dist(1, 50);
  return uniform_dist(generator);
}

void Print(const std::map<int, int>& hist) {
  for (const std::pair<int, int>& it : hist) {
    std::cout << std::setw(2) << it.first << ": " << it.second << std::endl;
  }
}

}

int main() {
  std::map<int, int> hist;
  for (int i = 0; i < 10000; i++) {
    hist[Generate()]++;
  }
  Print(hist);
  return 0;
}
