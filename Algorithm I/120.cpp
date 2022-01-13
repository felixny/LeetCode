// 120. Triangle

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int len1 = triangle.size();
    int len2;
    for (int i = len1 - 2; i >= 0; i--) {
      len2 = triangle[i].size();
      for (int j = 0; j < len2; j++) {
        triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    }
    return triangle[0][0];
  }
};