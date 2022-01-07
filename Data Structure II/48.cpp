// 48. Rotate Image
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int temp;
    int minRow, maxRow;

    for (int i = 0; i < n / 2; i++) {
      minRow = i;
      maxRow = n - i - 1;
      for (int j = i, k = 0; j < maxRow; j++, k++) {
        // store top left to temp
        temp = matrix[minRow][minRow + k];
        // move bottom left to top left
        matrix[minRow][minRow + k] = matrix[maxRow - k][minRow];
        // move bottom right to bottom left
        matrix[maxRow - k][minRow] = matrix[maxRow][maxRow - k];
        // move top right to bottom right
        matrix[maxRow][maxRow - k] = matrix[minRow + k][maxRow];
        // move temp to top right
        matrix[minRow + k][maxRow] = temp;
      }
    }
  }
};

void printMatrix(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<std::vector<int>> matrix{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  Solution s;
  s.rotate(matrix);
  printMatrix(matrix);

  return 0;
}