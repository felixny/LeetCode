// 9. Palindrome Number
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

/* bool isPalindrome(int x) {
  string str = to_string(x);
  // cout << str.length() << endl;
  int flag = 0;
  if (str[0] == '-' || str[2] == '0') {
    return false;
  }
  
  for (int i = 0; i <= str.length(); i++) {
    if (str[i] == str[str.length() - i - 1]) {
      flag = 1;
    }
  }
  if (flag) {
    return true;
  } else {
    return false;
  }
} */

 bool isPalindrome(int x) {
     string str = to_string(x);

     string p = str;

     reverse(p.begin(),p.end());

     if (str == p){
         return true;
     } else {
         return false;
     }

 }

int main() {
  cout << isPalindrome(50) << endl;
  cout << isPalindrome(121) << endl;
  cout << isPalindrome(-121) << endl;
  cout << isPalindrome(-10) << endl;
  cout << isPalindrome(10) << endl;
  cout << isPalindrome(100) << endl;
  cout << isPalindrome(1000) << endl;

  return 0;
}