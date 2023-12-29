#include "queue.h"

template <class DataType> 
Queue<DataType>::Queue(int val) //constructor - when queue is created
{
    //sets queue prts to null by defauly
    front = nullptr;
    back = nullptr;

    queueCnt = 0;   // 0 nodes in queue at start
    queueSize = val;    //set the max size of queue, default is 5
}

template <class DataType>
Queue<DataType>::~Queue()   //deconstructor, delete all nodes until front == nullptr
{   
    while(front != nullptr) 
    {

        deQueue();
        // QueueNode<DataType> *temp = front;
        // front = front->next;
        // delete temp;
    }
}

template <class DataType>
void Queue<DataType>::enQueue(const DataType val)   //insert new Node to back of queue
{
    //create new node
    QueueNode<DataType> *newQueueNode = new QueueNode<DataType>;
    newQueueNode->data = val;   //paramter is data for new node
    if(isEmpty()) 
    {
        front = newQueueNode;
        back = newQueueNode;

	queueCnt++;
    } else {
    if(!(isFull())) { //if the queue is not Full insert into back
    //insert node at back of queue
    back->next = newQueueNode;
    back = newQueueNode;

   queueCnt++; 
    } 
    
    else 
    {
        cout << "Queue is full" << endl;
    }
    }

   
}

template <class DataType>
DataType Queue<DataType>::deQueue() //remove the first node from the queue and return its value 
{
if(!(isEmpty()))  //check is queue is empty
{
QueueNode<DataType> *temp = front;    //return the original front value, make the queues front = front->next delete og front
front = front->next;
DataType Data = temp->data;
delete temp;

queueCnt--;
return Data; //return data 
}    

throw runtime_error("Error - Queue is empty");
}


template <class DataType>
DataType Queue<DataType>::topQueue() const
{
    if(!(isEmpty())) {
return front->data;
    }
    else 
    {
     throw runtime_error("Error - Queue is empty");   
    }
}
 
template <class DataType>
bool Queue<DataType>::isFull() const 
{
    if(queueCnt >= queueSize) { //if the queue count is > queue max size
        return true;
    } else 
    {
        return false;
    }
}

template <class DataType>
bool Queue<DataType>::isEmpty() const 
{
    if(queueCnt <= 0)     //if front and back are null return true
    {
        return true;
    } else 
    {
    return false;
    }
}
