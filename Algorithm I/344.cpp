// 344. Reverse String
// two pointers

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    swap(s[i], s[j]);
    i++, j--;
  }
 
}

void reverseString1(vector<char>& s) {
  vector<char> rev;
  for (int i = s.size() - 1; i >= 0; i--) {
    rev.push_back(s[i]);
  }

  for (int i = 0; i < rev.size(); i++) {
    cout << rev[i];
  }
}

int main() {
  vector<char> s{'h', 'e', 'l', 'l', 'o'};
  vector<char> s1{'H','a','n','n','a','h'};

  reverseString(s);
  reverseString(s1);

  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }

    cout << endl;
  for (int i = 0; i < s.size(); i++) {
    cout << s1[i];
  }

  return 0;
}