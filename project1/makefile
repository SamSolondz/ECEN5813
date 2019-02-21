#makefile for project 1
#the compilier is gcc
CC = gcc

#compiler flags:
#	-Wall	turns on most compiler warnings
CFLAGS = -Wall -Werror

TARGET = terminal

OBJECTS = terminal.o help.o allocate.o write.o

#$(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

terminal: $(OBJECTS)
	cc -o terminal $(OBJECTS)

help.o: help.c help.h
	cc -c help.c

allocate.o: allocate.c allocate.h
	cc -c allocate.c

free.o: free.c free.h
	cc -c free.c

displaymem.o: displaymem.c displaymem.h
	cc -c displaymem.c

write.o: write.c write.h
	cc -c write.c

invert.o: invert.c invert.h
	cc -c invert.c

pattern.o: pattern.c pattern.h
	cc -c pattern.c

verify.o: verify.c verify.h
	cc -c verify.c


clean:
	-rm *.o $(objects)
