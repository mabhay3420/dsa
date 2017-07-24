#include <bits/stdc++.h>

using namespace std;

typedef std::vector<std::vector<string>> Grid;

void PrintLayer(const Grid& grid, int offset) {
  int min_x = offset;
  int max_x = grid[0].size() - 1 - offset;
  int min_y = offset;
  int max_y = grid.size() - 1 - offset;
  
  for (int i = min_x; i <= max_x; i++) {
    cout << grid[min_y][i] << endl;
  }
  min_y++;
  if (min_y > max_y) return;
  
  for (int j = min_y; j <= max_y; j++) {
    cout << grid[j][max_x] << endl;
  }
  max_x--;
  if (min_x > max_x) return;
  
  for (int i = max_x; i >= min_x; i--) {
    cout << grid[max_y][i] << endl;
  }
  max_y--;
  if (min_y > max_y) return;
  
  for (int j = max_y; j >= min_y; j--) {
    cout << grid[j][min_x] << endl;
  }
  min_x++;
}

void PrintSpiral(const Grid& grid) {
  if (grid.empty() || grid[0].empty()) return;
  int offset = 0;
  int limit = std::min(grid.size() / 2, grid[0].size() / 2);
  while (offset <= limit) {
    PrintLayer(grid, offset);
    offset++;
  }
}

int main() {
  Grid grid{
    {"A", "B", "C", "D"},
    {"J", "K", "L", "E"},
    {"I", "H", "G", "F"},
  };
  cout << "case 1: " << endl;
  PrintSpiral(grid);
  
  grid = {
    {"A", "B", "C"},
    {"R", "S", "D"},
    {"Q", "T", "E"},
    {"P", "U", "F"},
    {"O", "V", "G"},
    {"N", "W", "H"},
    {"M", "X", "I"},
    {"L", "K", "J"}
  };
  cout << "case 2: "<< endl;
  PrintSpiral(grid);
  return 0;
}
