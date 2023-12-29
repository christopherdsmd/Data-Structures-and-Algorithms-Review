//Lab 7.5 - binary search tree with template
//programmer: Christopher Desmond
#include"bst.h"
#include"tnode.h"
#include"students.h"
#include<iostream>
#include<iomanip>
using namespace std; 

int main () 
{
BST<int> Int_BST;  //binary search tree object type int
BST<Students*> Stu_BST;      //student type

//menu select var
int chooseDataType = -1;
int userInput = -1; 
char subcase3 = -1;  //case 3 sub variables
char subcase3_2 = -1;  //case 3 sub variables
int TreeType = -1;

    while (chooseDataType != -1)   //select queue node datatypes
    {
        cout << "Please select the datatype for the queue" << endl;
        cout << "1: Integer" << endl;
        cout << "2: Student - object" << endl;

        while(!(cin >> chooseDataType))    //error check
        {
        cout << "Error enter a valid selection" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        
        if (chooseDataType == 1)   
        {
            cout << "You selected Integer queue" << endl;
            TreeType = 1;  //1 = int
            chooseDataType = -1;
        }
        else if (chooseDataType == 2)
        {
            cout << "You selected Student queue" << endl;
            TreeType = 2;  //2 = students
            chooseDataType = -1;
        }
    }


switch(TreeType) {
case 1: //int
while(userInput != 5) { //binary search tree menu
userInput = -1;
cout << "Binary Search Tree with <template>" << endl;
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
    Int_BST.bst_Insert();
    break; 

    case 2: //delete 
    Int_BST.bst_Delete();
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
                Int_BST.Inorder_walk();
            break;

            case 'b':   //postorder
                Int_BST.Preorder_walk();
            break;

            case 'c':   //preorder
                Int_BST.Postorder_walk();
            break;
        }
    break; 

    case 4:
    Int_BST.bst_Search();
    break;

    case 5: //exit prog
    cout << "Exiting Program" << endl; 
    Int_BST.~BST();        //call deconstructor clear tree 
    exit(0);
    break;

    default:
    cout << "Invalid selection - please enter a menu option 1 - 4" << endl; 
    break;
    }
    }
    break;



///////////////////////////////////////////////////////////
    case 2: //student type
    while(userInput != 5) { //binary search tree menu
userInput = -1;
cout << "Binary Search Tree with <template>" << endl;
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
    Stu_BST.bst_Insert();
    break; 

    case 2: //delete 
    Stu_BST.bst_Delete();
    break;

    case 3: //print options 
        cout << "select print type" << endl;
        cout << "a: Inorder" << endl;
        cout << "b: Preorder" << endl;
        cout << "c: Postorder" << endl;
    
        while(!(cin >> subcase3_2)) 
        {
            cin.clear();
            cin.ignore();
        }

        switch(subcase3_2) 
        {
            case 'a':   //inorder
                Stu_BST.Inorder_walk();
            break;

            case 'b':   //postorder
                Stu_BST.Preorder_walk();
            break;

            case 'c':   //preorder
                Stu_BST.Postorder_walk();
            break;
        }
    break; 

    case 4:
    Stu_BST.bst_Search();
    break;

    case 5: //exit prog
    cout << "Exiting Program" << endl; 
    Stu_BST.~BST();        //call deconstructor clear tree 
    exit(0);
    break;

    default:
    cout << "Invalid selection - please enter a menu option 1 - 4" << endl; 
    break;
    }
    }
    break;
}


    return 0;
}
