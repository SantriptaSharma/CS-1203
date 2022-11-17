CC = gcc
SRC = avl.c
FLAGS = -g3 -Wall
PROGO = prog
ARR_FILES = from_array.c
TEST_R_FILES = test_rotates.c
DEL_FILES = deletions.c

.PHONY: default clean

default: clean

clean:
	rm -f *.o
	rm -f $(PROGO) $(PROGO).exe

from_array: $(ARR_FILES)
	$(CC) $(FLAGS) $(SRC) $(ARR_FILES) -o $(PROGO)

test_rotates: $(TEST_R_FILES)
	$(CC) $(FLAGS) $(SRC) $(TEST_R_FILES) -o $(PROGO)

deletions: $(DEL_FILES)
	$(CC) $(FLAGS) $(SRC) $(DEL_FILES) -o $(PROGO)