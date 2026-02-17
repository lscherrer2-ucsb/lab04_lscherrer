CC := g++
FLAGS := -Wall -g

all: examheap

examheap: heap.o examheap.o
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm *.o examheap

.PHONY: clean
