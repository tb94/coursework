#
# PROGRAM:	Assign8
# PROGRAMMER:	Tim Bretz
# LOGON ID:	z1697841
# DATE DUE:	4/26/15
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.cpp

# Rule to compile source code files to object code
assign8.o: assign8.cpp mergesort.h quicksort.h sorts.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-targer to remove object code and executable files
clean:
	-rm *.o assign8
