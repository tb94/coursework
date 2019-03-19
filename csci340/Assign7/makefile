#
# PROGRAM:  Assign7
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi

# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.cpp

# Rules to compile source code files to object code
assign7.o: assign7.cpp
	g++ $(CCFLAGS) -c assign7.cpp

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o assign7

