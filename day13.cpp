// Day 13: Abstract Classes

/*
Given a Book class and a Solution class, write a MyBook class that does the following:

  - Inherits from Book
  - Has a parameterized constructor taking these 3 parameters:
    1. string title 
    2. string author 
    3. int price 
  - Implements the Book class' abstract display() method so it prints these 3 lines:
    1. "Title:", a space, and then the current instance's title.
    2. "Author:", a space, and then the current instance's author.
    3. "Price: ", a space, and then the current instance's price.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Book {
  protected:
    string title;
    string author;
  
  public:
    Book(string t,string a) {
      title = t;
      author = a;
    }

    virtual void display() = 0;
};

class MyBook : Book {
  private:
    int price;
  public:
    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    MyBook(string title, string author, int price) : Book(title, author) {
      this->price = price;
    }
  
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    virtual void display(void) {
      cout << "Title: " << this->title << endl;
      cout << "Author: " << this->author << endl;
      cout << "Price: " << this->price << endl;
    }
};


int main(void) {
  string title, author;
  int price;

  getline(cin, title);
  getline(cin, author);
  cin >> price;

  MyBook novel(title, author, price);
  novel.display();

  return 0;
}
