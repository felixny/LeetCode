// 74. Search a 2D Matrix
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == target) {
          return true;
        }
      }
    }
    return false;
  }

  bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    // taking the size of row and column
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = (row * col - 1);

    int mid = start + (end - start) / 2;

    while (start <= end) {
      // taking out the indexes of row , and column
      int element = matrix[mid / col][mid % col];

      if (element == target) {
        return 1;
      }
      if (element < target) {
        start = mid + 1;
      }
      if (element > target) {
        end = mid - 1;
      }

      mid = start + (end - start) / 2;
    }

    return 0;
  }
};

int main() {
  vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  return 0;
}
