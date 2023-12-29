//Programmer: Christopher Desmond
//Date: 09/19/23

#include <iostream>
#include<iomanip>
using namespace std;

//include header file
#include "link.h"
using namespace std;


Node *createNode()
{
    //create new node
    Node *newNode = new Node; 
   
    //save information 
    cout << "Enter Student last name"<< endl;
    cin >> newNode->lastName;

    cout << "Enter Student first name" << endl;
    cin >> newNode->firstName;

    cout << "Enter Student ID number" << endl;
    //error check make sure int is input
    while(!(cin >> newNode->idNumber)) 
    {
        cout << "Error: must enter a number" << endl;
        cin.clear();
        cin.ignore();
    }
     
     newNode->next = NULL;

    cout << "New Node has been created" << endl << endl; 
    return newNode;
}

Node *insertNode(Node *head)
{
//create node and save information 
Node * newNode = createNode();
Node *current = head; 

while(current != nullptr)   //prevent duplicate ID nums 
{ if(current->idNumber == newNode->idNumber) 
{
    cout << "Error: Duplicate student ID" << endl << endl;

    cout << current->lastName; 
    cout << current->firstName;
    cout << current->idNumber << endl;

    return head; 
}
current = current->next;
}

//WORKS
//case 1 - empty list 
if(head == nullptr) {       //if the head is null, set the head to a new node
head = newNode;
return head;
}

//case 2 insert smallest key node
if(newNode->idNumber < head->idNumber)  //if the newly created node is smaller than the id of the head swap
{
    newNode->next = head;
    head = newNode;
   return head;
}
Node *current = head;


//case 3 insert largest key node
while(current->next != nullptr && newNode->idNumber > current->next->idNumber)
{
    current = current->next;
}

newNode->next = current->next;
current->next = newNode;

cout << "Node has been added to the list" << endl << endl;
return head;
}



Node *searchNode(Node *head, int searchID)
{
Node *current = head;
while(current != nullptr) { //itterate entire list
if(current->idNumber == searchID)
{
    cout << endl << endl << "Student ID found in list:" << endl;
    
    cout << current->firstName << " ";
    cout << current->lastName << " ";
    cout << "Student ID #" << current->idNumber << " " << endl << endl;

    return current;
    }
    current = current->next;
    }

        cout << endl << endl << "ID Number not found in list - Please try another number" << endl << endl;
    return nullptr;
}


Node *deleteNode(Node *head, int delID)
{
    // If the list is empty
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return head;
    }

    // Deleting the head node
    if (head->idNumber == delID)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from the list" << endl << endl;
        return head;
    }

//case delete between nodes 
    Node *current = head;
    while (current->next != nullptr && current->next->idNumber != delID)
    {
        current = current->next;
    }

//case delete not in list
    if (current->next == nullptr)
    {
        cout << "Value not found in the list" << endl << endl;
        return head;
    }

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "Node deleted from the list" << endl << endl;

    printList(head);
    return head;
}


void printList(Node* head)
{
//display student info in the list (for empty list, display message "Empty list")
  if (head == nullptr) {
        cout << "Empty list" << endl;
    }

Node *current = head;
    while (current != nullptr) {    //loop until nullptr
        cout << setw(10) << left << current->firstName << " ";
        cout << setw(10) << left << current->lastName << " ";
        cout << "StudentID #" << current->idNumber << endl;
        
        current = current->next; //set head to next node
    }
    cout << endl; //space between entrys 
}
