CC = gcc
SRC = avl.c
FLAGS = -g3 -Wall
PROGO = prog
ARR_FILES = from_array.c

.PHONY: default clean

default: clean

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe

from_array:
	$(CC) $(FLAGS) $(SRC) $(ARR_FILES) -o $(PROGO)