# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -g -std=c++17

# Source files
SRCS = fcfs.cpp rr.cpp sjf.cpp srtf.cpp driver.cpp CPU.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

EXES = fcfs rr sjf srtf

all: $(EXES) 

fcfs: driver.o fcfs.o CPU.o
	$(CC) $(CFLAGS) -o fcfs driver.o fcfs.o  CPU.o

rr: driver.o rr.o CPU.o
	$(CC) $(CFLAGS) -o rr driver.o rr.o CPU.o
	
sjf: driver.o sjf.o CPU.o
	$(CC) $(CFLAGS) -o sjf driver.o sjf.o CPU.o

srtf: driver.o srtf.o CPU.o
	$(CC) $(CFLAGS) -o srtf driver.o srtf.o CPU.o
	
# Rule to compile the source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(EXES)

# Phony targets are not real files and prevent conflicts with file names
.PHONY: all clean

