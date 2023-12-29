#include <iostream>
using namespace std;

#ifndef GROCERY_H
#define GROCERY_H

struct Node {
  int itemNum;
  char itemName[40];
  double unit; // for pound or number of unit
  double unitprice;
  double tax;
  double subtotal;

  Node *next; // pointer to next Node in list
};
// function prototypes
Node *insertNode(Node *head, Node *newNode);
Node *deleteNode(Node *head, int delID);
void printList(Node *head);
void deleteList(Node *head);

#endif
