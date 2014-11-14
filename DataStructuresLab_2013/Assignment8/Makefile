CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=pushRelabel.c queue.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=assignment8

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

