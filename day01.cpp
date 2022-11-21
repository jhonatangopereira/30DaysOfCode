// Day 1: Data Types

/*
The variables i, d, and s are already declared and initialized for you. You must:

1. Declare  variables: one of type int, one of type double, and one of type String.
2. Read  lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your  variables.
3. Use the  operator to perform the following operations:
  1. Print the sum of  plus your int variable on a new line.
  2. Print the sum of  plus your double variable to a scale of one decimal place on a new line.
  3. Concatenate  with the string you read as input and print the result on a new line.
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
  int i = 4;
  double d = 4.0;
  string s = "HackerRank ";

  
  // Declare second integer, double, and String variables.
  int inputInteger;
  double inputDouble;
  string inputString;
  
  // Read and save an integer, double, and String to your variables.
  cin >> inputInteger;
  cin >> inputDouble;
  getline(cin >> ws, inputString);

  // Print the sum of both integer variables on a new line.
  cout << i + inputInteger << endl;
  
  // Print the sum of the double variables on a new line.
  cout << fixed << setprecision(1) << (d + inputDouble) << endl;
  
  // Concatenate and print the String variables on a new line
  // The 's' variable above should be printed first.
  cout << s << inputString << endl;

  return 0;
}
