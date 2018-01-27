# Various flags
COMPILE_FLAGS = -c -Wall
DEBUG_FLAGS = -g -pg

# Tools
CC = g++
RM = rm -f

# These are example object files that you might want to build
OBJS = person.o college_person.o bag.o utils.o pa4.o

# This is the name of your executable file
EXE = pa4

all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

clean:
	$(RM) $(EXE) $(OBJS)

.cpp.o: $<
	$(CC) $(COMPILE_FLAGS) $(DEBUG_FLAGS) -o $@ $<
