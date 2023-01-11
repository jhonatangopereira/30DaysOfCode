// Day 14: Scope

/*
Complete the Difference class by writing the following:

  - A class constructor that takes an array of integers as a parameter and saves it
  to the __elements instance variable.
  - A computeDifference method that finds the maximum absolute difference between any 2
  numbers in __elements and stores it in the maximumDifference instance variable.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Difference {
  private:
    vector<int> elements;

  public:
    int maximumDifference;

    Difference(vector<int> elements) {
      this->elements = elements;
    }

    void computeDifference(void) {
      int minimumElement = *min_element(this->elements.begin(), this->elements.end());
      int maximumElement = *max_element(this->elements.begin(), this->elements.end());

      this->maximumDifference = maximumElement - minimumElement;
    }
};

int main(void) {
  int N;
  cin >> N;
  
  vector<int> a;  
  for (int i = 0; i < N; i++) {
    int e;
    cin >> e;
    
    a.push_back(e);
  }
  
  Difference d(a);
  
  d.computeDifference();
  
  cout << d.maximumDifference;
  
  return 0;
}
