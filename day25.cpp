// Day 25: Running Time and Complexity

/*
A prime is a natural number greater than 1 that has no positive divisors
other than 1 and itself. Given a number, n, determine and print whether it
is Prime or Not prime.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
  int T = 0;
  cin >> T;

  for (int i = 0; i < T; i++) {
    bool isPrime = false;
    
    int n = 0;
    cin >> n;
    for (int j = 2; j < n / 2; j++) {
      if (n % j == 0) {
        isPrime = true;
        break;
      }
    }

    cout << ((isPrime or n == 1 or n == 4) ? "Not prime" : "Prime") << endl;
  }

  return 0;
}
