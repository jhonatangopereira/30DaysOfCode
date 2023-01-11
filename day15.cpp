// Day 15: Linked List

/*
Complete the insert function in your editor so that it creates a new Node
(pass data as the Node constructor argument) and inserts it at the tail of the
linked list referenced by the head parameter. Once the new node is added, return
the reference to the head node.
*/

#include <iostream>
#include <cstddef>

using namespace std;	


class Node {
  public:
    int data;
    Node *next;

    Node(int d) {
      this->data = d;
      this->next = NULL;
    }
};

class Solution {
  public:
    Node* insert(Node *head, int data) {
      if (head == NULL) {
        head = new Node(data);
      } else {
        Node *start = head;
        while (start) {
          if (start->next == NULL) {
            Node *node = new Node(data);
            start->next = node;

            break;
          }
          start = start->next;
        }
      }

      return head;
    }

    void display(Node *head) {
      Node *start = head;
      while (start) {
        cout << start->data << " ";
        start = start->next;
      }
    }
};

int main(void) {
	Node* head = NULL;
  Solution mylist;
  
  int T, data;
  cin >> T;

  while (T --> 0) {
    cin >> data;
    head = mylist.insert(head, data);
  }

	mylist.display(head);

  return 0;
}
