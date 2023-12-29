#include "tnode.h"
#include <iostream>
using namespace std;

template <class T>
TNode<T>::TNode() 
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;

    //data = -1;      //set default value to null
}

template <class T>
void TNode<T>::printNode()
{
    cout << this->data << endl;
}
