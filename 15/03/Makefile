CC = gcc
CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

qsort: qsort.o quicksort.o
	$(CC) $(CFLAGS) -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	$(CC) $(CFLAGS) -c qsort.c

quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c quicksort.c
