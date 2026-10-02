CC = gcc
CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

inventory2: inventory2.o readline.o
	$(CC) $(CFLAGS) -o inventory2 inventory2.o readline.o

inventory2.o: inventory2.c readline.h
	$(CC) $(CFLAGS) -c inventory2.c

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c readline.c
