#ifndef NODE_H
#define NODE_H

class Node 
{
    private:
        char lastName[20];
        char firstName[20];
        int idNumber; 
        Node *next;

    public:
        Node();
        void printNode();
        friend class LinkedList;    //make linked list class friend - can access private members
};

#endif
