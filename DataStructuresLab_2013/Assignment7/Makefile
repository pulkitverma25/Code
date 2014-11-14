CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=fordFulkerson.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=assignment7

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

