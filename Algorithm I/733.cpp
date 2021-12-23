// 733. Flood Fill
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                              int newColor) {
  int originColor = image[sr][sc];
  if (originColor == newColor) return image;
  stack<std::pair<int,int>> stack;
  stack.push({sr,sc});
  while (!stack.empty()){
      // temp does top and pop 
      pair<int,int> temp = stack.top(); stack.pop();
      int i = temp.first;
      int j = temp.second;
      image[i][j] = newColor;
      // right
      if (i+1 >= 0 && i+1 < image.size() && image[i+1][j] == originColor) stack.push({i+1,j});
      // left
      if (i-1 >= 0 && i-1 < image.size() && image[i-1][j] == originColor) stack.push({i-1,j});
      // bot
      if (j+1 >= 0 && j+1 < image[0].size() && image[i][j+1] == originColor) stack.push({i,j+1});
      // bot
      if (j-1 >= 0 && j+1 < image[0].size() && image[i][j-1] == originColor) stack.push({i,j-1});

  }
  return image;

}

int main() {
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

  floodFill(image,1,1,2);

  return 0;
}