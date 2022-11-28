// Day 9: Recursion 3

/*
Complete the factorial function in the editor below. Be sure to use recursion.

factorial has the following parameter:
  int n: an integer
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n) {
  return n == 0 ? 1 : (n * factorial(n - 1));
}

int main() {
  int n;
  cin >> n;

  cout << factorial(n) << endl;

  return 0;
}
