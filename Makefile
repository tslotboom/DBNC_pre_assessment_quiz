CC = gcc
CFLAGS = -g 
CPPFLAGS = -std=gnu90 -Wall -pedantic -Wextra

all: q1

q1: q1.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o q1 q1.o

q1.o: q1.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I./ -c q1.c

clean:
	rm -rf *.o q1 q2