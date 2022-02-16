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
    int start, end;

    for (int i = 0; i < n / 2; i++) {
      start = i;
      end = n - 1 - i;
      for (int i = start; i < end; i++) {
        // store top left to temp
       int temp = matrix[start][i];
       // left in top
       matrix[start][i] = matrix[n-1-i][start];
       // bottom in left
       matrix[n-1-i][start] = matrix[end][n-1-i];
       // right in bottom
       matrix[end][n-1-i] = matrix[i][end];
       // top in right
       matrix[i][end] = temp;
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