# makefile
# compiles all the files found in prelab 6

CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c 
TARGETS = fundamental array swap

# all the targets to be compiled
all: $(TARGETS)

fundamental: fundamental.c
	$(CC) $(CFLAGS) $@.c -o f

array: array.c
	$(CC) $(CFLAGS) $^ -o a

swap: swap.c
	$(CC) $(CFLAGS) $@.c -o s


# remove executeable files and obj files when finished
clean:
		rm *.o fundamental array swap
		rm -r *.dSYM