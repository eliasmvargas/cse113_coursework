CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c 
TARGETS = zombie lab6

all: $(TARGETS)

zombie: zombie.c zombie.h
	$(CC) $(OBJFLAGS) $@.c

lab6: lab6.c zombie.o
	$(CC) $(CFLAGS) $^ -o ./lab6