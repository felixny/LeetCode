// 70. Climbing Stairs
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int climbStairs(int n) {
  vector<int> f(n + 1, 0);
  f[0] = f[1] = 1;

  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

int main() {

    cout << climbStairs(10);

    return 0;
}
