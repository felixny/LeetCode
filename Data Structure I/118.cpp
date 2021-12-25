// 118. Pascal's Triangle
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    if (numRows <= 0) return result;

    result.push_back({1});

    for (int i = 1; i < numRows; i++) {
      vector<int> row;
      row.push_back(1);
       //cout << i << endl;
      for (int j = 1; j < i; j++){
          //cout << i << endl;
       //cout << j << endl;  
        row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
      }

      row.push_back(1);
      result.push_back(row);
    }
    return result;
  }
};

int main() {

    for (int i = 1; i < 5; i++){
        for (int j = 1 ; j < i; j++){
            cout << "#";
        }
        cout << endl;
    }
  Solution().generate(5);

  return 0;
}