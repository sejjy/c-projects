CC = gcc
CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

inventory: inventory.o readline.o
	$(CC) $(CFLAGS) -o inventory inventory.o readline.o

inventory.o: inventory.c readline.h
	$(CC) $(CFLAGS) -c inventory.c

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c readline.c
