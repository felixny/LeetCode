// 62. Unique Paths

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};
