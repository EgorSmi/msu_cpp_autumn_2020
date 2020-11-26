CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o
		$(CC) main.o ThreadPool.o -o prog
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o
ThreadPool.o: ThreadPool.cpp
		$(CC) $(CFLAGS) ThreadPool.cpp -o ThreadPool.o
clean:
	rm -rf *.o prog