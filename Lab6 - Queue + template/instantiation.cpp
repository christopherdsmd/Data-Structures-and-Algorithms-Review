//instantiation file - compiles with templates
#include "students.cpp"
#include "lab6.cpp"
#include "queue.cpp"

//int type node
template class Queue<int>;
template class QueueNode<int>;

//student type node 
template class Queue<Students*>;
template class QueueNode<Students*>;