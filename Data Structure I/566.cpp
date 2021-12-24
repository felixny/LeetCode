// 566. Reshape the Matrix
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if (r * c != mat.size() * mat[0].size()) return mat;

    vector<vector<int>> res(r, vector<int>(c));

    int sR = 0;
    int sC = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (sC == c) {
          sR++;
          sC = 0;
        }
        res[sR][sC] = mat[i][j];
        sC++;
      }
    }
    return res;
  }
};

void print_vector(vector<vector<int>> v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    cout << "[";
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << ", ";
    }
    cout << "],";
  }
  cout << "]" << endl;
}

int main() {
  vector<vector<int>> v = {{5, 10}, {15, 20}};

  print_vector(Solution().matrixReshape(v, 1, 4));

  return 0;
}