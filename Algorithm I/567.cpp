// 567. Permutation in String
// sliding window

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
  // cout << s2[0] - 'a' << endl;
  int m = s1.length();
  int n = s2.length();
  if (m > n) {
    return false;
  }
  // initialize vector with zeros
  vector<int> map1(26);
  vector<int> map2(26);

  // increment count in s1 should be 1
  for (int i = 0; i < m; i++) {
    map1[s1[i] - 'a']++;
    map2[s2[i] - 'a']++;
  }

  //cout << map2[4] << endl;

  if (map1 == map2) return true;

  for (int i = 0; i + m < n; i++) {
    map2[s2[i] - 'a']--;
    // cout << map2[i] << endl;
    map2[s2[i + m] - 'a']++;
    if (map1 == map2) return true;
  }

  return false;
}

int main() {
  string s1 = "ab";
  string s2 = "eidbaooo";

  checkInclusion(s1, s2);

  return 0;
}