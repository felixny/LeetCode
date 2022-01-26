// 17. Letter Combinations of a Phone Number

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  const vector<string> map = {"abc", "def",  "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
  void backtrack(vector<string> &result, string &current, int index,
                 string &digits) {
    if (index == digits.size()) result.push_back(current);
    if (index < digits.size()) {
      for (auto c : map[digits[index] - '2']) {
        current[index] = c;
        backtrack(result, current, index + 1, digits);
      }
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.size() == 0) return result;
    string current(digits.size(), '0');
    backtrack(result, current, 0, digits);
    return result;
  }
};