// 547. Number of Provinces

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void dfs(vector<vector<int>>& isConnected, int i, int j) {
    isConnected[i][j] = 0;
    // check row
    for (auto k = 0; k < isConnected.size(); k++) {
      if (isConnected[j][k] == 1) dfs(isConnected, j, k);
    }
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int maxProvinces = 0;
    // next row
    for (auto i = 0; i < isConnected.size(); i++) {
        // next col
      for (auto j = 0; j < isConnected[0].size(); j++) {
        if (isConnected[i][j] == 1) {
          maxProvinces++;
          dfs(isConnected, i, j);
        }
      }
    }

    return maxProvinces;
  }
};

int main() { return 0; }