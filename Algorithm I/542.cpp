// 542. 01 Matrix
#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, 10000000 - m * n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j]) {
          if (i > 0) {
            // left
            result[i][j] = min(result[i][j], result[i - 1][j] + 1);
          }
          if (j > 0) {
            // top
            result[i][j] = min(result[i][j], result[i][j - 1] + 1);
          }
        } else {
          result[i][j] = 0;
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i < m - 1) {
          // right
          result[i][j] = min(result[i][j], result[i + 1][j] + 1);
        }
        // bot
        if (j < n - 1) {
          result[i][j] = min(result[i][j], result[i][j + 1] + 1);
        }
      }
    }

    return result;
  }
};

int main() { 
    
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};

    Solution().updateMatrix(mat);
    
    return 0; }