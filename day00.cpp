// Day 0: Hello, World.

/*
To complete this challenge, you must save a line of input from stdin to a variable,
print Hello, World. on a single line, and finally print the value of your variable
on a second line.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string inputString;
  getline(cin, inputString);

  cout << "Hello, World." << endl;
  cout << inputString << endl;
  
  return 0;
}

/*
Sample Input:
  `Welcome to 30 Days of Code!`

Sample Output:
  `Hello, World!`
  `Welcome to 30 Days of Code!`
*/
