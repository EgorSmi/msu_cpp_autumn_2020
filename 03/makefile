CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: mainVector.o MyVector.o
		$(CC) mainVector.o MyVector.o -o prog
mainVector.o: mainVector.cpp
		$(CC) $(CFLAGS) mainVector.cpp -o mainVector.o
MyVector.o: MyVector.cpp
		$(CC) $(CFLAGS) MyVector.cpp -o MyVector.o
clean:
	rm -rf *.o prog