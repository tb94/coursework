#
# PROGRAM:  Assign2
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign2: assign2.o
	g++ $(CCFLAGS) -o Assign2 assign2.cpp

# Rules to compile source code files to object code
assign2.o: assign2.cpp
	g++ $(CCFLAGS) -c assign2.cpp

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o Assign2









