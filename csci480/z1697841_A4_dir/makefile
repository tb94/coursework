#
# PROGRAM:  Assign 4
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
Assign4: assign4.o
	g++ $(CCFLAGS) -o Assign4 assign4.cpp data.txt

# Rules to compile source code files to object code
assign4.o: assign4.cpp
	g++ $(CCFLAGS) -c assign4.cpp 

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o z1697841_A4

