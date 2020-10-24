CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o Matrix.o Vector.o
		$(CC) main.o Matrix.o Vector.o -o prog
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o
Matrix.o: Matrix.cpp
		$(CC) $(CFLAGS) Matrix.cpp -o Matrix.o
Vector.o: Vector.cpp
		$(CC) $(CFLAGS) Vector.cpp -o Vector.o
clean:
	rm -rf *.o prog