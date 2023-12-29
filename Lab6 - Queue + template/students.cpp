#include "queue.h"
#include "students.h"
#include <iostream>
using namespace std;

Students::Students() 	//constructor takes in student data from keyboard
{
	cout << "Enter student Last name" << endl;
	cin >> lastName;

	cout << "Enter student First name" << endl;
	cin >> firstName;

	cout << "Enter student ID number" << endl;
	while(!(cin >> IDnum))
	{
	 cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

//prints current student data type
void Students::printStudents() 
{
    cout << "ID# ";
    cout << this->IDnum << " - ";
    cout << this->lastName << ", " << this->firstName << endl; 
}
