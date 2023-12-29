// Programmer: Christopher Desmond
// Date: 09/29/23
// Grocery Receipt System - functions file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring> // Include for C-style strings
#include "grocery.h"

using namespace std;

Node* insertNode(Node* head, Node* newNode) {
    Node* current = head;
    // Case 1 - empty list
    if (head == nullptr) {
        head = newNode;
        return head;
    }

    // Case 2 insert smallest key node
    if (newNode->itemNum < head->itemNum) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* temp = head;

    // Case 3 insert largest key node
    while (temp->next != nullptr && newNode->itemNum > temp->next->itemNum) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node has been added to the list" << endl << endl;
    return head;
}

void printList(Node* head) {

    double total = 0; 

    if (head == nullptr) {
        cout << "Empty list" << endl;
    }
  
    cout << setw(10) << left << "Item Num";
    cout << setw(25) << left << "Item Name";
    cout << setw(12) << left << "Unit";
    cout << setw(10) << left << "Unit Price";
    cout << setw(15) << left << "   Tax";
    cout << setw(10) << left << "Subtotal" << endl;
    cout << "---------------------------------------------------------------------------------------"<<endl;

  
    Node* current = head;
  
   while (current != nullptr) {
  cout << setw(10) << current->itemNum << setw(25) << current->itemName;                       
            cout <<setw(12) << current->unit << "$" << setw(10); 
            cout<< fixed << setprecision(2)  << current->unitprice << "$"<<setw(10);
            cout << current->tax << "$" << setw(10) << fixed  <<setprecision(2);
            cout << current->subtotal << endl << endl;

        total = total + current->subtotal;


        current = current->next;
    }
    cout << "Total" << setw(75) << right << fixed << setprecision(2) << "$" << total << endl;
    cout << endl;
}

Node* deleteNode(Node* head, int delID) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return head;
    }

    // Deleting the head node
    if (head->itemNum == delID) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from the list" << endl << endl;
        return head;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->itemNum != delID) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Value not found in the list" << endl << endl;
        return head;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "Node deleted from the list" << endl << endl;

    return head;
}

void deleteList(Node *head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
