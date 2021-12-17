// 14. Longest Common Prefix
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  int minimumLegnth = strs.at(0).size();

  for (int i = 1; i < strs.size(); i++) {
    if (strs.at(i).size() < minimumLegnth) minimumLegnth = strs.at(i).size();
  }

  // cout << minimumLegnth << endl;

  string result;
  char current;

  for (int i = 0; i < minimumLegnth; i++) {
    //  first character in a string
    current = strs[0][i];

    for (int j = 1; j < strs.size(); j++)
      if (strs[j][i] != current) {
        return result;
      }

    result.push_back(current);
  }
  return result;
}

int main() {
  vector<string> strs = {"flower", "flow", "flight"};
  vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
  vector<string> arr1 = {"dog", "racecar", "car"};

  cout << longestCommonPrefix(strs) << endl;
  cout << longestCommonPrefix(arr) << endl;
  cout << longestCommonPrefix(arr1) << endl;

  /* cout << strs.size() << endl;
  for (int i = 0; i < strs.size(); i++) {
    cout << strs.at(i) << endl;
    cout << strs.at(i).size() << endl;
  } */

  // cout << strs[0][0] << endl;

  /*  char c;
   c = strs[0][0];
   cout << c << endl; */
}
