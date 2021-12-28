// 77. Combinations
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> comb;
    vector<vector<int>> result;
    dfs(1, n, k, comb, result);
    return result;
  }

 private:
  void dfs(int index, int n, int k, vector<int> comb,
           vector<vector<int>>& result) {
    if (comb.size() == k) {
      result.push_back(comb);
      return;
    }

    for (int i = index; i <= n; i++) {
      comb.push_back(i);
      dfs(i + 1, n, k, comb, result);
      comb.pop_back();
    }
  }
};

void print_vec(const vector<int>& vec) {
  for (int e : vec) cout << e << " ";
  cout << endl;
}

int main() {
  vector<vector<int>> res = Solution().combine(4, 3);
  for (int i = 0; i < res.size(); i++) print_vec(res[i]);
  return 0;
}