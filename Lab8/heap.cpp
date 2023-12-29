#include "heap.h"
#include<iostream>
using namespace std;

Heap::Heap() 	//constructor
{
	heapSize = 10;
	//initialize values
	int temp[10] = {4,12,3,19,23,5,32,11,2,24};	//given values 
	for (int i =0; i < heapSize; i++) 
	{
		heap[i] = temp[i];
	}

	buildHeap();	//build inital heap 
}

int Heap::parent(int i) 
{
	if(i % 2 == 0)	//int i = even
	{
		return ((i-1)/2); //even 
	}	else 
	{
		return (i/2); //odd
	}
}

int Heap::leftChild(int i) 
{
	return (2*i+1);
}

int Heap::rightChild(int i) 
{
	return(2*i+2);
}

void Heap::heapify(int i)
{
	int L = leftChild(i);
	int R = rightChild(i);
	int Largest;

	if(L < heapSize && heap[L] > heap[i])  	//if left child value is < the heapSize and [L] > largest element, make largest = L
	{
		Largest = L;
	} else 
	{
		Largest = i;
	}

	if(R < heapSize && heap[R] > heap[Largest]) //if right child value is >= the heapSize and [R] > largest element, make largest = R
	{
		Largest = R;
	}

	if(Largest != i) 	//if left or right child become largest swap and re-heapify
	{
		swap(heap[i], heap[Largest]); 
		heapify(Largest);
	}
}

void Heap::swap(int &x, int &y) 		//swap by reference
{
	int temp = x;
	 x = y;
	 y = temp;
}

void Heap::buildHeap() 
{
	int temp = (heapSize/2)-1;  

	for(int i = temp; i >= 0; i--) 
	{
		heapify(i);
	}
}

void Heap::heapSort() 
{
	//buildHeap();
	int n = heapSize;

	for(int i = heapSize-1; i >= 0; i--) //decrease heapsize for each loop ` 
	{
		swap(heap[0], heap[i]);	//move current root to end of list
		heapSize = heapSize-1; 
		heapify(0);
	}

	heapSize = n;
}

int Heap::extractmax() //extract max - take max value out of heap reduce size of heap by 1
{
	if(heapSize < 1) //heap empty
	{
		//error heap underflow
		throw std::runtime_error("error - heap underflow");
	} else 
	{
		int max = heap[0];
		heap[0] = heap[heapSize-1]; //end of list
		heapSize = heapSize -1; //reduce size for extracted element 

		heapify(0);
		return (max);	//heap [0] is max val
	}
}

void Heap::heapinsert(int key) 
{

	heapSize = heapSize +1;
	int i = heapSize-1;

	while(i > 0 && heap[parent(i)] < key) //while heapsize is > 0 and the parent heap is < key
	{
		heap[i] = heap[parent(i)];		//last element in heap = parent 
		i = parent(i);
	}

	heap[i] = key;	//insert 
	std::cout << key << " inserted into heap" << std::endl;
}

void Heap::printHeap() 
{
	//print all elements in heap itterate until heapsize
	for(int i = 0; i < heapSize; i++) 
	{
		std::cout << heap[i] << " ";
	}
	std::cout << std::endl;
 }

void Heap::maximum() 
{
	if(heapSize < 1) //heap empty
	{
		std::cout << "error - heap undeflow" << std::endl;
	} else 
	{
			//element 0 of heap should be max value after heapify
		std::cout << heap[0] << std::endl;
	}
}
