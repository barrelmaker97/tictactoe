# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
tic: tic.o Board.o
	g++ $(CCFLAGS) -o tic tic.o Board.o

# Rule to compile source code file to object code
tic.o: tic.cc Board.h
	g++ $(CCFLAGS) -c tic.cc

# Rule to compile source code file to object code
Board.o: Board.cc Board.h
	g++ $(CCFLAGS) -c Board.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o tic
