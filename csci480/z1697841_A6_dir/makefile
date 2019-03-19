#
# PROGRAM: Assignment 6
# PROGRAMMER: Tim Bretz
# LOGON ID: z1697841
#

# Compiler Variables
CCFLAGS = -ansi -Wall

# Rule to link object code to create executable file
Assign6: assign6.o
	g++ $(CCFLAGS) -o Assign6 assign6.cpp

# Rules to compile source code files to object code
assign6.o: assign6.cpp
	g++ $(CCFLAGS) -c assign6.cpp

# Psudo-target to remove object code and executable files
clean:
	-rm *.o Assign6
