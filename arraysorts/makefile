CC = gcc
FLAGS = -g3 -Wall
QSORT_FILES = quicksort.c
SELSORT_FILES = selection_sort.c
INSORT_FILES = insertion_sort.c
PROGO = prog

.PHONY: default clean

default: clean

quicksort:
	$(CC) $(FLAGS) -o $(PROGO) $(QSORT_FILES)

selection_sort:
	$(CC) $(FLAGS) -o $(PROGO) $(SELSORT_FILES)

insertion_sort:
	$(CC) $(FLAGS) -o $(PROGO) $(INSORT_FILES)

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe