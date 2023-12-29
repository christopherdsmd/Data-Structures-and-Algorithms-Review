#include<iostream>
#include<iomanip>

#ifndef STACK_H
#define STACK_H

//class template for Stack node
template <class DataType>
struct stackNode {
    DataType data;  //data stored in stack node, can be any datatype due to template
    stackNode<DataType> *next; //pointer to next node 
};

template<class DataType>
class stack 
{
    stackNode<DataType> *top; //pointer to top node of stack
    int maxSize;        //max allowed size of stack
    int numNodes;       //couints the number of nodes inside the stack
public:
    stack(int = 5);    //constructor -  sets top = null, numnodes = 0 ,  param =  maxsize (default =  10)
    ~stack();   //deconstructor - delete stack 
    //functions
    bool isEmpty() const;   //check if the stack is empty
    bool isFull() const;    //check if the stack is full
    void push(const DataType);  //insert new data into top of stack
    void pop();                 //pop top node off top of stack 
    DataType topStack() const;  //return data from the top of the stack
};

#endif 
