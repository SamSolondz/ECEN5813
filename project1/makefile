#makefile for project 1
#the compilier is gcc
CC = gcc

#compiler flags:
#	-Wall	turns on most compiler warnings
CFLAGS = -Wall -Werror

TARGET = terminal

OBJECTS = terminal.o help.o allocate.o

#$(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

terminal: $(OBJECTS)
	cc -o terminal $(OBJECTS)

help.o: help.c help.h
	cc -c help.c

allocate.o: allocate.c allocate.h
	cc -c allocate.c




clean:
	$(RM) $(TARGET)
