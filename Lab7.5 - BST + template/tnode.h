#ifndef TNODE_H
#define TNODE_H

template <class T>
class TNode 
{
	public:
		TNode<T> *parent;		//pointer parent node 
		TNode<T> *left; 		//pointer to left child 
		TNode<T> *right; 		//pointer to right child 

		T data;				//data stored inside each node


		TNode();				//constructor set values of TNode
		void printNode();		//print node informatio
		
		template <class T>
		friend class BST<T>;
};

#endif
