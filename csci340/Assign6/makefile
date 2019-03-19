#
# PROGRAM:  Assign6
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign6: assign6.o assign5.o
	g++ $(CCFLAGS) -o assign6 assign5.cpp assign6.cpp assign6main.cpp

# Rules to compile source code files to object code
assign5.o: assign5.cpp
	g++ $(CCFLAGS) -c assign5.cpp

assign6.o: assign6main.cpp
	g++ $(CCFLAGS) -c assign6main.cpp

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o assign6

