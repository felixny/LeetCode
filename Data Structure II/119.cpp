// 119. Pascal's Triangle II
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    // initialize vector with 1
    vector<int> result(rowIndex + 1, 1);
    for (int i = 2; i < rowIndex + 1; i++) {
      for (int k = i - 1; k > 0; k--) {
        result[k] += result[k - 1];
      }
    }

    return result;
  }
};

class Solution1 {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> prev = {1}, curr;
    for (int i = 1; i <= rowIndex; i++) {
      curr.clear();
      curr.resize(i + 1, 1);
      for (int j = 1; j < i; j++) curr[j] = prev[j] + prev[j - 1];
      prev = curr;
    }
    return prev;
  }
};

int main() {
  Solution().getRow(3);

  return 0;
}