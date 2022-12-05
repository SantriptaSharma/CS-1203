#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skiplist.h"

int main()
{
    SkipList *list = CreateSkipList();

    srand(time(0));

    SkipListInsert(list, 12);
    SkipListInsert(list, 23);
    SkipListInsert(list, 43);
    SkipListInsert(list, 2);
    SkipListInsert(list, 1);
    SkipListInsert(list, 43);
    SkipListInsert(list, 54);
    SkipListInsert(list, 37);
    SkipListInsert(list, 39);
    SkipListInsert(list, 42);

    for(int i = 0; i < MAX_LAYERS; i++)
    {
        printf("Level %d: ", i);
        PrintLevel(list, i);
    }

    FreeSkipList(list);

    return 0;
}