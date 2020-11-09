CFLAGS = -std=c++11 -Wall -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o Serializer.o
		$(CC) main.o Serializer.o -o prog
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o
BigInt.o: Serializer.cpp
		$(CC) $(CFLAGS) Serializer.cpp -o Serializer.o
clean:
	rm -rf *.o prog