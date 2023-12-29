#include "tnode.h"
#include <iostream>
using namespace std;

TNode::TNode() 
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;

    data = -1;      //set default value to null
}

void TNode::printNode()
{
    cout << this->data << endl;
}
