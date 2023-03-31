CC=g++
CFLAGS=-c -Wall -std=c++98 
LDFLAGS=
SOURCES=LinkedListDemo.cpp LinkedList.cpp Node.cpp Card.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ll

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
