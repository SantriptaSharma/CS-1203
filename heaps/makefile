CC = gcc
FLAGS = -g3 -Wall
BASIC_FILES = basic.c
SORT_FILES = sort.c
PROGO = prog

.PHONY: default clean

default: clean

basic: $(BASIC_FILES)
	$(CC) $(FLAGS) -o $(PROGO) $(BASIC_FILES)

sort: $(SORT_FILES)
	$(CC) $(FLAGS) -o $(PROGO) $(SORT_FILES)

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe