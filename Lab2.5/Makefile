all: grocery

grocery: groceryMain.o groceryFunctions.o
	g++ groceryMain.o groceryFunctions.o -o grocery

groceryMain.o: groceryMain.cpp grocery.h
	g++ -c groceryMain.cpp

groceryFunctions.o: groceryFunctions.cpp grocery.h
	g++ -c groceryFunctions.cpp

clean:
	rm -rf *.o grocery