// Combination Sum

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  void dfs(vector<int>& candidates, int index, int target,
           vector<int>& current_result, vector<vector<int>>& result) {
    if (target == 0) {
      result.push_back(current_result);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (target >= candidates[i]) {
        current_result.push_back(candidates[i]);
        dfs(candidates, i, target - candidates[i], current_result, result);
        current_result.pop_back();
      }
    }
    return;
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current_result;
    dfs(candidates, 0, target, current_result, result);
    return result;
  }
};

void print_vec(const vector<int>& vec) {
  for (int e : vec) cout << e << " ";
  cout << endl;
}

int main() {
  vector<int> candidates = {2, 3, 6, 7};
  vector<vector<int>> res = Solution().combinationSum(candidates, 7);
  for (const vector<int>& a_res : res) print_vec(a_res);

  return 0;
}