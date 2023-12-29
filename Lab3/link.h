//Programmer: Christopher Desmond
//Date: 09/19/23
#include<iostream>
using namespace std;

#ifndef LINK_H	// only include code inside this header file 
#define LINK_H

//Node Struct 
struct Node 
{
	char lastName[20];	//student last name
	char firstName[20];	//student first name
	int idNumber;	//student Id
	
	Node *next;	//pointer to next Node
};

//function protoypes 
Node *createNode();
Node *insertNode(Node *);
Node *searchNode(Node*, int);
Node *deleteNode(Node* , int);
void printList(Node*);

#endif
