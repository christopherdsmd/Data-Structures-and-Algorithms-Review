all: tree

tree: bst.o tnode.o lab6.o
	g++ bst.o tnode.o lab6.o -o tree

bst.o: bst.cpp
	g++ -c bst.cpp

tnode.o: tnode.cpp
	g++ -c tnode.cpp

lab6.o: lab6.cpp
	g++ -c lab6.cpp

make clean:
	rm -rf *.o tree