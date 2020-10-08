CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

prog: main.o allocator.o
	$(CC) main.o allocator.o -o prog
allocator.o: Allocator.cpp
	$(CC) $(CFLAGS) Allocator.cpp -o allocator.o
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o
clean:
	rm -rf *.o prog