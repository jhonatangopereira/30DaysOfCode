// Day 24: More Linked Lists

/*
Complete removeDuplicates so that it deletes any duplicate nodes from the list
and returns the head of the updated list.
*/

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Node {
  public:
    int data;
    Node *next;
    Node(int d)
    {
      data = d;
      next = NULL;
    }
};

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
      if (head == NULL) {
        return head;
      }
      vector<int> data;
      Node *start = head;
      data.push_back(head->data);

      while (start->next != NULL) {
        if (find(data.begin(), data.end(), start->next->data) != data.end()) {
          start->next = start->next->next;
        } else {
          start = start->next;
          data.push_back(start->data);
        }
      }

      return head;
    }

    Node *insert(Node *head, int data) {
      Node *p = new Node(data);
      if (head == NULL) {
        head = p;
      } else if (head->next == NULL) {
        head->next = p;
      } else {
        Node *start = head;
        while (start->next != NULL)
        {
          start = start->next;
        }
        start->next = p;
      }
      return head;
    }

    void display(Node *head) {
      Node *start = head;
      while (start)
      {
        cout << start->data << " ";
        start = start->next;
      }
    }
};

int main(void) {
  Node *head = NULL;
  Solution mylist;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    head = mylist.insert(head, data);
  }
  head = mylist.removeDuplicates(head);

  mylist.display(head);
}
