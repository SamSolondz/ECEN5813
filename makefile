#makefile for project 1
#the compilier is gcc
CC = gcc

#compiler flags:
#	-Wall	turns on most compiler warnings
CFLAGS = -Wall

TARGET = terminal.o display.o

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
