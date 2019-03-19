#
# PROGRAM:      Assign5
# PROGRAMMER:   Tim Bretz
# LOGON ID:     z1697841
# DATE DUE:     3/27/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link objet code files to create executable file
assign5: assign5.o VectorN.o
	g++ $(CCFLAGS) -o assign5 assign5.o VectorN.o

# Rules to compile source code files to object code
assign5.o: assign5.cpp VectorN.h
	g++ $(CCFLAGS) -c assign5.cpp

VectorN.o: VectorN.cpp VectorN.h
	g++ $(CCFLAGS) -c VectorN.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5

