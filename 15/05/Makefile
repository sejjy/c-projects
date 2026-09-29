CC = gcc
CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

calc: calc.o stack.o
	$(CC) $(CFLAGS) -o calc calc.o stack.o

calc.o: calc.c stack.h
	$(CC) $(CFLAGS) -c calc.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
