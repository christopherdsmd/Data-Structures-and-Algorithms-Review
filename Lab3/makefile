all:List

List: linkedlist.o LinkFun.o
	g++ linkedlist.o LinkFun.o -o List

linkedlist.o: linkedlist.cpp
	g++ -c linkedlist.cpp

Linkfun.o: LinkFun.cpp
	g++ -c Linkfun.cpp

clean:
	rm -rf *.o List
