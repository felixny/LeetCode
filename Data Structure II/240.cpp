// 240. Search a 2D Matrix II
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] > target)
        j--;
      else
        i++;
    }

    return false;
  }
};

int main() { return 0; }