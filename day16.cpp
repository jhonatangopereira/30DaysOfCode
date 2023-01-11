// Day 16: Exceptions

/*
Read a string, S, and print its integer value; if S cannot be converted to an integer, print Bad String.
*/

#include <bits/stdc++.h>

using namespace std;


void convertStringInAnInteger(string S);

int main(void) {
  string S;
  getline(cin, S);

  convertStringInAnInteger(S);

  return 0;
}

void convertStringInAnInteger(string S) {
  try {
    cout << stoi(S) << endl;
  } catch (...) {
    cout << "Bad String" << endl;
  }
}
