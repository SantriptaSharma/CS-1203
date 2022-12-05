CC = gcc
SRC = skiplist.c
FLAGS = -g3 -Wall
PROGO = prog

.PHONY: default clean

default: clean

basic: $(SRC)
	$(CC) $(FLAGS) -o $(PROGO) $(SRC) basic.c

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe