
#include "heap.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main () 
{
Heap heap;  //create heap object
int userInput = -1;
while(userInput != 6) 
{
cout << "Heap Array Program" <<endl;
cout << "1: Insert element into heap" << endl;
cout << "2: Print max value" << endl;
cout << "3: Extract max value" << endl;
cout << "4: Print Heap" << endl;
cout << "5: Heap Sort, print and exit" << endl;
cout << "6 Exit Program" << endl;

while(!(cin >> userInput))  //user input for menu
{
    cin.clear();
    cin.ignore();
}

switch(userInput) 
{
case 1: //insert int to heap array
int key;

cout << "enter value to be inserted into heap" << endl; 
while(!(cin >> key)) 
{
    cin.clear();
    cin.ignore();
}

heap.heapinsert(key);
break;

case 2:
heap.maximum(); //print max value 
break;

case 3: //extract max - take max value out of heap reduce size of heap by 1
cout << heap.extractmax() << " extracted" << endl;
break;

case 4: //print heap
heap.printHeap();
break;

case 5: //sort heap and print, exit
heap.heapSort();
heap.printHeap();
exit(0);
break;

case 6:
cout << "Exiting Program" << endl; 
exit(0);
break;

default:
cout << "Invalid selection - please enter a menu option 1 - 4" << endl; 
break;
}
}
return 0;
}