#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skiplist.h"

int main()
{
    SkipList *list = CreateSkipList();

    int seed = time(0);
    printf("%d\n", seed);
    srand(seed);

    SkipListInsert(list, 1);
    SkipListInsert(list, 2);
    SkipListInsert(list, 12);
    SkipListInsert(list, 23);
    SkipListInsert(list, 37);
    SkipListInsert(list, 39);
    SkipListInsert(list, 42);
    SkipListInsert(list, 43);
    SkipListInsert(list, 43);
    SkipListInsert(list, 54);

    for(int i = 0; i <= list->maxHeight; i++)
    {
        printf("Level %d: ", i);
        PrintLevel(list, i);
    }

    SkipNode *found = SkipListBinarySearch(list, 54), *notFound = SkipListBinarySearch(list, 24);

    printf("%d @ %p, %d @ %p\n", found ? found->val : -1, (void*) found, (notFound ? notFound->val : -1), (void*) notFound);

    FreeSkipList(list);

    return 0;
}