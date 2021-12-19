// 28. Implement strStr()

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
  // if empty
  if (!needle.size()) {
    return 0;
  }

  for (int i = 0; i < haystack.size(); i++) {
    if (haystack[i] == needle[0]) {
      int j = 0;
      for (int j = 0; i < needle.size(); j++) {
        if (haystack[i + j] != needle[j]) break;
      }
      if (j == needle.size()) return i;
    }
  }
  return -1;
}

int strStr(string haystack, string needle) {
  int n = haystack.length();
  int m = needle.length();

  if (m == 0) return 0;

  if (m > n) return -1;

  // iterate till last front value used for window matching
  for (int i = 0; i <= n - m; i++) {
    // comparing value from front and rear simultaneously to save time
    if (needle[0] == haystack[i] && needle[m - 1] == haystack[i + m - 1]) {
      int start = 0;    // window start
      int end = m - 1;  // window end

      while (start <= end && needle[start] == haystack[i + start] &&
             needle[end] == haystack[i + end]) {
        start++;
        end--;
      }

      if (start > end)  // we have matched all values so we successfully find
                        // the substring
        return i;
    }
  }
  return -1;
}

int main() { return 0; }