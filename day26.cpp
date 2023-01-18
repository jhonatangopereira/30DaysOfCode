// Day 26: Nested Logic

/*
Your local library needs your help! Given the expected and actual return dates for a library book,
create a program that calculates the fine (if any). The fee structure is as follows:
  1. If the book is returned on or before the expected return date, no fine will be charged.
  2. If the book is returned after the expected return day but still within the same calendar month and year as the expected return date.
  3. If the book is returned after the expected return month but still within the same calendar year as the expected return date.
  3. If the book is returned after the calendar year in which it was expected, there is a fixed fine.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int calculateFine(int returnedDay, int returnedMonth, int returnedYear, int dueDay, int dueMonth, int dueYear);

int main(void) {
  int returnedDay, returnedMonth, returnedYear = 0;
  cin >> returnedDay >> returnedMonth >> returnedYear;
  
  int dueDay, dueMonth, dueYear = 0;
  cin >> dueDay >> dueMonth >> dueYear;

  cout << calculateFine(returnedDay, returnedMonth, returnedYear, dueDay, dueMonth, dueYear) << endl;

  return 0;
}

int calculateFine(int returnedDay, int returnedMonth, int returnedYear, int dueDay, int dueMonth, int dueYear) {
  if (returnedYear > dueYear) {
    return 10000;
  }
  if (returnedMonth > dueMonth and returnedYear == dueYear) {
    return 500 * (returnedMonth - dueMonth);
  } 
  if (returnedDay > dueDay and returnedMonth == dueMonth and returnedYear == dueYear) {
    return 15 * (returnedDay - dueDay);
  }

  return 0;
}
