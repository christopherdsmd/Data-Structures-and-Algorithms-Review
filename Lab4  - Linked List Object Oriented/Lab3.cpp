//programmer: Christopher Desmond
//Date: 10/04/23
//COSC 220 DrPark
//Lab 4 - Linked List with Class
#include <iostream>
#include<iomanip>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main() 
{
    int userVar = -1; 
    int DelID = -1;
    int searchID = -1;

    // Make class object 
    LinkedList List;

    while(userVar != 5) {
        cout << "\nLinked List with class program:" << endl;
        cout << "1: Insert Node to List" << endl;
        cout << "2: Delete a node from list" << endl; 
        cout << "3: Print List " << endl;
        cout << "4: Search Node " << endl;
        cout << "5: Quit program" << endl;

        if (!(cin >> userVar)) // Error validation  
        {
            cin.clear();
            cin.ignore();
            continue; // Restart the loop if input is not a number
        }

        switch(userVar) {
            case 1: // Insert Node
                List.insertNode();
                break;

            case 2: // Delete node 
                // Print first
                List.printList();
                cout << "Enter Student ID number to be deleted " << endl;
                cin >> DelID;
                List.deleteNode(DelID);
                break;

            case 3: // Print list 
                List.printList();
                break;

            case 4: // Search node 
                cout << "Enter a student ID # to search in the list" << endl;
                cin >> searchID;
                List.searchNode(searchID);
                break;

            case 5:  // Quit program
                cout << "Exiting Program - Thank you for using Linked List Program" << endl;
                return 0;

            default:
                cout << "Error - Please enter a menu option 1 - 5" << endl;
                break; 
        }
    }
    return 0;
}
