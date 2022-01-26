// 22. Generate Parentheses

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string ans = "(";
    int open = 1;
    int closed = 0;
    dfs(result, ans, open, closed, n);
    return result;
  }

 private:
  void dfs(vector<string>& result, string ans, int open, int closed, int n) {
    if (open + closed == 2 * n) result.push_back(ans);

    if (open < n) dfs(result, ans + "(", open + 1, closed, n);
    if (closed < open) dfs(result, ans + ")", open, closed + 1, n);

    //return;
  }
};
