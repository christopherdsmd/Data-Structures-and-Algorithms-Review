#include "student.h"
#include <iostream>
using namespace std;

Students::Students() 
{
    cout << "Enter student last name" << endl;
    cin >> LastName; 

    cout << "Enter student first name" << endl;
    cin >> firstName;

    cout << "Enter student ID number" << endl;  
    while(!(cin >> IDnumber)) //error check
    {
        cout << "Error enter a id number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
}

void Students::printStudent() 
{
    cout << "ID# ";
    cout << this->IDnumber << " - ";
    cout << this->LastName << ", " << this->firstName << endl; 
}