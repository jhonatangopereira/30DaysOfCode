// Day 21: Generics

/*
Write a single generic function named printArray; this function must take an array of
generic elements as a parameter. The locked Solution class in your editor tests your function.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
*    Name: printArray
*    Print each element of the generic vector on a new line. Do not return anything.
*    @param A generic vector
**/
template <typename T>
void printArray(vector<T> A);

int main(void) {
	int n;
	
	cin >> n;
	vector<int> int_vector(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		int_vector[i] = value;
	}
	
	cin >> n;
	vector<string> string_vector(n);
	for (int i = 0; i < n; i++) {
		string value;
		cin >> value;
		string_vector[i] = value;
	}

	printArray<int>(int_vector);
	printArray<string>(string_vector);

	return 0;
}

template <typename T>
void printArray(vector<T> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " " << endl;
  }
}
