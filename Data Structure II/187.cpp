// 187. Repeated DNA Sequences

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    unordered_map<string, int> tmp;

    if (s.length() < 10) {
      return result;
    }

    for (int i = 0; i <= s.length() - 10; i++) {
      string str = s.substr(i, 10);
      tmp[str]++;
      if (tmp[str] == 2) {
        result.push_back(str);
      }
    }

    return result;
  }
};

void print_vec(const vector<string> &vec) {
  for (string e : vec) cout << e << " ";
  cout << endl;
}

int main() {
  print_vec(
      Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
  print_vec(Solution().findRepeatedDnaSequences("A"));

  return 0;
}