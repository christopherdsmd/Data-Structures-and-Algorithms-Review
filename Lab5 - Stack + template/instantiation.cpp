//instantiation.cpp
//file to like the templated.cpp files
#include "student.cpp"
#include "stack.cpp"
#include "lab5.cpp"

//defines class templates for int and student types
template class stack<Students*>;
template class stackNode<Students*>;

template class stack<int>;
template class stackNode<int>;

//compile with
//g++ -o stack instantiantion.cpp
