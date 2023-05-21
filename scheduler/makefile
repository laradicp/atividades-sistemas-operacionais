# compiler
CC=g++

# compiler flags
CFLAGS=-c -Wall
LDFLAGS=

# source files
SOURCES=$(wildcard src/*.cpp)

# object files
OBJECTS=$(addprefix obj/, $(notdir $(SOURCES:.cpp=.o)))

# executable
EXECUTABLE=scheduler.exe

# create obj directory if it does not exist
MKDIR_P = mkdir -p
.PHONY: directories

all: directories $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

directories:
	${MKDIR_P} obj

clean:
	rm -f obj/*.o $(EXECUTABLE)

.PHONY: all clean directories
