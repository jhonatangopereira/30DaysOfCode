// Day 22: Binary Search Trees

/*
The height of a binary search tree is the number of edges between the tree's root and its
furthest leaf. You are given a pointer, root, pointing to the root of a binary search tree.
Complete the getHeight function provided in your editor so that it returns the height of
the binary search tree.
*/

#include <iostream>
#include <cstddef>

using namespace std;	


class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
      this->data = d;
      this->left = NULL;
      this->right = NULL;
    }
};

class Solution {
  public:
    Node* insert(Node* root, int data) {
      if (root == NULL) {
        return new Node(data);
      }
      else {
        Node* cur;
        if (data <= root->data) {
          cur = insert(root->left, data);
          root->left = cur;
        }
        else {
          cur = insert(root->right, data);
          root->right = cur;
        }

        return root;
      }
    }

  int getHeight(Node* root) {
    if (root == NULL) {
      return -1;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
  }
};

int main(void) {
  Solution myTree;
  Node* root = NULL;
  int t;
  int data;

  cin >> t;

  while (t-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }

  int height = myTree.getHeight(root);
  cout << height;

  return 0;
}
