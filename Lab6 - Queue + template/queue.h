#ifndef QUEUE_H
#define QUEUE_H

template<class DataType>
struct QueueNode
{
	DataType data;
	QueueNode<DataType> *next;
};

template <class DataType>
class Queue
{
	private:
		QueueNode<DataType> *front;
		QueueNode<DataType> *back;
		int queueSize;	//size of queue
		int queueCnt;	//element count in queue

	public:
		Queue(int = 5);	//class constructor , sets front and back to nullptr, count to 0 and max size to param
		~Queue();		//class desturctor - remove all memory space used by queue elements

		void enQueue(const DataType);			//add an item to back of the queue
		DataType deQueue();				//removae the first item from queue and return value
		DataType topQueue() const;			//return the value of the first item in the queue
		bool isEmpty()	const;				//returns true if there are no elements in the queue
		bool isFull() const;				//returns true if there is no system memory for a new queue node						
};

#endif
