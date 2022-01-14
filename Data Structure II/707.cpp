// 707. Design Linked List

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class MyLinkedList {
  vector<int> vec;

 public:
  MyLinkedList() {}

  int get(int index) {
    if (index < 0 || index >= vec.size()) return -1;
    return vec[index];
  }

  void addAtHead(int val) { vec.insert(vec.begin(), val); }

  void addAtTail(int val) { vec.push_back(val); }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > vec.size()) return;
    if (index == vec.size()) {
      vec.push_back(val);
      return;
    }
    vec.insert(vec.begin() + index, val);
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= vec.size()) return;
    vec.erase(vec.begin() + index);
  }
};