CFLAGS = -std=c++11 -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o Format.o ParseError.o
		$(CC) main.o Format.o ParseError.o -o prog
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o
Format.o: Format.cpp
		$(CC) $(CFLAGS) Format.cpp -o Format.o
ParseError.o: ParseError.cpp
		$(CC) $(CFLAGS) ParseError.cpp -o ParseError.o
clean:
	rm -rf *.o prog