CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o
		$(CC) main.o -o prog
main.o: main.cpp Iterator.hpp Allocator.hpp Vector.hpp
		$(CC) $(CFLAGS) main.cpp -o main.o
clean:
	rm -rf *.o prog