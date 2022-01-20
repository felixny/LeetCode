// 200. Number of Islands

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
      int rows = grid.size();
      if (rows == 0) return 0;
      int cols = grid[0].size();

      int no_of_islands = 0;
      for (int i = 0; i < rows; i++){
          for (int j = 0; j < cols; j++){
              if (grid[i][j] == '1'){
                  mark(grid,i,j,rows,cols);
                  no_of_islands += 1;
              }
          }
      }
      return no_of_islands;
  }

 private:
  void mark(vector<vector<char>>& matrix, int x, int y, int r, int c) {
    if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != '1') return;

    matrix[x][y] = '2';

    mark(matrix, x + 1, y, r, c); // right
    mark(matrix, x, y + 1, r, c); // top
    mark(matrix, x - 1, y, r, c); // left
    mark(matrix, x, y - 1, r, c); // bot
  }
};
