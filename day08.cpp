// Day 8: Dictionaries and Maps

/*
Given n names and phone numbers, assemble a phone book that maps friends'
names to their respective phone numbers. You will then be given an unknown
number of names to query your phone book for. For each name queried, print the
associated entry from your phone book on a new line in the form
name=phoneNumber; if an entry for name is not found, print Not found instead.
*/

#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main(void) {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  unordered_map<string, int> map;
  for (int i = 0; i < n; i++) {
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    map.insert({arr_temp[0], stoi(arr_temp[1])});
  }

  string query;
  while (getline(cin, query)) {
    if (map.find(query) == map.end()) {
      cout << "Not found" << endl;
    } else {
      cout << query << "=" << map.at(query) << endl;
    }
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

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
