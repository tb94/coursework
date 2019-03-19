#
# PROGRAM:  Assign5
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign5: assign5.o
	g++ $(CCFLAGS) -o assign5 assign5.cpp

# Rules to compile source code files to object code
assign5.o: assign5.cpp
	g++ $(CCFLAGS) -c assign5.cpp

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o assign5


