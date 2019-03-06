#makefile for project 1
#the compilier is gcc
CC = gcc

#compiler flags:
#	-Wall	turns on most compiler warnings
CFLAGS = -Wall -Werror

TARGET = terminal

OBJECTS = terminal.o help.o allocate.o write.o freemem.o displaymem.o invert.o write_pattern.o

terminal: $(OBJECTS)
	cc -o terminal $(OBJECTS)

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

# help.o: help.c help.h
# 	cc -c help.c
#
# allocate.o: allocate.c allocate.h
# 	cc -c allocate.c
#
# freemem.o: freemem.c freemem.h
# 	cc -c freemem.c
#
# displaymem.o: displaymem.c displaymem.h
# 	cc -c displaymem.c
#
# write.o: write.c write.h
# 	cc -c write.c
#
# invert.o: invert.c invert.h
# 	cc -c invert.c
#
# write_pattern.o: write_pattern.c write_pattern.h
# 	cc -c write_pattern.c
#
# verify.o: verify.c verify.h
# 	cc -c verify.c

clean:
	-rm -rf *.o $(OBJECTS)
	-rm -rf $(TARGET)
	-rm -rf testoutput

test:
	-rm -rf testoutput
	./terminal < testscript > testoutput
