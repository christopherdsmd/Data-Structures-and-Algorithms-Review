#include"bst.h"
#include"tnode.h"
#include<iostream>
using namespace std;

#ifndef BST_CPP
#define BST_CPP

template <class T>
BST<T>::BST()  //constructor set empty tree 
{
    Root = nullptr;
}

template <class T>
BST<T>::~BST() //deconstructor, delete all nodes, clear memory
{
clear_Tree(Root);
}

template <class T>
TNode<T>* BST<T>::createNode(T val)
{
    TNode<T> *newNode = new TNode<T>;     //create new node
    newNode->data = val; //insert the user give parameter as newnode data

    //set rest tot null
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;

    cout << "New Node has been created " << endl;
    return newNode;
}

template <class T>
TNode<T>* BST<T>::insertNode(TNode<T> *currentNode, T val) 
{
    //if tree is empty insert newnode as new root value
    if(!currentNode) 
    {
        cout << "inserting node "  << val << " into tree" << endl;
        return createNode(val);  //create new node 
    } 
        
    //if node is less than root put node as node->left
    if(currentNode->data > val) 
    {
        currentNode->left = insertNode(currentNode->left, val);            //recursive, set Root->left as TNode * param value
    }
 
    //if node is greater than root put node as node->right
    else if (currentNode->data < val)
    {
        currentNode->right = insertNode(currentNode->right, val);       //recursive, set Root->right as TNode * param value
    }

    else if (currentNode->data == val) //duplication check , does not insert into tree
    {
        cout << "Duplicate Node, cannot insert" << endl;
    }

    return currentNode;
}

template <class T>
TNode<T>* BST<T>::searchNode(TNode<T>* current, T search) {    
    if (current == nullptr) { // if current is null    
        cout << "Node not found" << endl;
        return nullptr;
    }

    if (current->data == search) { // if found
        cout << "Node " << current->data << " found" << endl;       
        return current;
    }
    
    if (current->data < search) { // recursion 
        return searchNode(current->right, search);
    } else {
        return searchNode(current->left, search);
    }
}

template <class T>
TNode<T>* BST<T>::deleteNode(TNode<T> *current, T data)
{
if(current == nullptr) //if node is null return 
{
    cout << "Node " << data << " not found in tree" << endl;
    return nullptr;
}

//seatch for value to be deleted
if(current->data > data) 
{
    current->left = deleteNode(current->left, data);
} else if (current->data < data) 
{
    current->right = deleteNode(current->right, data);
} else  {

    //if node has 1 or 0 child

    if(current->left == nullptr) 
    {
        TNode<T> *temp = current->right;
        delete current;
        cout << "Node " << data << " deleted" << endl;
        return temp;
    } else if (current->right == nullptr) 
    {
        TNode<T>* temp = current->left;
        delete current;
        cout << "Node " << data << " deleted" << endl;
        return temp;
    }

    //if node has 2 children
    TNode<T> *successor = Tree_Successor(current);    //find successor

    current->data = successor->data;
    current->right = deleteNode(current->right, successor->data);
}
    return current;
}

template <class T>
void BST<T>::inorder(TNode<T> *current)
{
    if (current != nullptr) 
    {
        inorder(current->left);     //left
        cout << current->data << " ";   //print
        inorder(current->right);        //right
    } 
}

template <class T>
void BST<T>::preorder(TNode<T> *current)
{
    if (current != nullptr) 
    {
        cout << current->data << " ";  // print 
        preorder(current->left);       // left
        preorder(current->right);      // right
    }
}

template <class T>
void BST<T>::postorder(TNode<T> *current)
{    
    if (current != nullptr) 
    {
        postorder(current->left);    // left
        postorder(current->right);   // right
        cout << current->data << " "; // print
    }

}

// TNode BST::*Tree_Predecessor(TNode *)
// {
// }
template <class T>
TNode<T>* BST<T>::Tree_Successor(TNode<T> *current)      //finds successor (used for delete when 2 childs )
{
if(current->right != nullptr)           //find min value greater than currnt val 
{
    return Tmin(current->right);     //call util function
}
else 
{
    TNode<T> *temp;
    temp = current->parent;

    while(temp != nullptr && current == temp->right) 
    {
        current = temp;
        temp = temp->parent;
    }
    return temp;
}

}

template <class T>
void BST<T>::clear_Tree(TNode<T>* curr)
{
if (curr != nullptr)            //traverse the tree 
{                   
    clear_Tree(curr->left);
    clear_Tree(curr->right);

    delete curr;        //delete the node 
}
}


template <class T>
void BST<T>::bst_Insert()      //public function call gets user , updates root
{
    T data;       
    cout << "Enter data for node" << endl;

    while(!(cin>>data)) 
    {
        cin.clear();
        cin.ignore();
    }
    Root = insertNode(Root, data);
}

//public function call gets user 
template <class T>
void BST<T>::bst_Search()
{
    T data;
    cout << "Enter node id to search" << endl;

    while(!(cin>>datg++ -o tree instantiation.cpp
a)) 
    {
        cin.clear();
        cin.ignore();
    }
     searchNode(Root, data);
}

template <class T>
void BST<T>::bst_Delete() //public function call gets user , updates root
{
    T data;
    inorder(Root);  //print tree for user 
    cout << endl;
    cout << "Enter node id to be deleted" << endl;

    while(!(cin>>data)) 
    {
        cin.clear();
        cin.ignore();
    }

   TNode<T>* curr = Root;
    Root = deleteNode(Root, data);
}
template <class T>
void BST<T>::Inorder_walk()    //print inorder walk 
{
cout << "Inorder "<< endl;
inorder(Root);
cout << endl;
}

template <class T>
void BST<T>::Preorder_walk()   //print preorder walk
{
cout << "Preorder "<< endl;
preorder(Root);
cout << endl;
}

template <class T>
void BST<T>::Postorder_walk()  //print post order walk
{   
cout << "Postorder "<< endl;
postorder(Root);
cout << endl;
}

template <class T>
TNode<T>* BST<T>::Tmin(TNode<T> *current)        //find min by checking left side of tree 
{
TNode<T> *temp = current;
while(temp->left != nullptr) 
{
    temp = temp->left;
}  
return temp;
}

template <class T>
TNode<T>* BST<T>::Tmax(TNode<T> *current)  //find min by checking right side of treew
{
TNode<T> *temp = current;
while(temp->right != nullptr) 
{
    temp = temp->right;
}  
return temp;
}

#endif