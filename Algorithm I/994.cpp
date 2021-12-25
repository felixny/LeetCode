// 994. Rotting Oranges
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    bool changed = false;
    int no = 2;
    while (true) {
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          if (grid[i][j] == no) {
            // right
            if (isValid(i + 1, j, grid) && grid[i + 1][j] == 1) {
              grid[i + 1][j] = grid[i][j] + 1;
              changed = true;
            }
            // left
            if (isValid(i - 1, j, grid) && grid[i - 1][j] == 1) {
              grid[i - 1][j] = grid[i][j] + 1;
              changed = true;
            }
            // bot
            if (isValid(i, j + 1, grid) && grid[i][j + 1] == 1) {
              grid[i][j + 1] = grid[i][j] + 1;
              changed = true;
            }
            // top
            if (isValid(i, j - 1, grid) && grid[i][j - 1] == 1) {
              grid[i][j - 1] = grid[i][j] + 1;
              changed = true;
            }
          }
        }
      }

      if (!changed) break;
      changed = false;
      no++;
    }

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }

    return no - 2;
  }

 private:
  bool isValid(int i, int j, vector<vector<int>>& grid) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
      return true;
    }

    return false;
  }
};

int main() {
  vector<vector<int>> g = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  vector<vector<int>> g1 = {{2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
  cout << Solution().orangesRotting(g) << endl;
  cout << Solution().orangesRotting(g1) << endl;
  return 0;
}