#include "students.h"
#include "bst.h"
#include "tnode.h"

//int type node 
template class BST<int>;
template class TNode<int>;

//student type node
template class BST<Students*>;
template class TNode<Students*>;