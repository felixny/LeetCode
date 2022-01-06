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

int main() {
  Solution().getRow(3);

  return 0;
}