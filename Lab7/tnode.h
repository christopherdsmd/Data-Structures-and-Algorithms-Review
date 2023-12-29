#ifndef TNODE_H
#define TNODE_H

class TNode 
{
	private:
		TNode *parent;		//pointer parent node 
		TNode *left; 		//pointer to left child 
		TNode *right; 		//pointer to right child 

		int data;				//data stored inside each node

	public:
		TNode();				//constructor set values of TNode
		void printNode();		//print node information

	friend class BST;
};

#endif
