// 784. Letter Case Permutation
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> result;
    dfs(s, result, 0);
    return result;
  }

 private:
  void dfs(string& s, vector<string>& result, int index) {
    if (index == s.length()) {
      result.push_back(s);
      return;
    }

    char c = s[index];

    if (isdigit(c)) {
      dfs(s, result, index + 1);
      return;
    } else {
      dfs(s, result, index + 1);
      if (isupper(c)) {
        // 1A -> 1a
        s[index] = tolower(s[index]);
      } else {
        s[index] = toupper(s[index]);
      }
      dfs(s, result, index + 1);
    }
  }
};

void print_vec(vector<string>& vec) {
  for (string e : vec) cout << e << " ";
  cout << endl;
}

int main() { 
    string s = "a1b2";
    vector<string> res = Solution().letterCasePermutation(s);
  for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
  }
    
    return 0; }
