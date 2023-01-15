// Day 23: BST Level-Order Traversal

/*
A level-order traversal, also known as a breadth-first search, visits each level of
a tree's nodes from left to right, top to bottom. You are given a pointer, root, pointing
to the root of a binary search tree. Complete the levelOrder function provided in your
editor so that it prints the level-order traversal of the binary search tree.
*/

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	


class Node {
  public:
    int data;
    Node *left, *right;
    Node(int d) {
      data = d;
      left = right = NULL;
    }
};

class Solution {
  public:
    Node* insert(Node* root, int data) {
      if (root == NULL) {
        return new Node(data);
      } else {
        Node* cur;
        if (data <= root->data) {
          cur = insert(root->left, data);
          root->left = cur;
        } else {
          cur = insert(root->right, data);
          root->right = cur;
        }           
        return root;
      }
    }

    void levelOrder(Node* root) {
      queue<Node*> queue;
      if (root != NULL) {
        queue.push(root);
        while (queue.empty() != true) {
          Node* node = queue.front();
          cout << queue.front()->data << " ";
          queue.pop();

          if (node->left != NULL) {
            queue.push(node->left);
          }
          if (node->right != NULL) {
            queue.push(node->right);
          }
        }
      }
    }
};

int main(void) {
  Solution myTree;
  
  Node* root = NULL;
  
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.levelOrder(root);
  
  return 0;
}