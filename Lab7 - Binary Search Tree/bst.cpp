#include"bst.h"
#include"tnode.h"
#include<iostream>
using namespace std;

BST::BST()  //constructor set empty tree 
{
    Root = nullptr;
}

BST::~BST() //deconstructor, delete all nodes, clear memory
{
clear_Tree(Root);  //clean tree 
}

TNode* BST::createNode(int val)
{
    TNode *newNode = new TNode;     //create new node
    newNode->data = val; //insert the user give parameter as newnode data

    //set ptrs  to null
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;

    cout << "New Node has been created " << endl;
    return newNode;
}

TNode* BST::insertNode(TNode *currentNode, int val) 
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

TNode* BST::searchNode(TNode* current, int search) {    
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


TNode* BST::deleteNode(TNode *current, int data)
{
if(current == nullptr) //if node is null return 
{
    cout << "Node " << data << " not found in tree" << endl;    //cannot delete 
    return nullptr;
}

//case if node ->left or ->right is empty (no left or right or 1 left/right)
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
        TNode *temp = current->right;
        delete current;
        cout << "Node " << data << " deleted" << endl;
        return temp;
    } else if (current->right == nullptr) 
    {
        TNode* temp = current->left;
        delete current;
        cout << "Node " << data << " deleted" << endl;
        return temp;
    }

    //if node has 2 children
    TNode *successor = Tree_Successor(current);    //find successor util 

    current->data = successor->data;
    current->right = deleteNode(current->right, successor->data);
}
    return current;
}

void BST::inorder(TNode *current)  //print until null
{
    if (current != nullptr) 
    {
        inorder(current->left);     //left
        cout << current->data << " ";   //print
        inorder(current->right);        //right
    } 
}

void BST::preorder(TNode *current)    //print until null 
{
    if (current != nullptr) 
    {
        cout << current->data << " ";  // print 
        preorder(current->left);       // left
        preorder(current->right);      // right
    }
}


void BST::postorder(TNode *current)   //post order print until null 
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

TNode* BST::Tree_Successor(TNode *current)      //finds successor (used for delete when 2 childs )
{
if(current->right != nullptr)           //find min value greater than currnt val 
{
    return Tmin(current->right);     //call util function
}
else 
{
    TNode *temp;
    temp = current->parent;

    while(temp != nullptr && current == temp->right)     //return the successor, smallest node that is > current 
    {
        current = temp;
        temp = temp->parent;
    }
    return temp;
}

}

void BST::clear_Tree(TNode* curr)    //clean entire tree, delete all nodes until current node is null 
{
if (curr != nullptr)            //traverse the tree 
{                   
    clear_Tree(curr->left);
    clear_Tree(curr->right);

    delete curr;        //delete the node 
}
}


void BST::bst_Insert()      //public function call gets user , updates root
{
    int data;       //user input for new node insert (int )
    cout << "Enter int for node" << endl;

    while(!(cin>>data)) 	//error check 
    {
        cin.clear();
        cin.ignore();
    }
    Root = insertNode(Root, data); 		//insert into tree, update root / tree with new node inserted 
}
//public function call gets user 
void BST::bst_Search()
{
    int data;
    cout << "Enter node id to search" << endl;

    while(!(cin>>data)) 
    {
        cin.clear();
        cin.ignore();
    }
     searchNode(Root, data);		//void does not need to update root 
}


void BST::bst_Delete() //public function call gets user , updates root
{
    int data;
    inorder(Root);  //print tree for user 
    cout << endl;
    cout << "Enter node id to be deleted" << endl;

    while(!(cin>>data)) 
    {
        cin.clear();
        cin.ignore();
    }

   TNode* curr = Root;			
    Root = deleteNode(Root, data);		//call delete, update root 
}
//public functions call util 
void BST::Inorder_walk()    //print inorder walk 
{
cout << "Inorder "<< endl;
inorder(Root);
cout << endl;
}

void BST::Preorder_walk()   //print preorder walk
{
cout << "Preorder "<< endl;
preorder(Root);
cout << endl;
}

void BST::Postorder_walk()  //print post order walk
{   
cout << "Postorder "<< endl;
postorder(Root);
cout << endl;
}

TNode* BST::Tmin(TNode *current)        //find min by checking left side of tree 
{
TNode *temp = current;
while(temp->left != nullptr) //go left until null
{
    temp = temp->left;
}  
return temp;
}

TNode* BST::Tmax(TNode *current)  //find min by checking right side of treew
{
TNode *temp = current;
while(temp->right != nullptr) //go right until null 
{
    temp = temp->right;
}  
return temp;
}
