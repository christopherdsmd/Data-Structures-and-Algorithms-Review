#include<iostream>
#include "Node.h"
using namespace std;
Node::Node() 
{
  //save information
    cout << "Enter student last name" << endl;
    cin >> lastName;
    cout << "Enter student first name" << endl;
    cin >> firstName;
    cout << "Enter student ID" << endl;
    while(!(cin >> idNumber)) 
    {
        cout << "Error: must enter a number - try again" << endl;
        cin.clear();
        cin.ignore();
    }

    this->next = nullptr;  //set nodes next member to nullptr
}

void Node::printNode() 
{
  cout << "ID #" << this->idNumber;
  cout << " Student: " << this->firstName << " " << this->lastName << endl;
  
}
