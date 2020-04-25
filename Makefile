# Rogers Xiang
# May 8, 2018
# Makefile for the t9 program.

# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
# -Wall for debugger warnings
# -std=c11 for updated standards
# -g for debugging info
CFLAGS = -Wall -std=c11 -g

# The name of the program to be produced.
TARGET = t9

# A "phony" target that tells make what other targets to build.
all: $(TARGET)

# All the .o files we need for our executable.
OBJS = main.o trie.o parse.o

# The executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Individual source files
trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

parse.o: parse.c parse.h trie.h
	$(CC) $(CFLAGS) -c parse.c

main.o: main.c trie.h parse.h
	$(CC) $(CFLAGS) -c main.c

# A "phony" target to remove built files and backups
clean:
	rm -f *.o $(TARGET) *~