// 557. Reverse Words in a String III

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseWords(string s) {
  int index = 0;
  for (int i = 0; i <= s.length(); ++i) {
    if (i == s.length() || s[i] == ' ') {
      std::reverse(s.begin() + index, s.begin() + i);
      index = i + 1;
    }
  }       
  return s;
}

int main() {
  string s = "Let's take LeetCode contest";

  reverseWords(s);

  return 0;
}