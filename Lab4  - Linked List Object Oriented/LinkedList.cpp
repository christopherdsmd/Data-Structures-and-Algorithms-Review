#include"LinkedList.h"
#include<iostream>
#include<iomanip>
using namespace std;

LinkedList::LinkedList() //sets start of list to nullptr
{
List = nullptr;
}

LinkedList::~LinkedList()   //when List object is out of scope check or deleted
{
while(List != nullptr)  //loop while list is not empty 
    {
        Node* temp = List;  //delete node inside list
        List = List->next;
        delete temp;
    }
}

void LinkedList::printList()
{
//display student info in the list (for empty list, display message "Empty list")
  if (List == nullptr) {
        cout << "Empty list" << endl;
        return;
        }

Node *current = List;
    while (current != nullptr) 
    {    //loop until nullptr
        current->printNode();   //Node print node function and itterate 
        current = current->next; //set current to next node of list 
    }
    cout << endl; //space between entrys 
}

void LinkedList::deleteNode(int DelID) 
{
    // Case: List is empty
    if (List == nullptr) 
    {
        cout << "List is empty" << endl;
        return;
    }

    // Case: Delete the first node
    if (List->idNumber == DelID) 
    {
        Node *temp = List;
        List = List->next;
        delete temp;
        cout << "Student #" << DelID << " has been deleted." << endl;
        return;
    }

    // Delete between nodes and at the end of the list
    Node *previous = searchLocation(DelID);

    // Check if the node was found
    if (previous == nullptr || previous->next == nullptr) 
    {
        cout << "ID not found in list" << endl;
        return;
    }

    // Delete the node
    Node *temp = previous->next;
    previous->next = previous->next->next;
    cout << "Student #" << DelID << " has been deleted." << endl;
    delete temp;
}


Node *LinkedList::createNode()
{
Node *newNode = new Node;
newNode->next = nullptr;
    
cout << "New Node has been created" << endl;
return newNode; 
}

Node *LinkedList::searchLocation(int studentID)
{
    Node* current = List;
    Node* previous = nullptr;

    while (current != nullptr && current->idNumber < studentID)
    {
        previous = current;
        current = current->next;
    }

    return previous;
}

void LinkedList::insertNode() 
{
    Node *NewNode = createNode(); // create a new node
    Node *Tmp = List; // temporary pointer to traverse the linked list

    // Case 1: List is empty
    if (List == NULL) 
    {
        List = NewNode;
        return;
    }
        //duplciate check
       if (List->idNumber == NewNode->idNumber) 
    {
        cout << "Node ID already exists in the list" << endl;
        return;
    }
    // Case 2: New node as the first node
    else if (List->idNumber > NewNode->idNumber) 
    {
        NewNode->next = List;
        List = NewNode;
        return;
    }
   
    else {
        //using utility function search location 
        Node *previous = searchLocation(NewNode->idNumber);

    
        if(previous->next != nullptr && previous->next->idNumber == NewNode->idNumber) 
        {
            cout << "Node ID already exists in the list" << endl;
            return;
        }  

        // Case 3: Insert between two nodes
        NewNode->next = previous->next;
        previous->next = NewNode;
        cout << "Student has been added to the list" << endl;
    }
}

void LinkedList::searchNode(int searchID)
{

if(List == nullptr) 
{
    cout << "empty list " << endl;
    return;
}
//search location util return previous ptr 
Node *previous = searchLocation(searchID);

//list only has 1 element
if(previous == nullptr && List != nullptr) 
{

    if(List->idNumber == searchID) {
    cout << "Student ID found in list" << endl;
    List->printNode();
    return;
    } else  {
        cout << endl << endl << "Student ID Number not found in list" << endl << endl;  
    return;
    }
}


if(previous->next != nullptr && previous->next->idNumber == searchID)
{
    cout << endl << endl << "Student ID found in list:" << endl;

    previous->next->printNode();
    return;    
}


else {
    cout << endl << endl << "Student ID Number not found in list" << endl << endl;  
}

}
