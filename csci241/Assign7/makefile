#
# PROGRAM:	Assign7
# PROGRAMMER:	Tim Bretz
# LOGON ID:	z1697841
# DATE DUE:	4/14/ 2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

# Rule to compile source code files to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7
