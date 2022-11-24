// Day 3: Intro to Conditional Statements

/*
Given an integer, n, perform the following conditional actions:

If n is odd, print Weird
If n is even and in the inclusive range of 2 to 5, print Not Weird
If n is even and in the inclusive range of 6 to 20, print Weird
If n is even and greater than 20, print Not Weird
Complete the stub code provided in your editor to print whether or not n is
weird.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
  string N_temp;
  getline(cin, N_temp);

  int N = stoi(ltrim(rtrim(N_temp)));

  if (N % 2 != 0) {
    cout << "Weird" << endl;
  } else if (N % 2 == 0 and 2 <= N and N <= 5) {
    cout << "Not Weird" << endl;
  } else if (N % 2 == 0 and 6 <= N and N <= 20) {
    cout << "Weird" << endl;
  } else if (N % 2 == 0 and 20 < N) {
    cout << "Not Weird" << endl;
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
