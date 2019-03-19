#
# PROGRAM:	Assignment 1
# PROGRAMMER:	Tim Bretz
#

CC = g++
CCFLAGS = -Wall

assign1a: assign1a.o
	$(CC) $(CCFLAGS) -o assign1a assign1a.o

assign1a.o: assign1a.cpp
	$(CC) $(CCFLAGS) -c assign1a.cpp

assign1b: assign1b.o
	$(CC) $(CCFLAGS) -o assign1b assign1b.o

assign1b.o: assign1b.cpp
	$(CC) $(CCFLAGS) -c assign1b.cpp


clean:
	- rm *.o assign1a assign1b
