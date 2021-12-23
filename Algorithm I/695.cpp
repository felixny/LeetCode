// 695. Max Area of Island
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
  int r = grid.size();
  int c = grid[0].size();
  /* cout << r << endl;
  cout << c << endl; */

  if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1) {
    return 0;
  }

  grid[i][j] = 2;

  return (1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) +
          dfs(grid, i, j - 1));
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int r = grid.size();
  int c = grid[0].size();
  int result = 0;

  for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
          if (grid[i][j] == 1){
              result = max(result, dfs(grid,i,j));
          }
      }
  }

  return result;
}

int main() {
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  dfs(grid, 1, 1);
  cout << maxAreaOfIsland(grid);

  return 0;
}
