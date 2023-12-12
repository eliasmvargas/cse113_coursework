CC=gcc
CFLAGS=-g -Wall
OBJFLAGS=-g -Wall -c 
targets=gl life

# all targets to be compiled
all: $(targets)

gl: gl.c 
	$(CC) $(OBJFLAGS) $@.c 

life: gl.o life.c 
	$(CC) $(CFLAGS) $^ -o $@

# clean it all up
clean:
	rm *.o gl-demo
		 

