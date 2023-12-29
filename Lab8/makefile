all: heap

heap: heap.o heapmain.o
	g++ heap.o heapmain.o -o heap

heapmain.o: heapmain.cpp
	g++ -c heapmain.cpp

heap.o:	heap.cpp
	g++ -c heap.cpp

make clean:
	rm -rf *.o heap