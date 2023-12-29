#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
	private:
		Node *List;	//creates Node object pointing to list inside constructor
		//utility functions 
		Node *createNode();	
		Node *searchLocation(int studentID);
	public:
		LinkedList();
		~LinkedList();
		void insertNode();
		void deleteNode(int DelID);
		void printList();
		void searchNode(int searchID);
};

#endif
