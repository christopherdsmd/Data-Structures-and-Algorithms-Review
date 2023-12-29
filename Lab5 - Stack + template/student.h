#ifndef STUDENT_H
#define STUDENT_H

struct Students
{
    char LastName[20];  //data
    char firstName[20];
    int IDnumber;
    Students();     //constructor
    void printStudent();    //print the student info function 
};

#endif
