CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=linkedList.c minHeap.c stack.c readAdjacency.c dijNprim.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=dijNprim

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

