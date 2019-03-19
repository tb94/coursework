#
# PROGRAM:  Assign3
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign2: assign3.o
	g++ $(CCFLAGS) -o z1697841_A3 assign3.cpp

# Rules to compile source code files to object code
assign3.o: assign3.cpp
	g++ $(CCFLAGS) -c assign3.cpp

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o z1697841_A3

