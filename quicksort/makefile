CC = gcc
FLAGS = -g3 -Wall
FILES = quicksort.c
PROGO = prog

.PHONY: default clean

default: quicksort

quicksort:
	$(CC) $(FLAGS) -o $(PROGO) $(FILES)

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe