// 3. Longest Substring Without Repeating Characters

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring1(string s) {
  sort(s.begin(), s.end());

  cout << s << endl;
  map<char, int> temp;
  int count = 0;

  for (int i = 0; i < s.size(); i++) {
    temp.insert(pair<char, int>(s[i], count++));
  }

  map<char, int>::iterator itr;
  cout << "\nThe map gquiz1 is : \n";
  cout << "\tKEY\tELEMENT\n";
  for (itr = temp.begin(); itr != temp.end(); ++itr) {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << endl;

  return 0;
}

int lengthOfLongestSubstring2(string s) {
  sort(s.begin(), s.end());
  cout << s << endl;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s[i + 1]) {
      count++;
    }
    // count++;
  }
  // cout << count;
  return count;
}

int lengthOfLongestSubstring(string s) {
  int n = s.size();
  int res = 0;

  for (int i = 0; i < n; i++) {
    vector<bool> visisted(256);
    for (int j = i; j < n; j++) {
      if (visisted[s[j]] == true) {
        break;
      } else {
        res = max(res, j - i + 1);
        visisted[s[j]] = true;
      }
    }
    //visisted[s[i]] = false;
  }

  return res;
}

int main() {
  string s = "abcabcbb";
  string s1 = "bbbbb";
  string s2 = "pwwkew";

  cout << lengthOfLongestSubstring(s) << endl;
  cout << lengthOfLongestSubstring(s1) << endl;
  cout << lengthOfLongestSubstring(s2) << endl;

  return 0;
}