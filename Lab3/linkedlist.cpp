//Programmer: Christopher Desmond
//Date: 09/19/23
#include<iostream>
#include<iomanip>
#include "link.h"   //include header file 

using namespace std;
int main ()
{
//head points to linked list
Node *head = nullptr;


int userVar = -1;
while(userVar !=  5) 
{
int DelID = -1; 
int searchID = -1;

cout << "Linked List Program: " << endl;
cout << "1: Insert a Node " << endl;
cout << "2: Delete a Node " << endl;
cout << "3: Print list " << endl;
cout << "4: Search a node " << endl;
cout << "5: Exit program " << endl << endl;

cin >> userVar;

//error validation for non int entry 
if (cin.fail())
{
         cout << "Error - Please enter a valid number" << endl << endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

switch(userVar) {
//function 1 - insert 
case 1: 
head = insertNode(head);
break;

//function 2 - delete

case 2:
 if (head == nullptr)  //if head is empty dont allow
{
    cout << "Error  - list is empty" << endl << endl; 
} else 
{
    //print first
    printList(head);
    cout << "Enter Student ID number to be deleted " << endl;
    cin >> DelID;
    head = deleteNode(head, DelID);
}

break;

//funciton 3 - print
case 3:
printList(head);
break;

//function 4 - search 
case 4:


cout << "Enter a student ID # to search in the list" << endl;
cin >> searchID;
searchNode(head, searchID);
break;

//5 end of loop -  exit program
case 5:
cout << endl << "Exiting Program, Thank you for using the linked List program" << endl << endl;
break;


//error validation
default:
cout << "Invalid input - Please enter menu selection 1 - 5 " << endl;
break;
        }
    }

return 0;
}
