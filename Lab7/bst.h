//binary search tree lab
//programmer: Christopher Desmond
#include <iostream>
#include "tnode.h"
using namespace std;

#ifndef BST_H
#define BST_H

class BST 
{
    private:
        TNode *Root;                                //pointer to root node 
        TNode* insertNode(TNode *, int);                  //insert a new node to tree

        //util functions 
        TNode* createNode(int);                        //create a new node
        TNode* searchNode(TNode* current, int searchData);           	    //search for a node 
        TNode* deleteNode(TNode *, int deleteData);                       //delete a node 
        void inorder(TNode *);                      //print inorder walk
        void preorder(TNode *);                     //print preorder walk
        void postorder(TNode *);
        TNode* Tree_Predecessor(TNode *);
        TNode* Tree_Successor(TNode *);
        void clear_Tree(TNode* curr);
        TNode* Tmin(TNode *);
        TNode* Tmax(TNode *);
                
   public: 
        BST();                                      //constructor set variables
        ~BST();                                     //delete all nodes in tree, clear memory 
        void bst_Insert();                          //insert a new node into bst
        void bst_Search();                          //search a node inside bst
        void bst_Delete();                          //delete a node from bst
        void Inorder_walk();
        void Preorder_walk();
        void Postorder_walk();
};

#endif
