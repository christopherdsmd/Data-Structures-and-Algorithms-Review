//Lab 7 - binary search tree 
//programmer: Christopher Desmond
#include "bst.h"
#include "tnode.h"
#include<iostream>
#include<iomanip>
using namespace std; 

int main () 
{
BST BST;  //binary search tree object

//menu select var
int userInput = -1; 
char subcase3 = -1;  //case 3 sub variables

while(userInput != 5) { //binary search tree menu
userInput = -1;
cout << "Binary Search Tree" << endl;
cout << "1: Insert a element into tree" << endl;
cout << "2: Delete element from tree" << endl;
cout << "3: Print tree" << endl;
cout << "4: Search a node in tree" << endl;
cout << "5: Exit program" << endl;

while(!(cin >> userInput))  //user input for meny
{
    cin.clear();
    cin.ignore();
}

switch(userInput)
    {
    case 1:  //insert 
    BST.bst_Insert();
    break; 

    case 2: //delete 
    BST.bst_Delete();
    break;

    case 3: //print options 
        cout << "select print type" << endl;
        cout << "a: Inorder" << endl;
        cout << "b: Preorder" << endl;
        cout << "c: Postorder" << endl;
    
        while(!(cin >> subcase3)) 
        {
            cin.clear();
            cin.ignore();
        }

        switch(subcase3) 
        {
            case 'a':   //inorder
                BST.Inorder_walk();
            break;

            case 'b':   //postorder
                BST.Preorder_walk();
            break;

            case 'c':   //preorder
                BST.Postorder_walk();
            break;
        }
    break; 

    case 4:
    BST.bst_Search();
    break;

    case 5: //exit prog
    cout << "Exiting Program" << endl; 
    BST.~BST();        //call deconstructor clear tree 
    exit(0);
    break;

    default:
    cout << "Invalid selection - please enter a menu option 1 - 4" << endl; 
    break;
    }
}

    return 0;
}
