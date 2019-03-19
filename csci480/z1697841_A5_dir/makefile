#
# PRIGRAM: Assign 5
# PROGRAMMER: Tim Bretz
# LOGON ID: z1697841
#

# Compiler Variables
CCFLAGS = -pthread -ansi -Wall

# Rule to link object code files to create executable file
Assign5: assign5.o
	g++ $(CCFLAGS) -o Assign5 assign5.cpp

# Rules to compile source code files to object code
assign5.o: assign5.cpp
	g++ $(CCFLAGS) -c assign5.cpp

# Psudo-target to remove object code and executable files
clean:
	-rm *.o Assign5
