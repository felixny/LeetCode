// 59. Spiral Matrix II
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = n - 1;

    int val = 1;

    while (r1 <= r2 && c1 <= c2) {
      // move left to right
      for (int c = c1; c <= c2; ++c) ans[r1][c] = val++;

      // move down
      for (int r = r1 + 1; r <= r2; ++r) ans[r][c2] = val++;

      // move right to left
      if (r1 < r2 && c1 < c2) {
        for (int c = c2 - 1; c >= c1; --c) ans[r2][c] = val++;

        // move up
        for (int r = r2 - 1; r >= r1 + 1; --r) ans[r][c1] = val++;
      }
      r1++;
      r2--;
      c1++;
      c2--;
    }

    return ans;
  }
};

void printMatrix(vector<vector<int>> matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  printMatrix(Solution().generateMatrix(5));
  printMatrix(Solution().generateMatrix(20));

  return 0;
}