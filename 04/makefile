CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o BigInt.o
		$(CC) main.o BigInt.o -o prog
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o
BigInt.o: BigInt.cpp
		$(CC) $(CFLAGS) BigInt.cpp -o BigInt.o
clean:
	rm -rf *.o prog