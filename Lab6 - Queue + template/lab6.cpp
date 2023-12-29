// Programmer: Christopher Desmond
// Date: 10/25/23
#include "queue.h"
#include "students.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    Queue<Students*> squeue; // queue of Students objects
    Queue<int> iqueue;        // queue of integers

    //menu variables
    int userVar = 0;
    int intqueueVal = -1;
    int userChoose = -1;
    int userChoose2 = -1;

    //selecs queue type 1 = int, 2 = students
    int queueType = -1;
    int enter = -1;

    while (userVar != -1)   //select queue node datatypes
    {
        cout << "Please select the datatype for the queue" << endl;
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
            cout << "You selected Integer queue" << endl;
            queueType = 1;  //1 = int
            userVar = -1;
        }
        else if (userVar == 2)
        {
            cout << "You selected Student queue" << endl;
            queueType = 2;  //2 = students
            userVar = -1;
        }
    }

    // Integer queue
    switch (queueType)  //case 1 = int case 2 = students
    {
    case 1:
        while (userChoose != 4)
        {
            cout << "Queue Program" << endl;
            cout << "1: enQueue - enter a number into the end queue" << endl;
            cout << "2: deQueue - remove a student from the front of queue" << endl;
            cout << "3: Top - display the number from the front of the queue" << endl;
            cout << "4: Quit - Exit Program" << endl;
            while(!(cin >> userChoose))
                {
                cout << "Error enter a id number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 

            switch (userChoose)     //menu options user select
            {
            case 1:
                cout << "Enter a number to enter into front of queue" << endl;
                while(!(cin >> enter))  //error check
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                iqueue.enQueue(enter);      //enter = user data int node 
                break;

            case 2:
                if (!iqueue.isEmpty())      //if not empty deQueue first node in list
                {
                    cout << "deQueued node: " << iqueue.deQueue() << endl;  //call deQueue() - remove first node in queue and return data
                    
                } else {
                    cout << "Queue is empty" << endl;
                }
            
            break;

            case 3:
                if (!iqueue.isEmpty())      //if not empty return first node in list and print
                {
                    cout << "Front of queue: " << iqueue.topQueue() << endl;
                }
                else
                {
                    cout << "queue is empty" << endl;
                }
                break;

            case 4:     //exit prog
                cout << "Exiting Program - Thanks for using the queue data structure program" << endl;
                return 0;

            default:
                cout << "Invalid choice - please select a menu option 1 - 4" << endl;
                break;
            }
        }
        break;

    // Student queue
    case 2:
        while (userChoose2 != 4)
        {
             cout << "Queue Program" << endl;
            cout << "1: enQueue - enter a number into the end queue" << endl;
            cout << "2: deQueue - remove a student from the front of queue" << endl;
            cout << "3: Top - display the number from the front of the queue" << endl;
            cout << "4: Quit - Exit Program" << endl;
               while(!(cin >> userChoose2))
                {
                cout << "Error enter a id number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 

            switch (userChoose2)
            {
            case 1:
                squeue.enQueue(new Students);
                cout << "has entered the queue" << endl;
                break;

            case 2:
                if (!squeue.isEmpty())
                {
                    cout << "deQueued Node ";
                    squeue.deQueue()->printStudents();  //call deQueue() - remove first node in queue and return data
                    cout << endl;
                }
                else
                {
                    cout << "Queue is empty" << endl;
                }
               break;

            case 3:
                if (!squeue.isEmpty())
                {
                    cout << "Front of queue: " << endl;
                    squeue.topQueue()->printStudents();
                }
                else
                {
                    cout << "queue is empty" << endl;
                }
                break;
            break;

            case 4:
                cout << "Exiting Program - Thanks for using the queue data structure program" << endl;
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
