CFLAGS = -std=c++1z -Wall -Werror -c -ggdb3
CC=g++

all: prog

test:
	./prog

prog: main.o TokenParser.o Myfunc.o MyAdditionalfunc.o
		$(CC) main.o TokenParser.o Myfunc.o MyAdditionalfunc.o -o prog
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o
TokenParser.o: TokenParser.cpp
		$(CC) $(CFLAGS) TokenParser.cpp -o TokenParser.o
Myfunc.o: Myfunc.cpp
		$(CC) $(CFLAGS) Myfunc.cpp -o Myfunc.o
MyAdditionalfunc.o: MyAdditionalfunc.cpp
		$(CC) $(CFLAGS) MyAdditionalfunc.cpp -o MyAdditionalfunc.o
clean:
	rm -rf *.o prog