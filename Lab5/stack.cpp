#include <iostream>
#include"stack.h"
using namespace std;

template <class DataType>
stack<DataType>::stack(int i)  //i = max stack size , default = 10
{
    //stack is set to nullptr be default as stack is empty
    top = nullptr;
    numNodes = 0;
    maxSize = i;
}

template <class DataType>
stack<DataType>::~stack()
{
while(top != nullptr)  //loop while list is not empty 
    {

        pop();
        // stackNode<DataType>* temp = top;  //delete node inside list
        // top = top->next;
        // delete temp;
    }
}

template <class DataType>
bool stack<DataType>::isFull() const
{   
    //if the number of nodes is > maxSize of stack
    if(numNodes >= maxSize) 
    {
        //return true
        return true;
    } else {
        //if not false
        return false;
    }
}


template <class DataType>
bool stack<DataType>::isEmpty() const
{
    //the number of nodes in stack is less than or = 0 
   if(top != nullptr) 
    {   
        //stack not empty return false
        return false;
    } else { 
        //stakc is empty else true
        return true;
    }
}

template <class DataType>
DataType stack<DataType>::topStack() const
{
    if(isEmpty() == true) 
    {
        cout << "Stack is empty" << endl;
        return DataType();  //returns default value for datatype
    }
    return top->data;
}

template <class DataType>
void stack<DataType>::push(const DataType val)  //pushes new node into stack
{
    //check if the stakc is full
if(isFull() == true) {
 cout << "Cannot push new Node, Stack is full" << endl;
 return; 
}

   //make new stack node 
   stackNode<DataType>* NewStackNode = new stackNode<DataType>;
   NewStackNode->data = val;
   
   NewStackNode->next = top;
   top = NewStackNode;

    numNodes++;  //increase the number of nodes 
}

template <class DataType>
void stack<DataType>::pop()
{
if(isEmpty() == true) 
{
    cout << "Stack is empty" << endl; 
    return;
} 
    //delete the top value 
    stackNode<DataType>* temp = top;
    top = top->next;
    delete temp;

    numNodes--; //decrement the count of nodes 
}

