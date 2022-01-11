// 409. Longest Palindrome

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
      map<char,int> m;
      for (int i = 0; i < s.size(); i++){
          // if key is present 
          if (m.count(s[i])) m[s[i]]++;
          // if key is not present initialize to 1;
          else m[s[i]] = 1;
      }

    int count = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++){
        int temp = iter->second;
        if (temp %2 == 1) count++;
    }

    // if 
    if (count > 0 ) count -= 1;

    return s.size()-count;


  }
};

int main(){


    return 0;
}