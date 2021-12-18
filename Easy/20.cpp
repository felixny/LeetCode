// 20. Valid Parentheses
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isValid(string s) {
  stack<char> t;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      t.push(s[i]);
    } else if (s[i] == ')' && !t.empty() && t.top() == '(') {
      t.pop();
    } else if (s[i] == ']' && !t.empty() && t.top() == '[') {
      t.pop();
    } else if (s[i] == '}' && !t.empty() && t.top() == '{') {
      t.pop(); 
    } else {
        return false;
    }
  }
  return t.empty();
}

int main() {
  string s = "()";
  string s1 = "()[]{}";
  string s2 = "(]";  // false
  cout << isValid(s);
  cout << isValid(s1);
  cout << isValid(s2);
}
