// 91. Decode Ways

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s.length() == 0 || s[0] == '0') return 0;
    if (s.length() == 1) return 1;

    int count1 = 1, count2 = 2;
    for (int i = 1; i < s.length(); i++) {
      int d = s[i] - '0';
      int dd = s[i - 1] - '0' * 10 + d;
      int count = 0;
      if (d > 0) count += count2;
      if (dd >= 0 && dd <= 26) count += count1;
      count1 = count2;
      count2 = count;  // count2 prev sol
    }

    return count2;
  }
};

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.length();
    if (s[0] == '0') return 0;
    if (n == 1) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      int onedigit = s[i - 1] - '0';
      int twodigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      if (onedigit >= 1) dp[i] += dp[i - 1];
      if (twodigit >= 10 && twodigit <= 26) dp[i] += dp[i - 2];
    }
    return dp[n];
  }
};