// Day 27: Testing

/*
A coworker has prepared functions that will perform the tests and validate return values.
Finish the implementation of 3 classes to provide data and expected results for the tests.

Complete the following methods.

In the class TestDataEmptyArray:
  - get_array() returns an empty array
In the class TestDataUniqueValues:
  - get_array() returns an array of size at least 2 with all unique elements
  - get_expected_result() returns the expected minimum value index for this array
In the class TestDataExactlyTwoDifferentMinimums:
  - get_array() returns an array where the minimum value occurs at exactly 2 indices
  - get_expected_result() returns the expected index
*/

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;


int minimum_index(vector<int> seq) {
  if (seq.empty()) {
    throw invalid_argument("Cannot get the minimum value index from an empty sequence");
  }
  
  int min_idx = 0;
  for (int i = 1; i < seq.size(); ++i) {
    if (seq[i] < seq[min_idx]) {
      min_idx = i;
    }
  }

  return min_idx;
}

class TestDataEmptyArray {
  public:
  static vector<int> get_array(void) {
    vector<int> vector;
    return vector;
  }
};

class TestDataUniqueValues {
  public:
  static vector<int> get_array(void) {
    vector<int> vector = {1, 2, 3, 4, 5};
    return vector;
  }

  static int get_expected_result(void) {
    return 0;
  }
};

class TestDataExactlyTwoDifferentMinimums {
  public:
  static vector<int> get_array(void) {
    vector<int> vector = {1, 2, 4, 3, 1};
    return vector;
  }

  static int get_expected_result(void) {
    return 0;
  }
};

void TestWithEmptyArray(void) {
  try {
    auto seq = TestDataEmptyArray::get_array();
    auto result = minimum_index(seq);
  } catch (invalid_argument& e) {
    return;
  }

  assert(false);
}

void TestWithUniqueValues() {
  auto seq = TestDataUniqueValues::get_array();
  assert(seq.size() >= 2);

  assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

  auto expected_result = TestDataUniqueValues::get_expected_result();
  auto result = minimum_index(seq);
  assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
  auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
  assert(seq.size() >= 2);

  auto tmp = seq;
  sort(tmp.begin(), tmp.end());
  assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

  auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
  auto result = minimum_index(seq);
  assert(result == expected_result);
}

int main(void) {
  TestWithEmptyArray();
  TestWithUniqueValues();
  TestWithExactlyTwoDifferentMinimums();
  
  cout << "OK" << endl;
  
  return 0;
}
