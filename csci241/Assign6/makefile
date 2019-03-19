#
# PROGRAM:      Assign6
# PROGRAMMER:   Tim Bretz
# LOGON ID:     z1697841
# DATE DUE:    4/7/ 2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create exectuable file
assign6: assign6.o Queue.o
	g++ $(CCFLAGS) -o assign6 assign6.o Queue.o

# Rules to compile source code files to object code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

Queue.o: Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
