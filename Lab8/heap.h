#ifndef HEAP_H
#define HEAP_H

class Heap 
{
	private:
		int heapSize;					//set 10 in constructor
		int heap[10]; 					//max space for heap
					
		//private util functions
		int parent(int i);				//return index of parent of i	
		int leftChild(int i);			//return index of left child of i
		int rightChild(int i);			//return index of right child of i
		void heapify(int i);			//make unsorted array into heap structure
		void buildHeap();		
		void swap(int &x, int &y);

	public:
		Heap(); 						//constructor set heap[] array elements and set heapSize = 10
		void heapinsert(int);			//insert new data into array  
		void heapSort();    			// heapify -  sort array - put max value at the end
		int extractmax();   			//extact max value from heap
		void maximum();					//return max value in heap 
		void printHeap();				//print the heap 
};

#endif
