#
# PROGRAM: Assignment 7
# PROGRAMMER: Tim Bretz
# LOGON ID: Z1697841
#

# Compiler Variables
CCFLAGS = -ansi -Wall 

# Rule to link object code to create executable file
Assign7: assign7.o
	g++ $(CCFLAGS) -o Assign7 assign7.cpp

# Rules to compile source code files to object code
assign7.o: assign7.cpp
	g++ $(CCFLAGS) -c assign7.cpp

# Psudo-target to remove object code and executable files
clean:
	-rm *.o Assign7
