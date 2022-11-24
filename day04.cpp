// Day 04: Class vs. Instance

/*
Write a Person class with an instance variable, age, and a constructor that
takes an integer, initialAge, as a parameter. The constructor must assign
initialAge to age after confirming the argument passed as initialAge is not
negative; if a negative argument is passed as initialAge, the constructor
should set age to 0 and print Age is not valid, setting age to 0.. In
addition, you must write the following instance methods:

  yearPasses() should increase the age instance variable by 1.
  amIOld() should perform the following conditional actions:
    If age < 13, print You are young..
    If age >= 13 and age < 18, print You are a teenager..
    Otherwise, print You are old..
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
  public:
    int age;
    Person(int initialAge) {
      this->age = initialAge >= 0 ?
        initialAge : (cout << "Age is not valid, setting age to 0." << endl, 0);
    }

  public: void yearPasses(void) {
    this->age += 1;
  }

  public: void amlOld(void) {
    if (age < 13) {
      cout << "You are young." << endl;
    } else if (age < 18) {
      cout << "You are a teenager." << endl;
    } else {
      cout << "You are old." << endl;
    } 
  }
};


int main(void) {

  int T;
  cin >> T;

  int age;
  for (int i = 0; i < T; i++) {
    cin >> age;
    Person person(age);
    person.amlOld();

    person.yearPasses();
    person.yearPasses();
    person.yearPasses();
    person.amlOld();
    if (i < T - 1) {
      cout << endl;
    }
  }

  return 0;
}
