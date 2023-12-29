//binary search tree lab
//programmer: Christopher Desmond
#include <iostream>
#include "tnode.h"
#include "bst.cpp"
using namespace std;

#ifndef BST_H
#define BST_H

template <class T>
class BST
{
    private:
        TNode<T>*Root;                                //pointer to root node 
        TNode<T>*insertNode(TNode<T> *, T);                  //insert a new node to tree

        //util functions 
        TNode<T>* createNode(T);                        //create a new node
        TNode<T>* searchNode(TNode<T>* current, T searchData);           	    //search for a node 
        TNode<T>* deleteNode(TNode<T>*, T deleteData);                       //delete a node 
        void inorder(TNode<T> *);                      //print inorder walk
        void preorder(TNode<T> *);                     //print preorder walk
        void postorder(TNode<T> *);
        TNode<T>* Tree_Predecessor(TNode<T> *);
        TNode<T>* Tree_Successor(TNode<T> *);
        void clear_Tree(TNode<T>* curr);
        TNode<T>* Tmin(TNode<T>*);
        TNode<T>* Tmax(TNode<T>*);

        
   public: 
        BST();                                      //constructor set variables
        ~BST();                                     //delete all nodes in tree, clear memory 
        void bst_Insert();                          //insert a new node into bst
        void bst_Search();                          //search a node inside bst
        void bst_Delete();                          //delete a node from bst
        void Inorder_walk();
        void Preorder_walk();
        void Postorder_walk();

        friend class TNode<T>;
};

#endif
