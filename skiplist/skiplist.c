#include <stdlib.h>
#include <stdio.h>

#include "skiplist.h"
#include "../utils.h"

SkipNode *__CreateSkipListNode(int val)
{
    SkipNode *node = (SkipNode *)malloc(sizeof(SkipNode));
    node->val = val;
    node->height = 0;
    for (int i = 0; i < MAX_LAYERS; i++) node->next[i] = NULL;
    return node;
}

SkipList *CreateSkipList()
{
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->maxHeight = -1;
    for (int i = 0; i < MAX_LAYERS; i++) list->head[i] = NULL;
    return list;
}

void PrintLevel(SkipList *list, int level)
{
    if (level >= MAX_LAYERS) return;

    SkipNode *head = list->head[level];

    printf("[ ");
    while (head != NULL)
    {
        printf(head->next[level] == NULL ? "%d (%d)" : "%d (%d), ", head->val, head->height);
        head = head->next[level];
    }
    printf(" ]\n");
}

static void __FreeRecursive(SkipNode *head)
{
    if (head == NULL) return;
    __FreeRecursive(head->next[0]);
    free(head);
}

void FreeSkipList(SkipList *list)
{
    __FreeRecursive(list->head[0]);
    free(list);
}

void SkipListInsert(SkipList *list, int val)
{
    SkipNode *node = __CreateSkipListNode(val);
    float prob = rand() / (float) RAND_MAX;

    int height = 0;

    for (int i = 1; i < MAX_LAYERS; i++)
    {
        if (prob <= 1.0f/(i + 1))
        {
            height = i;
        }
    }

    node->height = height;
    list->maxHeight = max(list->maxHeight, height);

    for (int i = 0; i <= height; i++)
    {
        if (list->head[i] == NULL)
        {
            list->head[i] = node;
            continue;
        }

        SkipNode *pred = list->head[i];
        while (pred->next[i] != NULL) pred = pred->next[i];
        
        pred->next[i] = node;
    }
}

// Assumes Sorted List
void SkipListBinarySearch(SkipList *list, int val)
{

}