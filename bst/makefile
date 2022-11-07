CC = gcc
SRC = bst.c
FLAGS = -g3 -Wall
B_FILES = basic.c
ARR_FILES = from_array.c
PROGO = prog

.PHONY: default clean

default: clean

basic: $(B_FILES) $(SRC)
	$(CC) $(FLAGS) -o $(PROGO) $(B_FILES) $(SRC)

from_array: $(ARR_FILES) $(SRC)
	$(CC) $(FLAGS) -o $(PROGO) $(ARR_FILES) $(SRC)

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe