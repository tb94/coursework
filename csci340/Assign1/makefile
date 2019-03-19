#
# PROGRAM:  Assign1
# PROGRAMMER:  Tim Bretz
# LOGON ID: z1697841
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.cpp

# Rules to compile source code files to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

#Psudo-taget to remove object code and executable files
clean:
	-rm *.o assign1

