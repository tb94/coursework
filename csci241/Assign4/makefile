#
# PROGRAM:	Assign4
# PROGRAMMER:	Tim Bretz
# LOGON ID:	z1697841
# DATE DUE:	3/20/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign4: assign4.o Vector3.o
	g++ $(CCFLAGS) -o assign4 assign4.o Vector3.o

# Rules to compile source code files to object code
assign3.o: assign3.cpp Vector3.h
	g++ $(CCFLAGS) -c assign4.cpp

Vector3.o: Vector3.cpp Vector3.h
	g++ $(CCFLAGS) -c Vector3.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4




