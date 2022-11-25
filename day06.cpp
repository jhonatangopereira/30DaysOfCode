// Day 6: Let's Review

/*
Given a string, S, of length N that is indexed from 0 to N - 1, print its
even-indexed and odd-indexed characters as 2 space-separated strings on a
single line (see the Sample below for more detail).
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void print_even_and_odd_characters(string S) {
  for (int evenIndex = 0; evenIndex < S.length(); evenIndex += 2) {
    cout << S[evenIndex];
  }
  cout << " ";
  for (int oddIndex = 1; oddIndex < S.length(); oddIndex += 2) {
    cout << S[oddIndex];
  }
  cout << endl;
}

int main(void) {
  string t_temp;
  getline(cin, t_temp);

  int T = stoi(ltrim(rtrim(t_temp)));

  for (int index = 0; index < T; index++) {
    string S;
    getline(cin, S);
    print_even_and_odd_characters(S);
  }

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
  );

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
    find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
    s.end()
  );

  return s;
}
