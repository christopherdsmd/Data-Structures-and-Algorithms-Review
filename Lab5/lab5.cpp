// Programmer: Christopher Desmond
// Date: 10/20/23
#include "stack.h"
#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    stack<Students *> sstack; // Stack of Students objects
    stack<int> istack;        // Stack of integers

    //menu variables
    int userVar = 0;
    int intstackVal = -1;
    int userChoose = -1;
    int userChoose2 = -1;

    //selecs stack type 1 = int, 2 = students
    int stackType = -1;

    while (userVar != -1)
    {
        cout << "Please select the datatype for the stack" << endl;
        cout << "1: Integer" << endl;
        cout << "2: Student - object" << endl;

        while(!(cin >> userVar))    //error check
        {
        cout << "Error enter a valid selection" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        

        if (userVar == 1)
        {
            cout << "You selected Integer type" << endl;
            stackType = 1;  //1 = int
            userVar = -1;
        }
        else if (userVar == 2)
        {
            cout << "You selected Student type" << endl;
            stackType = 2;  //2 = students
            userVar = -1;
        }
    }

    // Integer stack
    switch (stackType)  //case 1 = int case 2 = students
    {
    case 1:
        while (userChoose != 4)
        {
            cout << "Stack Program" << endl;
            cout << "1. Push - a number into the stack" << endl;
            cout << "2. Pop - a number off the top of the stack" << endl;
            cout << "3. Top - display the number from the top of the stack" << endl;
            cout << "4. Exit Program" << endl;
            while(!(cin >> userChoose))
                {
                cout << "Error enter a id number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 

            switch (userChoose)
            {
            case 1:
                cout << "Enter a number to insert into the stack" << endl;
                while(!(cin >> intstackVal))    //error check
                {
                    cout << "Error enter a id number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                istack.push(intstackVal);   //variable from keyboard
                cout << "push into stack" << endl;
                break;

            case 2:

               if (!istack.isEmpty())
                {
                    cout << "Popped node: " << istack.topStack() << endl;
                }
                else
                {
                    cout << "Stack is empty" << endl;
                }
                istack.pop();
                break;

            case 3:
                if (!istack.isEmpty())
                {
                    cout << "Top of stack: " << istack.topStack() << endl;
                }
                else
                {
                    cout << "Stack is empty" << endl;
                }
                break;

            case 4:
                cout << "Exiting Program - Thanks for using the stack data structure program" << endl;
                return 0;

            default:
                cout << "Invalid choice - please select a menu option 1 - 4" << endl;
                break;
            }
        }
        break;

    // Student stack
    case 2:
        while (userChoose2 != 4)
        {
            cout << "Stack Program" << endl;
            cout << "1. Push - a student into the stack" << endl;
            cout << "2. Pop - Pop a student off the top of the stack" << endl;
            cout << "3. Top - display the student from the top of the stack" << endl;
            cout << "4. Exit Program" << endl;
               while(!(cin >> userChoose2))
                {
                cout << "Error enter a id number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 

            switch (userChoose2)
            {
            case 1:
                sstack.push(new Students);  //calls constructor in argument
                cout << "push into stack" << endl;
                break;

            case 2:
                if (!sstack.isEmpty())
                {
                    cout << "Popped node  " << endl;
                    sstack.topStack()->printStudent();  //return top and print
                }
                else
                {
                    cout << "Stack is empty" << endl;
                }
                sstack.pop();
                break;

            case 3:
                if (!sstack.isEmpty())
                {
                    cout << "Top of student stack: " << endl;
                    sstack.topStack()->printStudent();  //return top and print
                }
                else
                {
                    cout << "Stack is empty" << endl;
                }
                break;

            case 4:
                cout << "Exiting Program - Thanks for using the stack data structure program" << endl;
                return 0;

            default:
                cout << "Invalid choice - please select a menu option 1 - 4" << endl;
                break;
            }
        }
        break;

    default:
        cout << "Invalid selection" << endl;
        break;
    }

    return 0;
}
