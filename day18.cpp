// Day 18: Queues and Stacks

/*
Write the following declarations and implementations:

Two instance variables: one for your stack, and one for your queue.
A void pushCharacter(char ch) method that pushes a character onto a stack.
A void enqueueCharacter(char ch) method that enqueues a character in the  instance variable.
A char popCharacter() method that pops and returns the character at the top of the stack instance variable.
A char dequeueCharacter() method that dequeues and returns the first character in the queue instance variable.
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;


class Solution {
  private:
    std::stack<char> stack;
    std::queue<char> queue;
  public:
    void pushCharacter(char character) {
      this->stack.push(character);
    }

    char popCharacter(void) {
      char character = this->stack.top();
      this->stack.pop();

      return character;
    }

    void enqueueCharacter(char character) {
      this->queue.push(character);
    }

    char dequeueCharacter(void) {
      char character = this->queue.front();
      this->queue.pop();

      return character;
    }
};

int main(void) {
  // read the string s.
  string s;
  getline(cin, s);
  
  // create the Solution class object p.
  Solution obj;
  
  // push/enqueue all the characters of string s to stack.
  for (int i = 0; i < s.length(); i++) {
    obj.pushCharacter(s[i]);
    obj.enqueueCharacter(s[i]);
  }
  
  bool isPalindrome = true;
  
  // pop the top character from stack.
  // dequeue the first character from queue.
  // compare both the characters.
  for (int i = 0; i < s.length() / 2; i++) {
    if (obj.popCharacter() != obj.dequeueCharacter()) {
      isPalindrome = false;
      
      break;
    }
  }
  
  // finally print whether string s is palindrome or not.
  if (isPalindrome) {
    cout << "The word, " << s << ", is a palindrome.";
  } else {
    cout << "The word, " << s << ", is not a palindrome.";
  }
  
  return 0;
}
