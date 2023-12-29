// Programmer: Christopher Desmond
// Date 09/29/23
// Grocery Reciept System - main file
#include "grocery.h"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  Node *head = nullptr; // head points to the linked list

  // ifstream read in var and open
  ifstream fileRead;
  fileRead.open("item.txt");
  ofstream fileWrite;
  fileWrite.open("Desmond_Christopher.txt"); // create receipt .txt file
  if (!fileRead)                             // error validation
  {
    cout << "Error - could not open file" << endl;
    return 0;
  }

  // grocery variables
  // user variables
  int userInput = -1;
  float userAmount = -1;
  // grocery
  int current_item_num = -1;
  char item_name[40];
  char tax_type;
  char sales_type;
  float unit_price = 0.00;

  // tax rate
  const float tax_rate = 0.06;

  // calculations
  float tax_amount = 0.00;
  float subtotal = 0.00;
  

  // menu - loop
  int userVar = -1;
  while (userVar != 4) { // break on 4 - print reciept
    fileRead.clear();
    fileRead.seekg(0);

    cout << endl << endl;
    cout << "Grocery Recipet Linked List System" << endl;
    cout << "1: Insert a item" << endl;
    cout << "2: Print current list to screen" << endl;
    cout << "3: Delete an item from current list" << endl;
    cout << "4: Create receipt - write to .txt file and exit program" << endl;
    cin >> userVar;

    // error validation
    if (cin.fail()) {
      cout << "Error: enter a menu option 1-4" << endl;
      cin.clear();
      cin.ignore();
    }

    Node *newNode = new Node;
    newNode->next = nullptr;

    int delID = -1;
    bool foundInList = false;

    switch (userVar) {
    case 1: // insert node into linked list (search item ID)
      cout << "Enter item ID number to add to list. " << endl;
      cin >> userInput;

      while (!fileRead.eof()) {
        // Reset variables for each item
        tax_amount = 0.00;
        subtotal = 0.00;

        // read in grocery data
        fileRead >> current_item_num;
        fileRead >> item_name;
        fileRead >> tax_type;
        fileRead >> sales_type;
        fileRead >> unit_price;

        // found
        if (userInput == current_item_num) {
          foundInList = true;

          // if tax == 't', calculate tax
          if (tax_type == 't') {
            cout << item_name << " is Taxed " << endl << endl;
            tax_amount = unit_price * tax_rate;
          }

          switch (sales_type) {
          case 's':
            userAmount = 1;
            cout << item_name << " - $" << unit_price
                 << ", Has been added to the list." << endl;
            break;

          case 'n':
            cout << "How many number of " << item_name << ", Would you like? "
                 << endl;
            cin >> userAmount;
            cout << item_name << "x" << userAmount
                 << ", Has been added to the list." << endl;
            break;

          case 'p':
            cout << "How many pounds of " << item_name << ", Would you like? "
                 << endl;
            cin >> userAmount;
            cout << userAmount << " pounds of " << item_name
                 << ", Has been added to the list." << endl;
            break;
          }

           // calculations
        subtotal = userAmount * (unit_price + tax_amount);
       // total = total + subtotal;
          
          // Populate newNode with the correct values
          newNode->itemNum = current_item_num;
          strcpy(newNode->itemName, item_name);
          newNode->unit = userAmount;
          newNode->unitprice = unit_price;
          newNode->tax = tax_amount;
          newNode->subtotal = subtotal;

          // Insert newNode into the linked list
          head = insertNode(head, newNode);
        }

       
      }

      if (foundInList == false && userInput != 0) {
        cout << "Item number not found, Try another number" << endl;
      }

      break;
    case 2:                // print linked list to user
      if (head == nullptr) // if list is empty cannot print list
      {
        cout << "Error: list is empty" << endl << endl;
      } else {
        printList(head);
      }
      break;

    case 3:                // delete a node from list (search via item ID)
      if (head == nullptr) // if list is empty cannot delete
      {
        cout << "Error: list is empty" << endl << endl;
      } else {
        // print the list first
        printList(head);
        
        cout << "Enter an Item number from list to delete :";
        cin >> delID;



        head = deleteNode(head, delID); // update linked list
      }
      break;

    case 4: // create .txt output of linked list
      if (head == nullptr) // if list is empty cannot make reciept
      {
        cout << "Error: list is empty" << endl << endl;
      } else {
        // print reciept functionality
         fileWrite << left << setw(15) << "Item Number" << setw(15) << "Item Name"  << setw(10) << "Unit" << setw(15) << "Unit Price" << setw(10) << "Tax" << setw(15) << "Subtotal" << endl;
    fileWrite << "__________________________________________________________________________________________" << endl;


      float total = 0.00;

        
        while(head != nullptr)
              {
            fileWrite << fixed << setprecision(2) << setw(10) << head->itemNum << setw(25) << head->itemName;                       
            fileWrite <<setw(12) << fixed << setprecision(2)  << head->unit << "$" << setw(10); 
            fileWrite<< fixed << setprecision(2)  << head->unitprice << "$"<<setw(10);
            fileWrite << head->tax << "$" << setw(10) << fixed  <<setprecision(2);
            fileWrite << head->subtotal << endl << endl;

        total = total + head->subtotal;

                Node* temp = head;
                head = head->next;
                delete temp;
              }
                    fileWrite << "Total" << setw(75) << right << fixed << setprecision(2) << "$" << total << endl;
        
        // delete list function call - prevent memory leak
        //deleteList(head);
        cout << "Your reciept has printed - Thank you for using grocery "
                "reciept system " << endl;
      }
      return 0;
      break;

    default: // error validation
      cout << "Invalid input - Please enter menu selection 1 - 5" << endl;
      break;
    }
  }

  fileRead.close();
  fileWrite.close();
  return 0;
}
