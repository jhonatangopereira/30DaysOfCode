#include <bits/stdc++.h>
#include <bitset>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string intToBinary(int n) {
  string binary = bitset<32>(n).to_string();

  return binary;
}

int maximumNumberOfConsecutivesOnes(string n) {
  int counter, maximumCounter = 0;

  for (int i = 0; i < n.length(); i++) {
    if (n[i] == '1') {
      counter += 1;
    } else {
      counter = 0;
    }
    if (counter > maximumCounter) {
      maximumCounter = counter;
    }
  }

  return maximumCounter;
}


int main(void) {
  int n;
  cin >> n;

  cout << maximumNumberOfConsecutivesOnes(intToBinary(n)) << endl;

  return 0;
}

