# Various flags
COMPILE_FLAGS = -c -Wall
DEBUG_FLAGS = -g -pg

# Tools
CC = g++
RM = rm -f

# These are example object files that you might want to build
OBJS = pa2.o quadratic.o utils.o

# This is the name of your executable file
EXE = pa2

all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

clean:
	$(RM) $(EXE) $(OBJS)

.cpp.o: $<
	$(CC) $(COMPILE_FLAGS) $(DEBUG_FLAGS) -o $@ $<
