CC = gcc
LLC = linkedlist.c
FLAGS = -g3 -Wall
FINT_FILES = from_integers.c
REV_FILES = reverse.c
CHUNK_REV_FILES = chunk_reverse.c
SELSORT_FILES = selection_sort.c
PROGO = prog

.PHONY: default clean

default: clean

from_integers: $(FINT_FILES) $(LLC)
	$(CC) $(FLAGS) -o $(PROGO) $(FINT_FILES) $(LLC)

reverse: $(REV_FILES) $(LLC)
	$(CC) $(FLAGS) -o $(PROGO) $(REV_FILES) $(LLC)

chunk_reverse: $(CHUNK_REV_FILES) $(LLC)
	$(CC) $(FLAGS) -o $(PROGO) $(CHUNK_REV_FILES) $(LLC)

selection_sort: $(SELSORT_FILES) $(LLC)
	$(CC) $(FLAGS) -o $(PROGO) $(SELSORT_FILES) $(LLC)

clean:
	rm -f *.o
	rm -f prog prog.exe