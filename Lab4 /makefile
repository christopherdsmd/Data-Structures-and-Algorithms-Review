all: List

List: Lab3.o Node.o LinkedList.o
	g++ Lab3.o Node.o LinkedList.o -o List

LinkedList.o: LinkedList.cpp 
	g++ -c LinkedList.cpp

Node.o:	Node.cpp 
	g++ -c Node.cpp

Lab3.o: Lab3.cpp 
	g++ -c Lab3.cpp

clean:
	rm -rf *.o List
